#include<stdio.h>
#include<string.h>
void longest_common_subsequence(char x[],char y[],int n,int m){
	int L[n+1][m+1];
    char D[n+1][m+1];
	int ans,i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if(i==0 || j==0){
				L[i][j] = 0;
				D[i][j] = 'n'; //nil
				continue;
			}
			else if( x[i-1] == y[j-1] ){
				L[i][j] = L[i-1][j-1] + 1;
				D[i][j] = 'd';//diagonal
			}
			else if( L[i-1][j] > L[i][j-1] ){//top > left
				L[i][j] = L[i-1][j];
				D[i][j] = 'u'; //up
			}
			else{
				L[i][j] = L[i][j-1];
				D[i][j] = 'l';//left
			}
		}
	}
	ans = L[n][m];
	printf("Length of LCS=%d\n",ans);

	//now display LCS in reverse order:
	printf("LCS is:");
	i = n;
	j = m;
	while(i!=0 && j!=0){
		if( D[i][j] == 'd' ){
			printf("%c",y[j-1]);
			i-=1;
			j-=1;
			continue;
		}
		else if(D[i][j] =='u'){
			i-=1;
			continue;
		}
		else
			j-=1;
		
	}
}
int main(){
	char x[] = "AGGTAB";
char y[] = "GXTXAYB";
int n = strlen(x);
int m = strlen(y);
	longest_common_subsequence(x,y,n,m);
	return 0;
}
