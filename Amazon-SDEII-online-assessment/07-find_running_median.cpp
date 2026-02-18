//https://www.hackerrank.com/challenges/find-the-running-median/problem


    #include <bits/stdc++.h>

    using namespace std;

    string ltrim(const string &);
    string rtrim(const string &);

    /*
    * Complete the 'runningMedian' function below.
    *
    * The function is expected to return a DOUBLE_ARRAY.
    * The function accepts INTEGER_ARRAY a as parameter.
    */

    vector<double> runningMedian(vector<int> a) {
        
        priority_queue<int> low; // max-heap
        priority_queue<int, vector<int>, greater<int>> high; // min-heap

        vector<double> medians;
        medians.reserve(a.size());

        for (int x : a) {
            // 1) Insert
            if (low.empty() || x <= low.top()) {
                low.push(x);
            } else {
                high.push(x);
            }

            // 2) Rebalance (size difference at most 1)
            if ((int)low.size() > (int)high.size() + 1) {
                high.push(low.top());
                low.pop();
            } else if ((int)high.size() > (int)low.size() + 1) {
                low.push(high.top());
                high.pop();
            }

            // 3) Compute median
            if (low.size() == high.size()) {
                double median = (low.top() + high.top()) / 2.0;
                medians.push_back(median);
            } else if (low.size() > high.size()) {
                medians.push_back((double)low.top());
            } else {
                medians.push_back((double)high.top());
            }
        }

        return medians;
    }

    int main()
    {
        ofstream fout(getenv("OUTPUT_PATH"));

        string a_count_temp;
        getline(cin, a_count_temp);

        int a_count = stoi(ltrim(rtrim(a_count_temp)));

        vector<int> a(a_count);

        for (int i = 0; i < a_count; i++) {
            string a_item_temp;
            getline(cin, a_item_temp);

            int a_item = stoi(ltrim(rtrim(a_item_temp)));

            a[i] = a_item;
        }

        vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
    