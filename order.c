#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Order {
    int orderID;
    char customerName[50];
    float orderAmount;
    struct Order* next;
} Order;

Order* front = NULL; 
Order* rear = NULL;  

int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str) && *str != '.') return 0;
        str++;
    }
    return 1;
}

Order* createOrder(int id, const char* name, float amount) {
    Order* newOrder = (Order*)malloc(sizeof(Order));
    newOrder->orderID = id;
    strcpy(newOrder->customerName, name);
    newOrder->orderAmount = amount;
    newOrder->next = NULL;
    return newOrder;
}

void addOrder() {
    int id;
    char name[50];
    float amount;
    
    printf("Enter Order ID: ");
    scanf("%d", &id);
    printf("Enter Customer Name: ");
    getchar(); 
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Enter Order Amount: ");
    scanf("%f", &amount);
    
    Order* newOrder = createOrder(id, name, amount);
    
    if (rear == NULL) {
        front = rear = newOrder;
    } else {
        rear->next = newOrder;
        rear = newOrder;
    }
    printf("Order added successfully.\n");
}

void processOrder() {
    if (front == NULL) {
        printf("No pending orders to process.\n");
        return;
    }
    
    Order* temp = front;
    front = front->next;
    
    if (front == NULL) {
        rear = NULL;
    }
    
    printf("Processing Order ID: %d\n", temp->orderID);
    printf("Customer Name: %s\n", temp->customerName);
    printf("Order Amount: %.2f\n", temp->orderAmount);
    
    free(temp);  
}

void displayOrders() {
    if (front == NULL) {
        printf("No pending orders.\n");
        return;
    }
    
    Order* temp = front;
    printf("\nPending Orders:\n");
    printf("-----------------\n");
    while (temp != NULL) {
        printf("Order ID: %d\n", temp->orderID);
        printf("Customer Name: %s\n", temp->customerName);
        printf("Order Amount: %.2f\n", temp->orderAmount);
        printf("-----------------\n");
        temp = temp->next;
    }
}

void searchOrder() {
    int searchID;
    printf("Enter Order ID to search: ");
    scanf("%d", &searchID);
    
    Order* temp = front;
    while (temp != NULL) {
        if (temp->orderID == searchID) {
            printf("Order found:\n");
            printf("Order ID: %d\n", temp->orderID);
            printf("Customer Name: %s\n", temp->customerName);
            printf("Order Amount: %.2f\n", temp->orderAmount);
            return;
        }
        temp = temp->next;
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

