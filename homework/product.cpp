#include <iostream>
#include <string>

class Product {
private:
    std::string name;
    double price;
    int quantity;

public:
    // по дефолту
    Product() : name(""), price(0.0), quantity(0) {}

    // параметры
    Product(const std::string& n, double p, int q) {
        setName(n);
        setPrice(p);
        setQuantity(q);
    }

    // сеттеры с проверками
    void setName(const std::string& n) { name = n; }
    void setPrice(double p) { if (p >= 0) price = p; }
    void setQuantity(int q) { if (q >= 0) quantity = q; }

    // геттеры
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    // продажа
    void sell(int amount) {
        if (amount > 0 && quantity >= amount) {
            quantity -= amount;
        } else {
            std::cout << "Недостаточно товара!\n";
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Product apple("Яблоки", 50.0, 100);
    std::cout << "Товар: " << apple.getName() 
              << ", Цена: " << apple.getPrice() 
              << ", Количество: " << apple.getQuantity() << "\n";

    apple.sell(30);
    std::cout << "После продажи: " << apple.getQuantity() << " шт.\n";

    return 0;
}
