#include <iostream>
#include <stdio.h>

using namespace std;

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void BubbleSort(int A[], int n) {
  int flag;
  for (int i = 0; i < n; i++) {
    flag = 0;
    for (int j = 1; j < n - i; j++)
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        flag = 1;
      }
    if (flag == 0)
      return;
  }
}

void SelectSort(int A[], int n) {
  for (int i = 0; i < n; i++) {
    int min = i, tmp = A[i];
    for (int j = i + 1; j < n; j++)
      if (A[min] > A[j])
        min = j;
    swap(A[i], A[min]);
  }
}

void InsertSort(int A[], int n) {
  int j, tmp;
  for (int i = 1; i < n; i++) {
    tmp = A[i];
    j = i;
    while (j >= 1 && tmp < A[j - 1]) {
      A[j] = A[j - 1];
      j--;
    }
    A[j] = tmp;
  }
}

void QuickSort(int A[], int low, int high) {
  int i = low, j = high, pivot;
  if (low < high) {
    pivot = A[low];
    while (i < j) {
      while (i < j && pivot <= A[j])
        j--;
      if (i < j) {
        A[i] = A[j];
        i++;
      }
      while (i < j && pivot > A[i])
        i++;
      if (i < j) {
        A[j] = A[i];
        j--;
      }
    }
    A[i] = pivot; // i=j
    QuickSort(A, low, i - 1);
    QuickSort(A, j + 1, high);
  }
}

void Adjust(int A[], int low, int high) {
  if (low < high) {
    A[0] = A[low];
    int i = low, j = 2 * i;
    while (j <= high) {
      if (j < high && A[j] < A[j + 1])
        j++;
      if (A[0] < A[j]) {
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
  printf("堆排：");
  for (i = n; i > 0; i--) {
    cout << A[1] << ' ';
    swap(A[1], A[i]);
    Adjust(A, 1, i - 1);
  }
  cout << endl;
}

void Merge(int A[], int low, int mid, int high) {
  int i, j, k, B[10];
  for (i = low; i < high; i++)
    B[i] = A[i];
  for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
    if (B[i] < B[j])
      A[k] = B[i++];
    else
      A[k] = B[j++];
  }
  while (i <= mid)
    A[k++] = B[i++];
  while (j <= high)
    A[k++] = B[j++];
}

void MergeSort(int A[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    MergeSort(A, low, mid);
    MergeSort(A, mid, high);
    Merge(A, low, mid, high);
  }
}

void print(int A[], int n) {
  for (int i = 0; i < n; i++) {
    cout << A[i] << ' ';
  }
  cout << endl;
}

int main() {
  int A[] = {-1, 65, 23, 45, 89, 12, 6, 9, 23, 55};
  print(A, 10);
  // BubbleSort(A, 10);
  // SelectSort(A,10);
  // InsertSort(A, 10);
  // QuickSort(A,0,9);
  // HeapSort(A,9);
  MergeSort(A, 0, 9);
  print(A, 10);
  return 0;
}
