//Name: Abhishek Sharma SE CMPN-A Batch 1
//Roll-18102A0002
//Divide And Conquer And Linear Approach Time Compare
#include<stdio.h>		//Program
#include<stdlib.h>
#include<time.h>
void linear (long long int arr[], long long int n, long long int *max,
	long long int *min)
{
  long long int i;
  *max = arr[0];
  for (i = 1; i < n; i++)
    if (arr[i] > *max)
      *max = arr[i];
  *min = arr[0];
  for (i = 1; i < n; i++)
    if (arr[i] < *min)
      *min = arr[i];
}

void minmax (long long int x[], long long int i, long long int j,
	long long int *fmin, long long int *fmax)
{
  long long int gmin, gmax, hmin, hmax, m;
  if (i == j)
    *fmin = *fmax = x[i];
  else if (i == j - 1)
    {
      if (x[i] < x[j])
	{
	  *fmin = x[i];
	  *fmax = x[j];
	}
      else
	{
	  *fmin = x[j];
	  *fmax = x[i];
	}
    }
  else
    {
      m = (i + j) / 2;
      minmax (x, i, m, &gmin, &gmax);
      minmax (x, m + 1, j, &hmin, &hmax);
      *fmin = gmin < hmin ? gmin : hmin;
      *fmax = gmax > hmax ? gmax : hmax;
    }
}

int
main ()
{
  FILE *f;
  clock_t start1, end1, start2, end2;
  float time_taken1, time_taken2;
  long long int i1, n;
  printf ("Enter no of elements ");
  scanf ("%lld", &n);
  f = fopen ("numbers.txt", "w");
  for (i1 = 0; i1 < n; i1++)
    {
      fprintf (f, "%lld ", rand () % 500 + 5);
    }
  fclose (f);
  long long int i, a[n], *fmin, *fmax, *max, *min;
  f = fopen ("numbers.txt", "r");
  for (i = 0; i <= n; i++)
    fscanf (f, "%lld ", &a[i]);
  fclose (f);
  start1 = clock ();
  minmax (a, 0, n - 1, &fmin, &fmax);
  end1 = clock ();
  time_taken1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
  printf ("Time for Divide Conquer=%f\n", time_taken1);
  printf ("max = %lld\n", fmax);
  printf ("min %lld\n", fmin);
  start2 = clock ();
  linear (a, n, &max, &min);
  end2 = clock ();
  time_taken2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
  printf ("Time for Linear=%f\n", time_taken2);
  printf ("max = %lld\n", max);
  printf ("min %lld", min);
  return 0;
}				//Program Ends
