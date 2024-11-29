#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define FILENAME "users.txt"
#define MAX_LINE 256

typedef struct {
    char id[20];
    char name[50];
    int age;
} User;

void create_file() {
    FILE *file = fopen(FILENAME, "a");
    if (file != NULL) {
        fclose(file);
    }
}

void add_user() {
    User newuser;
    FILE *file = fopen(FILENAME, "a");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("Enter User ID: ");
    scanf("%s", newuser.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", newuser.name);
    printf("Enter Age: ");
    scanf("%d", &newuser.age);

    fprintf(file, "%s,%s,%d\n", newuser.id, newuser.name, newuser.age);
    fclose(file);

    printf("User added successfully!\n");
}

int main() {
    int choice;

    create_file();

    while (1) {
        printf("\nUser Management System\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                display_users();
                break;
            case 3:
                update_user();
                break;
            case 4:
                delete_user();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
