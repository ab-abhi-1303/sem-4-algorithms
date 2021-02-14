#include <stdio.h>

int a[100]={0};
int visited[100]={0};
struct edge{
    int u,v,w;
};

int present(int x[100],int n,int ele){
    int i;
    for(i=0;i<n;i++){
        if(ele == x[i])
            return 1;
    }
    return 0;
}

int main()
{
    int no,i,j,k2,flag,cost = 0;
    struct edge e[100],temp;
    printf("Enter no of edges ");
    scanf("%d",&no);
    
    for(i=0;i<no;i++){
        printf("Enter Starting Vertex,Ending Vertex and Weight of edge ");
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    for(i=1;i<no;i++){//sorting on ascending weights
        for(j=0;j<no-i;j++){
            if(e[j].w > e[j+1].w){
                temp = e[j];
                e[j] = e[j+1];
                e[j+1] = temp;
            }
        }
    }//sort done
    
    for(i=0;i<no;i++){
        printf(" %d",e[i].w);
    }//sort hora h ki nahi(for checking)
   
    k2 = 0;
    for(i=0;i<no;i++){
        flag = 0;
        if(!present(visited,k2,e[i].u)){
            visited[k2++] = e[i].u;
            flag = 1;
        }
        if(!present(visited,k2,e[i].v)){
            visited[k2++] = e[i].v;
            flag = 1;
        }
        if(flag == 1) cost+=e[i].w;
        
    }
    
    printf("\nCost is %d",cost);
    return 0;
}
