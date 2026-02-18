#include <iostream>
#include <string>


int main(){

	std::string line;
	int test;
	std::cin >> test;
	while(test--){
		std::cin >> line;
		int smaller_than = 0, dimonds = 0;
		int i = 0;
		while(line[i]){
			if(line[i] == '<')	
				smaller_than++;
			if(line[i] == '>' && smaller_than > 0){
				dimonds++;
				smaller_than--;
			}
			i++;
		}
		std::cout << dimonds << std::endl;
	}
	return 0;
}
	

	

