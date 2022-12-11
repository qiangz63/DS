#include "inc/func.h"

void print(int M[], int n) {
  for (int i = 0; i < n; i++)
    cout << M[i] << ' ';
  cout << endl;
}

void visit(BiTree T) { cout << T->data; }

void qsort(int M[], int low, int high) {
  if (low < high) {
    int i = low, j = high, p = M[low];
    while (i < j) {
      while (M[j] > p && i < j)
        j--;
      if (i < j) {
        M[i] = M[j];
        i++;
      }
      while (M[i] < p && i < j)
        i++;
      if (i < j) {
        M[j] = M[i];
        j--;
      }
    }
    M[i] = p;
    qsort(M, low, i - 1);
    qsort(M, i + 1, high);
  }
}

void adjust(int A[], int low, int high) {
  if (low < high) {
    A[0] = A[low];
    int i = low, j = 2 * low;
    while (j <= high) {
      if (j < high && A[j + 1] < A[j])
        j++;
      if (A[0] > A[j]) {
        A[i] = A[j];
        i = j;
        j = 2 * i;
      } else
        break;
    }
    A[i] = A[0];
  }
}

void heapsort(int B[], int n) {
  int i;
  for (i = n / 2; i > 0; i--)
    adjust(B, i, n);
  for (i = n; i > 0; i--) {
    cout << B[1] << ' ';
    B[0] = B[1];
    B[1] = B[i];
    B[i] = B[0];
    adjust(B, 1, i - 1);
  }
  cout << endl;
}

void PreOrder(BiTree T) {
  if (T) {
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
  }
}

void InOrder(BiTree T) {
  if (T) {
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchild);
  }
}

void PostOrder(BiTree T) {
  if (T) {
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T);
  }
}

void LevelOrder(BiTree T) {
  Queue Q;
  InitQueue(Q);
  BiTree p = T;
  EnQueue(Q, p);
  while (!EmptyQueue(Q)) {
    DeQueue(Q, p);
    visit(p);
    if (p->lchild)
      EnQueue(Q, p->lchild);
    if (p->rchild)
      EnQueue(Q, p->rchild);
  }
}

void PreOrder2(BiTree T) {
  Stack S;
  InitStack(S);
  BiTree p = T;
  while (p || !EmptyStack(S)) {
    if (p) {
      visit(p);
      Push(S, p);
      p = p->lchild;
    } else {
      Pop(S, p);
      p = p->rchild;
    }
  }
}

void InOrder2(BiTree T) {
  Stack S;
  InitStack(S);
  BiTree p = T;
  while (p || !EmptyStack(S)) {
    if (p) {
      Push(S, p);
      p = p->lchild;
    } else {
      Pop(S, p);
      visit(p);
      p = p->rchild;
    }
  }
}

void PostOrder2(BiTree T) {
  Stack S;
  InitStack(S);
  BiTree p = T, r = NULL;
  while (p || !EmptyStack(S)) {
    if (p) {
      Push(S, p);
      p = p->lchild;
    } else {
      GetTop(S, p);
      if (p->rchild && p->rchild != r)
        p = p->rchild;
      else {
        Pop(S, p);
        visit(p);
        r = p, p = NULL;
      }
    }
  }
}

int FirstNeighbor(Graph G, int i) {
  ArcNode *first = G->vertices[i].first;
  return first == NULL ? -1 : first->adjvex;
}

int NextNeighbor(Graph G, int i, int j) {
  ArcNode *edge = G->vertices[i].first;
  while (edge && edge->adjvex != j)
    edge = edge->next;
  if (!edge || !edge->next)
    return -1;
  else
    return edge->next->adjvex;
}

void BFSTrav(Graph G, int i, int *visited) {
  cout << G->vertices[i].data;
  visited[i] = 1;
  int Q[MaxVexNum], front = -1, rear = -1;
  Q[++front] = i;
  while (front != rear) {
    i = Q[++rear];
    for (int j = FirstNeighbor(G, i); j >= 0; j = NextNeighbor(G, i, j)) {
      if (!visited[j]) {
        cout << G->vertices[j].data;
        visited[j] = 1;
        Q[++front] = j;
      }
    }
  }
}

void BFS(Graph G) {
  int i, visited[MaxVexNum];
  for (i = 0; i < G->vexnum; i++)
    visited[i] = 0;
  for (i = 0; i < G->vexnum; i++)
    if (!visited[i])
      BFSTrav(G, i, visited);
}

void DFSTrav(Graph G, int i, int *visited) {
  cout << G->vertices[i].data;
  visited[i] = 1;
  ArcNode *p = G->vertices[i].first;
  while (p) {
    if (!visited[p->adjvex])
      DFSTrav(G, p->adjvex, visited);
    p = p->next;
  }
}

void DFS(Graph G) {
  int i, visited[MaxVexNum];
  for (i = 0; i < G->vexnum; i++)
    visited[i] = 0;
  for (i = 0; i < G->vexnum; i++)
    if (!visited[i])
      DFSTrav(G, i, visited);
}

void DFS2(Graph G, int v) {
  int S[MaxVexNum], top = -1;
  int i, visited[MaxVexNum];
  for (i = 0; i < G->vexnum; i++)
    visited[i] = 0;
  cout << G->vertices[v].data;
  visited[v] = 1;
  S[++top] = v;
  while (top != -1) {
    int j = S[top];
    ArcNode *p = G->vertices[j].first;
    while (p && visited[p->adjvex])
      p = p->next;
    if (!p)
      top--;
    else {
      cout << G->vertices[p->adjvex].data;
      visited[p->adjvex] = 1;
      S[++top] = p->adjvex;
    }
  }
}

void merge(int A[], int low, int mid, int high) {
  int i = low, j = mid + 1, k, B[10];
  for (k = low; k <= high; k++)
    B[k] = A[k];
  for (k = i; i <= mid && j <= high; k++)
    if (B[i] > B[j])
      A[k] = B[j++];
    else
      A[k] = B[i++];
  while (i <= mid)
    A[k++] = B[i++];
  while (j <= high)
    A[k++] = B[j++];
}

void mergesort(int A[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    mergesort(A, low, mid);
    mergesort(A, mid + 1, high);
    merge(A, low, mid, high);
  }
}

int main() {
  int A[10] = {99, -3, -29, 23, 34, 91, 0, 8, 34, 84};
  qsort(A, 0, 9);
  print(A, 10);
  int B[10] = {99, -3, -29, 23, 34, 91, 0, 8, 34, 84};
  heapsort(B, 9);
  int C[10] = {99, -3, -29, 23, 34, 91, 0, 8, 34, 84};
  mergesort(C, 0, 9);
  print(C, 10);
  BiTree tree = NULL;
  CreateTree(tree);
  printf("-----层次遍历-----\n");
  LevelOrder(tree);
  printf("\n-----前序遍历-----\n");
  PreOrder(tree);
  printf("\n-----中序遍历-----\n");
  InOrder(tree);
  printf("\n-----后序遍历-----\n");
  PostOrder(tree);
  printf("\n-----前序非递归遍历\n");
  PreOrder2(tree);
  printf("\n-----中序非递归遍历\n");
  InOrder2(tree);
  printf("\n-----后序非递归遍历\n");
  PostOrder2(tree);
  cout << endl;
  Graph G = CreateExampleALgraph();
  PrintALgraph(*G);
  cout << "广度优先遍历(BFS):";
  BFS(G);
  printf("%s", "\n深度优先遍历(DFS):");
  DFS(G);
  printf("%s", "\n非递归深度优先遍历:");
  DFS2(G, 0);
  cout << endl;
  return 0;
}
