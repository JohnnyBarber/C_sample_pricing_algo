class Point {
public:
	double x, y;
	void offset(double offsetx, double offsety);
	void print();
};

class Vector {
	Point start, end;
	void offset(double offsetx, double offsety);
	void print();
};
