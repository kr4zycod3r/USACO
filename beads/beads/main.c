/*
 ID: piyushg2
 LANG: C
 TASK: beads
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int crossmax(char *a,int low,int mid,int high)
{
    int i=mid,sum=0,sum1=0,sum2=0,low1=0,high1=0,low2=0,high2=0;
    char check,check1;
    
    //at least one is not w
    if((*(a+mid)!='w')||(*(a+mid+1)!='w'))
    {
        if(*(a+mid)!='w')
            check=*(a+mid);
        else
            check=*(a+mid+1);
        while(((*(a+i)==check)||(*(a+i)=='w'))&&(i>=low))
        {
            sum+=1;
            i--;
        }
        low1=i+1;
        i=mid+1;
        while(((*(a+i)==check)||(*(a+i)=='w'))&&(i<=high))
        {
            sum+=1;
            i++;
        }
        high1=i-1;
        
    }
    //both are w
    else
    {
        i=mid;
        while(*(a+i)=='w')
            i--;
        check=*(a+i);
        i=mid;
        sum=0;
        while(((*(a+i)==check)||(*(a+i)=='w'))&&(i>=low))
        {
            sum+=1;
            i--;
        }
        low1=i+1;
        i=mid+1;
        while(((*(a+i)==check)||(*(a+i)=='w'))&&(i<=high))
        {
            sum+=1;
            i++;
        }
        high1=i-1;
        i=mid+1;
        while(*(a+i)=='w')
            i++;
        check1=*(a+i);
        i=mid;
        while(((*(a+i)==check1)||(*(a+i)=='w'))&&(i>=low))
        {
            sum1+=1;
            i--;
        }
        low2=i+1;
        i=mid+1;
        while(((*(a+i)==check1)||(*(a+i)=='w'))&&(i<=high))
        {
            sum1+=1;
            i++;
        }
        high2=i+1;
        
        low1=sum>sum1?low1:low2;
        high1=sum>sum1?high1:high2;
        check=sum>sum1?check:check1;
        sum=sum>sum1?sum:sum1;
        //debug print
        //printf("\nlow1=%d high1=%d",low1,high1);
    }
    //2nd string
    i=low1-1;
    sum1=0;
    while((*(a+i)!=check)&&(i>=low))
    {
        sum1+=1;
        i-=1;
    }
    i=high+1;
    sum2=0;
    while((*(a+i)!=check)&&(i<=high))
    {
        sum2+=1;
        i+=1;
    }
    sum+=(sum1>sum2?sum1:sum2);
    //debug print
   // printf("\nlow1=%d mid=%d high1=%d sum=%d",low1,mid,high1,sum);
    return sum;
};
int maxstring(char *a,int low,int high)
{
    int mid=0,leftstring=0,rightstring=0,midstring=0,sum=0;
    if(high-1<=low)
        return (high-1==low?2:1);
    
    else if(high-1>low)
    {
        mid=(high+low)/2;
        leftstring=maxstring(a,low,mid);
        rightstring=maxstring(a,mid+1,high);
        midstring=crossmax(a,low,mid,high);
        sum=(leftstring>rightstring?leftstring:rightstring);
    }
    return (sum>midstring?sum:midstring);
};
int main(void)
{
    int n=0,largest=0,largest1=0;
    FILE *fr=fopen("beads.in","r"),*fw=fopen("beads.out","w");
    fscanf(fr,"%d",&n);
    char arr[n+1],arr1[2*n+1];
    fscanf(fr,"%s",arr);
    //fread(arr,sizeof(arr),1,fr);
    largest=maxstring(arr,0,n-1);
    strcpy(arr1,arr);
    strcat(arr1,arr);
    largest1=crossmax(arr1,0,n-1,2*n-1);
    //fprintf(fw,"%d",largest);
    largest=(largest>largest1?largest:largest1);
    largest=(largest>n?n:largest);
    fprintf(fw,"%d\n",largest);
    return 0;
}