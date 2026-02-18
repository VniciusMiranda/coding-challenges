#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> v;
    int n, q, x, i = 1;
    while(cin >> n >> q, (n || q)){


        while(n--){
            cin >> x;
            v.push_back(x);  
        }

        sort(v.begin(), v.end());

        cout << "CASE# " << i ++ << ":" << endl;

        while(q--){
            cin >> x;
            auto f = find(v.begin(), v.end(), x);

            if(f != v.end())
                cout << x << " found at " << distance(v.begin(), f) + 1 << endl;
            else
                cout << x << " not found" << endl;
        }

        v.clear();
    }



    return 0;

}