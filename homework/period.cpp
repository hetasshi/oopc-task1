#include <iostream>

class TimePeriod {
private:
    int start; // в секундах если что
    int end;

public:
    // конструктор с проверкой
    TimePeriod(int s, int e) {
        if (e >= s) {
            start = s;
            end = e;
        }
        else {
            start = end = s; // start = end если при ошибке
            std::cerr << "Ошибка: конец раньше начала!\n";
        }
    }

    // сеттеры с проверкой
    void setStart(int s) {
        if (s <= end) start = s;
        else std::cerr << "Ошибка: начало позже конца!\n";
    }

    void setEnd(int e) {
        if (e >= start) end = e;
        else std::cerr << "Ошибка: конец раньше начала!\n";
    }

    // геттеры
    int getStart() const { return start; }
    int getEnd() const { return end; }

    // в секундах, минутах, часах
    int getDurationInSeconds() const { return end - start; }
    double getDurationInMinutes() const { return getDurationInSeconds() / 60.0; }
    double getDurationInHours() const { return getDurationInSeconds() / 3600.0; }


    bool isPositive() const { return (end >= start); }
};

int main() {
    setlocale(LC_ALL, "Rus");
    TimePeriod meeting(3600, 7200);
    std::cout << "Продолжительность: "
        << meeting.getDurationInHours() << " ч.\n";

    meeting.setEnd(1800); // ерорка для теста
    std::cout << "Корректный период? "
        << (meeting.isPositive() ? "Да" : "Нет") << "\n";

    return 0;
}
