#include <iostream>
#include <limits.h>
using namespace std;

#define V 9

int minDistance(int dist[],bool sptSet[])
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false &&
                   dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printPath(int parent[], int j)
{

    if (parent[j] == - 1)
        return;

    printPath(parent, parent[j]);

    cout<< j;
}

void printSolution(int dist[], int n,
                      int parent[])
{
    int src = 0;
    cout <<"Vertex\t     Distance\t        Path" << endl;
    for (int i = 1; i < V; i++)

    {
        cout  <<endl<<src<<" -> "<< i << " \t\t"<<dist[i]<< " \t\t"<<src;
        printPath(parent, i);
        cout<<endl;
    }
}

void dijkstra(int graph[V][V], int src)
{

    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    printSolution(dist, V, parent);
}

int main()
{
    int graph[V][V] = {{0, 5, 0, 0, 0, 0, 0, 2, 0},
                       {5, 0, 4, 0, 0, 0, 0, 0, 1},
                       {0, 4, 0, 3, 0, 0, 0, 0, 0},
                       {0, 0, 3, 0, 7, 6, 0, 0, 0},
                       {0, 0, 0, 7, 0, 5, 0, 0, 7},
                       {0, 0, 0, 6, 5, 0, 9, 0, 0},
                       {0, 0, 0, 0, 0, 9, 0, 2, 2},
                       {2, 0, 0, 0, 0, 0, 2, 0, 8},
                       {0, 1, 0, 0, 7, 0, 2, 8, 0}
                      };

    dijkstra(graph, 0);
    return 0;
}
