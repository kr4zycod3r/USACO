/*
 ID  :   piyushg2
 LANG:   C
 PROG:   crypt1
*/
#include<stdio.h>

int verify(int num,int *a,int n)  //verifies if num is present in the array a--returns 1 if true
{
	int i=0;

	for(i=0;i<n;i++)
	{
		if(num==*(a+i))
		{
			return 1;
		}
	}
	return 0;
};

int threedigit(int *a,int *b,int n) // creates n^3 three digit numbers for the given numbers in array a
{
	int i=0,j=0,k=0,threes=0,twos=0,ones=0,length=0;

	for(i=0;i<n;i++)
	{
		threes=*(a+i)*100;
		for(j=0;j<n;j++)
		{
			twos=*(a+j)*10;
			for(k=0;k<n;k++)
			{
				ones=*(a+k);
				*(b+k+j*n+i*n*n)=ones+twos+threes;
				length+=1;
			}
		}
	
	}
	
	return length;

};
int twodigit(int *a,int *c,int n)   // creates n^2 two digit numbers for the given numbers in array a
{
	int j=0,k=0,twos=0,ones=0,length=0;

                for(j=0;j<n;j++)
                {
                        twos=*(a+j)*10;
                        for(k=0;k<n;k++)
                        {
                                ones=*(a+k);
                                *(c+k+j*n)=ones+twos;
                                length+=1;
                        }
                }
        
        
        
        return length;	
};

int main(void)
{
	int n=0,a[9],b[1000],c[100],thd=0,twd=0,i=0,j=0,ones=0,twos=0,pp1=0,pp2=0,first=0,second=0,third=0,
	fourth=0,p=0,solution=0;
	FILE *fr=fopen("crypt1.in","r"),*fw=fopen("crypt1.out","w");
	
	fscanf(fr,"%d",&n);
	while(fscanf(fr,"%d",&a[i])!=EOF)
		i++;

	thd=threedigit(a,b,n);
	twd=twodigit(a,c,n);

	for(i=0;i<thd;i++)
	{
		for(j=0;j<twd;j++)
		{
			ones=c[j]%10;
			twos=c[j]/10;
			pp1=b[i]*ones;
			if(pp1/1000!=0)
				continue;
			else
			{
				first=pp1%10;
				if(!verify(first,a,n))
					continue;
				second=pp1/10;
				second%=10;
				if(!verify(second,a,n))
					continue;
				third=pp1/100;
				if(!verify(third,a,n))
					continue;

				pp2=b[i]*twos;
				if(pp2/1000!=0)
					continue;
				else
				{
					first=pp2%10;
					if(!verify(first,a,n))
						continue;
					second=pp2/10;
					second%=10;
					if(!verify(second,a,n))
						continue;
					third=pp2/100;
					if(!verify(third,a,n))
						continue;

					p=pp1+pp2*10;
					
					if(p/10000!=0)
						continue;
					else
					{
						first=p%10;
						if(!verify(first,a,n))
							continue;
						second=p/10;
						second%=10;
						if(!verify(second,a,n))
							continue;
						third=p/100;
						third%=10;
						if(!verify(third,a,n))
							continue;
						fourth=p/1000;
						if(!verify(fourth,a,n))
							continue;
						solution+=1;	
					}

                               }



				
			
			}
		
		}
	
	
	}

	fprintf(fw,"%d\n",solution);

	return 0;
}

