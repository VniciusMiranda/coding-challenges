#include<iostream>


using namespace std;


int main(){

	int hour_i, min_i, hour_f, min_f;
	int start_time, end_time, sleep_time;


	while(true){

		cin >> hour_i >> min_i  >> hour_f  >> min_f;

		if(hour_f == 0 && min_i == 0 && hour_f == 0 &&  min_f == 0) break;

		if(hour_i == 0) hour_i = 24;
		if(hour_f == 0) hour_f = 24;

		start_time = hour_i*60 + min_i;
		end_time = hour_f*60 + min_f;

		if(end_time <= start_time) end_time += 24*60;

		cout << end_time - start_time << endl;
	}
	return 0;
}
