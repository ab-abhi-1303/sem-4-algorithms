//for 2 stations only
#include<stdio.h>
int min(int x,int y){
	return (x<y)?x:y;
}

int min_cost(int a[][4],int t[][4],int n,int e[],int x[]){
	int i,T1[n],T2[n];
	T1[0] = e[0] + a[0][0];
	T2[0] = e[1] + a[1][0];
	
	for(i=1;i<n;i++){
		
		T1[i] = min( T1[i-1]+a[0][i],T2[i-1]+t[1][i]+a[0][i] );
		T2[i] = min( T2[i-1]+a[1][i],T1[i-1]+t[0][i]+a[1][i]);
		
	}
	
	return min( T1[n-1]+x[0] , T2[n-1]+x[1] );
	
	
}

int main(){
	int n = 4;
	int a[][4] = {  {4,5,3,2},
			    {2,10,1,4}	 };
	int t[][4] = {  {0,7,4,5},
			    {0,9,2,8}	 };
	int e[] = {10,12},x[] = {18,7};
	printf("Min cost=%d",min_cost(a,t,n,e,x));
	return 0;
}
