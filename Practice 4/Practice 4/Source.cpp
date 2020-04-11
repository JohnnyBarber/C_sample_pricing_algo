#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int arr[4];
	cout << "Enter 4 integer, on e at a time:" << endl;
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}
	cout << "Integers entered are:" << endl;
	for (int i = 0; i < 4; i++) {
		cout << arr[i] << " ";
	}

	system("pause");

	return 0;
}

