#include<stdio.h>
#include<string.h>
#include "header.h"  

void delete_contact(struct address *addr, int *count, int *searched_index)
{
    char ch;
    int del_ch[20]={0},co=0;

    printf("what you want to Delete\n");
    search_list(addr,count,searched_index,del_ch);
    
    for(int i=0 ; i<20 ; i++)
    {
        if(del_ch[i] == 1)
            co++;
        if(co==2)
            break;
    }

    if(co>1)
    {
        printf("Multiple Names are matching with entry\n");
        printf("Please Enter respective index to delete\n");
        
        loop:
        scanf("%d", searched_index);
        if((*searched_index < 1 || *searched_index > 20) || del_ch[(*searched_index)-1] != 1 )
        {
            printf("Invalid Index\n");
            printf("Please Enter respective index to edit\n");
            goto loop;
        } 
        *searched_index = (*searched_index) - 1;
    }

    if(*searched_index != -1)
    {
        printf("Are sure you want to delete it!!(y/n)\n");
        scanf(" %c",&ch);

        if(  ch=='y')
        {
            for(int i=(*searched_index) ; i<((*count)-1) ; i++)  //  0 1 2 3 4 (5)
            {
                strcpy(addr->c[i].name,addr->c[i+1].name);
                strcpy(addr->c[i].phone,addr->c[i+1].phone);
                strcpy(addr->c[i].email,addr->c[i+1].email);
            }  

            (*count)--;
            printf("Deleted Successfully\n");          
        }

        else
            printf("Nothing Deleted\n");

        *del_ch = 0;
    }
}