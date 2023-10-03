#ifndef Bank
#define Bank
#define MaxCustomers (int)1e6

typedef struct {

   double cash;
   int id;
   char name[50];
   char type[7];

}customer_t;

void DeleteALLCustomers();
int Create_New_Customer();
int ifExist(int id , int idx);
void transfer_money();
void Print_Customer();
void Delete_Customer_Data();
void Edit_Customer();

#endif

