#include<stdio.h>
int min(int a,int b){
	return (a<b)?a:b ;
}

void copy(int c[50][50],int a[50][50],int n){
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a[i][j] = c[i][j];
		}
	}
}

void accept(int c[50][50],int D[50][50],int n){
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	//generating D0
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(c[i][j] == 0 || c[i][j] == 999)
				D[i][j] = -1;
			else
			    D[i][j] = i+1;
		}
	}//D0 generated
}

void all_pairs_shortest_path(int A[50][50],int D[50][50],int n){
	int i,j,k;
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if ( A[i][j] > (A[i][k]+A[k][j]) )
					D[i][j] = k+1;
				A[i][j] = min( A[i][j] , (A[i][k]+A[k][j]) ) ;
			}
		}
	}
}

void path(int v1,int v2,int D[50][50],int n){
	if( v1 == D[v1-1][v2-1])
		return;
	printf("%d-",D[v1-1][v2-1]);
	path(D[v1-1][v2-1],v2,D,n);				
}

void find_path(int A[50][50],int D[50][50],int n){
	int v1,v2,ch;
	while(1){
		printf("\n1:Continue 2:Break\n");
		scanf("%d",&ch);
		if(ch == 2) break;
		
		printf("Enter 2 vertices to find path");
		scanf("%d%d",&v1,&v2);
		printf("Length=%d\n",A[v1-1][v2-1]);
		printf("Path:%d-",v1);
		path(v1,v2,D,n);
		printf("%d\n",v2);
	}
}

void display(int mat[50][50],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int cost[50][50],D[50][50],A[50][50];
	int i,j,k,n;
	printf("Enter no of vertices ");
	scanf("%d",&n);
	printf("Enter cost adjacency matrix:\n");
	accept(cost,D,n);
	copy(cost,A,n);
	all_pairs_shortest_path(A,D,n);
	printf("A^n Matrix is:\n");
	display(A,n);
	printf("D^n Matrix is:\n");
	display(D,n);
	find_path(A,D,n);
	return 0;
}
