//https://www.hackerrank.com/challenges/contacts/problem
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'contacts' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_STRING_ARRAY queries as parameter.
 */

vector<int> contacts(vector<vector<string>> queries) 
{
    string add_command = "add";
    string find_command = "find";
    unordered_map<string, int> chars;
    vector<int> name_occurrences = vector<int>();
        
    for (vector<string> action : queries)
    {
        string command = action[0];
        string argument = action[1];
        
        if (command == add_command)
        {
            string name = "";
            for (char& c : argument) 
            {
                name += c;
                chars[name]++;
            }
            continue;
        }
        else if (command == find_command) 
        {
            name_occurrences.push_back(chars[argument]);    
        }
    }
    return name_occurrences;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string queries_rows_temp;
    getline(cin, queries_rows_temp);

    int queries_rows = stoi(ltrim(rtrim(queries_rows_temp)));

    vector<vector<string>> queries(queries_rows);

    for (int i = 0; i < queries_rows; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            string queries_row_item = queries_row_temp[j];

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> result = contacts(queries);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}