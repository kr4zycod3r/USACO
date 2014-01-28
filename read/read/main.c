//
//  main.c
//  read
//
//  Created by piyush goel on 1/6/13.
//  Copyright (c) 2013 piyush goel. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{

    FILE *file;
    int s=1;
        file = fopen("/Users/piyushgoel/Desktop/friday.rtf", "r");
    if (file == NULL)
    {
        printf("File not found!\n");
    }
    fscanf(file,"%d",&s);
      printf("%d",s);
    
   fclose(file);
    return 0;
}

