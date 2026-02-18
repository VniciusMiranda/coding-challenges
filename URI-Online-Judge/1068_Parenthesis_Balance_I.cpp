#include<iostream>
#include<string>

using namespace std;

int main(){

    string s;
    int p, ss;


    while(getline(cin, s)){
        ss = s.size();
        p = 0;

        for(int i = 0; i < ss; i++){

            if(s[i] == '(')
                p++;

            if(s[i] == ')')
                !(p > 0) ? p++ : p--;
                
            
        }

    if(!(p > 0)) 
        cout << "correct"<< endl;
    else 
        cout << "incorrect" << endl;

    }

    return 0;
}