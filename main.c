#include<stdio.h>  
#include "header.h"
int main()
{
    int choice=0,del_ch[20]={0};
    struct address addr;
    int searched_index=-1;
    addr.count=0;

    printf("------------------------------------------------------------\n");
    printf("                   WELCOME TO ADDRESS BOOK\n");
    printf("------------------------------------------------------------\n");
    
    initialization(&addr,&addr.count);

    do
    {
        printf("\n\n");
        printf("1.Create contact\n");
        printf("2.Search contact\n");
        printf("3.Edit Contact\n");
        printf("4.Delete Contact\n");
        printf("5.List Contact\n");
        printf("6.Save and Exit\n\n");

        while(!choice)
        {
            printf("Enter Your Choice:");
            if((scanf("%d",&choice)) != 1)
            {
                printf("Invalid Entry\n");
            }
            int temp;
            while( (temp=getchar()) != '\n');
        }
        
        switch(choice)
        {
            case 1: create_contact(&addr,&addr.count);                         break;
            case 2: search_list(&addr,&addr.count,&searched_index,del_ch);     break;
            case 3: edit_contact(&addr,&addr.count,&searched_index);           break;
            case 4: delete_contact(&addr,&addr.count,&searched_index);         break;
            case 5: list(&addr,&addr.count);                                   break;
            case 6: save_exit(&addr,&addr.count);
                    printf("Text File Saved..Exiting....\n");                  return 0;
            default: printf("Invalid Entry\n");
        }
        choice=0;
    }while(1);
}