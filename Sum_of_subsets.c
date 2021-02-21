#include<stdio.h>
int x[4] = {0};
int n = 4;
int arr[] = {4,5,8,9};
int M = 9;//target value

void display(int arr[]){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
}

void sum_of_subsets(int curr,int k,int rem){
	
	x[k] = 1;
	if( curr + arr[k] == M ){
		display(x);
		printf("\n");
	}	
	
	else if(curr + arr[k] + arr[k+1] <= M){
		sum_of_subsets(curr + arr[k] , k+1 , rem - arr[k]);
	}
	
	if( (curr + rem - arr[k]) >= M  && (curr + arr[k+1]) <=M ){
		x[k] = 0;
		sum_of_subsets(curr, k+1 , rem-arr[k]);
	}
	
}

int main(){
		int i,sum=0;
	for(i=0;i<n;i++){
		sum = sum + arr[i];
	}
	sum_of_subsets(0,0,sum);
	
	return 0;
	
}
