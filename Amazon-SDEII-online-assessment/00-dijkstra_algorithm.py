#https://www.geeksforgeeks.org/dsa/dijkstras-shortest-path-algorithm-greedy-algo-7/
import sys
from typing import List
from queue import PriorityQueue


def main(source_node: int, graph: List[List[List[int]]]) -> None:

    dist = [sys.maxsize] * len(graph)
    dist[source_node] = 0

    pq = PriorityQueue()
    pq.put((0, source_node))
    while pq.qsize() > 0:
        d, v = pq.get(block=False)

        if d > dist[v]:
            continue

        for u, w in graph[v]:
            if dist[v] + w < dist[u]:
                dist[u] = dist[v] + w
                pq.put((dist[u], u))

    print(dist)

if __name__ == '__main__':
    source_node = 0

    """
        The indexes are the vertices.
        The first value of the tuple is the adjacent vertices to the index vertice.
        The second value is the weight of the edge.

        Therefore:
        
        graph[0] = [[1, 4], [2, 8]]        
        
        means => Vertice 0 has a distance of 4 to vertice 1 and
                Vertice 0 has a distance of 8 to vertice 2.
    """
    graph = [
        [[1, 4], [2, 8]],
        [[0, 4], [4, 6], [2, 3]],
        [[0, 8], [3, 2], [1, 3]],
        [[2, 2], [4, 10]],
        [[1, 6], [3, 10]]
    ]
    try:
        main(source_node, graph)
    except Exception as ex:
        print("crashed")
        print(ex)

