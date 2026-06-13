#include<stdio.h>
#include "header.h"

void list(struct address *addr,int *count)
{ 
    

    printf("------------------------------------------------------------\n");
    printf("                 ENTERED TO LIST CONTACT\n");
    printf("------------------------------------------------------------\n\n");

    printf("--------------------------------------------------------------------------\n");
    printf("%-10s    %-17s    %-17s    %-17s\n","index","Name","Ph No","Email");
    for(int i=0 ; i<(*count) ; i++)
    {
        printf("%-10d %-20s %-20s %-20s\n",i+1,addr->c[i].name, addr->c[i].phone, addr->c[i].email);
    }
    printf("--------------------------------------------------------------------------\n");
}