
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct booking
{
    char name[32];
    int age;
    char gender[8];
};
struct booking obj1;
struct booking obj2;

void booking();
void login();
void display_service();
void heading();
int options();

int main()
{
    int select; 
    struct booking obj1;
    struct booking obj2;
    login();
    heading();
    options();
   
    printf("Press any key to continue...\n");
    fflush(stdout);
}
void login()
{
    char name[32];
    char pin[16];
    char username[]="admin";
    char password[]="admin@123";
    printf("Enter your name\n");
    scanf("%s",&name);
    fflush(stdin);

    printf("Enter pin\n");
    scanf("%s",&pin);
    if(!(strcmp(name,username)&&strcmp(pin,password)))
    {
        printf("Password match\n");
    }
    else
    {
        printf("Wrong password\n");
        exit(0);
    }
}
void display_service()
{
    int s,t,select;
    printf("\n\t\t\t==================================\n");
	printf("\n\t\t\t*******WELCOME TO TOURS AND TRAVELS AGENCY*******\n");
	printf("\t\t\t==================================\n");

    printf("***1 = Maldives-: Price per person=90000/-\n");
    printf("***2 = South Korea-: Price per person=45500/-\n");
    printf("***3 = Unites State Arab-: Price per person=70000/-\n");
    printf("***4 = Thailand-: Price per person=58500/-\n");
    printf("***5 = Europe-: Price per person=36000/-\n");
    printf("***6 = Mexico-: Price per person=100000/-\n");
    printf("***7 = Canada-: Price per person=95000/-\n");
    printf("***8 = Japan-: Price per person=85000/-\n");
    printf("***9 = China-: Price per person=155000/-\n");
    printf("***10 = Eygpt-: Price per person=60000/-\n");
    printf("***11 = South Africa-: Price per person=35000/-\n");
    printf("***12 = Singapore-: Price per person=95050/-\n");
    printf("***13 = Iserael-: Price per person=52000/-\n");
    printf("***14 = United Kingdom-: Price per person=90000/-\n");
    printf("***15 = United State America-: Price per person=100000/-\n");

    printf("\nSelect your destination\n");
    scanf("%d",&s);
    switch(s)
    {
        case 1:
        {
            printf("\t\tYour Destination is Maldives\n");
            printf("Enter number of travellers\n");
            scanf("%d",&t);
            printf("Total price = %d/-",90000*t);
            break;
        }
        case 2:
        {
            printf("\t\tYour Destination is South Korea\n");
            printf("Enter number of travellers\n");
            scanf("%d",&t);
            printf("Total price = %d/-",45500*t);
            break;
        }
        case 3:
        {
            printf("\t\tYour Destination is United States Arab\n");
            printf("Enter number of travellers\n");
            scanf("%d",&t);
            printf("Total price = %d",70000*t);
            break;
        }
        case 4:
        {
            printf("\t\tYour Destination is Thailand\n");
            printf("Enter number of travellers\n");
            scanf("%d",&t);
            printf("Total price = %d",58500*t);
            break;
        }
        case 5:
        {
            printf("\t\tYour Destination is Europe\n");
            printf("Enter number of travellers\n");
            scanf("%d",&t);
            printf("Total price = %d",36000*t);
            break;
        }
        case 6:
        {
            printf("\t\tYour destination is Mexico\n");
            printf("Enter number of travellers\n");
            scanf("%d",&t);
            printf("Total price = %d", 100000*t);
            break;
        }
        case 7:
        {
            printf("\t\tYour destination is Canada\n");
            printf("Enter number of travellers\n");
            scanf("%d",&t);
            printf("Total price = %d", 95000*t);
            break;
        }
        case 8:
        {
           printf("\t\tYour destination is Japan\n");
           printf("Enter number of travellers\n");
           scanf("%d",&t);
           printf("Total price = %d", 85000*t);
           break;
        }
        case 9:
        {
            printf("\t\tYour destination is China\n");
            printf("Enter number of travellers\n");
            scanf("%d",&t);
            printf("Total price= %d", 155000*t); 
            break;         
        }
        case 10:
        {
            printf("\t\tYour destination is Eygpt\n");
            printf("Enter number of travellers\n");
            scanf("%d",&t);
            printf("Total price= %d",60000*t);
            break;
        }
        case 11:
        {
            printf("\t\tYour desstination is South Africa\n");
            printf("Enter number of travellers\n");
            scanf("%d",&t);
            printf("Total price = %d",35000*t);
            break;
        }
        case 12:
        {
            printf("\t\tYour destination is Singapore\n");
            printf("Enter number of travellers\n");
            scanf("%d",&t);
            printf("Total price = %d",95050*t);
            break;
        }
        case 13:
        {
           printf("\t\tYour destination is Iserael\n");
           printf("Enter number of travellers\n");
           scanf("%d",&t);
           printf("Total price = %d",52000*t);
           break;  
        }
        case 14: 
        {
            printf("\t\tYour destination is Untied Kingdom\n");
            printf("Enter number of travellers\n");
            scanf("%d",&t);
            printf("Total price = %d", 90000*t);
            break;
        }
        case 15:
        {
            printf("\t\tYour destination is Untied State America\n");
            printf("Enter number of travellers\n");
            scanf("%d",&t);
            printf("Total price = %d", 100000*t);
            break;
        }
        default:
        {
            printf("Invalid Selection\n");
            break;
        }
    }
}
void booking()
{
    printf("Enter name\n");
    scanf("%s",&obj1.name);
    printf("Enter your age\n");
    scanf("%d",&obj1.age);
    printf("Enter Gender\n");
    scanf("%s",&obj1.gender);

    printf("Name : %s\n",obj1.name);
    printf("Age : %d\n",obj1.age);
    printf("Gender : %s\n",obj1.gender);
}
void heading()
{
    printf("\n1=Display Service\n");
    printf("2=Booking\n");
    printf("3=Display Ticket\n");
    printf("4=Exit\n");
    options();
}
int options()
{
    int select;
    printf("\nSelect option\n");
    scanf("%d",&select);

       switch(select)
    {
        case 1:
        {
            display_service();
            heading();
            break;
        }
        case 2:
        {
            booking();
            heading();
            break;
        }
        case 3:
        {
            struct booking obj2;
            
            printf("Enter name\n");
            scanf("%s",&obj2.name);
            printf("Enter your age\n");
            scanf("%d",&obj2.age);
            printf("Enter Gender\n");
            scanf("%s",&obj2.gender);

            printf("\n$$$$$$**TICKET**$$$$$$$\n");
            printf("Name : %s\n",obj2.name);
            printf("Age : %d\n",obj2.age);
            printf("Gender : %s\n",obj2.gender);
            heading();
            options();
            break;
        }
        case 4:
        {
            exit(0);
        }
        default:
        {
            printf("Invalid Selection\n");
        }
    }  
}