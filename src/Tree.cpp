#include "inc/func.h"

void visit(BiTree T) { putchar(T->data); }

void PreOrder(BiTree T) {
  if (T != NULL) {
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

void PostOrder2(BiTree T) {
  Stack S;
  InitStack(S);
  BiTree p = T;
  BiTree r = NULL;
  while (p || !EmptyStack(S)) {
    if (p) {
      Push(S, p);
      p = p->lchild;
    } else {
      GetTop(S, p);
      if (p->rchild && p->rchild != r) {
        p = p->rchild;
      } else {
        Pop(S, p);
        visit(p);
        r = p;
        p = NULL;
      }
    }
  }
}

int main() {
  BiTree tree = NULL; // 树根初始化为空
  CreateTree(tree);
  printf("-----层次遍历-----\n"); // 层序遍历
  LevelOrder(tree);
  printf("\n-----前序遍历-----\n"); // 先序遍历
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
  return 0;
}
