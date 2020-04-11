#include<iostream>
using namespace std;

void q21()
{
	const char *say = "Hellow, World!";
	cout << say << endl;
}

void q22(int n)
{
	cout << "Using for loop:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Hello, World!" << endl;
	}

	cout << "Using while loop:" << endl;
	int i = 0;
	while (i < n) {
		cout << "Hello, World!" << endl;
		i++;
	}

	cout << "Using do...while loop:" << endl;
	i = 0;
	do {
		cout << "Hello, World!" << endl;
		i++;
	} while (i < n);
}

int main()
{
	q21();
	q22(2);

	system("pause");

	return 0;
}