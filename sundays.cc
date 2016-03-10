#include <iostream>

int months_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool is_leap( int year ) {
	if ( year % 400 == 0 ) return true;
    if ( year % 100 == 0 ) return false;
	return year % 4 == 0;
}

int get_days( int year, int month ) {
	if ( is_leap(year) && month == 2 ) return 29;
	return months_days[month-1];
}

int main() {
	int day = 1;
	int month = 1;
	int year = 1900;
	int weekday = 1;
	int sundays = 0;

	int month_days = get_days( year, month );
	
    while ( year < 2001 ) {
        if ( year > 1900 && weekday == 7 && day == 1 ) sundays++;		

	    day++;
        weekday++;

        if ( weekday > 7 ) weekday = 1;

        if ( day > month_days ) {
	        month++;
	        day = 1;
            month_days = get_days( year, month );
        }

        if ( month > 12 ) {
            year++;
            month = 1;
            month_days = get_days( year, month );
        }
    }

    std::cout << sundays << std::endl;
}