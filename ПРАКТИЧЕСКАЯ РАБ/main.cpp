#include <iostream>
#include <string>

class Book {
    private:
        std::string title;
        std::string author;
        int year;
        int pages;

    public:
        Book() : title(""), author(""), year(0), pages(0) {}

        Book(std::string t, std::string a, int y, int p) {
            title = t;
            author = a;
            if (y >= 0) year = y;
            else year = 0;
            if (p > 0) pages = p;
            else pages = 0;
        }

        void setPages(int newPages) {
            if (newPages > 0) {
                pages = newPages;
            }
        }

        std::string getInfo() const {
            return "название: " + title + ", автор: " + author +
                ", год: " + std::to_string(year) +
                ", страниц: " + std::to_string(pages);
        }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Book book1("война и мир", "лев толстой", 1869, 1225);
    std::cout << book1.getInfo() << std::endl;

    book1.setPages(1300);
    std::cout << book1.getInfo() << std::endl;

    return 0;
}

