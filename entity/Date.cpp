#include "Date.h"

// Default constructor
Date::Date() : _day(1), _month(1), _year(1970) {}

// Parameterized constructor
Date::Date(int day, int month, int year) : _day(day), _month(month), _year(year) {}

// Getter methods
int Date::day() const {
    return _day;
}

int Date::month() const {
    return _month;
}

int Date::year() const {
    return _year;
}

// Setter methods
void Date::setDay(int day) {
    _day = day;
}

void Date::setMonth(int month) {
    _month = month;
}

void Date::setYear(int year) {
    _year = year;
}


/// @brief Calculate the number of days left from the current date to the given date
/// @param date 
/// @return positive integer representing the number of days left if the given date is in the future, else negative integer
int Date::dayLeft(Date date) const{
    // Get current time
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    // Create a tm structure for the given date
    tm futureDate = {};
    futureDate.tm_year = date.year() - 1900; // tm_year is years since 1900
    futureDate.tm_mon = date.month() - 1;    // tm_mon is 0-based
    futureDate.tm_mday = date.day();

    // Convert both dates to time_t
    time_t currentTime = mktime(now);
    time_t futureTime = mktime(&futureDate);

    // Calculate the difference in seconds and convert to days
    /// @note difftime returns the difference in seconds
    // double difftime(time_t end, time_t beginning) in time.h;
   
    double difference = difftime(futureTime, currentTime);
    int daysLeft = static_cast<int>(difference / (60 * 60 * 24));

    return daysLeft;
}

// Override toString method
string Date::toString() const { return "Date"; }