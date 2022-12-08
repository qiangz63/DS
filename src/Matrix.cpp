#include "iostream"
#include <cstdlib>

#define MAX 6
using namespace std;

typedef struct term {
  int col, row, v;
} term;

typedef struct matrix {
  int m = MAX, n = MAX, t;
  term Table[MAX];
} matrix;

void printarr(int arr[][MAX]) {
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      if (arr[i][j] != 0)
        cout << '<' << i << ',' << j << ">:" << arr[i][j] << endl;
}

void printmtx(matrix mtx) {
  for (int i = 0; i < mtx.t; i++)
    cout << '<' << mtx.Table[i].row << ',' << mtx.Table[i].col
         << ">:" << mtx.Table[i].v << endl;
}

void create(int arr[][MAX]) {
  cout << "输入数字（0视为结束）：";
  int v;
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      arr[i][j] = 0;
  srand(time(NULL));
  while (scanf("%d", &v) != EOF) {
    if (v == 0)
      break;
    arr[rand() % MAX][rand() % MAX] = v;
  }
}

void trans(int arr[][MAX], matrix &mtx) {
  int no = 0;
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      if (arr[i][j] != 0) {
        mtx.Table[no].row = i;
        mtx.Table[no].col = j;
        mtx.Table[no].v = arr[i][j];
        no++;
      }
  mtx.t = no;
}

matrix quicktranspose(matrix A) {
  matrix B;
  B.t = A.t;
  int num[MAX] = {0}, k[MAX] = {0};
  for (int i = 0; i < A.t; i++)
    num[A.Table[i].col]++;
  for (int i = 1; i < A.n; i++)
    k[i] = k[i - 1] + num[i - 1];
  // 借助辅助数组k，完成快速转置
  for (int i = 0; i < A.t; i++) {
    int index = k[A.Table[i].col]++;
    B.Table[index].col = A.Table[i].row;
    B.Table[index].row = A.Table[i].col;
    B.Table[index].v = A.Table[i].v;
  }
  return B;
}

int main() {
  int arr[MAX][MAX];
  matrix mtx;
  create(arr);
  printarr(arr);
  trans(arr, mtx);
  cout << "稀疏矩阵转为三元组：" << endl;
  printmtx(mtx);
  cout << "快速转置后为：" << endl;
  mtx = quicktranspose(mtx);
  printmtx(mtx);
  return 0;
}
