#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

// Stack arrays for item attributes
int item_id[MAX_ITEMS];
char item_name[MAX_ITEMS][50];
int item_quantity[MAX_ITEMS];
float item_price[MAX_ITEMS];

// Variable to track the top of the stack
int top = -1; // Initially, the stack is empty

// Function to push an item to the stack
void push(int id, char name[], int quantity, float price) {
    if (top >= MAX_ITEMS - 1) {
        printf("Inventory is full! Cannot add more items.\n");
    } else {
        top++;
        item_id[top] = id;
        strcpy(item_name[top], name);
        item_quantity[top] = quantity;
        item_price[top] = price;
        printf("Item added successfully!\n");
    }
}

// Function to pop an item from the stack
void pop() {
    if (top == -1) {
        printf("Inventory is empty! No items to delete.\n");
    } else {
        printf("Item deleted: ID: %d, Name: %s\n", item_id[top], item_name[top]);
        top--;
    }
}

// Function to peek at the top item of the stack
void peek() {
    if (top == -1) {
        printf("Inventory is empty!\n");
    } else {
        printf("Most recent item: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
               item_id[top], item_name[top], item_quantity[top], item_price[top]);
    }
}

// Function to search for an item by ID
void search(int id) {
    if (top == -1) {
        printf("Inventory is empty!\n");
    } else {
        int found = 0;
        int i; // Declare variable before the loop
        for (i = top; i >= 0; i--) {
            if (item_id[i] == id) {
                printf("Item found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
                       item_id[i], item_name[i], item_quantity[i], item_price[i]);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Item with ID %d not found.\n", id);
        }
    }
}

// Function to update an item's quantity or price
void update(int id) {
    if (top == -1) {
        printf("Inventory is empty!\n");
    } else {
        int found = 0;
        int i; // Declare variable before the loop
        for (i = top; i >= 0; i--) {
            if (item_id[i] == id) {
                printf("Updating item: %s\n", item_name[i]);

                printf("Enter new quantity: ");
                scanf("%d", &item_quantity[i]);

                printf("Enter new price: ");
                scanf("%f", &item_price[i]);

                printf("Item updated successfully!\n");
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Item with ID %d not found.\n", id);
        }
    }
}

// Function to display all items in the stack (in reverse order since it's a stack)
void display() {
    if (top == -1) {
        printf("Inventory is empty!\n");
    } else {
        printf("\nInventory List:\n");
        int i; // Declare variable before the loop
        for (i = top; i >= 0; i--) {
            printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
                   item_id[i], item_name[i], item_quantity[i], item_price[i]);
        }
    }
}

int main() {
    int choice, id;
    char name[50];
    int quantity;
    float price;

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Delete Item\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Display Items\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
    printf("Enter Item ID: ");
    scanf("%d", &id);  // Reads the item ID as an integer
    printf("Enter Item Name: ");
    scanf("%s", name);  // Reads the item name as a string (no spaces allowed)
    printf("Enter Item Quantity: ");
    scanf("%d", &quantity);  // Reads the item quantity as an integer
    printf("Enter Item Price: ");
    scanf("%f", &price);  // Reads the item price as a float
    push(id, name, quantity, price);  // Calls the push function to add item to the stack
    break;


            case 2:
                pop();
                break;

            case 3:
                printf("Enter Item ID to search: ");
                scanf("%d", &id);
                search(id);
                break;

            case 4:
                printf("Enter Item ID to update: ");
                scanf("%d", &id);
                update(id);
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting the system...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

