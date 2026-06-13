#include<stdio.h>
#include<string.h>
#include "header.h"  

void create_contact(struct address *addr,int *count)
{
    int flag=0,len=0,search_index=-1;
    
    printf("------------------------------------------------------------\n");
    printf("                   ENTERED TO CREATE CONTACT\n");
    printf("------------------------------------------------------------\n");

    name_validation(addr -> c[*count].name);
    
    loop1:
    phone_validation(addr -> c[*count].phone);
    search_index=-1;
    search_phone(addr->c,addr -> c[*count].phone,count,&search_index);
    if(search_index != -1)
    {
        printf("Phone No already exist at index %d!!\n\n",search_index+1);
        goto loop1;
    }

    loop2:
    email_validation(addr -> c[*count].email);
    search_index=-1;
    search_email(addr->c,addr -> c[*count].email,count,&search_index);
    if( search_index != -1)
    {
        printf("Email already exist at index %d!!\n\n",search_index+1);
        goto loop2;
    }
    
    (*count)++;
    printf("No. of contacts: %d\n",*count);
}

void name_validation(char *str)  
{
    int flag,i=0,j=0;
    do
    {
        char temp;
        flag=0;

        printf("Enter Valid Name:");
        scanf("%20[^\n]", str);
                
        if((str[0]=='\0') || (str[0] == ' '))
        {
            printf("Name should not be empty or start with space characters\n");
            flag=1;
            continue;
        }

        while(str[i])
        {
            char ch = str[i];

            if(!((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch==' ') || (ch=='.')))
            {
                flag=1;
                printf("Invalid Name\n");
                break;
            }
            i++;
        }
        while(temp=getchar() != '\n');
    }while(flag);

    i=0;
    while(str[i])
    {
        if(str[i]==' ' && str[i+1]==' ')
        {
            j=i;
            while(str[j])
            {
                str[j] = str[j+1];
                j++;
            }
        }
        else
        {
            i++;
        }
    }
}

void phone_validation(char *phone)
{
    int flag;
    do
    {
        int i=0;
        char temp;
        flag=0;

        printf("Enter Valid Phone No:");
        scanf("%20s", phone);
        
        if( (strlen(phone)) !=10)
        {
            printf("Number should contain 10 Digits\n");
            flag=1;
            continue;
        }
        
        while(phone[i])
        {
            char ch = phone[i];

            if( !(ch>='0' && ch<='9') )
            {
                flag=1;
                printf("Invalid Phone No\n");
                break;
            }
            i++;

        }
        
        if(!((phone[0] == '6') || (phone[0] == '7') || (phone[0] == '8') || (phone[0] == '9')))
        {
            printf("Number Must start with (6 or 7 or 8 or 9)\n");
            flag=1;
            continue;
        } 
        while(temp=getchar() != '\n');     
    }while(flag);
}

void email_validation(char *email)
{
    int i,flag,flag_at_index=0,flag_at=0,flag_dot=0;
    do
    {
        char *ret = NULL;
        char temp;
        i=0;
        flag=0;
        flag_dot=0;
        flag_at_index=-1;
        flag_at=0;

        printf("Enter Valid Email:");
        scanf("%20s",email);
                     
        while(email[i])
        {
            char ch = email[i];            
            if(ch=='@')
            {
                flag_at++;

                if( (flag_at_index == -1) && (flag_at == 1))
                {
                    flag_at_index=i;
                    int j=i+1;
                    while(email[j] != '.')
                    {
                        if(email[j] < 'a' || email[j] >'z')
                        {
                            printf("Email must have valid domain name after '@'\n");
                            flag=1;
                            break;
                        }
                        j++;
                    }                    
                }
                if(flag==1)
                {
                    break;
                }
                    
                if(flag_at == 2)
                {
                    flag=1;
                    printf("Only one '@' Accepted \n");
                    break;
                }
                i++;
                continue;
            }
            
            if(flag_at_index==0)
            {
                printf("mail should contain name before @domain.com\n");
                flag=1;
                break;
            }
            
            if(ch=='.')
            {
                flag_dot++;
                if(flag_dot == 2)
                {
                    flag=1;
                    printf("Only one '.' Accepted\n");
                    break;
                }
                i++;
                continue;
            }

            if(!((ch>='a' && ch<='z') || (ch>='0' && ch<='9')))
            {
                flag=1;
                printf("Email must contain only lower case alphabets\n");
                break;
            }
            i++;
        }
        while(temp=getchar() != '\n');
        if(flag)        
        {
            continue;
        }

        if(flag_at==0)
        {
            printf("Email must have one '@domain'\n");
            flag=1;
            continue;
        }

        ret=strstr(email,".com");
        if( ret == NULL)
        {
            printf("Email Must have .com\n");
            flag=1;
            continue;
        }

        if(*(ret+4) != '\0')
        {
            printf("No chars after after .com\n");
            flag=1;
            continue;   
        }        
    }while(flag);
}