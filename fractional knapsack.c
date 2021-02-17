#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct{
    int p,w;
    float p_by_w;
    float x;
    int id;
}items;

int main(){
        int i,n,m,j,k;
        float cw=0;
        float cp = 0;
        printf("Enter the no of items");
        scanf("%d",&n);
        printf("Enter the sack capacity");
        scanf("%d",&m);
        
        items item[100],temp;
        for(i=0;i<n;i++){
            printf("enter profit,weight");
            scanf("%d%d", &item[i].p,&item[i].w);
            item[i].p_by_w = item[i].p*1.0/item[i].w ;
            item[i].id = i;
        }
        //sorting on p/w ratio
        for(i=1;i<n;i++){
            for(j=0;j<n-i;j++){
                if( item[j].p_by_w < item[j+1].p_by_w ){
                    temp = item[j];
                    item[j] = item[j+1];
                    item[j+1] = temp;
                }
            }      
         }
         for(i=0;i<n;i++){
            if( (cw + item[i].w) < m){
                cp = cp + item[i].p;
                cw = cw + item[i].w;
                item[i].x = 1;
            }
            else{
                item[i].x = (m - cw)*1.0/item[i].w ;
                cp = cp +(item[i].p)*item[i].x;
                cw = m;
                break;
            }
         }
        //now sort by item id to display
        for(i=1;i<n;i++){
            for(j=0;j<n-i;j++){
                if( item[j].id > item[j+1].id ){
                    temp = item[j];
                    item[j] = item[j+1];
                    item[j+1] = temp;
                }
            }      
         }
         printf("ID\tP\tW\tProfit/Weight\tX[i]\n");
         for(i=0;i<n;i++)
         printf("%d\t%d\t%d\t%f\t%f\n",item[i].id,item[i].p,item[i].w,item[i].p_by_w,item[i].x);
         printf("Profit=%f Weight=%f",cp,cw);
return 0;
}
