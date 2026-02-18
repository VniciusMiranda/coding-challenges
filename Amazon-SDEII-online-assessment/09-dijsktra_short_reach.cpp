//https://www.hackerrank.com/challenges/dijkstrashortreach/problem
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'shortestReach' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER s
 */

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    
    // 1. convert edges to format we can work with
    vector<vector<pair<int, int>>> graph(n + 1);
    for (vector<int> edge: edges)
    {
        int start_node = edge[0];
        int end_node = edge[1];
        int weight = edge[2];
        graph[start_node].push_back(pair<int, int>(end_node, weight));
        graph[end_node].push_back(pair<int, int>(start_node, weight));    
    }
    
    
    vector<int> distances = vector<int>(n, INT_MAX);
    distances[s] = 0;
    
    priority_queue 
        <pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> control_queue;
    control_queue.push(pair<int, int>(distances[s], s));
    
    while (!control_queue.empty())
    {
        pair<int, int> p = control_queue.top();
        control_queue.pop();
        
        int distance = p.first;
        int current_node = p.second;
        
        if (distances[current_node] == INT_MAX) continue;
        
        for (pair<int, int> neighbour : graph[current_node])
        {
            int neighbour_node = neighbour.first;
            int neighbour_distance = neighbour.second;
         
            if (distances[current_node] + neighbour_distance < distances[neighbour_node]) 
            {
                distances[neighbour_node] = distances[current_node] + neighbour_distance;
                control_queue.push(pair<int, int>(distances[neighbour_node], neighbour_node));
            }   
        }
    }
    
    vector<int> answer;
    for (int i = 0; i <= n ; i++) 
    {
        if (i == s) continue;
        answer.push_back(distances[i] == INT_MAX ? -1 : distances[i]); 
    }
    
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(3);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 3; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = shortestReach(n, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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
