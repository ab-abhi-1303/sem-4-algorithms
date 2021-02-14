#include<stdio.h>

#include<stdlib.h>

#include<time.h>

long long int visited[25000] = {
  0
};
long long int mat[10000][10000];
struct edge {
  long long int u, v, w;
};
long long int present(long long int x[25000], long long int n, long long int ele) {
  long long int i;
  for (i = 0; i < n; i++) {
    if (ele == x[i])
      return 1;
  }
  return 0;
}
int main() {
  long long int n, i, j, k2, flag, cost = 0, k;
  FILE * f;
  clock_t start, end;
  struct edge e[10000], temp;
  printf("Enter no of nodes ");
  scanf("%lld", & n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      k = rand() % 25;
      mat[i][j] = k;
    }
  }
  for (i = 0; i < n; i++)
    mat[i][i] = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < i; j++) mat[i][j] = mat[j][i];
  }
  f = fopen("numbers.txt", "w");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      fprintf(f, "%lld\t", mat[i][j]);
    }
    fprintf(f, "\n");
  }
  fclose(f);
  k = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < i; j++) {
      if (mat[i][j] != 0) {
        e[k].u = i;
        e[k].v = j;
        e[k].w = mat[i][j];
        k++;
      }
    }
  start = clock();
  for (i = 1; i < k; i++) { //sorting on ascending weights
    for (j = 0; j < k - i; j++) {
      if (e[j].w > e[j + 1].w) {
        temp = e[j];
        e[j] = e[j + 1];
        e[j + 1] = temp;
      }
    }
  } //sort done
  k2 = 0;
  for (i = 0; i < k; i++) {
    flag = 0;
    if (!present(visited, k2, e[i].u)) {
      visited[k2++] = e[i].u;
      flag = 1;
    }
    if (!present(visited, k2, e[i].v)) {
      visited[k2++] = e[i].v;
      flag = 1;
    }
    if (flag == 1) cost += e[i].w;
  }
  end = clock();
  printf("no of edges is %d", k);
  printf("\nCost is %lld", cost);
  printf("\nTime is %f ", ((double)(end - start)) / CLOCKS_PER_SEC);
  return 0;
}