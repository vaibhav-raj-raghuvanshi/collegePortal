# 🎓 College Portal - Attendance Management System - C++ Console Project

> **2nd Semester Mini Project**  
> Developed by: [Vaibhav Raj Singh](https://github.com/Vaibhav-Raj-Raghuvanshi)  
> Contributed by: [Somesh Varshney](https://github.com/SomeshVarshney)  

---

## 📌 Project Overview

The **Attendance Management System** is a feature-rich console-based C++ project designed to manage student attendance efficiently. It offers three roles with secure login and interactive portals:

- 👨‍🎓 **Student**
- 👩‍🏫 **Teacher**
- 👨‍💼 **Admin**

Each role provides different functionalities like managing attendance, resetting credentials, and secure access control through a confidential code mechanism.

---

## 🚀 Features

### 👨‍🎓 Student Portal
- View personal attendance (CSE, ECS, Others)
- Reset username and email
- Update password (requires uppercase, lowercase, digit, special character)
- Password recovery via a unique confidential code

### 👩‍🏫 Teacher Portal
- Update attendance for batches by department
- Reset username and email
- Update password with validation
- Confidential code-based password recovery

### 👨‍💼 Admin Portal
- Add new students (auto-generated username, password, batch, roll number)
- View registered teacher details
- Reset student or teacher passwords
- Default teachers initialized at startup

### 📂 File Handling
- All student records are stored in `STUDENT'S_DATA.txt`
- Includes attendance data, personal details, login credentials
- Persistent storage using `fstream` for read/write operations

### 🔐 Confidential Code Generator
- A unique **confidential code (CONFID)** is auto-generated on registration
- Used for password recovery in case of forgotten credentials
- For students: based on `mail`, `father_name`, `name` (with randomization)
- For teachers: based on `department` and `name`
- Adds an extra layer of **security & personalization**

---

## 🧱 Tech Stack

- **Language**: C++
- **Platform**: Windows  
  *(uses `windows.h`, `conio.h` for UI control)*
- **File Storage**: Plain text file (`STUDENT'S_DATA.txt`)
- **Compiler**: g++ / Code::Blocks / Visual Studio

---

## 📸 Screenshots (Optional)

> Add screenshots of:
> - Login portal
> - Student attendance view
> - Teacher attendance update interface
> - Admin dashboard

---

## 🧑‍💻 How to Run

1. **Clone this repository**
   ```bash
   git clone https://github.com/Vaibhav-Raj-Raghuvanshi/attendance-management-system
