/*
    ID:piyushg2
    LANG: C
    PROG: calfflac
        */
#include<stdio.h>
#include<string.h>

#define VERIFY(n) \
 (((n>=65)&&(n<=90))||((n>=97)&&(n<=122)))

#define EQUALITY(n,m) \
  ((n==m)||(n==m-32)||(n-32==m))

int smin=0,smax=0;

int palindrome1(char *a,int i,int n)
{
	int length=0,j=1,k=1,category=0;

	while(1)
	{
		if(VERIFY(*(a+i+k)))
		{
			k+=1;
			continue;
		}
		if(VERIFY(*(a+i-j)))
		{
			j+=1;
			continue;
		}
		if(EQUALITY(*(a+i-j),*(a+i+k)))
		{
			category=2;
			break;
		}
		else
		{
			category=1;
			break;
		}

	}
	if(category==1)//unequal,even
	{
		j=0;
		k=1;
	}
	else //equal,consecutive type
	{
		length=1;
		while(1)
		{
			if(!VERIFY(*(a+i+k)))
			{
				k+=1;
				continue;
			}
			if(EQUALITY(*(a+i),*(a+i+k)))
			{
				length+=1;
				k++;
			}
			else
				break;
		}

		while(1)
		{
			if(!VERIFY(*(a+i-j)))
			{
				j+=1;
				continue;
			}
			if(EQUALITY(*(a+i),*(a+i-j)))
			{
				length+=1;
				j++;
			}
			else
				break;
		}
	}
	for(j=0,k=1;(i-j!=0)&&(i+k!=0);j++,k++)
		{
			if(!VERIFY(*(a+i-j)))
			{
				k-=1;
				continue;
			}
			if(!VERIFY(*(a+i+k)))
			{
				j-=1;
				continue;
			}
			if(EQUALITY(*(a+i-j),*(a+i+k)))
			{
				length+=2;
				smin=i-j;
	                        smax=i+k;
				//printf("\ncompared %c ,%c",*(a+i-j),*(a+i+k));

			}
			else
				break;
		
	       	}
	
	return length;
};
int palindrome2(char *a,int i,int n)
{
	int length=1,j=0,k=0;

	for(j=1,k=1;(i-j>=0)&&(i+k<=n-1);j++,k++)
	{
		if(!VERIFY(*(a+i-j)))
		{
			k-=1;
			continue;
		}
		if(!VERIFY(*(a+i+k)))
		{
			j-=1;
			continue;
		}
		if(EQUALITY(*(a+i-j),*(a+i+k)))
		{
			length+=2;
			smin=i-j;
			smax=i+k;
			//printf("\ncompared %c ,%c",*(a+i-j),*(a+i+k));
		}
		else
		     break;

	
	}
	return length;
};

int main(void)
{
	int i=0,j=0,k=0,n=0,length=0,maxlength=0,category=0,min=0,max=0;
	char buff,a[20001];
	FILE *fr=fopen("calfflac.in","r"),*fw=fopen("calfflac.out","w");

	while(1)
	{
		if(fscanf(fr,"%c",&buff)!=EOF)
			a[i]=buff;
		else
			break;

		i++;
		
	}
	//printf("%s",a);
	n=(int)strlen(a);
	for(i=0;i<n;i++)
	{
		
		if(!VERIFY(a[i]))
		{
			continue;
		}
		if(a[i]=='B')
		 //fprintf(fw,"B\n");
		if(i<smax)
		{
			j=smax+1;
			while(!VERIFY(a[j]))
			{
				j++;
			}
			k=smin-1;
			while(!VERIFY(a[k]))
			{
				k--;
			}
			if(!EQUALITY(a[k],a[j]))
			{
				continue;	
			}
		
		}
			j=i+1;
		while(!VERIFY(a[j]))
		{
			j++;
		}
			k=i-1;

		while(!VERIFY(a[k]))
		{
			k--;
		}
				
		if(EQUALITY(a[i],a[j]))//even
		{
			category=1;
			length=palindrome1(a,i,n);
		        //printf("\ncat=%d char=%c,length=%d,smin=%d,smax=%d,i=%d",category,a[i],length,smin,smax,i);
		}
		else if(EQUALITY(a[k],a[j]))//odd
		{
			category=2;
			length=palindrome2(a,i,n);
		      //printf("\ncat=%d char=%c,length=%d,smin=%d,smax=%d,i=%d",category,a[i],length,smin,smax,i);
		}
		else
		{
			category=0;
		}

		if(length>maxlength)
		{
			maxlength=length;
			//fprintf(fw,"%d %d %c\n",maxlength,category,a[i]);
			min=smin;
			max=smax;
		}

	
	}
	fprintf(fw,"%d\n",maxlength);
	i=min;
	while(i<=max)
	{
		fprintf(fw,"%c",a[i]);
		i++;
	}
	fprintf(fw,"\n");

	fclose(fr);	
	return 0;
	
}

