//https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/problem
//
// Created by vinicius on 2/11/26.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

class Graph 
{

    private:
        int DEFAULT_DISTANCE = 6;
        int nodes;
        vector<vector<int>> edges;
    public:

        Graph(int n) 
        {
            this->nodes = n;
            this->edges = vector<vector<int>>(n + 1);
        }

        void add_edge(int u, int v) 
        {
            this->edges[u].push_back(v);
            this->edges[v].push_back(u);
        }
        
        vector<int> shortest_reach(int start) 
        {
            vector<int> distance = vector<int>(this->nodes, -1);
            queue<int> control_queue;

            distance[start] = 0;
            control_queue.push(start);

            // O(V)
            while (!control_queue.empty()) 
            {
                int node = control_queue.front();
                control_queue.pop();

                // O(E)
                for(int neighbour : this->edges[node]) 
                {
                    if (distance[neighbour] == -1)
                    {
                        distance[neighbour] = distance[node] + this->DEFAULT_DISTANCE; 
                        control_queue.push(neighbour);
                    }
                }
            }
            // O(V + E)
            /*
                Why it's not V*E ?

                Because for a iteration the internal loop doesn't run E times, it runs
                only the number of node edges.

                The ammount it runs, ammount to E, total edges, but the relation is not
                V*E because for each iteration of V it doesn't run E times.

            */
            return distance;
        }

};

int main() 
{
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) 
    {

        int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) 
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) 
        {
            if (i != startId) 
            {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
