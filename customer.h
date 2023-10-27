#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void search_cid()
{
	system("cls");
	
	char c_id[50],c_name[50],c_name1[50],c_city[25],c_mob[10],c_email[50];
	char s_id[50];
	int flag=0;
	fflush(stdin);
	printf("Enter the id of customer:");
	gets(s_id);
	
	FILE *search=fopen("CustomerDetails.txt","r");
	
	while(fscanf(search,"%s\t%s%s\t\t%s\t\t%s\t%s",&c_id,&c_name,&c_name1,&c_city,&c_mob,&c_email)!=EOF)
	{
		if(strcmp(c_id,s_id)==0)
		{
			printf("%s\t%s %s\t\t%s\t\t%s\t%s\n",c_id,c_name,c_name1,c_city,c_mob,c_email);	
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("Customer id not found...");
	}
	fclose(search);
		
}

void search_cname()
{
	system("cls");
	char c_id[50],c_name[50],c_name1[50],c_city[25],c_mob[10],c_email[50];
	char s_namei[50],s_name[50];
	int flag=0;
	fflush(stdin);
	printf("Enter the name of customer:");
	scanf("%s %s",&s_namei,&s_name);
	
	FILE *search=fopen("CustomerDetails.txt","r");
	
	while(fscanf(search,"%s\t%s%s\t\t%s\t\t%s\t%s",&c_id,&c_name,&c_name1,&c_city,&c_mob,&c_email)!=EOF)
	{	
		if(strcmp(s_namei,c_name)==0 &&strcmp(s_name,c_name1)==0)
		{
			printf("%s\t%s %s\t\t%s\t\t%s\t%s\n",c_id,c_name,c_name1,c_city,c_mob,c_email);	
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("Customer name not found...");
	}
	
}

void cust_entry()
{
	system("cls");
	char c_id[50],c_name[50],c_city[25],c_mob[10],c_email[50];
		
	FILE *entry=fopen("CustomerDetails.txt","a");
	
	printf("\nEnter customer id: ");
	scanf("%s",&c_id);
	fprintf(entry,"%s\t",c_id);
	
	fflush(stdin);
	printf("\nEnter customer name: ");
	gets(c_name);
	fprintf(entry,"%s\t\t",c_name);
	
	printf("\nEnter customer city: ");
	scanf("%s",&c_city);
	fprintf(entry,"%s\t\t",c_city);
	
	do
	{
		printf("\nEnter customer Mobile number: ");
		scanf("%s",&c_mob);
		if(strlen(c_mob)!=10)
		{
			printf("Enter 10 Digit mobile number...");
		}
	}while(strlen(c_mob)!=10);
	fprintf(entry,"%s\t",c_mob);
	
	printf("\nEnter customer Email: ");
	scanf("%s",&c_email);
	fprintf(entry,"%s\n",c_email);
		
	fclose(entry);
	
}

void cust_list()
{
	system("cls");
	char c_id[50],c_name[50],c_name1[50],c_city[25],c_mob[10],c_email[50];
	
	FILE *c_list=fopen("CustomerDetails.txt","r");
	
	while(fscanf(c_list,"%s\t%s%s\t\t%s\t\t%s\t%s",&c_id,&c_name,&c_name1,&c_city,&c_mob,&c_email)!=EOF)
	{
		printf("%s\t%s %s\t\t%s\t\t%s\t%s\n",c_id,c_name,c_name1,c_city,c_mob,c_email);
	}
	
	fclose(c_list);
}

void cust_update()
{
	system("cls");
	char c_id[50],c_name[50],c_name1[50],c_city[25],c_mob[10],c_email[50];
	char u_id[50];
	
	FILE *f_ori=fopen("CustomerDetails.txt","r");
	FILE *f_cop=fopen("CustomerDetails1.txt","w");
	
	printf("Enter the id of customer which you want to update:");
	scanf("%s",&u_id);
	
	while(fscanf(f_ori,"%s\t%s%s\t\t%s\t\t%s\t%s",&c_id,&c_name,&c_name1,&c_city,&c_mob,&c_email)!=EOF)
	{
		if(strcmp(c_id,u_id)==0)
		{
			fflush(stdin);
			fprintf(f_cop,"%s\t",c_id);
			
			printf("\nEnter updated customer name: ");
			gets(c_name);
			fprintf(f_cop,"%s\t\t",c_name);
	
			printf("\nEnter updated customer city: ");
			scanf("%s",&c_city);
			fprintf(f_cop,"%s\t\t",c_city);
	
			do
			{
				printf("\nEnter updated customer Mobile number: ");
				scanf("%s",&c_mob);
				if(strlen(c_mob)!=10)
				{
					printf("Enter 10 Digit mobile number...");
				}
			}while(strlen(c_mob)!=10);
			fprintf(f_cop,"%s\t",c_mob);
	
			printf("\nEnter updated customer Email: ");
			scanf("%s",&c_email);
			fprintf(f_cop,"%s\n",c_email);
		}
		else
		{
			fprintf(f_cop,"%s\t%s %s\t\t%s\t\t%s\t%s\n",c_id,c_name,c_name1,c_city,c_mob,c_email);	
		}
	}
	
	fclose(f_ori);
	fclose(f_cop);
	remove("CustomerDetails.txt");
	rename("CustomerDetails1.txt","CustomerDetails.txt");
	
}

void customer()
{
	int cust_choice;
	do
	{
		
		printf("\nx------------x-------------x");
		printf("\n1) Search Customer");
		printf("\n2) Enter new Customer");
		printf("\n3) List all Customer");
		printf("\n4) Update Customer");
		printf("\n5) Exit");
		printf("\nx------------x-------------x");
		printf("\nEnter your Choice: ");
		scanf("%d",&cust_choice);
	
		switch(cust_choice)
		{
			case 1: {
						int ch;
						printf("\n1.Search by id\n2.search by name\nEnter your choice: ");
						scanf("%d",&ch);
						(ch==1)?search_cid():search_cname();
						break;
					}
			case 2: {
						cust_entry();
						break;
					}
			case 3: {
						cust_list();
						break;
					}
			case 4: {
						cust_update();
						break;
					}
			case 5: {
						break;
					}
			default:printf("Enter correct choice...");	
		}
	}while(cust_choice!=5);
}
