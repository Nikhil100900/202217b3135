#include <stdio.h>
//#include <conio.h> // Remove conio.h as it's not standard

#define MAX 20 // Increased from 10 to 20 for consistency with array size

// Function prototypes
void create();
void insert();
void deletion();
void search();
void display();

int b[MAX]; // Array to hold elements
int n = 0;  // Number of elements currently in the array

int main() {
    //clrscr(); // Removed clrscr() as it's not standard and necessary

    int ch;
    char g = 'y';

    do {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("\nEnter the correct choice:");
        }

        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &g);
    } while(g == 'y' || g == 'Y');

    //getch(); // Removed getch() as it's not standard and necessary
    return 0;
}

void create() {
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    printf("\nEnter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    if(n == 0) {
        printf("\nList is empty. Deletion not possible.\n");
        return;
    }

    int pos;
    printf("\nEnter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if(pos < 0 || pos >= n) {
        printf("\nInvalid position. Deletion failed.\n");
        return;
    }

    for(int i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }

    n--;

    printf("\nThe list after deletion:\n");
    display();
}

void search() {
    if(n == 0) {
        printf("\nList is empty. Search not possible.\n");
        return;
    }

    int e;
    printf("\nEnter the element to search: ");
    scanf("%d", &e);

    int found = 0;
    for(int i = 0; i < n; i++) {
        if(b[i] == e) {
            printf("Element %d found at position %d.\n", e, i);
            found = 1;
            break; // Exit loop once element is found
        }
    }

    if(!found) {
        printf("Element %d not found in the list.\n", e);
    }
}

void insert() {
    if(n == MAX) {
        printf("\nList is full. Insertion not possible.\n");
        return;
    }

    int pos, p;
    printf("\nEnter the position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if(pos < 0 || pos > n) {
        printf("\nInvalid position. Insertion failed.\n");
        return;
    }

    printf("\nEnter the element to insert: ");
    scanf("%d", &p);

    for(int i = n - 1; i >= pos; i--) {
        b[i + 1] = b[i];
    }

    b[pos] = p;
    n++;

    printf("\nThe list after insertion:\n");
    display();
}

void display() {
    if(n == 0) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nThe elements of the list are:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}
