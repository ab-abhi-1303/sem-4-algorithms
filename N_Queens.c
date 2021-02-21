#include<stdio.h>
#define n 4
char mat[n][n];
int marked_column(int row){
	int i;
	for(i=0;i<n;i++){
		if(mat[row][i] == 'Q')
			return i;
	}
}
int safe(int row,int col){
	int i,j,mark;
	//we need to get the marked col for that row and check if can be placed or not
	for(i=0;i<n;i++){
		mark = marked_column(i);
		if( mark==col || abs(row-i)==abs(col-mark) )
			return 0;
	}
	return 1;
}
void nqueens(int k){//k=current queen or row
	int i,j;
	if(k<n){
		for(i=0;i<n;i++){
			if( safe(k,i) ){
				mat[k][i] = 'Q';
				nqueens(k+1);
				mat[k][i] = '.';
			}
		}
	}
	else{
		printf("\nSolution:\n");
		print_mat();
	}
}
void print_mat(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%c\t",mat[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			mat[i][j] = '.';
	nqueens(0);
	return 0;
}
