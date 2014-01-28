//
//  main.c
//  transform
//
//  Created by piyush goel on 7/6/13.
//  Copyright (c) 2013 piyush goel. All rights reserved.
//

/*
 ID: piyushg2
 LANG: C
 TASK: transform
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CONDISCONNECT \
if(flag==0)\
break;

#define DISCONNECT \
{\
flag=0;\
break;\
}


#define SHOW(a)   \
if(flag==1)\
{ \
fprintf(fw,"%d\n",a);\
return 0;\
}

int main(void)
{
    FILE *fr=fopen("transform.in","r"),*fw=fopen("transform.out","w");
    int i=0,j=0,flag=1,n;
    //scanf("%d",&n);
    fscanf(fr,"%d",&n);
    char real[n][n+1],change[n][n+1];
    for(i=0;i<n;i++)
       // scanf("%s",real[i]);
       fscanf(fr,"%s",real[i]);
    for(i=0;i<n;i++)
       // scanf("%s",change[i]);
       fscanf(fr,"%s",change[i]);
    //test 1
    for(i=0;i<n;i++)
    {
        if(real[0][i]!=change[i][n-1])
            DISCONNECT
            }
    if(flag==1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(real[i][j]!=change[j][n-i-1])
                    DISCONNECT
                    }
            CONDISCONNECT
        }
    }
    SHOW(1)
    flag=1;
    //test2
    for(i=0;i<n;i++)
    {
        if(real[0][i]!=change[n-1][n-i-1])
            DISCONNECT
            }
    if(flag==1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(real[i][j]!=change[n-1-i][n-j-1])
                    DISCONNECT
                    }
            CONDISCONNECT
        }
        
    }
    SHOW(2)
    flag=1;
    //test3
    for(i=0;i<n;i++)
    {
        if(real[0][i]!=change[n-1-i][0])
            DISCONNECT
            }
    if(flag==1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(real[i][j]!=change[n-j-1][i])
                    DISCONNECT
                    }
            CONDISCONNECT
        }
    }
    SHOW(3)
    flag=1;
    //test4
    for(i=0;i<n;i++)
    {
        if(real[0][i]!=change[0][n-i-1])
            DISCONNECT
            }
    if(flag==1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(real[i][j]!=change[i][n-j-1])
                    DISCONNECT
                    }
            CONDISCONNECT
        }
    }
    SHOW(4)
    flag=1;
    //test5a
    for(i=0;i<n;i++)
    {
        if(real[0][i]!=change[n-i-1][n-1])
            DISCONNECT
            }
    if(flag==1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(real[i][j]!=change[n-j-1][n-1-i])
                    DISCONNECT
                    }
            CONDISCONNECT
        }
    }
    SHOW(5)
    flag=1;
    //test5b
    for(i=0;i<n;i++)
    {
        if(real[0][i]!=change[n-1][i])
            DISCONNECT
            }
    if(flag==1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(real[i][j]!=change[n-1-i][j])
                    DISCONNECT
                    }
            CONDISCONNECT
        }
    }
    SHOW(5)
    flag=1;
    //test5c
    for(i=0;i<n;i++)
    {
        if(real[0][i]!=change[i][0])
            DISCONNECT
            }
    if(flag==1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(real[i][j]!=change[j][i])
                    DISCONNECT
                    }
            CONDISCONNECT
        }
    }
    SHOW(5)
    flag=1;
    //test6
    for(i=0;i<n;i++)
    {
        if(real[0][i]!=change[0][i])
            DISCONNECT
            }
    if(flag==1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(real[i][j]!=change[i][j])
                    DISCONNECT
                    }
            CONDISCONNECT
        }
    }
    SHOW(6)
    fprintf(fw,"7\n");
    //printf("7");
    return 0;
}

