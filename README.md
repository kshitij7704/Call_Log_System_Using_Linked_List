# 📞 Call Log System Using Linked List

The **Call Log System** is a C-based program designed to manage call logs and contact information using **linked lists**. This system allows users to efficiently store and manage call history, contacts, and related functionalities.

---

## 🚀 Features

1. **Add Call Log**: Add a new call log to an existing contact or create a new contact if it does not exist.
2. **Retrieve Call Logs**: Display the call history of a specified contact.
3. **Clear Call Logs**: Remove all call logs for a specified contact.
4. **Delete Contact**: Remove a contact and all associated call logs from the system.
5. **Validate Input**: Check the validity of entered phone numbers and call durations.

---

## 🧠 Data Structures

### 1. `struct call`
Stores individual call log details:
- `char time[20]`: Time of the call.
- `int duration`: Duration of the call in seconds.
- `char status`: Status of the call (`Incoming`, `Rejected`, `Outgoing`, `Didn't Connect`, `Network Error`).
- `struct call *next`: Pointer to the next call log.

### 2. `struct contact`
Stores contact information:
- `char name[20]`: Name of the contact.
- `int number`: Phone number of the contact.
- `struct call *history`: Pointer to the contact's call logs.
- `struct contact *next`: Pointer to the next contact in the list.

---

## 🌐 Global Variable

- `struct contact *firstContact`: Pointer to the first contact in the linked list.

---

## 🧩 Functions

- `void call(int number, int duration, char status, char time[])`: Adds a call log or creates a new contact.
- `void getLogs(int number)`: Displays call logs for a contact.
- `void clearLogs(int number)`: Deletes all call logs for a contact.
- `void deleteContact(int number)`: Removes the contact and their call logs.
- `void checkNumber(int number)`: Validates the phone number (must be 10 digits).
- `void checkDuration(int duration)`: Validates the call duration (must be positive).
- `int main()`: Menu-driven interface for user interaction.

---

## 🛠️ Usage

1. **Compile the program**:  
   Use a C compiler (like `gcc`) to compile:
   ```
   gcc -o call_log_system main.c
   ```
2. **Run the executable**:
    ```
    ./call_log_system
    ```
3. **Follow the on-screen menu**: <br>
  ```1```: Call number <br>
  ```2```:Get the call logs <br>
  ```3```: Clear logs of a number <br>
  ```4```: Delete a contact <br>
  ```5```: Exit the call log system <br>

---
