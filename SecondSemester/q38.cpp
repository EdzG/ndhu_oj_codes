#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define MAXN 128
#define NEEDED 1

// Days in each month, 0 index is a placeholder to match month indexing
int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {
public:
    int value;
    // Default constructor
    Date() {};

    // Constructor to initialize date with an integer value (format YYYYMMDD)
    Date(const int d) : value(d) {};

    // Function to check if a given year is a leap year
    bool isLeapYear(int year) const {
        return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
    }

    // Function to get the next day from the current date
    Date nextDay() const {
        int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = value / 10000, month = value % 10000 / 100, day = value % 100;

        // Adjust February days in a leap year
        if (isLeapYear(year))
            days_in_month[2] = 29;

        day++;

        // Adjust the date if it exceeds the number of days in the current month
        if (day > days_in_month[month]) {
            day = 1;
            month++;
        }

        // Adjust the date if it exceeds the number of months in the year
        if (month == 13) {
            month = 1;
            year++;
        }

        // Return the new date
        return Date(year * 10000 + month * 100 + day);
    }

    // Function to get the previous day from the current date
    Date previousDay() const {
        int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = value / 10000, month = value % 10000 / 100, day = value % 100;

        // Adjust February days in a leap year
        if (isLeapYear(year))
            days_in_month[2] = 29;

        // Adjust the date if it's the first day of January
        if (month == 1 && day == 1) {
            year--;
            month = 12;
            day = 31;
        } else {
            day--;
            // Adjust the date if it goes below the first day of the current month
            if (day < 1) {
                month--;
                day = days_in_month[month];
            }
        }

        // Return the new date
        return Date(year * 10000 + month * 100 + day);
    }

    // Overload the output stream operator to print the date in MM/DD/YYYY format
    friend std::ostream& operator<<(std::ostream& out, const Date& d) {
        out << d.value % 10000 / 100 << "/" << d.value % 100 << "/" << d.value / 10000;
        return out;
    }
};

class DateRange {
public:
    int start, end;
    // Default constructor
    DateRange() {}; 
    // Constructor to initialize the date range
    DateRange(int s, int e) : start(s), end(e) {};
};

class StockQuoteManager {
    std::map<int, int> calendar; // Maps dates to indices
    std::vector<DateRange> pastRequests; // Vector of past date ranges
    std::vector<DateRange> newRequests; // Vector of new date ranges
    int NX, NR; // Number of past and new date ranges

public:
    StockQuoteManager() {};

    // Function to record a date and its adjacent days in the calendar
    void record(int date) {
        calendar[date] = 0;
        calendar[Date(date).nextDay().value] = 0;
        calendar[Date(date).previousDay().value] = 0;
    }

    // Function to clear all stored data
    void clear() {
        calendar.clear();
        pastRequests.clear();
        newRequests.clear();
    }

    // Function to process all input requests and determine the required quotes
    void processRequests() {
        int start, end, i, j, size, cases = 0;

        // Read the number of past and new requests until NX + NR is zero
        while (std::cin >> NX >> NR && (NX + NR)) {
            clear();

            // Read past requests and record the dates
            for (i = 0; i < NX; ++i) {
                std::cin >> start >> end;
                pastRequests.push_back(DateRange(start, end));
                record(start);
                record(end);
            }

            // Read new requests and record the dates
            for (i = 0; i < NR; ++i) {
                std::cin >> start >> end;
                newRequests.push_back(DateRange(start, end));
                record(start);
                record(end);
            }

            size = 0;
            std::vector<Date> date;

            // Assign unique indices to dates in the calendar
            for (auto it = calendar.begin(); it != calendar.end(); it++) {
                it->second = size++;
                date.push_back(Date(it->first));
            }

            // Mark the requested dates in the calendar
            std::vector<int> mark(size, 0);
            for (i = 0; i < NR; ++i) {
                start = calendar[newRequests[i].start];
                end = calendar[newRequests[i].end];
                for (j = start; j <= end; ++j) 
                    mark[j] = NEEDED;
            }

            // Mark the available quotes from past requests
            for (i = 0; i < NX; ++i) {
                start = calendar[pastRequests[i].start];
                end = calendar[pastRequests[i].end];
                for (j = start; j <= end; ++j) 
                    mark[j] = !NEEDED;
            }

            // Output the results
            std::cout << "Case " << ++cases << ":\n";
            bool quoteNeeded = false;

            for (i = 0; i < mark.size(); ++i) {
                if (mark[i] == NEEDED) {
                    quoteNeeded = true;
                    std::cout << date[i];

                    // Traverse and print continuous ranges
                    if (i + 1 < mark.size() && mark[i + 1] == NEEDED) {
                        std::cout << " to ";
                        while (i + 1 < mark.size() && mark[i + 1] == NEEDED)
                            i++;
                        std::cout << date[i];
                    }
                    std::cout << std::endl;
                }
            }

            // If no additional quotes are needed, print a message
            if (!quoteNeeded) 
                std::cout << "No additional quotes are required.\n";
        }
    }
};

int main() {
    StockQuoteManager manager;
    manager.processRequests();
    return 0;
}
