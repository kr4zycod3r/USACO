//
//  main.c
//  dualpal
//
//  Created by piyush goel on 7/10/13.
//  Copyright (c) 2013 piyush goel. All rights reserved.
//
/*
 ID: piyushg2
 LANG: C
 TASK: dualpal
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAP(quo)\
if(quo<=9)\
 bit=48+quo;\
else\
 bit=64+quo-9;

int elements(int base,int num)
{
    int i=1,great=base;
    for(i=1;great<num;i++)
        great*=base;
    return i;
};
void convert(int base,char *A,int num,int i)
{
    int power,j=0;
    char bit;
    *(A+i)='\0';
    for(j=0;i>0;i--,j++)
    {
        power=pow(base,i-1);
        if(power>num)
            *(A+j)='0';
        else
        {
            MAP(num/power)
            *(A+j)=bit;
            num%=power;
        }
    }
};
int palindrome(int base,int num)
{
    int i=0,j,flag=1;
    i=elements(base,num);
    char A[i+1];
    convert(base,A,num,i);
    for(j=0;j<i/2;j++)
    {
      if(A[j]!=A[i-1-j])
      {
          flag=0;
          break;
      }
    }
    if(flag==0)
        return 0;
    return 1;
};
int main(void)
{
    int base=0,num=0,s=0,n=0,i=0,flag=0,flag1=0;
    FILE *fr=fopen("dualpal.in","r"),*fw=fopen("dualpal.out","w");
    
    fscanf(fr,"%d %d",&n,&s);
    
    for(num=s+1;flag<n;num++)
      {
          
          flag1=0;
          for (base=2;(base<=10)&&(flag1<2);base++)
          {
              i=palindrome(base,num);
              if(i==1)
                  flag1++;
          }
          if(flag1==2)
          {
              fprintf(fw,"%d\n",num);
              flag++;
          }
      }
    return 0;
}

