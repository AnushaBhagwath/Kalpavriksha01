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



int custom_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (unsigned char)*str1 - (unsigned char)*str2;
}


void create_file() {
    
    FILE *file = fopen(FILENAME, "a");
    if (file != NULL) {
        fclose(file);  
    }
}


int check_id_exists(const char *id) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return 0; 
    }

    char details[MAX_LINE];
    while (fgets(details, sizeof(details), file)) {
        User existing_user;
        sscanf(details, "%[^,],%[^,],%d", existing_user.id, existing_user.name, &existing_user.age);
        if (custom_strcmp(existing_user.id, id) == 0) {
            fclose(file);
            return 1;  // Id exits
        }
    }
    fclose(file);
    return 0;  // ID doesn't exist
}


void add_user() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    User new_user;
    printf("Enter ID: ");
    scanf("%s", new_user.id);

    
    if (check_id_exists(new_user.id)) {
        printf("Error: User ID already exists.\n");
        fclose(file);
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", new_user.name);
    printf("Enter Age: ");
    scanf("%d", &new_user.age);

    fprintf(file, "%s,%s,%d\n", new_user.id, new_user.name, new_user.age);
    printf("User added successfully!\n");
    fclose(file);
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

        if (custom_strcmp(newuser.id, targetid) == 0) {
            present = 1;  
            int update_choice;
            
            printf("User found! What would you like to update?\n");
            printf("1. Name\n");
            printf("2. Age\n");
            printf("3. Both Name and Age\n");
            printf("Enter your choice (1/2/3): ");
            scanf("%d", &update_choice);

            switch (update_choice) {
                case 1:  // Update only Name
                    printf("Enter new Name: ");
                    scanf(" %[^\n]", newuser.name);
                    break;
                case 2:  // Update only Age
                    printf("Enter new Age: ");
                    scanf("%d", &newuser.age);
                    break;
                case 3:  // Update both Name and Age
                    printf("Enter new Name: ");
                    scanf(" %[^\n]", newuser.name);
                    printf("Enter new Age: ");
                    scanf("%d", &newuser.age);
                    break;
                default:
                    printf("Invalid choice. No updates made.\n");
                    break;
            }
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

        if (custom_strcmp(newuser.id, targetid) != 0) 
        {
            fprintf(tempfile, "%s,%s,%d\n", newuser.id, newuser.name, newuser.age);
        } 
        else 
        {
            present = 1;  
        }
    }

    fclose(file);
    fclose(tempfile);

    if (present)
     {
        remove(FILENAME);
        rename(temp_filename, FILENAME);
        printf("User deleted successfully!\n");
    } 
    else 
    {
        
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
        
        // Input validation: check if the input is an integer
        if (scanf("%d", &choice) != 1) {
            // If the input is not a valid integer, clear the input buffer
            while (getchar() != '\n');  // Clear the invalid input
            printf("Invalid input! Please enter a number.\n");
            continue;  // Skip the rest of the loop and ask for input again
        }

    
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
                printf("Exiting the program.\n");
                return 0;  
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
    printf("\n");
}
