#include <iostream>

class Date {
public:
    Date(int initMonth, int initDay, int initYear) {
        setMonth(initMonth);
        setDay(initDay);
        setYear(initYear);
    }

    void setMonth(int newMonth) {
        if (newMonth < 1 || newMonth > 12) {
            month = 1;
        } else {
            month = newMonth;
        }
    }

    void setDay(int newDay) {
        if (newDay < 1) {
            day = 1;
        } else {
            day = newDay;
        }
    }

    void setYear(int newYear) {
        year = newYear;
    }

    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    void displayDate() const {
        std::cout << getMonth() << '/' << getDay() << '/' << getYear();
    }

private:
    int month{1};
    int day{1};
    int year{1900};
};

int main() {
    Date first{10, 21, 2023};
    Date second{0, 5, 1999};

    std::cout << "First date: ";
    first.displayDate();
    std::cout << '\n';

    std::cout << "Second date (corrected month): ";
    second.displayDate();
    std::cout << '\n';

    second.setMonth(13);
    second.setDay(17);
    second.setYear(2001);

    std::cout << "Second date (updated): ";
    second.displayDate();
    std::cout << '\n';

    return 0;
}
