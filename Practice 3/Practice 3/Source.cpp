#include<iostream>
#include<string>
using namespace std;

int NumberFunction(int x)
{
	cout << "This is a number: " << x << endl;
	return x;
}

void ReturnNothing(int x, string y)
{
	cout << "This is a number: " << x << endl;
	cout << "and this is a string: " << y << endl;
}

int fibonacci(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return fibonacci(n - 2) + fibonacci(n - 1);
	}
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int	divide(int numerator, int denominator, int &remainder)
{
	remainder = numerator % denominator;
	return numerator / denominator;
}

int main()
{
	int temp, n = 6;

	//NumberFunction assigns a number to variable temp and print it out
	temp = NumberFunction(n);

	//fibonacci is a recurssion function that finds the nth fibonacci number
	cout << "the " << n << "th fibonacci number is: " << fibonacci(n) << endl;

	//swap first and second number using reference in function swap
	int first = 1, second = 2;
	cout << "first is " << first << " second is " << second << endl;
	swap(first, second);
	cout << "first is " << first << " second is " << second << endl;

	//reference allows a function to have multiple return value
	int num = 14, den = 4, rem;
	int result = divide(num, den, rem);
	cout << result << " * " << den << " + " << rem << " = " << num << endl;

	ReturnNothing(5, "Hello");

	system("pause");
	return 0;
}