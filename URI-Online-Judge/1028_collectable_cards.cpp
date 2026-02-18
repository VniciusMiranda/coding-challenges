#include <iostream>

using namespace std;

int gcd(int divisor, int dividend){

	int c;

	while(dividend % divisor != 0){

		c = dividend % divisor;
		dividend  = divisor;
		divisor = c;
	}


	return divisor;
}

int main(){

	int numb_test, b, a;
	int divisor, dividend;

    cin >> numb_test;

    for(int i = 0; i < numb_test; i++){

        cin >> a >> b;

        if(a > b){

		divisor = b;
		dividend = a;
		}else{
	
		divisor = a;
		dividend = b;
		}

		cout << gcd(divisor, dividend) << endl;
    }

    
	return 0;
}

