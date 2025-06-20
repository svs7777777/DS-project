#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100
char stack[max][100];
int top=-1;

void push(char data[]){
	if(top>=max-1){
		printf("document is overflow\n");
	}
	else{
		top++;
		strcpy(stack[top],data);
	}
}
char pop(){
	if(top<0){
		printf("document is underflow\n");
	}
	else{
		top--;
	}
}

void display(){
	int i;
	if(top<0){
		printf("document is empty\n");
		}
	else{
		for(i=0;i<=top;i++){
			printf("%s\n",stack[i]);
		}
	}
}
void main(){
    char word[100];
    int choice;

    while (1) {
        printf("\nText Editor Menu:\n");
        printf("1. Add word\n");
        printf("2. Undo last word\n");
        printf("3. Display document\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter a word to add: ");
                scanf("%s",&word);
                push(word);
                break;

            case 2:
                pop(); 
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting the program.\n");
                return 0; 

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
