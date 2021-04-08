#include "std_lib_facilities.h"

//Drill 10 =)

struct Point {
	int x;
	double y;
};

istream& operator>> (istream& is, Point& p)
{
	// (x,y)
	
	int xx,yy;
	char ch1, ch2, ch3;
	is >> ch1 >> xx >> ch2 >> yy >> ch3 ;

	if(!is) return is;
	
	/*if(ch1 != '(' || ch2 != ',' || ch3 != ')') 
		error("Bad token!");
		peoblem with creatibg error message and not getting (0,0) printouts if error occurs*/
	
	if(ch1 != '(' || ch2 != ',' || ch3 != ')')
	{
		is.clear(ios_base::failbit);
		return is;
	}
	
	p.x = xx;
	p.y = yy;
	
	return is;
}

ostream& operator<<(ostream& os, Point& p)
{
    return os << '(' << p.x << ',' << p.y << ')';
}

void fill_from_file(vector<Point>& points, string& name)
{
    ifstream ist {name};
    ist.exceptions(ist.exceptions()|ios_base::badbit);

    if (!ist) error("can't open input file ", name);
    for (Point p; ist >> p; )
        points.push_back(p);
}

int main()
try {

	string ifname;
	
	cout << "Please enter seven pairs of coordinates in the form of (x,y)\n";
 	
 	vector<Point> points;

	while (points.size() < 7) {
        	Point p;
        	cin >> p;
        	points.push_back(p);
        } 
        
	 for (Point p : points)
        	cout << p << endl;
    		
	
	string fname = "mydata.txt";
		
	

	ofstream ofs { fname };

	if ( !ofs ) error ("Cannot open file: ", fname);
	
	for (const auto& p : points)
	ofs <<'(' << p.x << ',' << p.y << ')' << endl;
	
		
	vector<Point> processed_points;
	fill_from_file(processed_points, fname);

	for (Point p : processed_points)
        cout << p << endl;

	if (points.size() != processed_points.size())
       cout << "Something's wrong!\n";
	
	return 0;

} catch (exception& e){
	cerr << e.what() << endl;
	return 1;
}
