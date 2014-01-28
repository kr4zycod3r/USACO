/*
 ID  : piyushg2
 LANG: C
 PROG: gift1
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char name[17];
    int net;
    struct node *link;
};

struct node *getnode()
{
    return (struct node *)malloc(sizeof(struct node));
};

char st[17];
int main(int argc, const char * argv[])
{

    
    FILE *fr,*fw;
    struct node *temp=NULL,*old=NULL,*root=NULL;
    int a=0,i=0,t=0,give=0,n=0,take=0;
    fr=fopen("gift1.in", "r");
    fw=fopen("gift1.out", "w");
    
    
    fscanf(fr,"%d",&a);
    i=0;
    while (i!=a)
    {
        temp=getnode();
        if(i==0)
            root=temp;
        else
            old->link=temp;
        fscanf(fr,"%s",temp->name);
        temp->net=0;
        temp->link=NULL;
        old=temp;
        i++;
    }
    i=0;
    while (i!=a)
    {
        fscanf(fr,"%s",st);
        fscanf(fr,"%d%d",&give,&n);
        t=0;
        old=root;
        while (strcmp(old->name,st)!=0)
        {
            old=old->link;
            t++;
        }
        if(n!=0)
        {
        old->net+=give%n-give;
        take=give/n;
        }
        else
         take=0;
        
        
        while (n!=0)
        {
            fscanf(fr,"%s",st);
            t=0;
            old=root;
            while (strcmp(old->name,st)!=0)
            {
                old=old->link;
                t++;
            }
            old->net+=take;
            n--;
        }
        i++;
   
    }
    
    i=0;
    old=root;
    while (old!=NULL)
    {
        fprintf(fw,"%s %d\n",old->name,old->net);
        old=old->link;
    }
    fclose(fr);
    fclose(fw);
    return 0;
}

