#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store call information
struct call {
    char time[20];
    int duration;
    char status;
    struct call *next;
};

// Structure to store contact information
struct contact {
    char name[20];
    int number;
    struct call *history;
    struct contact *next;
};

struct contact *firstContact;

// Function to handle call request
void call(int number, int duration, char status, char time[]) {
    struct call *newCall = (struct call *)malloc(sizeof(struct call));
    newCall->duration = duration;
    strcpy(newCall->time, time);
    newCall->status = status;
    newCall->next = NULL;

    struct contact *ptr = firstContact;
    if (ptr == NULL) {
        printf("\nCreating New Contact\n");
        struct contact *newContact = (struct contact *)malloc(sizeof(struct contact));
        newContact->number = number;
        printf("\nThe Contact Number is not in the List\nEnter The name to save the contact: ");
        scanf("%s", newContact->name);
        newContact->history = newCall;
        newContact->next = NULL;
        firstContact = newContact;
    } else {
        int flag = 0;
        struct contact *prev = NULL;
        while (ptr != NULL) {
            if (ptr->number == number) {
                printf("\nContact Found\n");
                flag = 1;
                break;
            } else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        if (flag == 0) {
            struct contact *newContact = (struct contact *)malloc(sizeof(struct contact));
            newContact->number = number;
            printf("\nThe Contact Number is not in the List\nEnter The name to save the contact: ");
            scanf("%s", newContact->name);
            newContact->history = newCall;
            newContact->next = NULL;
            prev->next = newContact;
        } else {
            printf("\nAdding To Logs of %s \n", ptr->name);
            newCall->next = ptr->history;
            ptr->history = newCall;
        }
    }
}

// Function to get call logs of a contact
void getLogs(int number) {
    struct contact *ptr = firstContact;
    printf("Getting Logs....\n");
    if (ptr == NULL) {
        printf("No Contact Found As Directory Is Empty");
    } else {
        int flag = 0;
        while (ptr != NULL) {
            if (ptr->number == number) {
                flag = 1;
                struct call *callPtr = ptr->history;
                if (callPtr == NULL) {
                    printf("No Calls For now\n");
                } else {
                    printf("Name - %s\n", ptr->name);
                    while (callPtr != NULL) {
                        printf("---------------------------------------------------------------\n");
                        switch (callPtr->status) {
                            case 'I':
                                printf("Call Status : Incoming\n");
                                break;
                            case 'R':
                                printf("Call Status : Rejected\n");
                                break;
                            case 'O':
                                printf("Call Status : Outgoing\n");
                                break;
                            case 'D':
                                printf("Call Status : Didn't Connect\n");
                                break;
                            case 'N':
                                printf("Call Status : Network Error\n");
                                break;
                            default:
                                break;
                        }
                        int h, m, s;
                        h = callPtr->duration / 3600;
                        m = (callPtr->duration - 3600 * h) / 60;
                        s = (callPtr->duration - 3600 * h - 60 * m);
                        printf("Call Duration: %d : %d : %d\n", h, m, s);
                        printf("Call Time: %s\n", callPtr->time);
                        callPtr = callPtr->next;
                    }
                    printf("---------------------------------------------------------------\n\n");
                }
                flag = 1;
                break;
            } else {
                ptr = ptr->next;
            }
        }
        if (flag == 0) {
            printf("No Records for the Number: %d\n", number);
        }
    }
}

// Function to clear logs of a contact
void clearLogs(int number) {
    struct contact *ptr = firstContact;
    if (ptr == NULL) {
        return;
    }
    int flag = 0;
    while (ptr != NULL) {
        if (ptr->number == number) {
            flag = 1;
            break;
        } else {
            ptr = ptr->next;
        }
    }
    if (flag) {
        if (ptr->history != NULL) {
            while (ptr->history != NULL) {
                struct call *prev = ptr->history;
                if (prev->next == NULL) {
                    ptr->history = NULL;
                    free(prev);
                } else {
                    struct call *callPtr = prev->next;
                    while (callPtr->next != NULL) {
                        prev = prev->next;
                        callPtr = callPtr->next;
                    }
                    prev->next = NULL;
                    free(callPtr);
                }
            }
            printf("Deleted All The Logs Successfully\n");
        } else {
            printf("The Logs Are All Cleared\n");
        }
    } else {
        printf("Contact Not Found\n");
    }
}

// Function to delete a contact
void deleteContact(int number) {
    struct contact *prev = firstContact;
    struct contact *ptr = firstContact;
    if (prev == NULL) {
        return;
    }
    if (prev->next == NULL) {
        if (prev->number == number) {
            clearLogs(number);
            firstContact = NULL;
            free(prev);
        } else {
            printf("Contact Not Found To Delete\n");
        }
    } else {
        ptr = firstContact->next;
        int flag = 0;
        do {
            if (ptr->number == number) {
                flag = 1;
                break;
            } else {
                ptr = ptr->next;
                prev = prev->next;
            }
        } while (ptr->next != NULL);
        if (flag) {
            clearLogs(number);
            prev->next = ptr->next;
            free(ptr);
        } else {
            printf("Contact Not Found To Delete\n");
        }
    }
}

// Function to check if the entered number is valid or not
void checkNumber(int number) {
    int count = 0;
    while (number != 0) {
        number = number / 10;
        count++;
    }
    if (count != 10) {
        printf("---------------------------------------------------------------\n");
        printf("Invalid mobile number!\n");
        printf("Please enter a valid number\n");
        exit(1);
    }
}

// Function to check if the entered duration is valid or not
void checkDuration(int duration) {
    if (duration <= 0) {
        printf("---------------------------------------------------------------\n");
        printf("Invalid duration!\n");
        printf("Please enter a non-negative value\n");
        exit(1);
    }
}

// Main function
int main() {
    firstContact = NULL;
    int opt;
    printf("\n---------------------------------------------------------------\n");
    printf("CALL LOG SYSTEM");
    do {
        printf("\n---------------------------------------------------------------\n");
        printf("Enter the following choices to perform operations on call logs:\n");
        printf("1. To call number\n");
        printf("2. To get the call logs\n");
        printf("3. To clear logs of a number\n");
        printf("4. To delete a contact\n");
        printf("5. To exit the call log system\n");
        scanf("%d", &opt);
        switch (opt) {
            case 1: {
                int number, duration, callType;
                char time[7], status;
                printf("Enter the number you want to call: ");
                scanf("%d", &number);
                checkNumber(number);
                printf("Please select the call status:\n");
                printf("1. Incoming call\n");
                printf("2. Declined/Rejected call\n");
                printf("3. Outgoing call\n");
                printf("4. Unable to connect\n");
                printf("5. Network error\n");
                scanf("%d", &callType);
                switch (callType) {
                    case 1:
                        status = 'I';
                        printf("Enter the duration of call in seconds: ");
                        scanf("%d", &duration);
                        checkDuration(duration);
                        break;
                    case 2:
                        status = 'R';
                        duration = 0;
                        break;
                    case 3:
                        status = 'O';
                        printf("Enter the duration of call in seconds: ");
                        scanf("%d", &duration);
                        checkDuration(duration);
                        break;
                    case 4:
                        status = 'D';
                        duration = 0;
                        break;
                    case 5:
                        status = 'N';
                        duration = 0;
                        break;
                    default:
                        printf("Invalid call status\n");
                }
                printf("Enter the time (ex. 12:45): ");
                scanf("%s", time);
                call(number, duration, status, time);
                break;
            }
            case 2: {
                int number;
                printf("Enter a number to get call logs: ");
                scanf("%d", &number);
                getLogs(number);
                break;
            }
            case 3: {
                int number;
                printf("Enter a number to clear logs of a contact: ");
                scanf("%d", &number);
                clearLogs(number);
                break;
            }
            case 4: {
                int number;
                printf("Enter a number to delete a contact: ");
                scanf("%d", &number);
                deleteContact(number);
                break;
            }
            case 5: {
                printf("---------------------------------------------------------------\n");
                printf("\nExiting the program\n");
                break;
            }
            default:
                printf("Invalid operation choice\n");
        }
    } while (opt != 5);
    return 0;
}