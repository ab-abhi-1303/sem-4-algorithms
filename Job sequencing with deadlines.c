#include<stdio.h>
#include<stdlib.h>
struct jobs{
	int j,p,d;//job no,profit,deadline of a job or process
};
struct slots{
	int job_no;
	int flag ;
};

int find_max_deadline(struct jobs job[],int n){
	int i;
	int max = job[0].d;
	for( i=1;i<n;i++){
		if(job[i].d > max){
			max = job[i].d;
		}
	}
	return max;
}

void sort_on_profit(struct jobs job[],int n){
	int i,j;
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			if(job[j].p < job[j+1].p){
				struct jobs temp;
				temp =  job[j];
				job[j] = job[j+1];
				job[j+1] = temp;
			}
		}
	}
}

void display_slot_array(struct slots s[],int total){
	int i;
	for(i=0;i<total;i++){
		printf("%d  %d\n",s[i].job_no,s[i].flag);
	}
}

int main(){
	int i,j,k,n,dl,count;
	int total_slots;
	int profit= 0;
	printf("Enter no of jobs");
	scanf("%d",&n);
	struct jobs job[n];
	for(i=0;i<n;i++){
		printf("Enter job's profit and deadline: ");
		scanf("%d%d",&job[i].p,&job[i].d);
		job[i].j = i+1;//job no
	}
	
	sort_on_profit(job,n);
	
	total_slots = find_max_deadline(job,n);
	
	//printf("Slots are %d ",total_slots);
	struct slots s[total_slots];
	
	for(i=0;i<total_slots;i++){
		s[i].flag = 0;
	}
	count = 0;
	for(i=0;i<n && count<total_slots;i++){
		dl = job[i].d;
		if(dl > total_slots){
			continue;
		}
		else{
			for(j= dl-1;j>=0;j--){
				if(s[j].flag == 0){
					s[j].flag=1;
					s[j].job_no = job[i].j;
					profit += job[i].p;	
					count++;
					break;
				}
			}
		}
	}
	display_slot_array(s,total_slots);
	printf("Profit is %d",profit);
	return 0;	
}