#include "std_lib_facilities.h"

//Drill 9 Q2

struct Date
{
	int y;
	int m;
	int d;
	
//void init_date(Date& date, int yy, int mm, int dd)
Date(int yy, int mm, int dd)
{
	if (yy < 0 || mm < 0 || mm > 12 || dd < 0  || dd > 31)
		error ("Invalid date"); // why did we use in mm & dd "< 0" not "< 1"
	else
	{
		y = yy;
		m = mm;
		d = dd;
		
	}
}


// -----------------------------------------------------------------------------

void add_day( int n)
{
	//increase date by n days
	d += n;
}
};


ostream& operator<<(ostream& os, const Date& d)
{
	return os << d.y
		<< "." << d.m
		<< "." << d.d ;
}



int main()
try {

	Date today = {1978, 6, 25};
	cout << today << endl;
	
	//tomorrow
	Date tomorrow = today;
	tomorrow.add_day(1);
	cout << tomorrow << endl;
	
	//invalid date
		
	Date invalid = {2004, 13, -5};
	cout << invalid << endl;
	
	
	
	return 0;
} catch (exception& e) {
	cerr << e.what() <<endl;
	return 1;
}




