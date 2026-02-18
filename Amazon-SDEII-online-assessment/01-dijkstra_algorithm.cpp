// https://www.geeksforgeeks.org/dsa/dijkstras-shortest-path-algorithm-greedy-algo-7/
#include<iostream>
#include<vector> 
#include<utility>
#include<functional>
#include<queue>

using namespace std;

typedef vector<vector<pair<int, int>>> graph_t;

vector<int> dijkstra(graph_t graph, int start_node) 
{
    vector<int> distances = vector<int>(graph.size(), __INT_MAX__);
    distances[start_node] = 0;

    // first == distance ; second == node_id;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> control_queue;
    control_queue.push(pair<int, int>(0, start_node));

    // O(E)
    while (!control_queue.empty())
    {
        // O(Log E)
        pair<int, int> p = control_queue.top();
        control_queue.pop();
        int distance = p.first;
        int current_node = p.second;

        if (distance > distances[current_node]) continue;

        // O(V)
        for (pair<int, int> neighbour : graph[current_node]) 
        {
            int weight = neighbour.second;
            int neighbour_node = neighbour.first;
            if (distances[current_node] + weight < distances[neighbour_node])
            {
                distances[neighbour_node] = distances[current_node] + weight;
                // O(Log V)
                control_queue.push(pair<int, int>(distances[neighbour_node], neighbour_node));
            }
        }
    }

    // O(E Log V + V Log V)
    // O((E + V)log V)

    return distances;
}

int main() 
{
    /* 
             2
         2  ---  3
    
      8/   \3     \10
    
    0  --- 1  ---  4
        4      6 
    */
    const graph_t graph = {
        {pair<int, int>(1, 4), pair<int, int>(2, 8)},
        {pair<int, int>(0, 4), pair<int, int>(4, 6), pair<int, int>(2, 3)},
        {pair<int, int>(0, 8), pair<int, int>(3, 2), pair<int, int>(1, 3)},
        {pair<int, int>(2, 2), pair<int, int>(4, 10)},
        {pair<int, int>(1, 6), pair<int, int>(3, 10)}
    };

    const int start_node = 0;
    vector<int> distances_from_start = dijkstra(graph, start_node);

    cout << "size of result: " << distances_from_start.size() << endl; 

    for (int distance : distances_from_start) {
        cout << distance << " ";
    }
    cout << endl;
}