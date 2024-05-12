#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int jobsequence(int salary[],int time[],int n){
   int profit_arr[n];
   for(int i=0;i<n;i++) profit_arr[i]=0;

   for(int i=0;i<n;i++){
    int pos=time[i]-1;
    if(profit_arr[pos]==0) profit_arr[pos]=salary[i];
    else{
        for(int j=pos;j>=0;j--){
            if(profit_arr[j]==0 || profit_arr[j]<salary[i]){ profit_arr[j]=salary[i];
            break;
            }
        }
    }
   }
   int totalprofit=0;
   printf("Profit Array  \n");
   for(int i=0;i<n;i++){
    printf("%d ",profit_arr[i]);
    totalprofit+=profit_arr[i];
   }

   return totalprofit;
}

int main(){
  int n;
  printf("Enter the total job number : ");
  scanf("%d",&n);
  int salary[n];
  int time[n];
  printf("Enter the salaries : ");
  for(int i=0;i<n;i++){
    scanf("%d",&salary[i]);
  }
  printf("Enter the time : ");
  for(int i=0;i<n;i++){
    scanf("%d",&time[i]);
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(salary[i]<salary[j]){
            swap(&salary[i],&salary[j]);
            swap(&time[i],&time[j]);
        }
    }
  }
  int profit=jobsequence(salary,time,n);
  printf("\nThe total Profit is : %d",profit);
return 0;
}
