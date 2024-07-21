#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      return i; // Element found at index i
    }
  }
  return -1; // Element not found
}

int main() {
  int arr[] = {10, 20, 30, 40, 50};
  int n = sizeof(arr) / sizeof(arr[0]); // Get array size
  int target = 30;

  int index = linearSearch(arr, n, target);

  if (index != -1) {
    printf("Element found at index %d\n", index);
  } else {
    printf("Element not found in array\n");
  }

  return 0;
}
