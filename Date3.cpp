#include "std_lib_facilities.h"

//Drill 9 Q3

class Date {
private:
	int y;
	int m;
	int d;

public:
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
	int get_year() { return y; }
	int get_month() { return m; }
	int get_day() { return d; }
	void set_year (int yy) 
	{ 
		if (yy < 0) error ("Invalid year");
		y = yy; 	
	}
	void set_month (int mm) 
	{
		if (mm < 0 || mm > 12) error ("Invalid month");
		m = mm;
	}
	void set_day (int dd) 
	{ 
		if (dd < 0  || dd > 31) error ("Invalid day");
		d = dd; 
	}
	void add_day(int n)
	{
	//increase date by n days
		d += n;
	}

}; //must have ";" after class and struct

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------

ostream& operator<<(ostream& os, Date& date)
{
	return os << date.get_year() << "."
		  << date.get_month() << "."
		  << date.get_day() << " ";
}

// -----------------------------------------------------------------------------

int main()
try {
	//date initialazed today 25 June 1978
	Date today (1978, 6, 25);
	   cout << today.get_year() << "." 
		<< today.get_month() << "." 
		<< today.get_day() << "\n" ;
	
	//tomorrow
	Date tomorrow(today);

	tomorrow.add_day(1);

	cout << tomorrow << endl;	
				
	//invalid date
	Date invalid (2004, 13, -5);
	 	
	cout << invalid << endl;

	return 0;
} catch (exception& e) {
	cerr << e.what() <<endl;
	return 1;
}




