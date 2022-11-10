#include "inc/func.h"

void visitm(MGraph M, int v, int e) {
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < e; j++)
      cout << M.edge[i][j] << ' ';
    cout << endl;
  }
}

void visit(ArcNode *x) { cout << x << ' '; }

void BFS(Graph G, int v, int visited[]) {
  for (int i = 0; i < G->vexnum; i++)
    visited[i] = 0;
  int Q[MAXSIZE];
  int front = -1, rear = -1;
  cout << v << " ";
  visited[v] = 1;
  Q[++rear] = v;
  while (front != rear) {
    int v = Q[++front];
    ArcNode *p = G->vertices[v].first;
    while (p != NULL) {
      if (visited[p->adjvex] == 0) {
        cout << p->adjvex << ' ';
        visited[p->adjvex] = 1;
        Q[++rear] = p->adjvex;
      }
      p = p->next;
    }
  }
  cout << endl;
}

void DFS() {}

int main() {
  // MGraph M = CreateMGraph(4, 4);
  // visitm(M, 4, 4);
  Graph G = CreateALGraph(4, 4);
  int visited[MAXSIZE];
  BFS(G, 1, visited);
  return 0;
}
