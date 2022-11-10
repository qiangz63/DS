#include <iostream>

using namespace std;

void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}

void qsort(int q[], int low, int high) {
  if (low < high) {
    int i = low, j = high, pivot = q[low];
    while (i < j) {
      while (i < j && q[j] >= pivot)
        j--;
      if (i < j) {
        q[i] = q[j];
        i++;
      }
      while (i < j && q[i] < pivot)
        i++;
      if (i < j) {
        q[j] = q[i];
        j--;
      }
      q[i] = pivot;
      qsort(q, low, i - 1);
      qsort(q, j + 1, high);
    }
  }
}

int main() {
  int m[] = {23, 45, 12, 87, 67, -3, -99, 0, 23, 34};
  qsort(m, 0, 9);
  for (int i = 0; i < 10; i++)
    cout << m[i] << ' ';
  return 0;
}
