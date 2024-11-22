#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    string name;
    double price;
    bool isOnPromotion;
    string category;

public:
    Product(string name = "", double price = 0.0, bool isOnPromotion = false, string category = "") {
        this->name = name;
        this->price = price;
        this->isOnPromotion = isOnPromotion;
        this->category = category;
    }

    string getName() { return name; }
    double getPrice() { return price; }
    bool getIsOnPromotion() { return isOnPromotion; }
    string getCategory() { return category; }

    void updateProduct(string newName, double newPrice, bool newIsOnPromotion, string newCategory) {
        name = newName;
        price = newPrice;
        isOnPromotion = newIsOnPromotion;
        category = newCategory;
    }

    void displayProduct() {
        cout << "Product Name: " << name << ", Price: $" << price << ", Category: " << category;
        cout << ", On Promotion: ";
        if (isOnPromotion) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
};

// Category class representing a product category
class Category {
private:
    string name;
    Product* products;  // Array of Products
    int productCount;
    int maxProducts;

public:
    Category(string name, int maxProducts) : name(name), maxProducts(maxProducts), productCount(0) {
        products = new Product[maxProducts];  // Dynamically allocate memory for products
    }

    string getName() { return name; }

    void addProduct(const Product& product) {
        if (productCount < maxProducts) {
            products[productCount++] = product;  // Add product to the array
        }
        else {
            cout << "Category is full, cannot add more products." << endl;
        }
    }

    void removeProduct(string productName) {
        for (int i = 0; i < productCount; ++i) {
            if (products[i].getName() == productName) {
                for (int j = i; j < productCount - 1; ++j) {
                    products[j] = products[j + 1];  // Shift products left
                }
                --productCount;  // Decrease product count
                break;
            }
        }
    }

    void displayProducts() {
        cout << "Category: " << name << endl;
        for (int i = 0; i < productCount; ++i) {
            products[i].displayProduct();
        }
    }

    ~Category() {
        delete[] products;  // Clean up allocated memory
    }
};

// Main program
int main() {
    Category electronics("Electronics", 5);
    Category fashion("Fashion", 5);
   
    Product laptop("Laptop", 999.99, true, "Electronics");
    Product phone("Phone", 699.99, false, "Electronics");
    Product shirt("Shirt", 29.99, true, "Fashion");

    electronics.addProduct(laptop);
    electronics.addProduct(phone);
    fashion.addProduct(shirt);

    electronics.displayProducts();
    fashion.displayProducts();

    return 0;
}
