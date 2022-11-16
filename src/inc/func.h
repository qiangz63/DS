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
// 一维数组算的是元素个数，二维数组算的是元素行数
#define LENGTH(a) (sizeof(a) / sizeof(a[0]))
#define isLetter(a)                                                            \
  ((((a) >= 'a') && ((a) <= 'z')) || (((a) >= 'A') && ((a) <= 'Z')))

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
// 读取一个输入字符
static char read_char() {
  char ch;
  do {
    ch = getchar();
  } while (!isLetter(ch));
  return ch;
}
// 返回ch在matrix矩阵中的位置
static int get_position(ALGraph g, char ch) {
  int i;
  for (i = 0; i < g.vexnum; i++) // 去顶点结构体数组中遍历每个顶点
    if (g.vertices[i].data == ch)
      return i; // 返回的是对应顶点的下标
  return -1;
}
// 将node链接到list的末尾
static void link_last(ArcNode *list, ArcNode *node) {
  ArcNode *p = list;
  while (p->next)
    p = p->next;
  p->next = node;
}
// 创建邻接表对应的图(自己输入)
ALGraph *CreateMyALGraph() {
  char c1, c2;
  int v, e;
  int i, p1, p2;
  ArcNode *node1, *node2;
  ALGraph *pG;
  // 输入"顶点数"和"边数"
  printf("Input vertex number: ");
  scanf("%d", &v);
  printf("Input edge number: ");
  scanf("%d", &e);
  if (v < 1 || e < 1 || (e > (v * (v - 1)))) {
    printf("input error: invalid parameters!\n");
    return NULL;
  }
  if ((pG = (ALGraph *)malloc(sizeof(ALGraph))) == NULL)
    return NULL;
  memset(pG, 0, sizeof(ALGraph));
  // 初始化"顶点数"和"边数"
  pG->vexnum = v;
  pG->arcnum = e;
  // 初始化"邻接表"的顶点
  for (i = 0; i < pG->vexnum; i++) {
    printf("vertex(%d): ", i);
    pG->vertices[i].data = read_char();
    pG->vertices[i].first = NULL;
  }
  // 初始化"邻接表"的边
  for (i = 0; i < pG->arcnum; i++) {
    // 读取边的起始顶点和结束顶点
    printf("edge(%d): ", i);
    c1 = read_char();
    c2 = read_char();
    p1 = get_position(*pG, c1);
    p2 = get_position(*pG, c2);
    // 初始化node1
    node1 = (ArcNode *)calloc(1, sizeof(ArcNode));
    node1->adjvex = p2;
    // 将node1链接到"p1所在链表的末尾"
    if (pG->vertices[p1].first == NULL)
      pG->vertices[p1].first = node1;
    else
      link_last(pG->vertices[p1].first, node1);
    // 初始化node2
    node2 = (ArcNode *)calloc(1, sizeof(ArcNode));
    node2->adjvex = p1;
    // 将node2链接到"p2所在链表的末尾"
    if (pG->vertices[p2].first == NULL)
      pG->vertices[p2].first = node2;
    else
      link_last(pG->vertices[p2].first, node2);
  }
  return pG;
}
// 创建邻接表对应的图(用已提供的数据) 无向图
ALGraph *CreateExampleALgraph() {
  char c1, c2;
  char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
  char edges[][2] = {{'A', 'C'}, {'A', 'D'}, {'A', 'F'}, {'B', 'C'},
                     {'C', 'D'}, {'E', 'G'}, {'F', 'G'}};
  int vlen = LENGTH(vexs);  // 顶点数
  int elen = LENGTH(edges); // 边数
  // 上面类似一个邻接矩阵存储
  int i, p1, p2;
  ArcNode *node1, *node2;
  ALGraph *pG; // pG表示图
  if ((pG = (ALGraph *)malloc(sizeof(ALGraph))) == NULL)
    return NULL;
  memset(pG, 0, sizeof(ALGraph)); // 把申请的空间全部初始化为零
  // 初始化"顶点数"和"边数"
  pG->vexnum = vlen;
  pG->arcnum = elen;
  // 初始化"邻接表"的顶点
  for (i = 0; i < pG->vexnum; i++) {
    pG->vertices[i].data = vexs[i];
    pG->vertices[i].first = NULL;
  }
  // 初始化"邻接表"的边
  for (i = 0; i < pG->arcnum; i++) {
    // 读取边的起始顶点和结束顶点
    c1 = edges[i][0];
    c2 = edges[i][1];
    p1 = get_position(*pG, c1); // p1对应起始顶点下标位置
    p2 = get_position(*pG, c2); // p2对应结束顶点下标位置
    // 初始化node1
    node1 = (ArcNode *)calloc(1, sizeof(ArcNode));
    node1->adjvex = p2;
    // 将node1链接到"p1所在链表的末尾"
    if (pG->vertices[p1].first == NULL)
      pG->vertices[p1].first = node1;
    else
      link_last(pG->vertices[p1].first, node1);
    // 初始化node2
    node2 = (ArcNode *)calloc(1, sizeof(ArcNode));
    node2->adjvex = p1;
    // 将node2链接到"p2所在链表的末尾"
    if (pG->vertices[p2].first == NULL)
      pG->vertices[p2].first = node2;
    else
      link_last(pG->vertices[p2].first, node2);
  }
  return pG;
}
// 创建邻接表对应的图(有向图)
ALGraph *CreateExampleALgraphDirected() {
  char c1, c2;
  char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
  char edges[][2] = {{'A', 'B'}, {'B', 'C'}, {'B', 'E'}, {'B', 'F'}, {'C', 'E'},
                     {'D', 'C'}, {'E', 'B'}, {'E', 'D'}, {'F', 'G'}};
  int vlen = LENGTH(vexs);
  int elen = LENGTH(edges);
  int i, p1, p2;
  ArcNode *node1;
  ALGraph *pG;
  if ((pG = (ALGraph *)malloc(sizeof(ALGraph))) == NULL)
    return NULL;
  memset(pG, 0, sizeof(ALGraph));
  // 初始化"顶点数"和"边数"
  pG->vexnum = vlen;
  pG->arcnum = elen;
  // 初始化"邻接表"的顶点
  for (i = 0; i < pG->vexnum; i++) {
    pG->vertices[i].data = vexs[i];
    pG->vertices[i].first = NULL;
  }
  // 初始化"邻接表"的边
  for (i = 0; i < pG->arcnum; i++) {
    // 读取边的起始顶点和结束顶点
    c1 = edges[i][0];
    c2 = edges[i][1];
    p1 = get_position(*pG, c1);
    p2 = get_position(*pG, c2);
    // 初始化node1
    node1 = (ArcNode *)calloc(1, sizeof(ArcNode));
    node1->adjvex = p2;
    // 将node1链接到"p1所在链表的末尾"
    if (pG->vertices[p1].first == NULL)
      pG->vertices[p1].first = node1;
    else
      link_last(pG->vertices[p1].first, node1);
  }
  return pG;
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
