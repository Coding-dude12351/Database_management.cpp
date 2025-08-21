# Simple Database System in C++

This is a lightweight database management system written in **C++**.  
It provides a simple menu-driven interface to manage records using file storage.  

---

## ✨ Features
- Add new records  
- View all records  
- Update existing records  
- Delete records  
- exit 

---

## ⚙️ How It Works
- Each record is stored in a text file (`data.txt`).  
- Records contain fields such as **ID, Name, Age** (you can extend with more fields).  
- The system reads/writes from the file to perform database operations.  

---

## 🛠️ Build Instructions
Compile using **g++**:
```bash
g++ main.cpp -o database
