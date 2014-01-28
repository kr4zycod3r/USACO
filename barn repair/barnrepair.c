/*
  ID:   piyushg2
  LANG: C
  PROG: barn1
*/

#include<stdio.h>

int maxsequence(int *a,int n)
{
	int maxseq=0,seq=0,i=0,min=0,max=0,mini=0,maxi=0;
	for(i=0;i<=n-1;i++)
	{
		if(*(a+i)!=0)
		{
			seq++;
		}
		else
		{
			if(seq>maxseq)
			{
				maxseq=seq;
				maxi=i-1;
				mini=i-seq;
				max=*(a+i-1);
				min=*(a+i-seq);
			}
		
			seq=0;
		
		
		}

	}
	//printf("unused min=%d\n",min);
	//printf("unused max=%d\n",max);

	for(i=mini;i<=maxi;i++)
	{
		*(a+i)=0;
	}
	return maxseq;

};
int main(void)
{
	int a[201],b[201],uns=0,us=0,i=0,j=0,n=0,m=0,c=0,s=0,min=1000,max=0;
	FILE *fr=fopen("barn1.in","r"),*fw=fopen("barn1.out","w");
	for(i=0;i<200;i++)
	{
		a[i]=0;
		b[i]=0;
	}
        
	fscanf(fr,"%d",&m);
	fscanf(fr,"%d",&s);
	fscanf(fr,"%d",&c);
	for(i=0;i<c;i++)
	{
		fscanf(fr,"%d",&us);
		b[us]=us;
		
		if(us<=min)
			min=us;

		if(us>=max)
			max=us;
	
	}
	//printf("min=%d\n",min);
	//printf("max=%d\n",max);
	for(i=0;i<=max-min;i++)
	{
		if(b[i+min]==0)
		{
			a[i]=i+min;
			uns++;
			//printf("a[%d]=%d\n",i,i+min);
		
		}
		else
			a[i]=0;

	
	}
	//printf("initial uns=%d\n",uns);
	for(j=0;j<m-1;j++)
	{

		n=maxsequence(a,max-min+1);
		if(n==0)
			break;
		uns-=n;
		//printf("uns=%d\n",uns);
	
	}
	//printf("%d\n",c);
	//printf("%d\n",uns);
	fprintf(fw,"%d\n",c+uns);
	fclose(fw);
	fclose(fr);


return 0;

}
