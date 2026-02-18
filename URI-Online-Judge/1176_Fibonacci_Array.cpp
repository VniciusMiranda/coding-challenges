#include <iostream>


using namespace std;


int main(){

	int numb_test, index, size = 61;
	long int fibonacci[size];

	fibonacci[0] = 0;
	fibonacci[1] = 1;

	cin >> numb_test;

	for(int i = 2; i < size; i++)
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	
	for(int i = 0; i < numb_test; i++){
		cin >> index;
		cout << "Fib(" << index << ") = " << fibonacci[index] << endl;
	}
	return 0;
}
