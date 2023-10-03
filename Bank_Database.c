#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bank_Database.h"

extern customer_t customers[MaxCustomers];

void DeleteALLCustomers(){
   for(int i = 0 ; i < MaxCustomers ; i++){
      customers[i].cash = -1;
      customers[i].id = -1;
      strcpy(customers[i].name , "-1");
      strcpy(customers[i].type , "-1");
   }
}

int ifExist(int id , int idx){
    for(int i = 0 ; i < MaxCustomers ; i++){
        if(customers[i].id == id && i != idx) return i;
    }
    return -1;
}

int Create_New_Customer(){
    int idx = -1;
    for(int i = 0 ; i < MaxCustomers ; i++){
        if(customers[i].id == -1){
            idx = i;
            break;
        }
    }

    if(idx == -1){
       printf("the maximum number of customers is %i so you can't add anymore\n" , MaxCustomers);
    }
    else{
        customer_t new_customer;

        printf("please enter the name of the customer: ");
        fflush(stdin);
        gets(new_customer.name);

        printf("please enter the type of the customer (debit or credit): ");
        fflush(stdin);
        gets(new_customer.type);

        printf("please enter the id of the customer: ");
        while(1){
            scanf("%i",&(new_customer.id));

            if(ifExist(new_customer.id , -1) != -1){
                printf("Sorry, The id %i is Unavailable, enter another one: " , new_customer.id);
            }
            else{
                break;
            }
        }

        while(1){
            printf("please enter the cash of the customer: ");
            scanf("%lf",&(new_customer.cash));

            if(new_customer.cash < 0){
                printf("the cash money should be positive number and greater than or equal to zero\n");
            }
            else{
                break;
            }
        }

        printf("\n\n");
        customers[idx] = new_customer;
    }
}

void Edit_Customer(){
    int id , idx;
    printf("please enter the id of the customer who you need to change its data: ");
    while(1){
        scanf("%i",&id);

        idx = ifExist(id , -1);
        if(idx == -1){
            printf("Wrong id, try to enter it again: ");
        }
        else{
            break;
        }
    }

    printf("please enter the new name: ");
    fflush(stdin);
    gets(customers[idx].name);

    printf("please enter the new cash: ");
    while(1){
        scanf("%lf",&(customers[idx].cash));

        if(customers[idx].cash < 0){
            printf("the cash money should be positive number and greater than or equal to zero, try to enter it again: ");
        }
        else{
            break;
        }
    }

    printf("please enter the new type (Debit or credit): ");
    fflush(stdin);
    gets(customers[idx].type);

    printf("please enter the new id: ");
    while(1){
        scanf("%i",&(customers[idx].id));

        if(ifExist(customers[idx].id , idx) != -1){
            printf("Sorry, The id %i is Unavailable, enter another one: " , customers[idx].id);
        }
        else{
            break;
        }
    }

    printf("\n\n");
}

void Delete_Customer_Data(){
    int id , idx;
    printf("please enter the id of the customer who you need to delete its data: ");
    while(1){
        scanf("%i",&id);

        idx = ifExist(id , -1);
        if(idx == -1){
            printf("Wrong id, try to enter it again: ");
        }
        else{
            break;
        }
    }

    customers[idx].id = -1;
    customers[idx].cash = -1;
    strcpy(customers[idx].name , "-1");
    strcpy(customers[idx].type , "-1");
}

void Print_Customer(){
    int id , idx;
    printf("please enter the id of the customer who you need to print its data: ");
    while(1){
        scanf("%i",&id);

        idx = ifExist(id , -1);
        if(idx == -1){
            printf("Wrong id, try to enter it again: ");
        }
        else{
            break;
        }
    }

    printf("the name of the customer is : %s\n" , customers[idx].name);
    printf("the cash of the customer is : %0.2lf\n" , customers[idx].cash);
    printf("the type of the customer is : %s\n" , customers[idx].type);
    printf("the id of the customer is : %i\n" , customers[idx].id);
    printf("\n\n");
}

void transfer_money(){
    int id_from , idx_from;
    printf("please enter the id of the customer who the money will transfer from his cash: ");
    while(1){
        scanf("%i",&id_from);

        idx_from = ifExist(id_from , -1);
        if(idx_from == -1){
            printf("Wrong id, try to enter it again: ");
        }
        else{
            break;
        }
    }

    int id_to , idx_to;
    printf("please enter the id of the customer who the money will transfer to his cash: ");
    while(1){
        scanf("%i",&id_to);

        idx_to = ifExist(id_to , -1);
        if(idx_to == -1){
            printf("Wrong id, try to enter it again: ");
        }
        else{
            break;
        }
    }

    double MoneyTransfered;
    printf("please enter the money which will be transfered: ");
    while(1){
        scanf("%lf" , &MoneyTransfered);

        if(MoneyTransfered > customers[idx_from].cash){
            printf("the customer who the money will transfer from his cash hasn't have enough money, try to enter smaller amount: ");
        }
        else{
            break;
        }
    }

    customers[idx_from].cash -= MoneyTransfered;
    customers[idx_to].cash += MoneyTransfered;
}

