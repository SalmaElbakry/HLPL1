#include "std_lib_facilities.h"
//Drill 9 Q1


struct Date
{
	int y;
	int m;
	int d;
};

// -----------------------------------------------------------------------------

void init_date(Date& date, int yy, int mm, int dd)
{
	if (yy < 0 || mm < 0 || mm > 12 || dd < 0  || dd > 31)
		error ("Invalid date"); // why did we use in mm & dd "< 0" not "< 1"
	else
	{
		date.y = yy;
		date.m = mm;
		date.d = dd;
		
	}
}

// -----------------------------------------------------------------------------

void add_day(Date& date, int n)
{
	//increase date by n days
	date.d += n;
}

// -----------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
	return os << d.y
		<< "." << d.m
		<< "." << d.d ;
}

// -----------------------------------------------------------------------------

int main()
try {
	Date today;
	Date invalid;
	
	init_date(today, 1978, 6, 25);
	
	Date tomorrow(today);

	add_day(tomorrow, 1);

	cout << today << endl;
			
	cout << tomorrow << endl;

	//invalid date
		
	init_date(invalid, 2004, 13, -5);
	
	cout << invalid << endl;

	return 0;
} catch (exception& e) {
	cerr << e.what() <<endl;
	return 1;
}




