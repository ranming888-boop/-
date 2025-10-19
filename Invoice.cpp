#include <iostream>
#include <string>

class Invoice {
public:
    Invoice(const std::string &number, const std::string &description,
            int quantity, int price)
        : partNumber(number), partDescription(description), quantity(0), pricePerItem(0) {
        setQuantity(quantity);
        setPrice(price);
    }

    void setPartNumber(const std::string &number) {
        partNumber = number;
    }

    const std::string &getPartNumber() const {
        return partNumber;
    }

    void setPartDescription(const std::string &description) {
        partDescription = description;
    }

    const std::string &getPartDescription() const {
        return partDescription;
    }

    void setQuantity(int qty) {
        if (qty < 0) {
            quantity = 0;
        } else {
            quantity = qty;
        }
    }

    int getQuantity() const {
        return quantity;
    }

    void setPrice(int price) {
        if (price < 0) {
            pricePerItem = 0;
        } else {
            pricePerItem = price;
        }
    }

    int getPrice() const {
        return pricePerItem;
    }

    int getInvoiceAmount() const {
        return quantity * pricePerItem;
    }

private:
    std::string partNumber;
    std::string partDescription;
    int quantity;
    int pricePerItem;
};

int main() {
    Invoice invoice{"A-1001", "USB-C Cable", 5, 25};

    std::cout << "Part Number: " << invoice.getPartNumber() << '\n';
    std::cout << "Description: " << invoice.getPartDescription() << '\n';
    std::cout << "Quantity: " << invoice.getQuantity() << '\n';
    std::cout << "Price per item: " << invoice.getPrice() << '\n';
    std::cout << "Total amount: " << invoice.getInvoiceAmount() << '\n';

    Invoice invalid{"B-0001", "Negative Test", -10, -5};
    std::cout << "\nAfter correcting negatives:" << '\n';
    std::cout << "Quantity: " << invalid.getQuantity() << '\n';
    std::cout << "Price per item: " << invalid.getPrice() << '\n';
    std::cout << "Total amount: " << invalid.getInvoiceAmount() << '\n';

    return 0;
}
