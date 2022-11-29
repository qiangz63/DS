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

int main() {
  int A[10] = {99, -3, -29, 23, 34, 91, 0, 8, 34, 84};
  qsort(A, 0, 9);
  print(A, 10);
  int B[10] = {99, -3, -29, 23, 34, 91, 0, 8, 34, 84};
  heapsort(B, 9);
  return 0;
}
