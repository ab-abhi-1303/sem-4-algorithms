#include<stdio.h>
int max(int x,int y){
	return (x>y)?x:y;
}
void knapSack_DP(int M, int wt[],int profit[], int n){
    int i,j,ans,res,DP[n+1][M+1],k;
	int select[n];
        for( i=0; i <= n; i++){
            for(j=0; j <= M; j++){
                if(i == 0 || j == 0){
                    DP[i][j] = 0;
                    continue;
                }
                if(j - wt[i-1] >= 0){   //lele usko, ab ya to usko leke remaining se max nikal ya fir usko chod k max nikal
                    DP[i][j] = max(DP[i-1][j], DP[i-1][j-wt[i-1]] + profit[i-1]);
                }else{//usko skip hi krna padega kyunki weight zyada h
                    DP[i][j] = DP[i-1][j];
                }
            }
        }
        ans = DP[n][M];
        //ab kis kis item ko select kia vo btana h
        j = M;
        k = n-1;
        res = ans;
		for(i=n;i>0;i--){
        	if(DP[i][j] == DP[i-1][j]){
        		select[k--] = 0;
        	}
        		
        	else{
        		select[k--] = 1;
        		j = j - wt[i-1];
			}
		}
		printf("\nMaximum profit is %d\n",ans);
		printf("Selected items array:\t");
		for(i=0;i<n;i++)
			printf("%d ",select[i]);
}
int main()
{
    int i, n, profit[20], wt[20], M;
    printf("Enter number of items:");
    scanf("%d", &n);
    printf("Enter profit and weight of items:\n");
    for(i = 0;i < n; ++i){
    	scanf("%d%d", &profit[i], &wt[i]);
    }
    printf("Enter size of knapsack:");
    scanf("%d", &M);
    knapSack_DP(M, wt, profit, n);
    return 0;
}
