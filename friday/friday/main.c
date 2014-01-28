/*
 ID  : piyushg2
 LANG: C
 PROG: friday
 */

#include <stdio.h>

int main(int argc, const char * argv[])
{

    int n=0,starty=1900,startm=1,day=6,mon=0,tue=0,wed=0,thu=0,fri=0,sat=0,sun=0,flag=0,oldy=1900,ly=0;
    FILE *fr,*fw;
    fr=fopen("friday.in","r");
    fw=fopen("friday.out","w");
    fscanf(fr,"%d",&n);
    
    for (startm=1;startm<=12;startm++)
    {
        flag=0;ly=0;
        switch (startm)
        {
            case 1:
                day=6;
                break;
             
            case 2:
                day=2;
                break;
                
            case 3:
                day=2;
                break;
                
            case 4:
                day=5;
                break;
     
            case 5:
                day=0;
                break;
                
            case 6:
                day=3;
                break;
     
            case 7:
                day=5;
                break;
            
            case 8:
                day=1;
                break;
     
            case 9:
                day=4;
                break;
                
            case 10:
                day=6;
                break;
     
            case 11:
                day=2;
                break;

           default:
                day=4;
                break;
        }
        
        for (starty=1900;starty<=1900+n-1;starty++)
        {
            ly=0;
            if (starty%400==0||(starty%4==0&&starty%100!=0))
                ly=1;
            if (ly==1&&startm>=3&&flag==0)
             day+=2;//pre more than 3
            
            else if(flag==0&&ly==1&&startm<=2)
                day++;//pre less than 2
            
            else if(starty!=1900&&flag==0&&ly==0)
            day++;//pre;post both normal
            
            else if (flag==1&&startm<=2&&ly==0)
                day+=2;//post less than 2
            
            else if(flag==1&&ly==0&&startm>=3)
                day++;//post more than 3
            
            switch (day%7)
            {
                case 1:
                    mon++;
                    break;
                    
                case 2:
                    tue++;
                    break;
                    
                case 3:
                    wed++;
                    break;
                 
                case 4:
                    thu++;
                    break;
                    
                case 5:
                    fri++;
                    break;
                    
                case 6:
                    sat++;
                    break;
                    
                
                default:
                    sun++;
                    break;
            }
            
            oldy=starty;
            if (oldy%400==0||(oldy%4==0&&oldy%100!=0))
                flag=1;
            else
                flag=0;
            
        }
    }
fprintf(fw,"%d %d %d %d %d %d %d\n",sat,sun,mon,tue,wed,thu,fri);
    return 0;
}

