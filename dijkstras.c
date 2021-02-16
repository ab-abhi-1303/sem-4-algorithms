#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#define MAX 1000

int d[MAX], Pre[MAX] = {
  0
}, n, Weight_Mat[MAX][MAX], Q[MAX], count = 0;

void findpath(int i) {
  if (Pre[i] == 0) {
    printf(" %d ", 1);
    return;
  }
  printf(" %d ", Pre[i] + 1);
  findpath(Pre[i]);

}

int EXTRACT_MIN(int Q[]) {
  int i, min_pos;

  min_pos = Q[0];
  for (i = 1; i < count; i++) {
    if (d[Q[i]] < d[min_pos])
      min_pos = Q[i];
  }

  return min_pos;
}

int belongs(int v) {
  int i;

  for (i = 0; i < count; i++) {
    if (v == Q[i])
      return 1;
  }

  return 0;
}

void remove_from_Q(int u) {
  int i, j;
  for (i = 0; i < count; i++) {
    if (u == Q[i]) {
      for (j = i; j < count; j++) {
        Q[j] = Q[j + 1];
      }
      count--;
      break;
    }
  }
}

int is_adj(int u, int v) {
  if (Weight_Mat[u][v] > 0)
    return 1;

  return 0;
}

void dijkstras() {
  int i, v, u;

  for (i = 0; i < n; i++) {
    d[i] = 999;
    Q[i] = i;
    count++;
  }

  d[0] = 0;
  Pre[0] = -2;
  while (count != 0) {
    u = EXTRACT_MIN(Q);
    for (v = 0; v < n; v++) {
      if ((is_adj(u, v)) && (belongs(v))) {
        if ((d[u] + Weight_Mat[u][v]) < d[v]) {
          d[v] = d[u] + Weight_Mat[u][v];
          Pre[v] = u;
        }
      }
    }
    remove_from_Q(u);
  }
}

void print() {
  long long int total_cost = 0;
  int i, j;

  for (i = 0; i < n; i++) {
    if (Pre[i] >= 0)
      total_cost = total_cost + d[i];
  }

  printf("\nTotal Cost : %lld", total_cost);
}

void print_matrix() {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d\t", Weight_Mat[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int i, j;
  clock_t t;
  float time_taken;

  printf("\nEnter no. of vertices : ");
  scanf("%d", & n);

  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      Weight_Mat[i][j] = Weight_Mat[j][i] = (rand() % 99) + 1;
    }

    Weight_Mat[i][i] = 0;
  }

  t = clock();
  dijkstras();
  t = clock() - t;
  time_taken = (float) t / CLOCKS_PER_SEC;

  print_matrix();
  print();
  printf("\n");
  for (i = 1; i < n; i++) { //i=0 not included as 0 is starting index
    printf("Path for %d is", d[i]);
    printf(" %d ", i + 1);
    findpath(i);
    printf("\n");
  }

  printf("\nThe time required for %d vertices is %f secs.", n, time_taken);

  return 0;
}