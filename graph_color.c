#include<stdio.h>
int x[50],g[50][50],n,i,j,m;
void next_value(int k)
{
    while(1){ //true
        x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
			return;
		for(j=0;j<n;j++)
		{
			if( (g[k][j]==1) && (x[k]==x[j]))//edge ho and same colorhua toh break;
				break;
		}
		if(j==n)
			return;
	}
}
void coloring(int k){
    do
	{
		next_value(k);
		if(x[k]==0)
			return;
		if(k==n)
		{
			for(i=0;i<n;i++)
                printf("vertex %d = color No. %d\t",i+1,x[i]);
			printf("\n");
		}
		else
			coloring(k+1);
	}while(k<n);
}
int main()
{
	int e,k,l;
	printf("Enter no. of vertices : ");
	scanf("%d",&n);	
	printf("Enter no. of edges : ");
	scanf("%d",&e);
	m=n-1;
	printf("\nThe maximum possible colours that can be assigned are: %d\n",m);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			g[i][j]=0;
	printf("Enter u and v of an edge\n");
	for(i=1;i<=e;i++)
	{
		printf("\nfor egde %d\n",i);
		scanf("%d%d",&k,&l);
		g[k][l]=1;
		g[l][k]=1;
	}
	for(i=0;i<n;i++)
        x[i]=0;
	printf("\nThe colouring possibilities are:\n");
    coloring(0);
	return 0;
}

