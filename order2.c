#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 100

int orderID[MAX_ORDERS];
char customerName[MAX_ORDERS][50];
float orderAmount[MAX_ORDERS];
int count;

int orderCount = 0;
int front = 0;
int rear = -1;

int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str) && *str != '.') return 0;
        str++;
    }
    return 1;
}
void addOrder() {
    if (orderCount >= MAX_ORDERS) {
        printf("Maximum number of orders reached!\n");
        return;
}

    int id;
    char name[50],input[50];
    float amount;
	
	printf("Enter item id: \n");
	scanf("%s", input);
    if (!is_number(input)) {
                    printf("Invalid input. Please enter a valid number for item id.\n");
                    return;
                }
    id = atoi(input);
    
    printf("Enter Customer Name: ");
    scanf("%s", name);
    
    printf("Enter item price: \n");
                scanf("%s", input);
                if (!is_number(input)) {
                    printf("Invalid input. Please enter a valid number for item price.\n");
                    return;
                }
    amount = atof(input);
    
    if(rear==MAX_ORDERS){
    	rear=1;
	}
	else{
		rear=rear+1;
	}
    orderID[rear] = id;
    strcpy(customerName[rear], name);
    orderAmount[rear] = amount;
    orderCount++;

    printf("Order added successfully.\n");
}

void processOrder() {
    if (orderCount == 0) {
        printf("No pending orders to process.\n");
        return;
    }

    printf("Processing Order ID: %d\n", orderID[front]);
    printf("Customer Name: %s\n", customerName[front]);
    printf("Order Amount: %.2f\n", orderAmount[front]);

    front = (front + 1) % MAX_ORDERS;
    orderCount--;
}

void displayOrders() {
    if (orderCount == 0) {
        printf("No pending orders.\n");
        return;
    }

    printf("\nPending Orders:\n");
    printf("-----------------\n");
    int i = front;
    for (count = 0; count < orderCount; count++) {
        printf("Order ID: %d\n", orderID[i]);
        printf("Customer Name: %s\n", customerName[i]);
        printf("Order Amount: %.2f\n", orderAmount[i]);
        printf("-----------------\n");
        
        i = (i + 1) % MAX_ORDERS;
    }
}

void searchOrder() {
    int searchID;
    printf("Enter Order ID to search: ");
    scanf("%d", &searchID);

    int i = front;
    for (count = 0; count < orderCount; count++) {
        if (orderID[i] == searchID) {
            printf("Order found:\n");
            printf("Order ID: %d\n", orderID[i]);
            printf("Customer Name: %s\n", customerName[i]);
            printf("Order Amount: %.2f\n", orderAmount[i]);
            return;
        }
        i = (i + 1) % MAX_ORDERS;
    }

    printf("Order with ID %d not found.\n", searchID);
}

int main() {
    int choice;
    
    while (1) {
        printf("\nOnline Store Order Management System\n");
        printf("1. Add Order\n");
        printf("2. Process Order\n");
        printf("3. Display Orders\n");
        printf("4. Search Order\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addOrder();
                break;
            case 2:
                processOrder();
                break;
            case 3:
                displayOrders();
                break;
            case 4:
                searchOrder();
                break;
            case 5:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

