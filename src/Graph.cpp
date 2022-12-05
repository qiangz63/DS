#include "inc/func.h"
#include <cstdio>

void visitm(MGraph M, int v, int e) {
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < e; j++)
      cout << M.edge[i][j] << ' ';
    cout << endl;
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
    for (int j = FirstNeighbor(G, i); j >= 0; j = NextNeighbor(G, i, j))
      if (!visited[j]) {
        cout << G->vertices[j].data;
        visited[j] = 1;
        Q[++front] = j;
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
  cout << endl;
}

void DFSTrav(Graph G, int i, int *visited) {
  ArcNode *p;
  cout << G->vertices[i].data;
  visited[i] = 1;
  p = G->vertices[i].first;
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
  cout << endl;
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
  cout << endl;
}

int main() {
  // MGraph M = CreateMGraph(4, 4);
  // visitm(M, 4, 4);
  Graph G = CreateExampleALgraph();
  PrintALgraph(*G);
  cout << "广度优先遍历(BFS):";
  BFS(G);
  cout << "深度优先遍历(DFS):";
  DFS(G);
  cout << "非递归深度优先遍历:";
  DFS2(G, 0);
  return 0;
}
