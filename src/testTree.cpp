#include "inc/func.h"

void print(int A[], int n) {
  for (int i = 0; i < n; i++)
    cout << A[i] << ' ';
  cout << endl;
}

void visit(BiTNode *p) { putchar(p->data); }

void qsort(int A[], int low, int high) {
  if (low < high) {
    int i = low, j = high, p = A[low];
    while (i < j) {
      while (i < j && A[j] > p)
        j--;
      if (i < j) {
        A[i] = A[j];
        i++;
      }
      while (i < j && p > A[i])
        i++;
      if (i < j) {
        A[j] = A[i];
        j--;
      }
    }
    A[j] = p;
    qsort(A, low, i - 1);
    qsort(A, j + 1, high);
  }
}

void Adjust(int A[], int low, int high) {
  if (low < high) {
    A[0] = A[low];
    int i = low, j = 2 * low;
    while (j <= high) {
      if (j < high && A[j] > A[j + 1])
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

void HeapSort(int A[], int n) {
  int i;
  for (i = n / 2; i > 0; i--)
    Adjust(A, i, n);
  for (i = n; i > 0; i--) {
    cout << A[1] << ' ';
    A[0] = A[1];
    A[1] = A[i];
    A[i] = A[0];
    Adjust(A, 1, i - 1);
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
  EnQueue(Q, T);
  while (!EmptyQueue(Q)) {
    DeQueue(Q, T);
    visit(T);
    if (T->lchild)
      EnQueue(Q, T->lchild);
    if (T->rchild)
      EnQueue(Q, T->rchild);
  }
  cout << endl;
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
  cout << endl;
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
  cout << endl;
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
      GetTop(S, p);                    //!!!
      if (p->rchild && p->rchild != r) //!!!
        p = p->rchild;                 //!!!
      else {
        Pop(S, p);
        visit(p);
        r = p;    //!!!
        p = NULL; //!!!
      }
    }
  }
  cout << endl;
}

int BTDepth(BiTree T) {
  if (!T)
    return 0;
  int ldepth = BTDepth(T->lchild);
  int rdepth = BTDepth(T->rchild);
  if (ldepth > rdepth)
    return ldepth + 1;
  else
    return rdepth + 1;
}

int BTDepth2(BiTree T) {
  BiTree Q[MAXSIZE];
  int front = -1, rear = -1, level = 0, last = 0;
  BiTree p = T;
  Q[++rear] = p;
  while (front != rear) {
    p = Q[++front];
    if (p->lchild)
      Q[++rear] = p = p->lchild;
    if (p->rchild)
      Q[++rear] = p = p->rchild;
    if (front == last) {
      level++;
      last = rear;
    }
  }
  return level;
}

int BTBridth(BiTree T) {
  BiTree Q[MAXSIZE];
  int front = -1, rear = -1, last = 0, cout = 0, max = 0;
  BiTree p = T;
  Q[++rear] = p;
  while (front != rear) {
    p = Q[++front];
    if (p->lchild)
      Q[++rear] = p->lchild;
    if (p->rchild)
      Q[++rear] = p->rchild;
    if (front == last)
      cout = rear - front;
    if (max < cout)
      max = cout;
  }
  return max;
}

int main() {
  int A[] = {88, 34, -9, 34, 0, 23, 14, 29, 68, 46};
  qsort(A, 0, 9);
  print(A, 10);
  int B[] = {88, 34, -9, 34, 0, 23, 14, 29, 68, 46};
  HeapSort(B, 9);
  BiTree T = NULL;
  CreateTree(T);
  printf("-----层次遍历-----\n");
  LevelOrder(T);
  printf("-----先序遍历-----\n");
  PreOrder(T);
  cout << endl;
  PreOrder2(T);
  printf("-----中序遍历-----\n");
  InOrder(T);
  cout << endl;
  InOrder2(T);
  printf("-----后序遍历-----\n");
  PostOrder(T);
  cout << endl;
  PostOrder2(T);
  printf("-------其他--------\n");
  cout << "树高H1=" << BTDepth(T) << endl;
  cout << "树高H2=" << BTDepth2(T) << endl;
  cout << "树宽B=" << BTBridth(T) << endl;
}
