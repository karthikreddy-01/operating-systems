#include <stdio.h>
#include <string.h>
#define MAX_USERS 10
#define MAX_FILES 10
#define NAME 30
struct user {
    char username[NAME];
    char files[MAX_FILES][NAME];
    int fileCount;
};
int main() {
    struct user users[MAX_USERS];
    int userCount = 0;
    int choice;
    char uname[NAME], fname[NAME];
    int uIndex, found;
    while (1) {
        printf("\n--- Two Level Directory ---\n");
        printf("1. Create User\n");
        printf("2. Create File\n");
        printf("3. Delete File\n");
        printf("4. Search File\n");
        printf("5. Display Directory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            if (userCount == MAX_USERS) {
                printf("User limit reached!\n");
                break;
            }
            printf("Enter username: ");
            scanf("%s", uname);
            found = 0;
            for (int i = 0; i < userCount; i++) {
                if (strcmp(users[i].username, uname) == 0) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                printf("User already exists!\n");
            } else {
                strcpy(users[userCount].username, uname);
                users[userCount].fileCount = 0;
                userCount++;
                printf("User created successfully.\n");
            }
            break;
        case 2:
            printf("Enter username: ");
            scanf("%s", uname);
            uIndex = -1;
            for (int i = 0; i < userCount; i++) {
                if (strcmp(users[i].username, uname) == 0) {
                    uIndex = i;
                    break;
                }
            }
            if (uIndex == -1) {
                printf("User not found!\n");
                break;
            }
            if (users[uIndex].fileCount == MAX_FILES) {
                printf("File limit reached for this user!\n");
                break;
            }
            printf("Enter file name: ");
            scanf("%s", fname);
            found = 0;
            for (int i = 0; i < users[uIndex].fileCount; i++) {
                if (strcmp(users[uIndex].files[i], fname) == 0) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                printf("File already exists for this user!\n");
            } else {
                strcpy(users[uIndex].files[users[uIndex].fileCount], fname);
                users[uIndex].fileCount++;
                printf("File created successfully.\n");
            }
            break;
        case 3: 
            printf("Enter username: ");
            scanf("%s", uname);
            printf("Enter file name: ");
            scanf("%s", fname);
            uIndex = -1;
            for (int i = 0; i < userCount; i++) {
                if (strcmp(users[i].username, uname) == 0) {
                    uIndex = i;
                    break;
                }
            }
            if (uIndex == -1) {
                printf("User not found!\n");
                break;
            }
            found = 0;
            for (int i = 0; i < users[uIndex].fileCount; i++) {
                if (strcmp(users[uIndex].files[i], fname) == 0) {
                    found = 1;
                    for (int j = i; j < users[uIndex].fileCount - 1; j++) {
                        strcpy(users[uIndex].files[j], users[uIndex].files[j + 1]);
                    }
                    users[uIndex].fileCount--;
                    printf("File deleted successfully.\n");
                    break;
                }
            }
            if (!found)
                printf("File not found!\n");
            break;
        case 4: 
            printf("Enter username: ");
            scanf("%s", uname);
            printf("Enter file name: ");
            scanf("%s", fname);
            found = 0;
            for (int i = 0; i < userCount; i++) {
                if (strcmp(users[i].username, uname) == 0) {
                    for (int j = 0; j < users[i].fileCount; j++) {
                        if (strcmp(users[i].files[j], fname) == 0) {
                            found = 1;
                            break;
                        }
                    }
                }
            }
            if (found)
                printf("File found.\n");
            else
                printf("File not found.\n");
            break;
        case 5: 
            if (userCount == 0) {
                printf("No users found.\n");
            } else {
                for (int i = 0; i < userCount; i++) {
                    printf("\nUser: %s\n", users[i].username);
                    if (users[i].fileCount == 0) {
                        printf("  No files\n");
                    } else {
                        for (int j = 0; j < users[i].fileCount; j++) {
                            printf("  %s\n", users[i].files[j]);
                        }
                    }
                }
            }
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
