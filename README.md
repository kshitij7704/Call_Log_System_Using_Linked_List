# Call Log System Using Linked List
The Call Log System is a C-based program designed to manage call logs and contact information using linked lists. This system allows users to store and manage call history, contacts, and related functionalities efficiently. The primary data structure used is a linked list, where each node represents a contact and contains another linked list to store the call logs for that particular contact.

## Features
1. <b>Add Call Log</b>: Add a new call log to an existing contact or create a new contact if it does not exist.
2. <b>Retrieve Call Logs</b>: Display the call history of a specified contact.
3. <b>Clear Call Logs</b>: Remove all call logs for a specified contact.
4. <b>Delete Contact</b>: Remove a contact and all associated call logs from the system.
5. <b>Validate Input</b>: Check the validity of entered phone numbers and call durations.

## Data Structures
### 1. struct call
This structure stores information about individual call logs:
1. <b>char time[20]</b>: Time of the call.
2. <b>int duration</b>: Duration of the call in seconds.
3. <b>char status</b>: Status of the call (Incoming, Rejected, Outgoing, Didn't Connect, Network Error).
4. <b>struct call *next</b>: Pointer to the next call log.
### 2. struct contact
This structure stores information about contacts:
1. <b>char name[20]</b>: Name of the contact.
2. <b>int number</b>: Phone number of the contact.
3. <b>struct call *history</b>: Pointer to the linked list of call logs.
4. <b>struct contact *next</b>: Pointer to the next contact.
## Global Variable
1. <b>struct contact *firstContact</b>: Pointer to the first contact in the linked list.
## Functions
1. <b>void call(int number, int duration, char status, char time[])</b>: Handles the process of making a call. It creates a new call log, adds it to an existing contact, or creates a new contact if necessary.
2. <b>void getLogs(int number)</b>: Retrieves and displays the call logs for a specified contact.
3. <b>void clearLogs(int number)</b>: Clears all call logs for a specified contact.
4. <b>void deleteContact(int number)</b>: Deletes a contact and all associated call logs from the system.
5. <b>void checkNumber(int number)</b>: Validates the entered phone number. Ensures it is a 10-digit number.
6. <b>void checkDuration(int duration)</b>: Validates the entered call duration. Ensures it is a positive value.
7. <b>int main()</b>: The main function provides an interface for the user to interact with the system. It includes options to add call logs, retrieve call logs, clear logs, delete contacts, and exit the program.

## Usage
1. <b>Compile the program</b>: Use a C compiler to compile the program.
2. <b>Follow the menu</b>: Use the displayed menu to interact with the system. Options include:<br>
    a. To call number<br>
    b. To get the call logs<br>
    c. To clear logs of a number<br>
    d. To delete a contact<br>
    e. To exit the call log system<br>
