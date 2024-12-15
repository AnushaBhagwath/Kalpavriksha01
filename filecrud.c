#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FILENAME "users.txt"
#define MAX_LINE 256

// Structure to represent a User
typedef struct {
    char id[20];
    char name[50];
    int age;
} User;

// Function to create the file if it doesn't exist
void create_file() {
    // Open file in append mode, create if doesn't exist
    FILE *file = fopen(FILENAME, "a");
    if (file != NULL) {
        fclose(file);  // Close the file after ensuring it exists
    }
}

// Function to add a new user to the file
void add_user() {
    User newuser;  // Declare a new user variable
    FILE *file = fopen(FILENAME, "a");  // Open file in append mode to add a new user

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    // Prompt user for input
    printf("Enter User ID: ");
    scanf("%s", newuser.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", newuser.name);  // To capture spaces in name
    printf("Enter Age: ");
    scanf("%d", &newuser.age);

    // Write the new user data into the file
    fprintf(file, "%s,%s,%d\n", newuser.id, newuser.name, newuser.age);
    fclose(file);  // Close the file

    printf("User added successfully!\n");
}

// Function to display all users in the file
void display_users() {
    FILE *file = fopen(FILENAME, "r");  // Open file in read mode
    if (file == NULL) {
        printf("No users found.\n");
        return;
    }

    // Print column headers for better formatting
    printf("\n%-10s %-20s %-5s\n", "ID", "Name", "Age");
    printf("-------------------------------\n");

    char details[MAX_LINE];  // Buffer to store each line read from file
    while (fgets(details, sizeof(details), file)) {  // Read each line
        User newuser;
        // Parse the line into a User structure
        sscanf(details, "%[^,],%[^,],%d", newuser.id, newuser.name, &newuser.age);
        // Display the user details in formatted columns
        printf("%-10s %-20s %-5d\n", newuser.id, newuser.name, newuser.age);
    }

    fclose(file);  // Close the file
}

// Function to update a user's information based on ID
void update_user() {
    FILE *file = fopen(FILENAME, "r");  // Open file in read mode
    if (file == NULL) {
        printf("No users found.\n");
        return;
    }

    // Temporary file for storing updated data
    char temp_filename[] = "temp.txt";
    FILE *temp_file = fopen(temp_filename, "w");
    if (temp_file == NULL) {
        printf("Error: Could not open temporary file.\n");
        fclose(file);
        return;
    }

    char targetid[20];
    // Prompt for the ID of the user to update
    printf("Enter the ID of the user to update: ");
    scanf("%s", targetid);

    char details[MAX_LINE];  // Buffer for each line in the file
    int present = 0;  // Flag to check if user was found
    while (fgets(details, sizeof(details), file)) {
        User newuser;
        // Parse each line into a User structure
        sscanf(details, "%[^,],%[^,],%d", newuser.id, newuser.name, &newuser.age);

        if (strcmp(newuser.id, targetid) == 0) {
            present = 1;  // Set flag if the user is found
            // Prompt for updated details
            printf("Enter new Name: ");
            scanf(" %[^\n]", newuser.name);
            printf("Enter new Age: ");
            scanf("%d", &newuser.age);
        }
        // Write the (possibly updated) user data to the temporary file
        fprintf(temp_file, "%s,%s,%d\n", newuser.id, newuser.name, newuser.age);
    }

    fclose(file);
    fclose(temp_file);

    // If user was updated, replace the original file with the temporary file
    if (present) {
        remove(FILENAME);
        rename(temp_filename, FILENAME);
        printf("User updated successfully!\n");
    } else {
        // If user wasn't found, remove the temporary file
        remove(temp_filename);
        printf("Error: User not found.\n");
    }
}

// Function to delete a user from the file based on ID
void delete_user() {
    FILE *file = fopen(FILENAME, "r");  // Open file in read mode
    if (file == NULL) {
        printf("No users found.\n");
        return;
    }

    // Temporary file for storing users who are not deleted
    char temp_filename[] = "temp.txt";
    FILE *tempfile = fopen(temp_filename, "w");
    if (tempfile == NULL) {
        printf("Error: Could not open temporary file.\n");
        fclose(file);
        return;
    }

    char targetid[20];
    // Prompt for the ID of the user to delete
    printf("Enter the ID of the user to delete: ");
    scanf("%s", targetid);

    char details[MAX_LINE];  // Buffer for each line in the file
    int present = 0;  // Flag to check if user was found
    while (fgets(details, sizeof(details), file)) {
        User newuser;
        // Parse each line into a User structure
        sscanf(details, "%[^,],%[^,],%d", newuser.id, newuser.name, &newuser.age);

        if (strcmp(newuser.id, targetid) != 0) {
            // If user is not the one to delete, write to the temporary file
            fprintf(tempfile, "%s,%s,%d\n", newuser.id, newuser.name, newuser.age);
        } else {
            present = 1;  // Set flag if user is found
        }
    }

    fclose(file);
    fclose(tempfile);

    // If user was deleted, replace the original file with the temporary file
    if (present) {
        remove(FILENAME);
        rename(temp_filename, FILENAME);
        printf("User deleted successfully!\n");
    } else {
        // If user wasn't found, remove the temporary file
        remove(temp_filename);
        printf("Error: User not found.\n");
    }
}

// Main function to drive the program
int main() {
    int choice;

    create_file();  // Ensure file exists before performing any operations

    while (1) {
        // Menu for user to choose an option
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
                add_user();  // Call function to add a user
                break;
            case 2:
                display_users();  // Call function to display all users
                break;
            case 3:
                update_user();  // Call function to update a user
                break;
            case 4:
                delete_user();  // Call function to delete a user
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;  // Exit the program with a single return statement
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
// Intentionally left blank