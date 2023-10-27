#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void bill()
{
	system("cls");
	char m_id1[50],m_name1[50],pur_date1[15],exp_date1[15],manu_date1[15],bill_no1[15],comp_name1[50],supp_name1[50];
	int r_no1,c_no1,quantity1,sale1,total1,unit1,qty1,Bye1,flag=1;
	float cost1,profit1;
	
	int billno,medi_qty,Day,Month,Year;
	char cname[50],mediname[50];
	float medi_rate,Total;
	
	FILE *bill=fopen("billDetails.txt","a");
	FILE *m_list=fopen("MedicineDetails.txt","r");
	
	printf("\nEnter bill number: ");
	scanf("%d",&billno);
	fprintf(bill,"%d\t",billno);
	
	printf("\nEnter customer name: ");
	fflush(stdin);
	gets(cname);
	fprintf(bill,"%s\t",cname);
	
	printf("\nEnter medicine name or id: ");
	gets(mediname);
	fprintf(bill,"%s\t",mediname);
	
	printf("\nEnter medicine quantity: ");
	scanf("%d",&medi_qty);
	fprintf(bill,"%d\t",medi_qty);
	
	while(fscanf(m_list,"%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%f\t%d\t%f\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",&m_id1,&m_name1,&r_no1,&c_no1,&quantity1,&sale1,
																								&total1,&unit1,&cost1,&Bye1,&profit1,&qty1,&pur_date1,
																								&exp_date1,&manu_date1,&bill_no1,&comp_name1,&supp_name1)!=EOF)
	{
		if(strcmp(mediname,m_id1)==0 ||strcmp(mediname,m_name1)==0)
		{
			if(medi_qty>qty1)
			{
				printf("This much quantity of medicine is not available");
				return;
			}
			medi_rate=cost1;
			flag=0;
		}
	}
	if(flag==1)
	{
		printf("Medicine not found...");
		return;
	}
	fprintf(bill,"%.3f\t",medi_rate);
	
	Total=medi_qty*medi_rate;
	fprintf(bill,"%.3f\t",Total);
	
	printf("\nEnter date (DD MM YYYY): ");
	scanf("%d%d%d",&Day,&Month,&Year);
	fprintf(bill,"%d %d %d\n",Day,Month,Year);
	
	fclose(bill);
	fclose(m_list);
	
	printf("%d\t%s\t%s\t%d\t%.3f\t%.3f\t%d/%d/%d",billno,cname,mediname,medi_qty,medi_rate,Total,Day,Month,Year);
	
}
