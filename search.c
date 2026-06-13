#include<stdio.h>
#include<string.h>  
#include "header.h"

void search_list(struct address *addr, int *count,int *searched_index,int *del_ch)
{
    int choice=0, flag;
    *searched_index=-1;
    printf("------------------------------------------------------------\n");
    printf("                   ENTERED TO SEARCH LIST\n");
    printf("------------------------------------------------------------\n");
    
    printf("1.Search by name\n");
    printf("2.Search by Phone No\n"); 
    printf("3.Search by Email\n");

    while(!choice)
    {
            printf("Enter Your Choise:");
            if(((scanf("%d",&choice)) != 1) || (choice<1 || choice>3))
            {
                printf("Invalid Entry\n");
                choice=0;
            }
            int temp;
            while( (temp=getchar()) != '\n');
    }

    switch(choice)
    {
        case 1: 
        {
            char name[50];
            name_validation(name);

            search_name(addr->c,name,count,searched_index,del_ch);
            
            break;
        }
        case 2: 
        {
            char ph_no[11];
            phone_validation(ph_no);

            search_phone(addr->c,ph_no,count,searched_index);

            printf("--------------------------------------------------------------------------\n");
            if(*searched_index != -1)
                printf("%10d %20s %20s %20s\n",*searched_index+1,addr->c[*searched_index].name, addr->c[*searched_index].phone, addr->c[*searched_index].email);
            else
                printf("                   Not Found\n");
            printf("--------------------------------------------------------------------------\n");
            break;
        }
        case 3:
        {
            char email[21];
            email_validation(email);
            search_email(addr->c,email,count,searched_index);
            printf("--------------------------------------------------------------------------\n");
            if(*searched_index != -1)
                printf("%10d %20s %20s %20s\n",*searched_index+1,addr->c[*searched_index].name, addr->c[*searched_index].phone, addr->c[*searched_index].email);
            else
                printf("                   Not Found\n");
            printf("--------------------------------------------------------------------------\n");
            break;
        }        
    }
}

void search_name(struct contact *c,char *str,int *count,int *searched_index,int *del_ch)
{
    int i=0,flag=0;
    *searched_index=-1;
    
    printf("--------------------------------------------------------------------------\n");
    for( i ; i<(*count) ; i++)
    {
        if(  !( strcmp( c[i].name , str) )  )
        {
            printf("%10d %20s %20s %20s\n",i+1,c[i].name, c[i].phone, c[i].email);
            flag=1;
            *searched_index=i;
            del_ch[i]=1;
        }
    }
        
    if(!flag)
    {
        printf("                   Not Found\n");
    }
        

    printf("--------------------------------------------------------------------------\n");
    
}

void search_phone(struct contact *c,char *str,int *count,int *searched_index)
{
    *searched_index = -1;
       
    for( int i=0 ; i<(*count) ; i++)
    {
        if(  !( strcmp( c[i].phone , str) )  )
        {
            *searched_index=i;
        }
    }
    
}

void search_email(struct contact *c,char *str,int *count,int *searched_index)
{
    
    *searched_index = -1;
     
    for( int i=0; i<(*count) ; i++)
    {
        if(  !( strcmp( c[i].email , str) )  )
        {
            *searched_index=i;
        }
    }
}