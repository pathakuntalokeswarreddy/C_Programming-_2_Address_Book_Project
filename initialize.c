#include<stdio.h>
#include<unistd.h>
#include "header.h"

void initialization(struct address *addr, int *count)
{
    printf("Entered to Loading stage...Wait for sometime!!!\n");
    FILE *fp=fopen("data.txt","r");

    if(fp==NULL)
    {
        printf("File not opened\n");
        return;
    }

    char temp;
    temp=fgetc(fp);
    while((temp) != '\n')
    {
            temp=fgetc(fp);
    }
        
    int i=0,j=0,pos;
    while(1)
    {
        
        fseek(fp,10,SEEK_CUR);
        

        char temp1,temp2;
        j=0;
        temp1=fgetc(fp);
        addr->c[i].name[j] = temp1;
        j++;
        while(j<19)
        {
            temp2=fgetc(fp);
            
            if((temp1 == ' ') && (temp2 == ' '))
            {
                addr->c[i].name[j-1] = '\0';
                fseek(fp,20-j-1,SEEK_CUR);
                break;
            }
            else
            {
                addr->c[i].name[j] = temp2;
            }
            j++;
            temp1 = temp2;
        }
        if(j==19)
        {
            addr->c[i].name[j-1] = '\0';
        }
        


        j=0;
        temp1=fgetc(fp);
        addr->c[i].phone[j] = temp1;
        j++;
        while(j<19)
        {
            temp2=fgetc(fp);
            if((temp1 == ' ') && (temp2 == ' '))
            {
                addr->c[i].phone[j-1] = '\0';
                fseek(fp,20-j-1,SEEK_CUR);
                break;
            }
            else
            {
                addr->c[i].phone[j] = temp2;
            }
            j++;
            temp1 = temp2;
        }
        if(j==19)
        {
            addr->c[i].phone[j-1] = '\0';
        }      


        j=0;
        temp1=fgetc(fp);
        addr->c[i].email[j] = temp1;
        j++;
        while(j<20)
        {
            temp2=fgetc(fp);
            if((temp1 == ' ') && ((temp2 == ' ') || (temp2 == '\n'))
             )
            {
                addr->c[i].email[j-1] = '\0';
                fseek(fp,20-j,SEEK_CUR);
                break;
            }
            else
            {
                addr->c[i].email[j] = temp2;
            }
            j++;
            temp1 = temp2;
        }
        if(j==20)
        {
            addr->c[i].email[j-1] = '\0';
        }
            
        
        i++;
        if(temp2 == EOF)
        {
            break;
        }
    }
    *count = --i;
    printf("Loading finished!!\n");

    printf("%d contacts are loaded\n",*count);

    fclose(fp);
}