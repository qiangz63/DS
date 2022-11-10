#include "inc/func.h"

void CreateGraph(MGraph &M) {
  int x;
  M.vexnum = 5;
  M.arcnum = 5;
  for (int i = 0; i < M.arcnum; i++)
    for (int j = 0; j < M.arcnum; j++) {
      cin >> x;
      M.edge[i][j] = x;
    }
}

int main() {
  MGraph M;
  CreateGraph(M);
  return 0;
}
