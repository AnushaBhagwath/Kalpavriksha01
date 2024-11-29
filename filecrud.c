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

void display_users() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No users found.\n");
        return;
    }

    printf("\n%-10s %-20s %-5s\n", "ID", "Name", "Age");
    printf("-------------------------------\n");

    char details[MAX_LINE];
    while (fgets(details, sizeof(details), file)) {
        User newuser;
        sscanf(details, "%[^,],%[^,],%d", newuser.id, newuser.name, &newuser.age);
        printf("%-10s %-20s %-5d\n", newuser.id, newuser.name, newuser.age);
    }

    fclose(file);
}


void update_user() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No users found.\n");
        return;
    }

    char temp_filename[] = "temp.txt";
    FILE *temp_file = fopen(temp_filename, "w");
    if (temp_file == NULL) {
        printf("Error: Could not open temporary file.\n");
        fclose(file);
        return;
    }

    char targetid[20];
    printf("Enter the ID of the user to update: ");
    scanf("%s", targetid);

    char details[MAX_LINE];
    int present = 0;
    while (fgets(details, sizeof(details), file)) {
        User newuser;
        sscanf(details, "%[^,],%[^,],%d", newuser.id, newuser.name, &newuser.age);

        if (strcmp(newuser.id, targetid) == 0) {
            present = 1;
            printf("Enter new Name: ");
            scanf(" %[^\n]", newuser.name);
            printf("Enter new Age: ");
            scanf("%d", &newuser.age);
        }
        fprintf(temp_file, "%s,%s,%d\n", newuser.id, newuser.name, newuser.age);
    }

    fclose(file);
    fclose(temp_file);

    if (present) {
        remove(FILENAME);
        rename(temp_filename, FILENAME);
        printf("User updated successfully!\n");
    } else {
        remove(temp_filename);
        printf("Error: User not found.\n");
    }
}


void delete_user() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No users found.\n");
        return;
    }

    char temp_filename[] = "temp.txt";
    FILE *tempfile = fopen(temp_filename, "w");
    if (tempfile == NULL) {
        printf("Error: Could not open temporary file.\n");
        fclose(file);
        return;
    }

    char targetid[20];
    printf("Enter the ID of the user to delete: ");
    scanf("%s", targetid);

    char details[MAX_LINE];
    int present = 0;
    while (fgets(details, sizeof(details), file)) {
        User newuser;
        sscanf(details, "%[^,],%[^,],%d", newuser.id, newuser.name, &newuser.age);

        if (strcmp(newuser.id, targetid) != 0) {
            fprintf(tempfile, "%s,%s,%d\n", newuser.id, newuser.name, newuser.age);
        } else {
            present = 1;
        }
    }

    fclose(file);
    fclose(tempfile);

    if (present) {
        remove(FILENAME);
        rename(temp_filename, FILENAME);
        printf("User deleted successfully!\n");
    } else {
        remove(temp_filename);
        printf("Error: User not found.\n");
    }
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