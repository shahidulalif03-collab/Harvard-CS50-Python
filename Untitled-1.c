#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Function Prototypes
void gotoxy(int x, int y);
void viewAllOrders();
void searchOrder();
void generateSalesReport();
void reportMenu();

// gotoxy Function
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// View all orders
void viewAllOrders()
{
    FILE *fp;
    int orderId;
    char customer[50];
    float total;

    fp = fopen("orders.txt", "r");

    if (fp == NULL)
    {
        gotoxy(17,2);
        printf("No order records found!\n");
        return;
    }

    system("cls");

    gotoxy(17,2);
    printf("========== ALL ORDERS ==========");

    gotoxy(5,4);
    printf("%-10s %-20s %-10s", "Order ID", "Customer", "Total");

    int row = 6;

    while (fscanf(fp, "%d %s %f", &orderId, customer, &total) == 3)
    {
        gotoxy(5,row++);
        printf("%-10d %-20s %.2f", orderId, customer, total);
    }

    fclose(fp);

    gotoxy(5,row+2);
    printf("Press Enter to return...");
    getchar();
    getchar();
}

// Search Order
void searchOrder()
{
    FILE *fp;
    int searchId;
    int orderId;
    char customer[50];
    float total;
    int found = 0;

    fp = fopen("orders.txt", "r");

    if (fp == NULL)
    {
        gotoxy(17,2);
        printf("No order records found!");
        return;
    }

    system("cls");

    gotoxy(17,2);
    printf("========== SEARCH ORDER ==========");

    gotoxy(17,4);
    printf("Enter Order ID: ");
    scanf("%d", &searchId);

    while (fscanf(fp,"%d %s %f",&orderId,customer,&total)==3)
    {
        if(orderId==searchId)
        {
            gotoxy(17,6);
            printf("Order Found");

            gotoxy(17,8);
            printf("Order ID : %d",orderId);

            gotoxy(17,9);
            printf("Customer : %s",customer);

            gotoxy(17,10);
            printf("Total    : %.2f",total);

            found=1;
            break;
        }
    }

    if(!found)
    {
        gotoxy(17,6);
        printf("Order not found!");
    }

    fclose(fp);

    gotoxy(17,13);
    printf("Press Enter to return...");
    getchar();
    getchar();
}

// Sales Report
void generateSalesReport()
{
    FILE *fp;
    int orderId;
    char customer[50];
    float total;

    int totalOrders = 0;
    float totalSales = 0;

    fp = fopen("orders.txt","r");

    if(fp==NULL)
    {
        gotoxy(17,2);
        printf("No order records found!");
        return;
    }

    while(fscanf(fp,"%d %s %f",&orderId,customer,&total)==3)
    {
        totalOrders++;
        totalSales += total;
    }

    fclose(fp);

    system("cls");

    gotoxy(17,2);
    printf("========== SALES REPORT ==========");

    gotoxy(17,5);
    printf("Total Orders : %d",totalOrders);

    gotoxy(17,6);
    printf("Total Sales  : %.2f",totalSales);

    gotoxy(17,9);
    printf("Press Enter to return...");
    getchar();
    getchar();
}

// Report Menu
void reportMenu()
{
    int choice;

    do
    {
        system("cls");

        gotoxy(17,2);
        printf("========== REPORT MENU ==========");

        gotoxy(17,4);
        printf("1. View All Orders");

        gotoxy(17,5);
        printf("2. Search Order");

        gotoxy(17,6);
        printf("3. Generate Sales Report");

        gotoxy(17,7);
        printf("4. Exit");

        gotoxy(17,9);
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                viewAllOrders();
                break;

            case 2:
                searchOrder();
                break;

            case 3:
                generateSalesReport();
                break;

            case 4:
                system("cls");
                gotoxy(17,2);
                printf("Exiting Report Menu...");
                break;

            default:
                gotoxy(17,11);
                printf("Invalid Choice!");
                getchar();
                getchar();
        }

    }while(choice!=4);
}

// Main Function
int main()
{
    reportMenu();
    return 0;
}