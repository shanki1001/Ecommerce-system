# 🛒 Mini E-commerce System (C++ CLI)

This is a simple console-based E-commerce Management System built using **C++**. It simulates basic e-commerce functionalities like user registration, login, product inventory management, cart operations, and file-based persistence using CSV files.

---

## ✨ Features

- 👤 **User System**: Register/Login as Customer or Admin
- 📦 **Inventory Management**: Add, update, delete, and view products (Admin only)
- 🛍️ **Cart System**: Customers can add/remove/view products in cart
- 💾 **Persistent Storage**: Data saved using CSV files
- 🧱 **OOP-Based Architecture**: Modular and extensible class structure

---

## 🗂️ Folder Structure

Mini-Ecommerce-System/ │ ├── include/ # Header files (.h) │ ├── User.h │ ├── Customer.h │ ├── Admin.h │ ├── Product.h │ ├── Cart.h │ └── InventoryManager.h │ ├── src/ # Source files (.cpp) │ ├── main.cpp │ ├── User.cpp │ ├── Customer.cpp │ ├── Admin.cpp │ ├── Product.cpp │ ├── Cart.cpp │ └── InventoryManager.cpp │ ├── data/ # Data files (CSV) │ ├── users.csv │ └── products.csv │ ├── Mini E-commerce System.cbp # Code::Blocks project file ├── Makefile (optional) └── README.md

yaml
Copy code

---

## ⚙️ How to Run

### 🖥️ Using Code::Blocks
1. Open `Mini E-commerce System.cbp` in Code::Blocks
2. Build & Run the project

### 🔧 Or via Terminal (Windows CMD or Git Bash)

# Navigate to bin directory after building in Code::Blocks
cd "bin/Debug"

# Run the executable
"./Mini E-commerce System.exe"
⚠️ Ensure the data/ folder is in the same path or correctly handled for reading CSV files.

📝 Technologies Used
C++ (Standard Library)

OOP Concepts

CSV File I/O

Code::Blocks (for project setup and IDE)

🚀 Future Improvements
User-friendly GUI (possibly with Qt or GTK)

Advanced authentication and password encryption

Better error handling and validations

Unit tests

🤝 Contributing
Pull requests are welcome! If you find a bug or want to improve something, feel free to fork the repo and submit a PR.

📄 License
This project is open-source and free to use under the MIT License.

🙌 Acknowledgements
Built as a learning project to understand C++ OOP, file I/O, and real-world system design.