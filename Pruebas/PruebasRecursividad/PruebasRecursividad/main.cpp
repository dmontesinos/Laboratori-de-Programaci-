#include <string>
#include <list>
#include <iostream>
using namespace std;


int fibonacci(int n)
{
	int fib;
	if ((n == 0) || (n == 1))
		fib = 1;
	else
		fib = fibonacci(n - 1) + fibonacci(n - 2);

	return fib;
}



int main()
{

	cout << fibonacci(100);

	return 0;
}