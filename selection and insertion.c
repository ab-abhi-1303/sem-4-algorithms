#include <stdio.h>//Abhishek Sharma 18102A0002

#include <stdlib.h>//selection and insertion

#include <math.h>

#include <time.h>

void swap(int * xp, int * yp) {
  int temp = * xp;
  * xp = * yp;
  * yp = temp;
}
void insertionSort(int arr[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}
void selectionSort(int arr[], int n) {
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;
    swap( & arr[min_idx], & arr[i]);
  }
}
void rev_sort(int number[], int n) {
  int i, j, a;
  for (i = 0; i < n; ++i) {
    for (j = i + 1; j < n; ++j) {
      if (number[i] < number[j]) {
        a = number[i];
        number[i] = number[j];
        number[j] = a;
      }
    }
  }
}
int main() {
  int a[25000], n, i, choice, ch;
  float total;
  FILE * fp1, * fp2;
  printf("Enter no of elements: ");
  scanf("%d", & n);
  fp1 = fopen("data1.txt", "w");
  for (i = 0; i < n; i++) {
    fprintf(fp1, "%d ", ((rand() % 25000) + 1));
  }
  fclose(fp1);
  fp1 = fopen("data1.txt", "r");
  fp2 = fopen("data2.txt", "w");
  for (i = 0; i < n; i++) {
    fscanf(fp1, "%d ", & a[i]);
  }
  printf("\nEnter option\n1: Worst Case Complexity\n2: Best Case Complexity :");
  scanf("%d", & choice);
  fflush(stdin);
  if (choice == 1) {
    printf("1:Selection 2:Insertion ");
    scanf("%d", & ch);
    if (ch == 1) {
      clock_t t;
      selectionSort(a, n);
      t = clock() - t;
      for (i = 0; i < n; i++) {
        fprintf(fp2, "%d ", a[i]);
      }
      printf("time = %f", ((float) t) / CLOCKS_PER_SEC);
    }
    if (ch == 2) {
      rev_sort(a, n);
      clock_t t;
      insertionSort(a, n);
      t = clock() - t;
      for (i = 0; i < n; i++) {
        fprintf(fp2, "%d ", a[i]);
      }
      printf("time = %f", ((float) t) / CLOCKS_PER_SEC);
    }
  } else if (choice == 2) {
    printf("1:Selection 2:Insertion ");
    scanf("%d", & ch);
    if (ch == 1) {
      clock_t t;
      selectionSort(a, n);
      t = clock() - t;
      for (i = 0; i < n; i++) {
        fprintf(fp2, "%d ", a[i]);
      }
      printf("time = %f", ((float) t) / CLOCKS_PER_SEC);
    }
    if (ch == 2) {
      selectionsort(a, 0, n - 1);
      clock_t t;
      insertionSort(a, n);
      t = clock() - t;
      for (i = 0; i < n; i++) {
        fprintf(fp2, "%d ", a[i]);
      }
      printf("time = %f", ((float) t) / CLOCKS_PER_SEC);
    }
  }
  return 0;
}