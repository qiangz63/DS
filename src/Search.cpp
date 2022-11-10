#include "iostream"

using namespace std;

int BinarySearch(int A[], int len, int key) {
  int mid, low = 0, high = len - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (A[mid] == key)
      return mid + 1;
    else if (A[mid] > key)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

int main() {
  int M[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int key = 100;
  int index = BinarySearch(M, 10, key);
  cout << key << "的位序为" << index << endl;
  return 0;
}
