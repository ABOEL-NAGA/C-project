#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct nodeDATA
{
	
	unsigned int BankID;
	
	int accPOINTER;
	
};
struct node 
{
	
	struct nodeDATA data;
	struct node* nodePTR;
	
};


struct node* head=NULL;

 struct information
{
char name[30];
char address[30];
long long  NationalID;
int age;

char gaurdian[30];
long long gaurdianID;
int status;
int balance;
unsigned int PASSWORD;

};




void create_new_acc(void);
void add_acc_data(int id, int pointer);
void admin_window(void);
void client_window(void);
int search_accPTR(unsigned int ID);
int search_accPASS(unsigned int ID);
bool check_national_id(long long ID);

void main(void)
{char adminORclient;
	
	printf("for admin window press 1\nfor client window press2\n");
	scanf("%d",&adminORclient);
	if(adminORclient==1)
		admin_window();
	else if(adminORclient==2)
		client_window();
	
		
	
		
	
}	




void create_new_acc(void)
{
	
	struct information* account=(struct information*) malloc(sizeof(struct information));
  int PtrToAcc=account;
  unsigned	 int ID;
  unsigned int PASSWORD;
	printf("please enter your name\n");
	gets(account->name);
	printf("enter your address\n");
	gets(account->address);
	printf("enter your national ID\n");
	
	scanf("%lld",&account->NationalID);
	while(!check_national_id(account->NationalID))
	{
		printf("the ID  you entered is wrong,please enter again\n");
		scanf("%lld",&account->NationalID);
		
		
	}
		
	printf("enter your age\n");
	scanf("%d",&account->age);
	
	if(account->age<21)
	{
		int c;
		while((c= getchar()) != '\n' && c != EOF);
		printf("enter the guardian name\n");
			gets(account->gaurdian);
		printf("enter the gaurdian ID\n");
		
		scanf("%lld",&account->gaurdianID);
		while(!check_national_id(account->gaurdianID))
	{
		printf("the ID  you entered is wrong,please enter again\n");
		scanf("%lld",&account->gaurdianID);
		
	}
		
	}
	
	account->balance=0;
	account->status=1; 
    /*if status =1 then it's active if 2 then it's closed*/
	srand(time(NULL));
	ID= (rand()%(6548231548-1897632554+1))+1897632554;
	account->PASSWORD=(rand()%(85433298-45875624+1))+45875624;
	
	add_acc_data(ID,PtrToAcc);
	 
	
}

void add_acc_data(int id,  int pointer)
{
	
	struct node* ptr=(struct node*) malloc(sizeof(struct node));
	struct node* ptr1=head;
	
	ptr->data.BankID=id;

	ptr->data.accPOINTER=pointer;
	
	if(head==NULL)
	{head=ptr;
ptr->nodePTR=NULL;
	}
	else 
	{
		while(ptr1->nodePTR)
		{
			ptr1=ptr1->nodePTR;
						
		}
		ptr1->nodePTR=ptr;
		ptr->nodePTR=NULL;

	}
		
}
bool check_national_id(long long ID)
{
	long long num=ID;
	int n=0;
	while(num!=0)
	{
		num/=10;
		n++;
		
	}
	if (n==14)
		return true;
	else
		return false;
	
}

int search_accPTR(unsigned int ID)
{
	struct node* ptr=head;
	int pointer;
	while(ptr)
	{
		if(ptr->data.BankID==ID)
		{
			pointer=ptr->data.accPOINTER;
			break;
		}
		else
		     ptr=ptr->nodePTR;
	}
	if(ptr==NULL)
		return 1;
	else 
		return pointer;
}


void admin_window(void)
{
	char adminOPTIONS,adminExistingAccOPTIONS,STATUS;
	unsigned int ID,correctPASSWORD,PASSWORD,transfreeID,money;
	struct information *heapPTR1,*heapPTR2;
	
	main_menu:
		printf("\nto create a new account press 1\nto open existing account press2\n to exit the system press 3");
		scanf("%d",&adminOPTIONS);
		if(adminOPTIONS==1)
			create_new_acc();
		else if(adminOPTIONS==2)
		{
			
			printf("enter the account ID and PASSWORD");
			scanf("%d",&ID);
			heapPTR1=search_accPTR(ID);
           correctPASSWORD=heapPTR1->PASSWORD;
		   
			while(heapPTR1==1)
			{
				printf("the ID you entered is wrong,please try again");
				scanf("%d",&ID);		
			}
			printf("please enter the password");
			scanf("%d",&PASSWORD);
			while(!PASSWORD==correctPASSWORD)
			{printf("the password you entered is wrong,please try again");
				scanf("%d",&PASSWORD);		
			}
			
			
				if(heapPTR1->status!=1)
				printf("your account is closed or restricted");
			else
			{	
					
			printf("\nif you want to make a transaction press 1\n if you want to change account states press 2\n if you want to get cash press 3\n if you want to deposit press4\n if you want to return to main menu press 5\n");
			scanf("%d",&adminExistingAccOPTIONS);
			
			if(adminExistingAccOPTIONS==1)
			{
				printf("enter the ID of the account you want to transfer money to");
				scanf("%d",&transfreeID);
				heapPTR2=search_accPTR(transfreeID);
                				
			printf("how much do you want to transfer");
			scanf("%d",&money);
			if((heapPTR1->balance-money)<0)
				printf("you don't have enough money");
			else
			{heapPTR1->balance-=money;
			
			heapPTR2->balance+=money;
				
			}
				
				
			}
			else if(adminExistingAccOPTIONS==2)
			{
				printf("if you want to change the status to active press 1\n if you want to change status to closed press 2\n if you want to change account status to restricted press 3");
				
				scanf("%d",&STATUS);
				if(STATUS==1)
					heapPTR1->status=1;
				else if(STATUS==2)
					heapPTR1->status=2;
				else if(STATUS==3)
					heapPTR1->status=3;
				
				
			}
			else if(adminExistingAccOPTIONS==3)
			{
				printf("please enter the money you want to withdraw");
				scanf("%d",&money);
				if((heapPTR1->balance-money)<0)
					printf("you don't have enough money in your account");
				else 
				heapPTR1->balance-=money;
				
			}
			else if(adminExistingAccOPTIONS==4)
			{
				printf("enter the money you want to deposit");
				scanf("%d",&money);
				heapPTR1->balance+=money;
				
				
			}
			else if(adminExistingAccOPTIONS==5)
				goto main_menu;
		}
			
	}
	
	else if(adminOPTIONS==3)
	{
	
	//terminate the program
	
	}
	
	
}


void client_window(void)
{
	char clientOPTIONS;
    unsigned int ID,correctPASSWORD,PASSWORD,transfreeID,money,NEWpassword;	
	struct information *heapPTR1,*heapPTR2;
	
	printf("enter the account ID and PASSWORD");
			scanf("%d",&ID);
			heapPTR1=search_accPTR(ID);
           correctPASSWORD=heapPTR1->PASSWORD;
		   
			while(heapPTR1==1)
			{
				printf("the ID you entered is wrong,please try again");
				scanf("%d",&ID);		
			}
			printf("please enter the password");
			scanf("%d",&PASSWORD);
			while(!PASSWORD==correctPASSWORD)
			{printf("the password you entered is wrong,please try again");
				scanf("%d",&PASSWORD);		
			}
			
			
				if(heapPTR1->status!=1)
				printf("your account is closed or restricted");
			else
			{
	printf("\n if you want to make a transaction press 1\n if you want to change account password press 2\n if you want to get cash press 3\n if you want to deposit press 4\n if you want to return to main menu press 5");
	scanf("%d",&clientOPTIONS);
	 
	 if(clientOPTIONS==1)
	 {
		 printf("please enter the ID of the account you want to transfer money to");
		 
		 scanf("%d",&transfreeID);
		 heapPTR2=search_accPTR(transfreeID);
		 
		 
		 printf("how much do you want to transfer");
			scanf("%d",&money);
			if((heapPTR1->balance-money)<0)
				printf("you don't have enough money");
			else
			{heapPTR1->balance-=money;
			
			heapPTR2->balance+=money;
		 
		    }
		 
	 }
	 else if(clientOPTIONS==2)
	 {
	    printf("please enter your old password");
	    scanf("%d",&PASSWORD);
		while(!PASSWORD==correctPASSWORD)
		{
			printf("please enter the correct password");
			scanf("%d",&PASSWORD);
			
			
		}
		printf("enter the new password");
		scanf("%d",&heapPTR1->PASSWORD);
		
	 }
	 else if(clientOPTIONS==3)
	 {
		 
		  printf("how much do you want to withdraw");
			scanf("%d",&money);
			if((heapPTR1->balance-money)<0)
				printf("you don't have enough money");
			else
			{heapPTR1->balance-=money;
		
		    }
	 }
	 else if(clientOPTIONS==4)
	 {
		 printf("enter the money you want to deposit");
				scanf("%d",&money);
				heapPTR1->balance+=money;
		 
	 }
	 
	
	
	
	
	
	
	}
	
	
	
	
	
	
	
	
	
	
	
}