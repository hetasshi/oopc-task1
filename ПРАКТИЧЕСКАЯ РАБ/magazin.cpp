#include <iostream>
#include <string>


class Store {
private:
    std::string address;
    std::string workingHours;
    std::string contacts;
    std::string photos;

public:
    Store() : address(""), workingHours(""), contacts("") {}

    Store(std::string addr, std::string hours, std::string cnt) {
        address = addr;
        workingHours = hours;
        contacts = cnt;
    }

    void addPhoto(std::string photo) {
        photos = photo; // если несколько фото то в vector
        // std::vector<std::string> photos; засунуть и нормально будет. Это чисто для теста
    }

    std::string getInfo() const {
        return "адрес: " + address +
            ", режим работы: " + workingHours +
            ", контакты: " + contacts;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Store store1("ул. Пушкина, 10", "9:00-21:00", "+77777777777");
    std::string phoh = "photo1.jpg";
    store1.addPhoto(phoh);
    std::cout << store1.getInfo() << std::endl;

    return 0;
}
