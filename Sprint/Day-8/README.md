# 🏦 Noble Bank Management System (C++)

---

## **__Project Overview__**
This project is a **console-based Banking System** written in **C++**, inspired by a medieval–themed narrative where a *noble* enters the halls of finance.  
Behind the dramatic narration lies a **robust, structured banking system** that focuses on **data integrity, validation, persistence, and clean STL usage**.

The project goes **beyond the original PDF requirements**, implementing real-world safeguards and logical constraints expected in actual banking software.

---

## **__Core Features__**

### **__Entry Point__**
- User is welcomed with a dramatic introduction.
- Two clear paths:
  - **Login** (existing noble)
  - **Register** (new noble)
- Input validation ensures:
  - Only numeric choices are accepted
  - Invalid input does not crash the program

---

### **__Registration System__**
- Ensures **username uniqueness** using `std::map`
- Password is securely associated with the username
- Automatically generates a **unique account number**
- User selects account type:
  - **Savings Account**
  - **Current Account**
- If registration fails at any stage:
  - The partially created user is **safely erased**
- All inputs are validated to prevent corruption

---

### **__Login System__**
- Username lookup via `std::map::find`
- Password verification
- Unlimited retries, but logically tracked
- Resets failure count on successful login

---

### **__Account Types__**

#### **Savings Account**
- Minimum balance enforced (`Rs. 1000`)
- Withdrawals blocked if minimum balance rule is violated

#### **Current Account**
- No minimum balance restriction
- Designed for high transaction flow

---

## **__Banking Operations__**

### **Deposit**
- Rejects:
  - Non-numeric input
  - Zero or negative deposits
- Successful deposits:
  - Update balance
  - Generate transaction ID
  - Log transaction to file

---

### **Withdraw**
- Rejects:
  - Non-numeric input
  - Negative withdrawal values
- Enforces:
  - Minimum balance rule (Savings Account)
  - Insufficient balance check
- Flags:
  - Large withdrawals (`> Rs. 50,000`)
- Tracks failed attempts and warns after multiple failures

---

### **Check Balance**
- Displays current balance safely
- No modification to data

---

### **Transaction History**
- Persistent transaction logging using file handling
- Displays **only the logged-in user's transactions**
- Each transaction includes:
  - Transaction ID
  - Type (Deposit / Withdraw)
  - Amount
  - Status (SUCCESS / FAILED)

---

### **Logout**
- Saves all data before exit
- Gracefully terminates the program

---

## **__Data Persistence__**
- User data stored in:
  - `users.txt`
- Transaction logs stored in:
  - `transactions.txt`
- Data is:
  - Loaded at program start
  - Saved after every critical operation
- Ensures continuity across program restarts

---

## **__STL Usage__**
- `std::map`  
  → Used to map **username → credentials**
- `std::string`  
  → For secure text handling
- Iterators  
  → Safe traversal and modification of map entries

---

## **__Input Validation & Safety__**
- Every `cin` operation is validated using:
  - `cin.fail()`
  - `cin.clear()`
  - `cin.ignore()`
- Prevents:
  - Crashes
  - Infinite loops
  - Corrupted state
- Ensures program stability even with malicious input

---

## **__Narrative Design__**
While the system is technically strong, it is wrapped in a **dramatic medieval-style narration**:
- The bank is portrayed as a grand vault
- The user as a noble
- Transactions as sacred movements of gold

This makes the experience engaging **without compromising clarity or logic**.

---

## **__Extra Enhancements Beyond PDF__**
- Username uniqueness enforcement
- Full input validation
- Persistent storage
- Transaction logging
- Failure tracking
- Minimum balance rules
- Large transaction warnings
- Clean modular function design

---

## **__Final Note__**
This project demonstrates a transition from **basic C++** to **real-world STL-based programming**, combining:
- Object-oriented design
- File handling
- Data validation
- Logical flow control

It reflects not just learning syntax — but **thinking like a software engineer**.

---

## **__Author__**
**Ammar Husain**

> *“Gold is counted not by greed, but by honour and record.”*
