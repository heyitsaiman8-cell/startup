#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class ShippingAddress {
private:
    string city;
    string street;

public:
    ShippingAddress(string c = "", string s = "")
        : city(c), street(s) {
    }

    void display() const {
        cout << "Shipping Address:\n";
        cout << "City: " << city << endl;
        cout << "Street: " << street << endl;
    }
};

class PaymentInfo {
private:
    string method;

public:
    PaymentInfo(string m = "") : method(m) {}

    void display() const {
        cout << "Payment Method: " << method << endl;
    }
};

class OrderItem {
private:
    string itemName;
    int quantity;
    double price;

public:
    OrderItem(string n = "", int q = 0, double p = 0)
        : itemName(n), quantity(q), price(p) {
    }

    double getTotal() const {
        return quantity * price;
    }

    void display() const {
        cout << left << setw(15) << itemName
            << setw(10) << quantity
            << setw(10) << price
            << setw(10) << getTotal() << endl;
    }
};

class Order {
private:
    ShippingAddress address;
    PaymentInfo payment;
    OrderItem items[5];

    int itemCount;

public:
    Order(string city, string street, string payMethod)
        : address(city, street), payment(payMethod) {

        itemCount = 0;
    }

    void addItem(string name, int qty, double price) {
        if (itemCount < 5) {
            items[itemCount++] = OrderItem(name, qty, price);
        }
        else {
            cout << "Order is full!\n";
        }
    }

    double grandTotal() const {
        double total = 0;

        for (int i = 0; i < itemCount; i++) {
            total += items[i].getTotal();
        }

        return total;
    }

        friend ostream& operator<<(ostream& out, const Order& o);
};

ostream& operator<<(ostream& out, const Order& o) {

    out << "\n======= ORDER RECEIPT =======\n\n";

    o.address.display();
    cout << endl;

    o.payment.display();
    cout << endl;

    out << left << setw(15) << "Item"
        << setw(10) << "Qty"
        << setw(10) << "Price"
        << setw(10) << "Total" << endl;

    cout << "-----------------------------------\n";

    for (int i = 0; i < o.itemCount; i++) {
        o.items[i].display();
    }

    cout << "-----------------------------------\n";

    out << "Grand Total: " << o.grandTotal() << endl;

    return out;
}

int main() {

    Order order("Lahore", "Main Boulevard", "Credit Card");

    order.addItem("Laptop", 1, 85000);
    order.addItem("Mouse", 2, 1500);
    order.addItem("Keyboard", 1, 3500);

    cout << order;

    return 0;
}
