//
//  main.c
//  milk
//
//  Created by piyush goel on 7/10/13.
//  Copyright (c) 2013 piyush goel. All rights reserved.
//
/*
 ID: piyushg2
 LANG: C
 TASK: milk
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int p,a;
    struct node *link;
};
struct node *getnode()
{
    return (struct node *)malloc(sizeof(struct node));
};
int main(void)
{
    int n=0,m=0,i=0,smallest=0,smalla=0,total=0;
    FILE *fr=fopen("milk.in","r"),*fw=fopen("milk.out","w");
    struct node *temp,*old,*root,*nutemp;
    
    fscanf(fr,"%d %d",&n,&m);
    if ((n==0)&&(m==0))
    {
        fprintf(fw,"%d\n",total);
        return 0;
    }
    for(i=0;i<m;i++)//creates Linked list
    {
        temp=getnode();
        fscanf(fr,"%d %d",&temp->p,&temp->a);
        temp->link=NULL;
        if(i==0)
         root=temp;
        else
            old->link=temp;
        old=temp;
    }
    temp=root;
    while(temp!=NULL)//sorts LL
    {
        smallest=2000;
        nutemp=temp;
        while(nutemp!=NULL)
        {
            if(nutemp->p<smallest)
            {
                old=nutemp;
                smallest=nutemp->p;
            }
            nutemp=nutemp->link;
        }
        smalla=old->a;
        old->p=temp->p;
        old->a=temp->a;
        temp->p=smallest;
        temp->a=smalla;
        temp=temp->link;
    }
    temp=root;
    while(n>0)//calculates total
    {
        if(temp->a>=n)
        {
            total+=n*temp->p;
            n=0;
        }
        else
        {
            total+=temp->p*temp->a;
            n-=temp->a;
        }
        temp=temp->link;
    }
    fprintf(fw,"%d\n",total);
    return 0;
}







