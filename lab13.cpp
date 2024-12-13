#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(string name, double price) : name(name), price(price) {}

    string getName() const { return name; }
    void setName(string name) { this->name = name; }

    double getPrice() const { return price; }
    void setPrice(double price) { this->price = price; }

    virtual double getFinalPrice() const = 0;
};

class Discountable {
public:
    virtual double applyDiscount(double price) const = 0; // Зроблено const
};

class Book : public Product, public Discountable {
public:
    Book(string name, double price) : Product(name, price) {}

    double applyDiscount(double price) const override {
        return price * 0.9; // Знижка 10%
    }

    double getFinalPrice() const override {
        return applyDiscount(price);
    }
};

class Pen : public Product, public Discountable {
public:
    Pen(string name, double price) : Product(name, price) {}

    double applyDiscount(double price) const override {
        if (price > 5) {
            return price - 5;
        }
        return price;
    }

    double getFinalPrice() const override {
        return applyDiscount(price);
    }
};

int main() {
    Book book("C++ Programming", 300.0);
    Pen pen("Blue Pen", 10.0);

    cout << "Product: " << book.getName() << endl;
    cout << "Base Price: " << book.getPrice() << " UAH" << endl;
    cout << "Final Price after Discount: " << book.getFinalPrice() << " UAH" << endl << endl;

    cout << "Product: " << pen.getName() << endl;
    cout << "Base Price: " << pen.getPrice() << " UAH" << endl;
    cout << "Final Price after Discount: " << pen.getFinalPrice() << " UAH" << endl;

    return 0;
}
