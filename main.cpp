#include"customer.h"
#include"medicine.h"
#include"supplier.h"
#include"about.h"
#include"Billing.h"

int main()
{	
	int choice;	
	do{
			
		printf("\n---------------------------");
		printf("\n1) Customer Information");
		printf("\n2) Medicine");
		printf("\n3) Supplier Information");
		printf("\n4) Billing");
		printf("\n5) About ");
		printf("\n6) Exit");
		printf("\n---------------------------");
		printf("\nEnter your Choice: ");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1: {
						customer();
						break;
					}	
			case 2: {
						medicine();
						break;
					}
			case 3: {
						supplier();
						break;
					}
			case 4: {
						bill();
						break;
					}
			case 5: {
						about();
						break;
					}
			case 6: {
						printf("\nThank you...");
						break;
					}		
			default:printf("Enter correct choice...");
		}
	}while(choice!=6);
	return 0;
}
