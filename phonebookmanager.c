#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

struct contact
{
    char name[35];
    char ph_number[10];
    //char address[35]
    //char email[35]
    
};
void addcontact();
void editcontact();
void search();
void list();
void deletecontact();

struct contact phonebook[100];
int serial_no=0;


void start()
{
    
    
    printf("Menu:\n");
    printf("1.Add    \t2.Edit  \t3.Delete   \n\n4.List      5.Search\n\n");
    char choice;
    scanf(" %c%*c", &choice);
    

    switch(choice)
    {
        case '1':
           addcontact();
           break;
        case '2':
           editcontact();
           break;
        case '3':
           deletecontact();
           break;
        case '4':
           list();
           break;
        case '5':
           search();
           break;
        default:
           printf("Invalid choice. Please select valid option\n");
           start();
           
    }    
    
    
           
}   

void addcontact()
    {
    
        printf("Enter Name:\n");
        scanf("%s",phonebook[serial_no].name);
        printf("Enter mobile number\n");
        scanf("%s",phonebook[serial_no].ph_number);
        printf("<Contact added successfully>\n\n");
        serial_no++;
        //printf("enter any key");
        //getch();
        start();

    }

void editcontact()
    {
        int i;
        int temp=0;
        char con[35];
        char namee[35];
        char phone[10];
        printf("write contact name you want to edit");
        scanf("%s",con);
        
        for (i=0;i<serial_no;i++)
        {
            if (strcmp(phonebook[i].name,con)==0)
            {
                printf("enter new name\n");
                scanf("%s",phonebook[i].name);
                printf("enter new mobile number\n");
                scanf("%s",phonebook[i].ph_number);
                printf("contact edited successfully");
                temp=1;
                break;
        
            }
        }
            
        if (temp==0)
        {
          printf("contact not found");
        }
        //printf("enter any key");
        //getch();
        start();
    
    }
    
void search()
{
    char con[35];
    int i;
    int temp=0;
    printf("enter the contact name you want to search");
    scanf("%s",con);
  
    for (i=0;i<=serial_no;i++)
    {
        if (strcmp(phonebook[i].name,con)==0)
        {
            printf("Contact found:\n");
            printf("Name: %s\n",phonebook[i].name);
            printf("Phone number: %s\n",phonebook[i].ph_number);
            temp=1;
            break;
        }
        if (temp==0)
        {
            printf("contact not found");
        }
        
        
        
    }
    //printf("enter any key");
    //getch(); 
    start();
}

void list()
{
    int i=0;
    while (i<serial_no);
    {
        printf("The list of contacts is %s\n",phonebook[i].name);
        i++;
    }
//printf("enter any key");
//getch();
start();
}

void deletecontact()
{
    int temp;
    char con[35];
    int i;
    printf("Enter the contact name you want to delete: ");
    scanf("%s", con);
    for (i = 0; i < serial_no; i++)
    {
        if (strcmp(phonebook[i].name, con) == 0)
        {
            for (int j = i; j < serial_no - 1; j++)
            {
                strcpy(phonebook[j].name, phonebook[j + 1].name);
                strcpy(phonebook[j].ph_number, phonebook[j + 1].ph_number);
            }
            serial_no--;
            printf("Contact deleted successfully.\n");
            temp=1;
            break;
        }
    }
    if (temp==0)
    {
        printf("contact not found");
    }
    //printf("enter any key");
    //getch();
    start();
}




int main() 
{
printf("****** welcome to phonebook*****\n");
start();

return 0; 
}
