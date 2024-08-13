#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

    // Function to check if a year is a leap year
    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // Function to get the number of days in a given month
    int daysInMonth(int m, int y) const {
        if (m == 2) {
            return isLeapYear(y) ? 29 : 28;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        }
        return 31;
    }

    // Function to calculate the day of the year (from 1 to 365 or 366)
    int dayOfYear() const {
        int days = 0;
        for (int i = 1; i < month; ++i) {
            days += daysInMonth(i, year);
        }
        days += day;
        return days;
    }

public:
    // Constructor
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    // Overloading relational operators
    bool operator<(const Date& other) const {
        if (year != other.year)
            return year < other.year;
        if (month != other.month)
            return month < other.month;
        return day < other.day;
    }

    bool operator<=(const Date& other) const {
        return *this < other || *this == other;
    }

    bool operator>(const Date& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Date& other) const {
        return !(*this < other);
    }

    bool operator==(const Date& other) const {
        return year == other.year && month == other.month && day == other.day;
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    // Overloading the ++ operator to increment date by one day
    Date& operator++() {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    // Overloading the + operator to add a given number of days
    Date operator+(int days) const {
        Date newDate = *this;
        while (days > 0) {
            newDate.day++;
            if (newDate.day > newDate.daysInMonth(newDate.month, newDate.year)) {
                newDate.day = 1;
                newDate.month++;
                if (newDate.month > 12) {
                    newDate.month = 1;
                    newDate.year++;
                }
            }
            days--;
        }
        return newDate;
    }

    // Conversion from Date to int (to get the number of days in the current year)
    operator int() const {
        return dayOfYear();
    }

    // Display the date
    void display() const {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    Date dt1(5, 3, 2023);
    Date dt2(12, 5, 2023);

    // Comparing dates using overloaded relational operators
    if (dt1 < dt2)
        cout << "dt1 is earlier than dt2" << endl;
    else
        cout << "dt1 is not earlier than dt2" << endl;

    // Incrementing date by one day
    ++dt1;
    dt1.display(); // Should show 6/3/2023

    // Adding days to a date
    Date dt3 = dt1 + 30;
    dt3.display(); // Should show 5/4/2023

    // Converting date to an integer (day of the year)
    int days = dt1;
    cout << "Days elapsed in the current year: " << days << endl;

    return 0;
}
