#include<stdio.h>
#include<string.h>  
#include "header.h"    

void edit_contact(struct address *addr, int *count,int *searched_index)
{
    int choice=0,del_ch[20]={0},co=0;

    *searched_index=-1;
    
    printf("------------------------------------------------------------\n");
    printf("                  ENTERED TO EDIT LIST\n");
    printf("------------------------------------------------------------\n");

    printf("what you want to edit\n");
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
        printf("Please Enter respective index to edit\n");
        
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

    if(  (*searched_index)!= -1)
    {
        printf("1.Edit by name\n");
        printf("2.Edit by Phone No\n");
        printf("3.Edit by Email\n");

        while(!choice)
        {
            printf("Enter Your Choice:");
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
                strcpy(addr->c[*searched_index].name , name);
                printf("Changed\n");
                break;
            }
            case 2: 
            {
                char ph_no[11];
            
                int target_index = *searched_index;

                loop1:
                *searched_index = -1;
                phone_validation(ph_no);
                search_phone(addr->c,ph_no,count,searched_index);

                if(*searched_index != -1)
                {
                    printf("Phone No already exist!!\n");
                    printf("Try another one\n");
                    goto loop1;
                }
                strcpy(addr->c[target_index].phone , ph_no);
                printf("Changed\n");
                break;
            }
            case 3:
            {
                char email[21];
                
                int target_index = *searched_index;
                loop2:
                *searched_index = -1;
                email_validation(email);
                search_email(addr->c,email,count,searched_index);
                if(*searched_index != -1)
                {
                    printf("Email already exist!!\n");
                    printf("Try another one\n");
                    goto loop2;
                }
                strcpy(addr->c[target_index].email , email);
                printf("Changed\n");
                break;
            }        
        }
        
    }

}