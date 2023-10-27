#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void supp_entry()
{
	system("cls");
	char s_id[50],s_name[50],s_city[25],s_mob[10],s_email[50];
		
	FILE *entry=fopen("SupplierDetails.txt","a");
	
	printf("\nEnter supplier id: ");
	scanf("%s",&s_id);
	fprintf(entry,"%s\t",s_id);
	
	fflush(stdin);
	printf("\nEnter supplier name: ");
	gets(s_name);
	fprintf(entry,"%s\t\t",s_name);
	
	printf("\nEnter supplier city: ");
	scanf("%s",&s_city);
	fprintf(entry,"%s\t\t",s_city);
	
	do
	{
		printf("\nEnter supplier Mobile number: ");
		scanf("%s",&s_mob);
		if(strlen(s_mob)!=10)
		{
			printf("Enter 10 Digit mobile number...");
		}
	}while(strlen(s_mob)!=10);
	fprintf(entry,"%s\t",s_mob);
	
	printf("\nEnter supplier Email: ");
	scanf("%s",&s_email);
	fprintf(entry,"%s\n",s_email);
		
	fclose(entry);
	
}

void supp_list()
{
	system("cls");
	char s_id[50],s_name[50],s_name1[50],s_city[25],s_mob[10],s_email[50];
	
	FILE *s_list=fopen("SupplierDetails.txt","r");
	
	while(fscanf(s_list,"%s\t%s%s\t\t%s\t\t%s\t%s",&s_id,&s_name,&s_name1,&s_city,&s_mob,&s_email)!=EOF)
	{
		printf("%s\t%s %s\t\t%s\t\t%s\t%s\n",s_id,s_name,s_name1,s_city,s_mob,s_email);
	}
	
	fclose(s_list);
}

void sup_update()
{
	system("cls");
	char s_id[50],s_name[50],s_name1[50],s_city[25],s_mob[10],s_email[50];
	char u_id[50];
	
	FILE *f_ori=fopen("SupplierDetails.txt","r");
	FILE *f_cop=fopen("SupplierDetails1.txt","w");
	
	printf("Enter the id of supplier which you want to update:");
	scanf("%s",&u_id);
	
	while(fscanf(f_ori,"%s\t%s%s\t\t%s\t\t%s\t%s",&s_id,&s_name,&s_name1,&s_city,&s_mob,&s_email)!=EOF)
	{
		if(strcmp(s_id,u_id)==0)
		{
			fflush(stdin);
			fprintf(f_cop,"%s\t",s_id);
			
			printf("\nEnter updated supplier name: ");
			gets(s_name);
			fprintf(f_cop,"%s\t\t",s_name);
	
			printf("\nEnter updated supplier city: ");
			scanf("%s",&s_city);
			fprintf(f_cop,"%s\t\t",s_city);
	
			do
			{
				printf("\nEnter updated supplier Mobile number: ");
				scanf("%s",&s_mob);
				if(strlen(s_mob)!=10)
				{
					printf("Enter 10 Digit mobile number...");
				}
			}while(strlen(s_mob)!=10);
			fprintf(f_cop,"%s\t",s_mob);
	
			printf("\nEnter updated supplier Email: ");
			scanf("%s",&s_email);
			fprintf(f_cop,"%s\n",s_email);
		}
		else
		{
			fprintf(f_cop,"%s\t%s %s\t\t%s\t\t%s\t%s\n",s_id,s_name,s_name1,s_city,s_mob,s_email);	
		}
	}
	
	fclose(f_ori);
	fclose(f_cop);
	remove("SupplierDetails.txt");
	rename("SupplierDetails1.txt","SupplierDetails.txt");
	
}

void search_sid()
{
	system("cls");
	
	char s_id[50],s_name[50],s_name1[50],s_city[25],s_mob[10],s_email[50];
	char sl_id[50];
	int flag=0;
	fflush(stdin);
	printf("Enter the id of supplier:");
	gets(sl_id);
	
	FILE *search=fopen("SupplierDetails.txt","r");
	
	while(fscanf(search,"%s\t%s%s\t\t%s\t\t%s\t%s",&s_id,&s_name,&s_name1,&s_city,&s_mob,&s_email)!=EOF)
	{
		if(strcmp(s_id,sl_id)==0)
		{
			printf("%s\t%s %s\t\t%s\t\t%s\t%s\n",s_id,s_name,s_name1,s_city,s_mob,s_email);	
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("Customer id not found...");
	}
	fclose(search);
	
}

void search_sname()
{
	system("cls");
	char s_id[50],s_name[50],s_name1[50],s_city[25],s_mob[10],s_email[50];
	char si_name[50],se_name[50];
	int flag=0;
	fflush(stdin);
	printf("Enter the name of customer:");
	scanf("%s %s",&si_name,&se_name);
	
	FILE *search=fopen("SupplierDetails.txt","r");
	
	while(fscanf(search,"%s\t%s%s\t\t%s\t\t%s\t%s",&s_id,&s_name,&s_name1,&s_city,&s_mob,&s_email)!=EOF)
	{	
		if(strcmp(si_name,s_name)==0 &&strcmp(se_name,s_name1)==0)
		{
			printf("%s\t%s %s\t\t%s\t\t%s\t%s\n",s_id,s_name,s_name1,s_city,s_mob,s_email);	
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("Customer name not found...");
	}
	fclose(search);
}


void supplier()
{
	int sup_choice;
	do
	{
		
		printf("\nx------------x-------------x");
		printf("\n1) Enter new supplier");
		printf("\n2) List of all supplier");
		printf("\n3) Update supplier");
		printf("\n4) Search supplier");
		printf("\n5) Exit");
		printf("\nx------------x-------------x");
		printf("\nEnter your Choice: ");
		scanf("%d",&sup_choice);
	
		switch(sup_choice)
		{
			case 1: {
						supp_entry();
						break;
					}
			case 2: {
						supp_list();
						break;
					}
			case 3: {
						sup_update();
						break;
					}
			case 4: {
						int ch;
						printf("\n1.Search by id\n2.search by name.\nEnter your choice: ");
						scanf("%d",&ch);
						(ch==1)?search_sid():search_sname();
						break;
					}
			case 5: {
						break;
					}
			default:printf("Enter correct choice...");	
		}
	}while(sup_choice!=5);
}
