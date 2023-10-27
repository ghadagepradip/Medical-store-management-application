#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void update_stock()
{
	system("cls");
	char m_id1[50],m_name1[50],pur_date1[15],exp_date1[15],manu_date1[15],bill_no1[15],comp_name1[50],supp_name1[50];
	int r_no1,c_no1,quantity1,sale1,total1,unit1,qty1,Bye1;
	float cost1,profit1;
	char s_in[50];
	int flag=1;
	
	FILE *f_ori=fopen("MedicineDetails.txt","r");
	FILE *f_cop=fopen("MedicineDetails1.txt","w"); 
	
	printf("Enter the id of medicine you want to update: ");
	scanf("%s",&s_in);
	
	while(fscanf(f_ori,"%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%f\t%d\t%f\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",&m_id1,&m_name1,&r_no1,&c_no1,&quantity1,&sale1,
																								&total1,&unit1,&cost1,&Bye1,&profit1,&qty1,&pur_date1,
																								&exp_date1,&manu_date1,&bill_no1,&comp_name1,&supp_name1)!=EOF)
	{
		if(strcmp(m_id1,s_in)==0 )
		{
			int sold_q=0,bye_q=0,option;
			
			fprintf(f_cop,"%s\t",m_id1);
	
			fprintf(f_cop,"%s\t",m_name1);
	
			fprintf(f_cop,"%d\t",r_no1);
	
			fprintf(f_cop,"%d\t",c_no1);
	
			fprintf(f_cop,"%d\t",quantity1);
			
			printf("\nHave you sold this medicine 1)yes 2)No: ");
			scanf("%d",&option);
			if(option==1)
			{
				printf("\nEnter quantity sold : ");			
				scanf("%d",&sold_q);
				fprintf(f_cop,"%d\t",sale1+sold_q);
			}
			else
			{
				fprintf(f_cop,"%d\t",sale1);
			}
			
			fprintf(f_cop,"%d\t",total1-sold_q);
	
			fprintf(f_cop,"%d\t",unit1);
	
			fprintf(f_cop,"%.2f\t",cost1);
			
			printf("\nHave you purchased this medicine 1)yes 2)No: ");
			scanf("%d",&option);
			if(option==1)
			{
				printf("\nEnter quantity purchased: ");			
				scanf("%d",&bye_q);
				fprintf(f_cop,"%d\t",Bye1+bye_q);
			}
			else
			{
				fprintf(f_cop,"%d\t",Bye1);
			}
	
			fprintf(f_cop,"%.2f\t",profit1);		
			
			fprintf(f_cop,"%d\t",qty1+bye_q+total1-sold_q);
	
			fprintf(f_cop,"%s\t",pur_date1);
	
			fprintf(f_cop,"%s\t",exp_date1);
	
			fprintf(f_cop,"%s\t",manu_date1);
	
			fprintf(f_cop,"%s\t",bill_no1);
	
			printf("\nEnter company name: ");
			scanf("%s",&comp_name1);
			fprintf(f_cop,"%s\t",comp_name1);
	
			printf("\nEnter supplier name: ");
			scanf("%s",&supp_name1);
			fprintf(f_cop,"%s\n",supp_name1);
			
			flag=0;
		}
		else
		{
			fprintf(f_cop,"%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%.2f\t%d\t%.2f\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",m_id1,m_name1,r_no1,c_no1,quantity1,sale1,
																								total1,unit1,cost1,Bye1,profit1,qty1,pur_date1,
																								exp_date1,manu_date1,bill_no1,comp_name1,supp_name1);
		}
	}
	if(flag==1)
	{
		printf("Medicine not found...");
	}
	
	fclose(f_ori);
	fclose(f_cop);
	remove("MedicineDetails.txt");
	rename("MedicineDetails1.txt","MedicineDetails.txt");
	
}

void medi_entry()
{
	system("cls");
	char m_id[50],m_name[50],pur_date[15],exp_date[15],manu_date[15],bill_no[15],comp_name[50],supp_name[50];
	int r_no,c_no,quantity,sale=0,total,unit,qty=0,Bye=0;
	float cost,profit;
	
	FILE *entry=fopen("MedicineDetails.txt","a");
	
	printf("\nEnter medicine id: ");
	scanf("%s",&m_id);
	fprintf(entry,"%s\t",m_id);
	
	printf("\nEnter medicine name: ");
	scanf("%s",&m_name);
	fprintf(entry,"%s\t",m_name);
	
	printf("\nEnter Rack number: ");
	scanf("%d",&r_no);
	fprintf(entry,"%d\t",r_no);
	
	printf("\nEnter Cabinet: ");
	scanf("%d",&c_no);
	fprintf(entry,"%d\t",c_no);
	
	printf("\nEnter capacity of cabinet: ");
	scanf("%d",&quantity);
	fprintf(entry,"%d\t",quantity);
	
	fprintf(entry,"%d\t",sale);
	
	printf("\nEnter total quantity: ");			
	scanf("%d",&total);
	fprintf(entry,"%d\t",total);
	
	printf("\nEnter units in 1 quantity: ");
	scanf("%d",&unit);
	fprintf(entry,"%d\t",unit);
	
	printf("\nEnter cost of 1 quantity: ");
	scanf("%f",&cost);
	fprintf(entry,"%.2f\t",cost);

	fprintf(entry,"%d\t",Bye);
	
	printf("\nEnter profit percentage: ");
	scanf("%f",&profit);
	fprintf(entry,"%.2f\t",profit);		//%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%f\t%f\t%f\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n
	
	fprintf(entry,"%d\t",qty);
	
	printf("\nEnter purchase date: ");
	scanf("%s",&pur_date);
	fprintf(entry,"%s\t",pur_date);
	
	printf("\nEnter Expiry date: ");
	scanf("%s",&exp_date);
	fprintf(entry,"%s\t",exp_date);
	
	printf("\nEnter manufacturing date: ");
	scanf("%s",&manu_date);
	fprintf(entry,"%s\t",manu_date);
	
	printf("\nEnter Bill number: ");
	scanf("%s",&bill_no);
	fprintf(entry,"%s\t",bill_no);
	
	printf("\nEnter company name: ");
	scanf("%s",&comp_name);
	fprintf(entry,"%s\t",comp_name);
	
	printf("\nEnter supplier name: ");
	scanf("%s",&supp_name);
	fprintf(entry,"%s\n",supp_name);
		
	fclose(entry);
}

void medi_sale()
{
	system("cls");
	char m_id1[50],m_name1[50],pur_date1[15],exp_date1[15],manu_date1[15],bill_no1[15],comp_name1[50],supp_name1[50];
	int r_no1,c_no1,quantity1,sale1,total1,unit1,qty1,Bye1,flag=0;
	float cost1,profit1;
	
	FILE *m_sale=fopen("MedicineDetails.txt","r");
	
	while(fscanf(m_sale,"%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%f\t%d\t%f\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",&m_id1,&m_name1,&r_no1,&c_no1,&quantity1,&sale1,
																								&total1,&unit1,&cost1,&Bye1,&profit1,&qty1,&pur_date1,
																								&exp_date1,&manu_date1,&bill_no1,&comp_name1,&supp_name1)!=EOF)
	{
		if(sale1!=0)
		{
			printf("Id=%s\tName=%s\tSold quantity=%d\tQuantity remaining=%d\tProfit Earned=%f",m_id1,m_name1,sale1,qty1,(sale1*cost1*profit1/100));
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("No sale until now...");
	}
	
	fclose(m_sale);
	
}

void medi_search()
{
	system("cls");
	char m_id1[50],m_name1[50],pur_date1[15],exp_date1[15],manu_date1[15],bill_no1[15],comp_name1[50],supp_name1[50];
	int r_no1,c_no1,quantity1,sale1,total1,unit1,qty1,Bye1;
	float cost1,profit1;
	char s_in[50];
	int flag=1;
	
	FILE *search=fopen("MedicineDetails.txt","r");
	
	printf("Enter the id of medicine you want to search:");
	scanf("%s",&s_in);
	
	while(fscanf(search,"%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%f\t%d\t%f\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",&m_id1,&m_name1,&r_no1,&c_no1,&quantity1,&sale1,
																								&total1,&unit1,&cost1,&Bye1,&profit1,&qty1,&pur_date1,
																								&exp_date1,&manu_date1,&bill_no1,&comp_name1,&supp_name1)!=EOF)
	{
		if(strcmp(m_id1,s_in)==0 )
		{
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%.2f\t%d\t%.2f\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",m_id1,m_name1,r_no1,c_no1,quantity1,sale1,total1,unit1,cost1,Bye1,
																								profit1,qty1,pur_date1,exp_date1,manu_date1,bill_no1,comp_name1,supp_name1);
			flag=0;
		}		
	}
	if(flag==1)
	{
		printf("Medicine not found...");
	}
	
	fclose(search);
	
}

void stock()
{
	system("cls");
	char m_id1[50],m_name1[50],pur_date1[15],exp_date1[15],manu_date1[15],bill_no1[15],comp_name1[50],supp_name1[50];
	int r_no1,c_no1,quantity1,sale1,total1,unit1,qty1,Bye1;
	float cost1,profit1;
	
	FILE *m_list=fopen("MedicineDetails.txt","r");
	
	while(fscanf(m_list,"%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%f\t%d\t%f\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",&m_id1,&m_name1,&r_no1,&c_no1,&quantity1,&sale1,
																								&total1,&unit1,&cost1,&Bye1,&profit1,&qty1,&pur_date1,
																								&exp_date1,&manu_date1,&bill_no1,&comp_name1,&supp_name1)!=EOF)
	{
		printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%.2f\t%d\t%.2f\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",m_id1,m_name1,r_no1,c_no1,quantity1,sale1,total1,unit1,cost1,Bye1,
																								profit1,qty1,pur_date1,exp_date1,manu_date1,bill_no1,comp_name1,supp_name1);
	}
	
	fclose(m_list);
}

void medicine()
{
	int med_choice;
	do
	{
		printf("\nx------------x-------------x");
		printf("\n1) Update medicine stock");
		printf("\n2) Add/Enter new medicine");
		printf("\n3) Medicine sale");
		printf("\n4) Search Medicine");
		printf("\n5) Stock of medicine");
		printf("\n6) Exit");
		printf("\nx------------x-------------x");
		printf("\nEnter your Choice: ");
		scanf("%d",&med_choice);
	
		switch(med_choice)
		{
			case 1: {
						update_stock();
						break;
					}
			case 2: {
						medi_entry();
						break;
					}
			case 3: {
						medi_sale();
						break;
					}
			case 4: {
						medi_search();
						break;
					}
			case 5: {
						stock();
						break;
					}
			case 6: {
						break;
					}
			default:printf("Enter correct choice...");	
		}
	}while(med_choice!=6);
}
