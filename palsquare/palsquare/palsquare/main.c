//
//  main.c
//  palsquare
//
//  Created by piyush goel on 7/10/13.
//  Copyright (c) 2013 piyush goel. All rights reserved.
//
/*
 ID: piyushg2
 LANG: C
 TASK: palsquare
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
int main(void)
{
 FILE*fr=fopen("palsquare.in","r"),*fw=fopen("palsquare.out","w");
    int base=0,num=0,i=0,sqnum=0,j=0,flag=1;
    fscanf(fr,"%d",&base);
    
    for(num=1;num<=300;num++)
    {
        flag=1;
        sqnum=num*num;
        i=elements(base,sqnum);
        char A[i+1];
        convert(base,A,sqnum,i);
        for(j=0;j<i/2;j++)
        {
            if(A[j]!=A[i-1-j])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            j=elements(base,num);
            char B[j+1];
            convert(base,B,num,j);
            fprintf(fw,"%s %s\n",B,A);
        }
    }
    return 0;
}