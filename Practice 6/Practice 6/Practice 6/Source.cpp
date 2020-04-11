#include<iostream>
#include<math.h>
#include<string>
#include "vector.h"
using namespace std;

//create a user-defined data type
class StudentInfo {
public:
	//create 2 fields/members
	string name;
	int ID;
};

//create a user-defined data type: point
class point {
public:
	double x, y;
};

//create a user-defined data type: vector
class vector {
public:
	//fields can be user-defined class
	point start, end;
};

void offsetvector(vector &v, double offsetx, double offsety)
{
	v.start.x += offsetx;
	v.start.y += offsety;
	v.end.x += offsetx;
	v.end.y += offsety;
}

void PrintVector(vector v) {
	cout << "(" << v.start.x << "," << v.start.y << ") -> (" << v.end.x << "," << v.end.y << ")" << endl;
}

//Modify our vecotr class and add methods into the class
class Vector_m {
public:
	point start, end;

	void offset(double offsetx, double offsety) {
		start.x += offsetx;
		start.y += offsety;
		end.x += offsetx;
		end.y += offsety;
	}

	void print() {
		cout << "(" << start.x << "," << start.y << ") -> (" << end.x << "," << end.y << ")" << endl;
	}
};

//Define function pre-declared in the header file vector.h
void Point::offset(double offsetx, double offsety) {
	x += offsetx;
	y += offsety;
}

//Define function pre-declared in the header file vector.h
void Point::print() {
	cout << "(" << x << "," << y << ")";
}

//Define function pre-declared in the header file vector.h
void Vector::offset(double offsetx, double offsety) {
	start.offset(offsetx, offsety);
	end.offset(offsetx, offsety);
}

//Define function pre-declared in the header file vector.h
void Vector::print() {
	start.print();
	cout << " -> ";
	end.print();
	cout << endl;
}

int main()
{
	//create 2 instances of class StudentInfo
	StudentInfo student1;
	StudentInfo student2;
	//access fields of instances, use variable.fieldname
	student1.name = "Jiaqi LI";
	student1.ID = 87654321;
	student2.name = "Xiangui MEI";
	student2.ID = 12345678;

	cout << "Student 1: " << student1.name << " with ID: " << student1.ID << endl;
	cout << "Student 2: " << student2.name << " with ID: " << student2.ID << endl;

	vector A;
	A.start.x = 1.0;
	A.start.y = 1.0;
	A.end.x = 5.0;
	A.end.y = 5.0;
	cout << "Following is a user-defined vector:" << endl;
	PrintVector(A);

	offsetvector(A, 1.1, 2.2);
	cout << "Move vector A up by 2.2, right by 1.1:" << endl;
	PrintVector(A);

	//Try the modified vector class
	Vector_m B;
	B.start.x = 1.0;
	B.start.y = 1.0;
	B.end.x = 5.0;
	B.end.y = 5.0;
	cout << "Manipulate the modified vector:" << endl;
	B.print();
	B.offset(1.5, 2.5);
	B.print();

	//Now, using pre-declared function of class from header file 
	Vector C;
	cout << "Pre-declared vector:" << endl;
	C.print();
	C.start.x = 1.0;
	C.start.y = 1.0;
	C.end.x = 5.0;
	C.end.y = 5.0;
	cout << "Make some change:" << endl;
	C.print();
	C.offset(1.5, 2.5);
	C.print();
	//same operation, different way of defining the functions

	//Make a copy of C
	Vector D = C;
	cout << "Look at the copy data:" << endl;
	D.print();
	cout << "Change the x position of start point of the vector:" << endl;
	cin >> D.start.x;
	//With a copy constructor defined in the header file,
	//change of D would not affect C
	cout << "copy vector: ";
	D.print();
	cout << "original vector: ";
	C.print();

	system("pause");
	return 0;
}