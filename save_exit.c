#include<stdio.h>
#include<string.h>
#include "header.h" 

void save_exit(struct address *addr, int *count)
{
    FILE *fp=fopen("data.txt","w+");

    fprintf(fp,"%-10s   %-17s   %-17s   %-17s\n","index","Name","Ph No","Email");
    for(int i=0 ; i<(*count) ; i++)
    {
        fprintf(fp,"%-10d%-20s%-20s%-20s\n",i+1,addr->c[i].name, addr->c[i].phone, addr->c[i].email);
    }
    fclose(fp);
}