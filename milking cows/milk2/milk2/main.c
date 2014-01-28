//
//  main.c
//  milk2
//
//  Created by piyush goel on 7/4/13.
//  Copyright (c) 2013 piyush goel. All rights reserved.
//

/*
 ID: piyushg2
 LANG: C
 TASK: milk2
 */
#include<stdio.h>
#include<stdlib.h>
#define NSTART (ntemp->start)
#define NEND (ntemp->end)
#define NDONE (ntemp->done)
struct node
{
    int done,start,end;
    struct node *link;
};
struct node *getnode()
{
    return (struct node *)malloc(sizeof(struct node));
};

int main(void)
{
    struct node *temp,*old,*root,*ntemp,*temp1,*root1,*old1;
    int low=0,high=0,gap=0,largegap=0,n=0,i=0,nomilk=0,tstart=0,tend=0;
    FILE *fr=fopen("milk2.in","r"),*fw=fopen("milk2.out","w");
    //scanf("%d",&n);
    fscanf(fr,"%d",&n);
    for(i=0;i<n;i++)//assigns values
    {
        temp=getnode();
        temp->done=0;
        temp->link=NULL;
        //scanf("%d %d",&temp->start,&temp->end);
        // printf("\n%d %d",temp->start,temp->end);
         fscanf(fr,"%d %d",&temp->start,&temp->end);
        if(i==0)
            root=temp;
        else
         old->link=temp;
        
        old=temp;
        
        
    }
    //sorts DS
    temp=root;
    for(i=0;temp!=NULL;i++)
    {
        ntemp=temp;
        tstart=1000000;
        while(ntemp!=NULL)
        {
            if(NSTART<tstart)
            {
                tstart=NSTART;
                tend=NEND;
                old=ntemp;
            }
            ntemp=ntemp->link;
            
        }
        old->start=temp->start;
        old->end=temp->end;
        temp->start=tstart;
        temp->end=tend;
        // printf("%d %d\n",temp->start,temp->end);
        temp=temp->link;
    }
    //end
    
    i=0;
    temp=root;
    while(temp!=NULL)//calculates largegap
    {
        tstart=temp->start;
        tend=temp->end;
        ntemp=temp->link;
        while((ntemp!=NULL)&&(NSTART<=tend))//assigns tstart and tend
        {
            
            if((NEND>=tend)&&(NDONE==0))
            {
                tend=NEND;
                NDONE=1;
            }
            ntemp=ntemp->link;
        }
        gap=tend-tstart;
        //nomilk DS LL
        temp1=getnode();
        temp1->start=tstart;
        temp1->end=tend;
        temp1->link=NULL;
        temp1->done=0;
        // printf("%d %d\n",tstart,tend);
        if(i==0)
            root1=temp1;
        else
            old1->link=temp1;
        old1=temp1;
        i++;
        //end DS
        
        
        
        if(gap>largegap)//calculates largegap
        {
            low=tstart;
            high=tend;
            largegap=gap;
        }
        temp=ntemp;
    }
   //calculates nomilk
    temp1=root1->link;
    old1=root1;
    for(i=0;temp1!=NULL;i++)
    {
        if(temp1->start>old1->end)
            nomilk=(nomilk>temp1->start-old1->end?nomilk:temp1->start-old1->end);
        
        old1=temp1;
        temp1=temp1->link;
    }
    
    
    //printf("%d %d ",largegap,nomilk);
    fprintf(fw,"%d %d\n",largegap,nomilk);
    return 0;
}