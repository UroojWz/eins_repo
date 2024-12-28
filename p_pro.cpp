#include <iostream>
using namespace std;

// Global variables
const int MAX_ITEMS = 100;
int itemIDs[MAX_ITEMS];
string itemNames[MAX_ITEMS];
double itemPrices[MAX_ITEMS];
int itemQuantities[MAX_ITEMS];
int itemCount = 0;

// Function prototypes
void addItem();
void updateItem();
void viewInventory();
void generateBill();
void menu();

// Main function
int main() {
    menu();
    return 0;
}

// Menu function
void menu() {
    int choice;
    do {
        cout << "\n--- Point of Sale System ---\n";
        cout << "1. Add Item\n";
        cout << "2. Update Item\n";
        cout << "3. View Inventory\n";
        cout << "4. Generate Bill\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                updateItem();
                break;
            case 3:
                viewInventory();
                break;
            case 4:
                generateBill();
                break;
            case 5:
                cout << "Exiting... Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
}

// Add a new item
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        cout << "Inventory full! Cannot add more items.\n";
        return;
    }
    cout << "Enter item details:\n";
    cout << "ID: ";
    cin >> itemIDs[itemCount];
    cout << "Name: ";
    cin >> itemNames[itemCount];
    cout << "Price: ";
    cin >> itemPrices[itemCount];
    cout << "Quantity: ";
    cin >> itemQuantities[itemCount];
    itemCount++;
    cout << "Item added successfully!\n";
}

// Update an existing item
void updateItem() {
    int id, found = -1;
    cout << "Enter item ID to update: ";
    cin >> id;

    for (int i = 0; i < itemCount; i++) {
        if (itemIDs[i] == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        cout << "Item not found!\n";
        return;
    }

    cout << "Enter new details for item ID " << id << ":\n";
    cout << "Name: ";
    cin >> itemNames[found];
    cout << "Price: ";
    cin >> itemPrices[found];
    cout << "Quantity: ";
    cin >> itemQuantities[found];
    cout << "Item updated successfully!\n";
}

// View inventory
void viewInventory() {
    cout << "\n--- Inventory ---\n";
    cout << "ID\tName\tPrice\tQuantity\n";

    for (int i = 0; i < itemCount; i++) {
        cout << itemIDs[i] << "\t" << itemNames[i] << "\t" << itemPrices[i]
             << "\t" << itemQuantities[i] << endl;
    }
}

// Generate bill
void generateBill() {
    int id, qty, found = -1;
    double total = 0;
    char choice;

    cout << "\n--- Billing System ---\n";

    do {
        cout << "Enter item ID to purchase: ";
        cin >> id;

        for (int i = 0; i < itemCount; i++) {
            if (itemIDs[i] == id) {
                found = i;
                break;
            }
        }

        if (found == -1) {
            cout << "Item not found!\n";
        } else {
            cout << "Enter quantity: ";
            cin >> qty;

            if (qty > itemQuantities[found]) {
                cout << "Insufficient stock!\n";
            } else {
                double itemTotal = itemPrices[found] * qty;
                total += itemTotal;
                itemQuantities[found] -= qty;
                cout << "Item added to bill. Total for this item: " << itemTotal
                     << endl;
            }
        }

        cout << "Add another item? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nTotal Bill Amount: " << total << endl;
}