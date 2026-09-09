// Experiment No: 04
// Title:  Implement Database Management using arrays of structures with operations Create, Display, Modify,Search and Sort.
// Aim: To create and manipulate employee   database by using array of structure. Data base Management using array of structure with operations Create, display, Modify, Append, Search and Sort.


#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    int salary;
} employee;

void display(employee e[], int total) {
    if (total == 0) {
        printf("Database is empty.\n");
        return;
    }
    for (int i = 0; i < total; i++) {
        printf("Employee %d: ID: %d | Name: %s | Salary: %d\n", i + 1, e[i].id, e[i].name, e[i].salary);
    }
}

void modify(employee e[], int total) {
    int target_id, found = 0; 
    printf("Enter ID to modify: ");
    scanf("%d", &target_id);
    
    for (int i = 0; i < total; i++) {
        if (e[i].id == target_id) {
            printf("Enter new Name: ");
            scanf("%s", e[i].name);
            printf("Enter new Salary: ");
            scanf("%d", &e[i].salary);
            printf("Record updated successfully.\n");
            found = 1;
            break; 
        }
    }
    if (!found) {
        printf("Employee ID %d not found.\n", target_id);
    }
}

void search(employee e[], int total) {
    int target_id, found = 0; 
    printf("Enter ID to search: ");
    scanf("%d", &target_id); 
    
    for (int i = 0; i < total; i++) {
        if (e[i].id == target_id) {
            printf("Found - Name: %s | Salary: %d\n", e[i].name, e[i].salary);
            found = 1;
            break; 
        }
    }
    if (!found) {
        printf("Employee ID %d not found.\n", target_id);
    }
}

void append(employee e[], int *total, int max) {
    if (*total >= max) {
        printf("Database is full!\n");
        return;
    }
    printf("\nEnter new employee details:\n");
    printf("Name: ");
    scanf("%s", e[*total].name);
    printf("ID: ");
    scanf("%d", &e[*total].id);
    printf("Salary: ");
    scanf("%d", &e[*total].salary);
    
    (*total)++;
    printf("Employee added successfully.\n");
}

void sort(employee e[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (e[j].id > e[j + 1].id) {
                employee temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
    printf("Database sorted by ID successfully.\n");
}

int main() {
    employee e[100]; 
    int total, choice;
    
    printf("Enter initial number of employees: "); 
    scanf("%d", &total);
    
    for (int i = 0; i < total; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", e[i].name);
        printf("ID: ");
        scanf("%d", &e[i].id);
        printf("Salary: ");
        scanf("%d", &e[i].salary);
    }

    do {
        printf("\nEmployee Database\n");
        printf("1. Display\n2. Append\n3. Modify\n4. Search\n5. Sort\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(e, total);
                break;
            case 2:
                append(e, &total, 100);
                break;
            case 3:
                modify(e, total);
                break;
            case 4:
                search(e, total);
                break;
            case 5:
                sort(e, total);
                printf("Sorted Database: \n");
                display(e, total);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0; 
}
