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
  int i, j;
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
        j = p->adjvex;
        if (!visited[j]) {
          visited[j] = 1;
          printf("%c", G->vertices[j].data);
          Q[rear++] = j;
        }
        p = p->next;
      }
    }
  }
  cout << endl;
}

void DFS(Graph G) {}

void DFS2(Graph G) {}

int main() {
  // MGraph M = CreateMGraph(4, 4);
  // visitm(M, 4, 4);
  Graph G = CreateExampleALgraph();
  BFS(G);
  DFS(G);
  DFS2(G);
  return 0;
}
