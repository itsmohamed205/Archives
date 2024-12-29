#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct {
    char username[20];
    char password[20];
    char role[10];
} User;

User users[] = {
    {"manager", "123", "manager"},
    {"worker", "123", "worker"},
    {"inspector", "123", "inspector"}
};

const char *RED = "\033[0;31m";
const char *GREEN = "\033[0;32m";
const char *YELLOW = "\033[0;33m";
const char *BLUE = "\033[0;34m";
const char *RESET = "\033[0m";

#define NUM_USERS (sizeof(users) / sizeof(users[0]))

void start_init();
void manager_menu();
void worker_menu();
void inspector_menu();
int authenticate(char *username, char *password, char *role);

int main() {
    
    char username[20], password[20], role[10];
    start_init();

    printf("%s\n=== System Login ===%s\n", YELLOW, RESET);
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (authenticate(username, password, role)) {
        printf("\nWelcome, %s!\n", username);
        if (strcmp(role, "manager") == 0) {
            manager_menu();
        } else if (strcmp(role, "worker") == 0) {
            worker_menu();
        } else if (strcmp(role, "inspector") == 0) {
            inspector_menu();
        } else {
            printf("Unknown role. Exiting.\n");
        }
    } else {
        printf("%sInvalid credentials. Exiting... %s\n", RED, RESET);
    }

    return 0;
}

int authenticate(char *username, char *password, char *role) {
    for (int i = 0; i < NUM_USERS; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            strcpy(role, users[i].role);
            return 1;
        }
    }
    return 0;
}

void start_init() {
    system("clear");
    system("alias removeSession='sudo rm -rf ~/Manufacturing'");
    system("sudo rm -rf ~/Manufacturing");
    printf("> %sSetting up directories and permissions...%s\n", YELLOW, RESET);
    system("mkdir -p ~/Manufacturing/{Manager,Workers,Inspectors,Archive} && chmod u=rwx ~/Manufacturing/{Manager,Workers,Inspectors,Archive}");
    system("sudo chown Manager ~/Manufacturing/Manager");
    system("sudo chown Worker ~/Manufacturing/Workers");
    system("sudo chown Inspector ~/Manufacturing/Inspectors");
    printf("%sDirectories and permissions set up successfully.%s\n", GREEN, RESET);
}

void manager_menu() {
    int choice;
    do {
        printf("\n=== Manager Menu ===\n");
        printf("1. List files in /Manager\n");
        printf("2. Create a production schedule\n");
        printf("3. Create a symbolic link for schedule\n");
        printf("4. Archive production schedule\n");
        printf("5. Search for schedules\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        system("clear");
        switch (choice) {
            case 1:
                system("ls -l ~/Manufacturing/Manager");
                break;
            case 2:
                system("sudo touch ~/Manufacturing/Manager/production_schedule");
                printf("%s Production schedule created.%s\n", GREEN, RESET);
                break;
            case 3:
                system("ln -s ~/Manufacturing/Manager/production_schedule ~/Manufacturing/shared_schedule.txt");
                printf("%sSymbolic link created.\n%s", GREEN, RESET);
                break;
            case 4:
                system("mkdir -p ~/Manufacturing/Archive");
                system("sudo mv ~/Manufacturing/Manager/production_schedule ~/Manufacturing/Archive/");
                printf("%sProduction schedule archived.%s\n", GREEN, RESET);
                break;
            case 5:
                printf("%sCreating some junk files for test purposes...%s\n", BLUE, RESET);
                system("sudo touch ~/Manufacturing/Manager/{a..f}{1..9}schedule.txt");

                printf("%sSearching for files with num '5' in the dir... (check ls for all files)%s\n", BLUE, RESET);
                system("find ~/Manufacturing/Manager/ -name '*5*'");
                break;
            case 6:
                printf("%sExiting Manager Menu. (Deleting the files tree)%s\n", RED, RESET);
                system("sudo rm -rf ~/Manufacturing");
                break;
            default:
                printf("%sInvalid choice, try again.%s\n", RED, RESET);
        }
    } while (choice != 6);
}

void worker_menu() {
    int choice;
    do {
        printf("\n=== Worker Menu ===\n");
        printf("1. List files in /workers\n");
        printf("2. Append to task log\n");
        printf("3. View task log\n");
        printf("4. Move task logs to archive directory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        system("clear");
        switch (choice) {
            case 1:
                system("ls -l ~/Manufacturing/Workers");
                break;
            case 2:
                system("sudo sh -c 'echo \"$(whoami) Logged some task at $(date +\\\"%c\\\")\" >> /home/postlemons/Manufacturing/Workers/task_log.txt'");
                printf("%sTask log updated.%s\n", GREEN, RESET);
                break;
            case 3:
                system("cat ~/Manufacturing/Workers/task_log.txt");
                break;
            case 4:
                system("sudo mkdir -p ~/Manufacturing/Workers/archive");
                system("sudo mv ~/Manufacturing/Workers/task_log.txt ~/Manufacturing/Workers/archive");
                printf("%sTask log moved to the archive directory.%s\n", GREEN, RESET);
                break;
            case 5:
                printf("%sExiting Worker Menu. (Deleting the files tree)%s\n", RED, RESET);
                system("sudo rm -rf ~/Manufacturing");
                break;
            default:
                printf("%sInvalid choice, try again.%s\n", RED, RESET);
        }
    } while (choice != 5);
}

void inspector_menu() {
    int choice;
    do {
        printf("\n=== Inspector Menu ===\n");
        printf("1. List files in /inspectors\n");
        printf("2. Log a quality issue\n");
        printf("3. View issues\n");
        printf("4. Archive resolved issues\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        system("clear");
        switch (choice) {
            case 1:
                system("ls -l ~/Manufacturing/Inspectors");
                break;
            case 2:
                system("sudo sh -c 'echo \"$(whoami) reported an issue at $(date +\\\"%c\\\")\" >> /home/postlemons/Manufacturing/Inspectors/quality_issues.txt'");
                printf("%sQuality issue logged.%s\n", GREEN, RESET);
                break;
            case 4:
                system("sudo mkdir -p ~/Manufacturing/Inspectors/archive");
                system("sudo mv ~/Manufacturing/Inspectors/quality_issues.txt ~/Manufacturing/Inspectors/archive/");
                printf("%sResolved issues archived.%s\n", GREEN, RESET);
                break;
            case 3:
                system("cat ~/Manufacturing/Inspectors/quality_issues.txt");
                break;
            case 5:
                printf("%sExiting Inspector Menu. (Deleting the files tree)%s\n", RED, RESET);
                system("sudo rm -rf ~/Manufacturing");
                break;
            default:
                printf("%sInvalid choice, try again.%s\n", RED, RESET);
        }
    } while (choice != 5);
}