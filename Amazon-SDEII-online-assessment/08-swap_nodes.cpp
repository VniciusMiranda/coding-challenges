//https://www.hackerrank.com/challenges/swap-nodes-algo/problem
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    int n = (int)indexes.size();

    // Children arrays for nodes 1..n
    vector<int> leftChild(n + 1, -1), rightChild(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        leftChild[i]  = indexes[i - 1][0];
        rightChild[i] = indexes[i - 1][1];
    }

    // Precompute nodes by depth using BFS
    vector<vector<int>> levels(n + 2); // levels[depth] = nodes at that depth
    queue<pair<int,int>> q;            // (node, depth)
    q.push({1, 1});
    int maxDepth = 1;

    while (!q.empty()) {
        auto [node, depth] = q.front();
        q.pop();
        if (node == -1) continue;

        maxDepth = max(maxDepth, depth);
        levels[depth].push_back(node);

        if (leftChild[node] != -1)  q.push({leftChild[node], depth + 1});
        if (rightChild[node] != -1) q.push({rightChild[node], depth + 1});
    }

    // In-order traversal helper
    function<void(int, vector<int>&)> inorder = [&](int node, vector<int>& out) {
        if (node == -1) return;
        inorder(leftChild[node], out);
        out.push_back(node);
        inorder(rightChild[node], out);
    };

    // Process each query
    vector<vector<int>> result;
    result.reserve(queries.size());

    for (int k : queries) {
        // Swap nodes at depths that are multiples of k
        for (int d = k; d <= maxDepth; d += k) {
            for (int node : levels[d]) {
                swap(leftChild[node], rightChild[node]);
            }
        }

        // Collect inorder traversal after swaps
        vector<int> traversal;
        traversal.reserve(n);
        inorder(1, traversal);
        result.push_back(move(traversal));
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

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
