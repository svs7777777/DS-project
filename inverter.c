#include<stdio.h>
#include<string.h>

#define maxitems 100

int item_id[maxitems];
char item_name[maxitems][50];
int item_quantity[maxitems];
float item_price[maxitems];

int top=-1;

void push(int id, char name[], int quantity, float price)
{
	if(top>maxitems){
		printf("overflow");
	}
	else{
		top++;
		item_id[top]=id;
		strcpy(item_name[top],name);
		item_quantity[top]=quantity;
		item_price[top]=price;
		printf("item added successfully!\n");
	}
}

void pop(int id)
{
    if(top == -1)
    {
        printf("underflow\n");
    }
    else
    {
        int i, found = 0;
        for(i = 0; i <= top; i++)
        {
            if(item_id[i] == id)
            {
                printf("Item with ID %d and Name %s is deleted\n", item_id[i], item_name[i]);
                found = 1;
                break;
            }
        }
        if(found)
        {
            for(; i < top; i++)
            {
                item_id[i] = item_id[i+1];
                strcpy(item_name[i], item_name[i+1]);
                item_quantity[i] = item_quantity[i+1];
                item_price[i] = item_price[i+1];
            }
            top--;
        }
        else
        {
            printf("Item with ID %d not found\n", id);
        }
    }
}

void search(int id)
{
	if(top==-1){
		printf("underflow\n");
	}
	else{
		int i,found=0;
		for(i=top;i>=0;i--)
		{
			if(item_id[i]==id)
			{
				printf("Item found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
                       item_id[i], item_name[i], item_quantity[i], item_price[i]);
                found=1;
                break;
			}
		}
		if (!found) {
            printf("Item with ID %d not found.\n", id);
        }
	}
}

void update(int id)
{
	if(top==-1)
	{
		printf("underflow\n");
	}
	else{
		int i,found=0;
		char name[50];
		for(i=top;i>=0;i--)
		{
			if(item_id[i]==id)
			{
				printf("Updating item name is: %s\n", item_name[i]);
				
				printf("Enter new item id: ");
                scanf("%d", &item_id[i]);
                
				printf("enter new item name: \n");
        		scanf("%s",&name);
				strcpy(item_name[i],name);
				
                printf("Enter new quantity: ");
                scanf("%d", &item_quantity[i]);

                printf("Enter new price: ");
                scanf("%f", &item_price[i]);
                
			    found=1;
                break;
			}
		}
		if (!found) {
            printf("Item with ID %d not found.\n", id);
        }
	}
}

void display()
{
	if(top==-1)
	{
		printf("underflow\n");
	}
	else
	{
		printf("\nInventory List:\n");
		int i;
		for(i=top;i>=0;i--)
		{
			printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
                   item_id[i], item_name[i], item_quantity[i], item_price[i]);
		}
	}
}
void main()
{
	int choice, id;
    char name[50];
    int quantity;
    float price;

	while(1)
	{
		printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Delete Item\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Display Items\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
        	case 1:{
        		printf("enter item id: \n");
        		scanf("%d",&id);
        		printf("enter item name: \n");
        		scanf("%s",&name);
        		printf("enter item quantity: \n");
        		scanf("%d",&quantity);
				printf("enter item price: \n");
				scanf("%f",&price);
				push(id,name,quantity,price);
				break;
			}
        	case 2:{
        		printf("enter item ib to delete: \n");
                scanf("%d", &id);
        		pop(id);
				break;
			}	
			case 3:{
				printf("enter item ib to search: \n");
                scanf("%d", &id);
                search(id);
				break;
			}
			case 4:{
				printf("enter item ib to update: \n");
                scanf("%d", &id);
                update(id);
				break;
			}
			case 5:{
				display();
				break;
			}
			case 6:{
				return 0;
			}
			default:{
				printf("invalid choice! please try again.\n");
			}
		}
	}
}
