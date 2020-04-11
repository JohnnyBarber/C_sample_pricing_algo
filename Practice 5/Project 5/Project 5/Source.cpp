#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void SimpleCalculation(int *num)
{
	//using dereference by calling *x
	*num = *num * *num;
}

void Enter4Number(int *arr)
{
	cout << "Enter 4 integer, one at a time:" << endl;
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}
	cout << "Integers entered are:" << endl;
	for (int i = 0; i < 4; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int number = 2;
	//using reference of number by calling &x
	SimpleCalculation(&number); 
	cout << number << endl;

	int arr[4] = { 0,0,0,0 };
	//Aware: arr itself is a reference, arr refers to the address of the 0th value in the arr
	Enter4Number(arr);
	//Now, the arr has been modified since Enter4Number passes value by using pointers
	cout << "Check global variable arr:" << endl;
	for (int i = 0; i < 4; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}