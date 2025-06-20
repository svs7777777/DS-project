#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct item {
    int item_id;
    char item_name[50];
    int item_quantity;
    float item_price;
    struct item *link;
} *first = NULL;

int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str) && *str != '.') return 0;
        str++;
    }
    return 1;
}

void push(int id, char name[], int quantity, float price) {
    struct item *newnode, *avail;
    avail = (struct item *)malloc(sizeof(struct item));
    if (avail == NULL) {
        printf("Memory not available\n");
        return;
    } else {
        newnode = avail;
        newnode->item_id = id;
        strcpy(newnode->item_name, name);
        newnode->item_quantity = quantity;
        newnode->item_price = price;
        if (first == NULL) {
            newnode->link = NULL;
        } else {
            newnode->link = first;
        }
        first = newnode;
    }
}

void pop(int id) {
    struct item *ptr = first, *q;
    if (first == NULL) {
        printf("List is empty\n");
    } else {
        if (ptr != NULL && ptr->item_id == id) {
            first = ptr->link;
            free(ptr);
            printf("Item with ID %d deleted\n", id);
            return;
        }
        while (ptr != NULL && ptr->item_id != id) {
            q = ptr;
            ptr = ptr->link;
        }
        if (ptr == NULL) {
            printf("Item with ID %d not found\n", id);
            return;
        }
        q->link = ptr->link;
        free(ptr);
        printf("Item with ID %d deleted\n", id);
    }
}

void search(int id) {
    struct item *ptr = first;
    while (ptr != NULL) {
        if (ptr->item_id == id) {
            printf("Item found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                   ptr->item_id, ptr->item_name, ptr->item_quantity, ptr->item_price);
            return;
        }
        ptr = ptr->link;
    }
    printf("Item with ID %d not found.\n", id);
}

void update(int id) {
    struct item *ptr = first;
    while (ptr != NULL) {
        if (ptr->item_id == id) {
            printf("Updating item with ID: %d\n", id);
            printf("Current name: %s\n", ptr->item_name);

            printf("Enter new item id: ");
            scanf("%d", &ptr->item_id);
            printf("Enter new item name: ");
            scanf("%s", ptr->item_name);
            printf("Enter new item quantity: ");
            scanf("%d", &ptr->item_quantity);
            printf("Enter new item price: ");
            scanf("%f", &ptr->item_price);

            printf("Item updated successfully.\n");
            return;
        }
        ptr = ptr->link;
    }
    printf("Item with ID %d not found.\n", id);
}

void display() {
    struct item *ptr;
    ptr = first;
    if (ptr == NULL) {
        printf("No items in the inventory\n");
        return;
    }
    printf("LINKED LIST ELEMENTS:\n");
    while (ptr != NULL) {
        printf("\t\t");
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               ptr->item_id, ptr->item_name, ptr->item_quantity, ptr->item_price);
        ptr = ptr->link;
    }
    printf("\n");
}

int main() {
    int choice, id;
    char name[50], input[50];
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
                printf("Enter item id: \n");
                scanf("%s", input);
                if (!is_number(input)) {
                    printf("Invalid input. Please enter a valid number for item id.\n");
                    break;
                }
                id = atoi(input);

                printf("Enter item name: \n");
                scanf("%s", name);

                printf("Enter item quantity: \n");
                scanf("%s", input);
                if (!is_number(input)) {
                    printf("Invalid input. Please enter a valid number for item quantity.\n");
                    break;
                }
                quantity = atoi(input);

                printf("Enter item price: \n");
                scanf("%s", input);
                if (!is_number(input)) {
                    printf("Invalid input. Please enter a valid number for item price.\n");
                    break;
                }
                price = atof(input);

                push(id, name, quantity, price);
                break;

            case 2:
                printf("Enter item id to delete: \n");
                scanf("%d", &id);
                pop(id);
                break;

            case 3:
                printf("Enter item id to search: \n");
                scanf("%d", &id);
                search(id);
                break;

            case 4:
                printf("Enter item id to update: \n");
                scanf("%d", &id);
                update(id);
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
