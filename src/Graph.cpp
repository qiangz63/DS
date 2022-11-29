#include "inc/func.h"
#include <cstdio>

void visitm(MGraph M, int v, int e) {
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < e; j++)
      cout << M.edge[i][j] << ' ';
    cout << endl;
  }
}

void BFS(Graph G) {
  cout << "广度优先遍历(BFS):";
  int i, j, k;
  int visited[MaxVexNum];
  for (i = 0; i < G->vexnum; i++)
    visited[i] = 0;
  int Q[MAXSIZE];
  int front = -1, rear = -1;
  ArcNode *p;
  for (i = 0; i < G->vexnum; i++) {
    if (!visited[i]) {
      visited[i] = 1;
      printf("%c", G->vertices[i].data);
      Q[rear++] = i;
    }
    while (front != rear) {
      j = Q[front++];
      p = G->vertices[j].first;
      while (p) {
        k = p->adjvex;
        if (!visited[k]) {
          visited[k] = 1;
          printf("%c", G->vertices[k].data);
          Q[rear++] = k;
        }
        p = p->next;
      }
    }
  }
  cout << endl;
}

void DFSTrav(Graph G, int i, int *visited) {
  ArcNode *p;
  visited[i] = 1;
  cout << G->vertices[i].data;
  p = G->vertices[i].first; // 拿当前顶点的后面一个顶点
  while (p) {
    if (!visited[p->adjvex]) // 只要对应顶点没有访问过，深入到下一个顶点访问
      DFSTrav(G, p->adjvex, visited);
    p = p->next; // 某个顶点的下一条边，例如B结点的下一条边
  }
}

void DFS(Graph G) {
  cout << "深度优先遍历(DFS):";
  int i, visited[MaxVexNum];
  for (i = 0; i < G->vexnum; i++)
    visited[i] = 0;
  for (i = 0; i < G->vexnum; i++)
    if (!visited[i])
      DFSTrav(G, i, visited);
  cout << endl;
}

void DFS2(Graph G) { cout << "非递归深度优先遍历:"; }

int main() {
  // MGraph M = CreateMGraph(4, 4);
  // visitm(M, 4, 4);
  Graph G = CreateExampleALgraph();
  PrintALgraph(*G);
  BFS(G);
  DFS(G);
  DFS2(G);
  return 0;
}
