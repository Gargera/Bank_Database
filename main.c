#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bank_Database.h"

customer_t customers[MaxCustomers];

int main()
{

    DeleteALLCustomers();
    int choice;

    while(1){
        printf("please select one of the following options: \n\n1- create a new customer (press 1 to select this option)\n2- edit customer (press 2 to select this option )\n3- delete customer (press 3 to select this option)\n4- print customer data (press 4 to select this option)\n5- cash transfer from customer to another (press 5 t select this option)\n6- exit (press 6 to select this option)\n\nplease enter your choice: ");
        fflush(stdin);
        scanf("%i" , &choice);

        if(choice == 1){
            Create_New_Customer();
        }
        else if(choice == 2){
            Edit_Customer();
        }
        else if(choice == 3){
            Delete_Customer_Data();
        }
        else if(choice == 4){
            Print_Customer();
        }
        else if(choice == 5){
            transfer_money();
        }
        else if(choice == 6){
            exit(0);
        }
        else{
           printf("Wrong choice\n\n");
        }
    }

    return 0;
}
