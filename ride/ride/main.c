/* 
 ID  : piyushg2
 LANG: C
 PROG: ride
 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[])
{
    char s[9];
    int i=0,product=1,old=0;
    FILE *fr,*fw;
    fr=fopen("ride.in", "r");
    fw=fopen("ride.out", "w");
    if (fr==NULL)
      exit(0);
    
    while (fgets(s, 8, fr)!=NULL)
    {
        if (i==0)
        {
            while (s[i]!='\0')
            {
                product*=(s[i]-64);
                i++;
               
            }
            i=0;
            old=product%47;
        }
        
        else
        {
            product=1;
            i=0;
            while (s[i]!='\0')
            {
                product*=(s[i]-64);
                i++;
            }
            
            if (old==product%47)
              fputs("GO\n", fw);
            else 
                fputs("STAY\n", fw);
            break;
        }
        i=1;
    }
    
    fclose(fr);
    fclose(fw);
    
   
    return 0;
}

