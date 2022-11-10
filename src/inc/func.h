#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define MAXSIZE 50
#define MaxVexNum 100

// 二叉树
typedef struct BiTNode {
  char data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
// 线索二叉树
typedef struct ThreadNode {
  char data;
  struct ThreadNode *lchild, *rchild;
  int ltag, rtag;
} ThreadNode, *ThreadTree;
// 辅助建树的单链表，用来得到辅助队列以建树
typedef struct tag {
  BiTree p; // 存放树的某一节点的地址值
  struct tag *next;
} tag, *ptag;
// 栈
typedef struct {
  BiTree data[MAXSIZE];
  int top;
} Stack;
// 单链表
typedef struct LNode {
  BiTree data;
  struct LNode *next;
} LNode, *LinkList;
// 链式辅助队列以实现广度优先遍历（层次遍历）
typedef struct {
  LNode *front, *rear;
} Queue;
// 邻接矩阵
typedef struct {
  char vex[MaxVexNum];
  int edge[MaxVexNum][MaxVexNum];
  int vexnum, arcnum;
} MGraph;
// 邻接表
typedef struct ArcNode {
  int adjvex;
  struct ArcNode *next;
} ArcNode;
typedef struct VNode {
  char data;
  ArcNode *first;
} VNode, AdjList[MaxVexNum];
typedef struct {
  AdjList vertices;
  int vexnum, arcnum;
} ALGraph, *Graph;

void InitStack(Stack &S) { S.top = -1; }
bool EmptyStack(Stack &S) {
  if (S.top == -1)
    return true;
  return false;
}
bool GetTop(Stack &S, BiTree &x) {
  if (EmptyStack(S))
    return false;
  x = S.data[S.top];
  return true;
}
bool Push(Stack &S, BiTree x) {
  if (S.top == MAXSIZE - 1)
    return false;
  S.data[++S.top] = x;
  return true;
}
bool Pop(Stack &S, BiTree &x) {
  if (EmptyStack(S))
    return false;
  x = S.data[S.top--];
  return true;
}
// 带有头节点的链式队列
void InitQueue(Queue &Q) {
  Q.front = Q.rear = (LNode *)malloc(sizeof(LNode)); // 均指向头节点
  Q.front->next = NULL; // 尾指针时刻指向尾部，故无需NULL
}
bool EmptyQueue(Queue Q) {
  if (Q.front == Q.rear)
    return true;
  return false;
}
void EnQueue(Queue &Q, BiTree x) {
  LNode *s = (LNode *)malloc(sizeof(LNode));
  s->data = x;
  s->next = NULL;
  Q.rear->next = s;
  Q.rear = s;
}
bool DeQueue(Queue &Q, BiTree &x) { // 头节点一直不变，故head也不会变
  if (EmptyQueue(Q))
    return false;
  LNode *p = Q.front->next;
  x = p->data;
  if (Q.rear == p)    // 判断要删除的节点是否为最后一个元素
    Q.rear = Q.front; // 需要置空
  Q.front->next = p->next;
  free(p);
  return true;
}
void CreateTree(BiTree &tree) {
  BiTree pnew; // 存放新的树节点
  // 新建一个不带头节点的辅助队列
  ptag phead = NULL, ptail = NULL, listpnew, pcur;
  // phead队列头，ptail队列尾，listpnew存放新节点
  char c;
  // 层次建树，abcdefghij
  cout << "层次建树￥请输入字母(无空格)：" << endl;
  while (scanf("%c", &c) != EOF) {
    if (c == '\n')
      break;
    pnew = (BiTree)calloc(1, sizeof(BiTNode));
    // calloc(1,sizeof())空间大小为1*sizeof()，且在创建空间后自动初始化为0或NULL
    pnew->data = c;                          // 给新树节点赋值
    listpnew = (ptag)calloc(1, sizeof(tag)); // 给要插入队列的节点申请空间
    listpnew->p = pnew;                      // 存放树节点地址
    if (tree == NULL) {
      tree = pnew;      // 得到树根
      phead = listpnew; // 队列头，永远不动
      ptail = listpnew; // 队列尾
      pcur = listpnew;  // pcur始终指向要插入的节点的位置
      continue;         //!!!第一次仅需建立1个树根和1个辅助队列
    } else {
      ptail->next = listpnew; // 尾插法将新节点放入队列
      ptail = listpnew;       // ptail指向队列尾部
    }
    if (pcur->p->lchild == NULL)        // 左孩子为空
      pcur->p->lchild = pnew;           // 把新结点作为左孩子放入树
    else if (pcur->p->rchild == NULL) { // 右孩子为空
      pcur->p->rchild = pnew;           // 把新结点作为右孩子放入树
      pcur = pcur->next; // 左右都有孩子时，pcur需指向队列下一个
    }
  }
}
Graph CreateALGraph(int v, int e) {
  Graph G = new ALGraph;
  G->vexnum = v;
  G->arcnum = e;
  for (int i = 0; i < v; ++i)
    G->vertices[i].first = NULL;
  cout << "邻接表头插法创建无向图(数字用逗号隔开):" << endl;
  for (int i = 0; i < e; ++i) {
    int v1, v2;
    cin >> v1;
    cin >> v2;
    ArcNode *p = new ArcNode;
    p->adjvex = v2;
    p->next = G->vertices[v1].first;
    G->vertices[v1].first = p;
    ArcNode *q = new ArcNode;
    q->adjvex = v1;
    q->next = G->vertices[v2].first;
    G->vertices[v2].first = q;
  }
  return G;
}
MGraph CreateMGraph(int v, int e) {
  int x;
  MGraph M;
  M.vexnum = v;
  M.arcnum = e;
  cout << "邻接矩阵创建无向图(N*N,数字用空格隔开):" << endl;
  for (int i = 0; i < M.vexnum; ++i)
    for (int j = 0; j < M.vexnum; ++j) {
      cin >> x;
      M.edge[i][j] = x;
    }
  return M;
}
