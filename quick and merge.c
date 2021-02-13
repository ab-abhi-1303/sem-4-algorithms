#include <stdio.h>//Abhishek Sharma 18102A0002

#include <stdlib.h>//Quick and Merge

#include <math.h>

#include <time.h>

void swap(int * xp, int * yp) {
  int temp = * xp;
  * xp = * yp;
  * yp = temp;
}
int partition(int a[], int low, int high) {
  int x, i, j, t;
  x = a[low];
  i = low;
  j = high;
  while (i <= j) {
    while (a[i] <= x) //i is looking for greater value than x
      i++;
    while (a[j] > x) //j is looking for <= value than x
      j--;
    if (i < j) {
      t = a[i];
      a[i] = a[j];
      a[j] = t;
    }
  }
  t = a[low];
  a[low] = a[j];
  a[j] = t;
  return j;
}
void quicksort(int a[], int low, int high) {
  int pos;
  if (low < high) {
    pos = partition(a, low, high);
    quicksort(a, low, pos - 1);
    quicksort(a, pos + 1, high);
  }
}
int simple_merge(int x[], int lb, int m, int ub) {
    int i = lb, j = m + 1, k = 0, temp[25000];
    while (i <= m && j <= ub) {
      if (x[i] < x[j])
        temp[k++] = x[i++];
      else
        temp[k++] = x[j++];
    }
    while (i <= m)
      temp[k++] = x[i++];
    while (j < ub)
      temp[k++] = x[j++];
    k = 0;
    while (lb < ub {
        x[lb++] = temp[k++];
      }
    }
    void mergesort(int x[], int lb, int ub) {
      int m;
      if (lb < ub) {
        m = (lb + ub) / 2;
        mergesort(x, lb, m);
        mergesort(x, m + 1, ub);
        simple_merge(x, lb, m, ub);
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
        printf(" 3:Merge 4:quick");
        scanf("%d", & ch);
        if (ch == 3) {
          clock_t t;
          mergesort(a, 0, n - 1);
          t = clock() - t;
          for (i = 0; i < n; i++) {
            fprintf(fp2, "%d ", a[i]);
          }
          printf("time = %f", ((float) t) / CLOCKS_PER_SEC);
        }
        if (ch == 4) {
          mergesort(a, 0, n - 1);
          clock_t t;
          quicksort(a, 0, n - 1);
          t = clock() - t;
          for (i = 0; i < n; i++) {
            fprintf(fp2, "%d ", a[i]);
          }
          printf("time = %f", ((float) t) / CLOCKS_PER_SEC);
        }
      } else if (choice == 2) {
        printf(" 3:Merge 4:quick");
        scanf("%d", & ch);
        if (ch == 3) {
          clock_t t;
          mergesort(a, 0, n - 1);
          t = clock() - t;
          for (i = 0; i < n; i++) {
            fprintf(fp2, "%d ", a[i]);
          }
          printf("time = %f", ((float) t) / CLOCKS_PER_SEC);
        }
        if (ch == 4) {
          //when pivot ele is at middle
          clock_t t;
          quicksort(a, 0, n - 1);
          t = clock() - t;
          for (i = 0; i < n; i++) {
            fprintf(fp2, "%d ", a[i]);
          }
          printf("time = %f", ((float) t) / CLOCKS_PER_SEC);
        }
      }
      return 0;
    }