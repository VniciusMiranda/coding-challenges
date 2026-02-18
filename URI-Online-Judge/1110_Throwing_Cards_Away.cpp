#include <iostream>
#include <queue>

using namespace std;


int main(){

    queue< int > q; 

    int i;
    
    while(true){
        cin >> i;
        if(!i) break;

        for(int j = 1; j <= i; j++){
            q.push(j);
        }

        cout << "Discarded cards: ";
        while (true)
        {

            if (q.size() > 2)
                cout << q.front() << ", ";
            else{
                cout << q.front() << endl;
                q.pop();
                cout << "Remaining card: " << q.front() << endl;
                q.pop();
                break;
            }
            q.pop();
            q.push(q.front());
            q.pop();
        }
    }
    
    return 0;
}