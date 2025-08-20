#include <iostream>
#include <vector>
#include <string>

struct Record {
    int id;
    std::string name;
    std::string email;
};

class Database {
private:
    std::vector<Record> records;
    int next_id = 1;

public:
    void addRecord(const std::string& name, const std::string& email) {
        records.push_back({next_id++, name, email});
        std::cout << "Record added successfully.\n";
    }

    void viewRecords() {
        if (records.empty()) {
            std::cout << "No records found.\n";
            return;
        }
        std::cout << "ID\tName\t\tEmail\n";
        for (const auto& rec : records) {
            std::cout << rec.id << "\t" << rec.name << "\t\t" << rec.email << "\n";
        }
    }

    void deleteRecord(int id) {
        for (auto it = records.begin(); it != records.end(); ++it) {
            if (it->id == id) {
                records.erase(it);
                std::cout << "Record deleted successfully.\n";
                return;
            }
        }
        std::cout << "Record not found.\n";
    }

    void updateRecord(int id, const std::string& name, const std::string& email) {
        for (auto& rec : records) {
            if (rec.id == id) {
                rec.name = name;
                rec.email = email;
                std::cout << "Record updated successfully.\n";
                return;
            }
        }
        std::cout << "Record not found.\n";
    }
};

int main() {
    Database db;
    int choice;

    while (true) {
        std::cout << "\nDatabase Management System\n";
        std::cout << "1. Add Record\n";
        std::cout << "2. View Records\n";
        std::cout << "3. Update Record\n";
        std::cout << "4. Delete Record\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string name, email;
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter email: ";
            std::getline(std::cin, email);
            db.addRecord(name, email);
        } else if (choice == 2) {
            db.viewRecords();
        } else if (choice == 3) {
            int id;
            std::string name, email;
            std::cout << "Enter record ID to update: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Enter new name: ";
            std::getline(std::cin, name);
            std::cout << "Enter new email: ";
            std::getline(std::cin, email);
            db.updateRecord(id, name, email);
        } else if (choice == 4) {
            int id;
            std::cout << "Enter record ID to delete: ";
            std::cin >> id;
            std::cin.ignore();
            db.deleteRecord(id);
        } else if (choice == 5) {
            std::cout << "Exiting...\n";
            break;
        } else {
            // Invalid choice
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}