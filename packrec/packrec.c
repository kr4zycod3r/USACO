#include<stdio.h>
#include<stdlib.h>
#define BAN(p,q) \
	if(p%2==0) \
	{ \
		if((q==p)||(q==p+1)){ \
			continue; \
		} \
	}\
	else { \
		if((q==p)||(q==p-1)){ \
			continue; \
		} \
	    }

struct node
{
	int length,breadth;
	struct node *link;
};

struct node *getnode()
{
	return (struct node *)malloc(sizeof(struct node));
};
 

void place(FILE *fw,int (*a)[2],int i,int j,int k,int l,struct node *root)
{
	struct node *next;
	next=root;
	next->length=**(a+i);
	next->breadth=*(*(a+i)+1);
	fprintf(fw,"\nplaced %d,%d\n",next->length,next->breadth);
	next=next->link;
	next->length=**(a+j);
	next->breadth=*(*(a+j)+1);
	 fprintf(fw,"\nplaced %d,%d\n",next->length,next->breadth);
	next=next->link;
	next->length=**(a+k);
	next->breadth=*(*(a+k)+1);
	 fprintf(fw,"\nplaced %d,%d\n",next->length,next->breadth);
	next=next->link;
	next->length=**(a+l);
	next->breadth=*(*(a+l)+1);
	 fprintf(fw,"\nplaced %d,%d\n",next->length,next->breadth);
	next->link=NULL;

};

int max(int a,int b,int c,int d)
{
	int n=a;
	if(b>n)
		n=b;
	if(c>n)
		n=c;
	if(d>n)
		n=d;
	return n;
}

int enclose(FILE *fw,struct node *root,int (*c)[2])
{
	struct node *next=root;
	int l=0,l1=0,l2=0,l3=0,l4=0,b=0,b1=0,b2=0,b3=0,b4=0,n=0;
		
	fprintf(fw,"\nenclose entered\n");	
	l1=next->length;
	b1=next->breadth;
	next=next->link;
	l2=next->length;
	b2=next->breadth;
        next=next->link;
	l3=next->length;
        b3=next->breadth;
        next=next->link;
        l4=next->length;
        b4=next->breadth;
	fprintf(fw,"\nl1=%d,b1=%d,l2=%d,b2=%d,l3=%d,b3=%d,l4=%d,b4=%d",l1,b1,l2,b2,l3,b3,l4,b4);
       	
	/*LAYOUT1*/
	l=max(l1,l2,l3,l4);
	b=b1+b2+b3+b4;
	**c=l*b;
	**(c+2)=l;
	*(*(c+2)+1)=b;
	fprintf(fw,"\nLayout1:l=%d,b=%d,min area=%d\n",l,b,**c);
	n=1;

	/*LAYOUT2*/
	l=l4+max(l1,l2,l3,0);
	b=max(b4,b1+b2+b3,0,0);
	if(**c>l*b)
	{
		**c=l*b;
		**(c+2)=l;
		*(*(c+2)+1)=b;
		n=1;
	}
	else if(**c==l*b)
	{
		**(c+2*(n+1))=l;
		*(*(c+2*(n+1))+1)=b;
		n+=1;	
	}
	fprintf(fw,"Layout2:l=%d,b=%d,min area=%d\n",l,b,**c);
	/*LAYOUT3*/
	l=max(l3,l4+max(l1,l2,0,0),0,0);
	b=max(b1+b2+b3,b3+b4,0,0);
	if(**c>l*b)
	{
		**c=l*b;
		**(c+2)=l;
		*(*(c+2)+1)=b;
		n=1;
	}
	else if(**c==l*b)
	{
		**(c+2*(n+1))=l;
		*(*(c+2*(n+1))+1)=b;
		n+=1;
	}
	fprintf(fw,"Layout3:l=%d,b=%d,min area=%d\n",l,b,**c);
	/*LAYOUT4*/
        l=max(l1,l4,l2+l3,0);
        b=b1+b4+max(b2,b3,0,0);
        if(**c>l*b)
        {
                **c=l*b;
                **(c+2)=l;
                *(*(c+2)+1)=b;
                n=1;
        }
        else if(**c==l*b)
        {
                **(c+2*(n+1))=l;
                *(*(c+2*(n+1))+1)=b;
                n+=1;
        }
	fprintf(fw,"Layout4:l=%d,b=%d,min area=%d,placed in %d and %d\n",l,b,**c,**(c+2*(n+1)),*(*(c+2*(n+1))+1));

	/*LAYOUT5*/
        l=max(l4,l3,l1+l2,0);
        b=b3+b4+max(b1,b2,0,0);
	if(**c>l*b)
        {
                **c=l*b;
                **(c+2)=l;
                *(*(c+2)+1)=b;
                n=1;
        }
        else if(**c==l*b)
        {
                **(c+2*(n+1))=l;
                *(*(c+2*(n+1))+1)=b;
                n+=1;
        }
	fprintf(fw,"Layout5:l=%d,b=%d,min area=%d\n",l,b,**c);

	/*LAYOUT6*/
        l=max(l1+l2,l3+l4,0,0);
	if(l2>l4)
	{
		if(l2>=l4+l3)
			b=max(b2+b3,b2+b4,b1,0);
		else
			b=max(b1+b3,b2+b3,b2+b4,0);
	}
	else
		b=max(b2+b4,b1+b3,b1+b4,0);

	if(**c>l*b)
        {
                **c=l*b;
                **(c+2)=l;
                *(*(c+2)+1)=b;
                n=1;
        }
        else if(**c==l*b)
        {
                **(c+2*(n+1))=l;
                *(*(c+2*(n+1))+1)=b;
                n+=1;
        }
	fprintf(fw,"Layout6:l=%d,b=%d,min area=%d\n",l,b,**c);
	
      return n;
};
int main(void)
{
	int i=0,j=0,k=0,l=0,b[7][2],n=0,min=1000,a[8][2],area[1000][2],m=0,solution=0;
       	struct node *root,*temp=NULL,*old=NULL;
	FILE *fr=fopen("packrec.in","r"),*fw=fopen("packrec.out","w");
	for(i=0;i<=3;i++)
	{
		temp=getnode();
		if(i==0)
		{
			root=temp;
			old=temp;
		}
		else
		{
			old->link=temp;
			old=temp;
		}
	
	}
	temp->link=NULL;
	i=0;
	while(fscanf(fr,"%d %d",&a[i][0],&a[i][1])!=EOF)
	{
		fprintf(fw,"\nsanity check1:a[0][0]=%d %d\n",a[0][0],a[0][1]);
		a[i+1][0]=a[i][1];
		a[i+1][1]=a[i][0];
		fprintf(fw,"i=%d l1=%d b1=%d\nl2=%d b2=%d\n",i,a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
		i+=2;
	}
	fprintf(fw,"\nsanity check2:a[0][0]=%d %d\n",a[0][0],a[0][1]);
	for(i=0;i<8;i++)
	{
		if(i==10)
			break;
		for(j=0;j<8;j++)
		{
			BAN(i,j)
		        if(i==10)
				break;
			for(k=0;k<8;k++)
			{
				BAN(i,k)
				BAN(j,k)
				if(i==10)
					break;
				for(l=0;l<8;l++)
				{
					if(i==10)
						fprintf(fw,"\nhere before ban\n");
					BAN(i,l)
					if(i==10)
						fprintf(fw,"\nhere after bani,l\n");
					BAN(j,l)
					BAN(k,l)
					fprintf(fw,"\ni=%d,j=%d,k=%d,l=%d\n",i,j,k,l);
					place(fw,a,i,j,k,l,root);
					fprintf(fw,"\nplace complete");
					fprintf(fw,"\nafter place i=%d,j=%d,k=%d,l=%d\n",i,j,k,l);
					n=enclose(fw,root,b);
					if(i==10)
						break;
					fprintf(fw,"\nenclose complete n=%d\n",n);
					fprintf(fw,"\nnew i=%d,j=%d,k=%d,l=%d\n",i,j,k,l);
					if(b[0][0]<min)
					{
						min=b[0][0];//min gives least area found
						m=1;
						solution=n;//no. of combos found
						while(m<=n)
						{
							area[m-1][0]=b[m][0];
							area[m-1][1]=b[m][1];
							m+=1;
						}
					}
					else if(b[0][0]==min)
					{
						m=1;
						while(m<=n)
						{
							area[solution+m-1][0]=b[m][0];
							area[solution+m-1][1]=b[m][1];
							m+=1;
						}
						//solution+=n;
					}



				}
				fprintf(fw,"\nexits l\n");

			
			}
			fprintf(fw,"\nexits k\n");
		}
		fprintf(fw,"\nexits j");
	
	}
	fprintf(fw,"\nexits i\n");

	fprintf(fw,"final min=%d,no. of sol.=%d\n",min,solution);


	return 0;
}
