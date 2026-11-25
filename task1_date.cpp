#include <iomanip>
#include <iostream>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int y, int m) const {
        if (m == 2) {
            return isLeapYear(y) ? 29 : 28;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        }
        return 31;
    }

    bool isValid(int y, int m, int d) const {
        if (y < 1 || m < 1 || m > 12 || d < 1) {
            return false;
        }
        return d <= daysInMonth(y, m);
    }

    void setDefault() {
        year = 1900;
        month = 1;
        day = 1;
    }

public:
    Date(int y = 1900, int m = 1, int d = 1)
        : year(y), month(m), day(d) {
        if (!isValid(y, m, d)) {
            cout << "Invalid date. Set to 1900-01-01." << endl;
            setDefault();
        }
    }

    void Init(int y, int m, int d) {
        if (isValid(y, m, d)) {
            year = y;
            month = m;
            day = d;
        } else {
            cout << "Invalid date. Set to 1900-01-01." << endl;
            setDefault();
        }
    }

    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }

    void setYear(int y) {
        if (isValid(y, month, day)) {
            year = y;
        } else {
            cout << "Invalid year." << endl;
        }
    }

    void setMonth(int m) {
        if (isValid(year, m, day)) {
            month = m;
        } else {
            cout << "Invalid month." << endl;
        }
    }

    void setDay(int d) {
        if (isValid(year, month, d)) {
            day = d;
        } else {
            cout << "Invalid day." << endl;
        }
    }

    void display() {
        cout << setfill('0') << setw(4) << year << '-'
             << setw(2) << month << '-'
             << setw(2) << day << setfill(' ') << endl;
    }

    int calWeekday() {
        int y = year;
        int m = month;
        int d = day;

        if (m == 1 || m == 2) {
            y = y - 1;
            m = m + 12;
        }

        int weekday = (d + 2 * m + 3 * (m + 1) / 5 + y
                       + y / 4 - y / 100 + y / 400 + 1) % 7;
        if (weekday < 0) {
            weekday = weekday + 7;
        }
        return weekday;
    }
};

int main() {
    int y, m, d;
    cin >> y >> m >> d;

    Date date(y, m, d);
    const char* weekdayName[7] = {
        "星期日", "星期一", "星期二", "星期三",
        "星期四", "星期五", "星期六"
    };

    cout << "Date: ";
    date.display();
    cout << "Weekday: " << weekdayName[date.calWeekday()] << endl;

    return 0;
}
