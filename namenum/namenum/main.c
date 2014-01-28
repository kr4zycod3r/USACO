/*
 ID: piyushg2
 LANG: C
 TASK: namenum
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAP(i)\
switch(flag)\
{\
case 1:\
if(num[i]=='2')\
check='A';\
else if(num[i]=='3')\
check='D';\
else if(num[i]=='4')\
check='G';\
else if(num[i]=='5')\
check='J';\
else if(num[i]=='6')\
check='M';\
else if(num[i]=='7')\
check='P';\
else if(num[i]=='8')\
check='T';\
else if(num[i]=='9')\
check='W';\
break;\
case 2:\
if(num[i]=='2')\
check='B';\
else if(num[i]=='3')\
check='E';\
else if(num[i]=='4')\
check='H';\
else if(num[i]=='5')\
check='K';\
else if(num[i]=='6')\
check='N';\
else if(num[i]=='7')\
check='R';\
else if(num[i]=='8')\
check='U';\
else if(num[i]=='9')\
check='X';\
break;\
case 3:\
if(num[i]=='2')\
check='C';\
else if(num[i]=='3')\
check='F';\
else if(num[i]=='4')\
check='I';\
else if(num[i]=='5')\
check='L';\
else if(num[i]=='6')\
check='O';\
else if(num[i]=='7')\
check='S';\
else if(num[i]=='8')\
check='V';\
else if(num[i]=='9')\
check='Y';\
break;\
}
#define COMPARE(char1,char2,char3)\
(names[j]==char1)||(names[j]==char2)||(names[j]==char3)

#define GET fscanf(dict,"%s",names)
/*
int convert(long long int numb,char *num)
{
    
    for (;numb!=0;num++)
    {
        *num=48+(numb%10);
        numb/=10;
    }
    return 0;
};
*/
int main(void)
{
    FILE *fr=fopen("namenum.in","r"),*fw=fopen("namenum.out","w"),
    *dict=fopen("dict.txt","r");
    char names[13],num[13],check;
    int j=0,flag=1,flag1=0,done=0;
    long len=0;
   // long long int numb=0;
    //done=convert(numb,num);
    //puts(names[i]);
    //fclose(dict);
    
    fscanf(fr,"%s",num);
    len=strlen(num);
    GET;
    for(flag=1;flag<=3;flag++)//uses 3 possibilities
    {
        MAP(0)
        //printf("check=%c\n",check);
        while((names[0]!=check)||(strlen(names)!=len))
        {
            if(GET==EOF)
                break;
            if(names[0]>check)
                break;
        }
        if(names[0]>check)
            continue;
        do
        {
             flag1=1;
             if(strlen(names)!=len)
             {
                 GET;
                 continue;
             }
            
             for(j=0;(j<len)&&(flag1==1);j++)
              {
                switch (num[j])
                {
                    case '2':
                        flag1=COMPARE(65,66,67)?1:0;
                        break;
                    case '3':
                        flag1=COMPARE(68,69,70)?1:0;
                        break;
                    case '4':
                        flag1=COMPARE(71,72,73)?1:0;
                        break;
                    case '5':
                        flag1=COMPARE(74,75,76)?1:0;
                        break;
                    case '6':
                        flag1=COMPARE(77,78,79)?1:0;
                        break;
                    case '7':
                        flag1=COMPARE(80,82,83)?1:0;
                        break;
                    case '8':
                        flag1=COMPARE(84,85,86)?1:0;
                        break;
                    case '9':
                        flag1=COMPARE(87,88,89)?1:0;
                        break;
                    default:
                        break;
                }
                //puts(names[i]);
                // printf("flag1=%d\n",flag1);
                
              }
            if(flag1==1)
            {
                fprintf(fw,"%s\n",names);
                done+=1;
            }
           GET;
        }while(names[0]==check);
    }
    if(done==0)
      fprintf(fw,"NONE\n");
       
    return 0;
}