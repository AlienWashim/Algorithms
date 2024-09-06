#include <iostream>
#include<limits.h>
using namespace std;

#define V 7

int mindistance(int distance[], bool visitedvertex[])
{
    int min = INT_MAX, minindex;
    for (int v = 0; v < V; v++)
    {
        if (visitedvertex[v] ==  false && distance[v] <= min)
        {
            min = distance[v];
            minindex = v;
        }

    }
    return minindex;
}

void printdijkstra(int distance[])
{
    cout << "Destination " << "\t"<<"     Distance\n";
    for (int i = 0; i < V; i++)
    {
        cout<< i << "\t\t\t" << distance[i] << "\n";
    }

}

void dijkstra (int graph[V][V], int source)
{
    int distance[V];
    bool visitedvertex[V];
    for (int i=0; i< V; i++)
    {
        distance[i]= INT_MAX;
        visitedvertex[i] = false;
    }
    distance[source] = 0;
    for (int j=0; j < V-1; j++)
    {
        int u = mindistance(distance, visitedvertex);
        visitedvertex[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visitedvertex[v] && graph[u][v] && distance[u] != INT_MAX && distance [u] + graph[u][v] < distance[v])
            {
                distance[v] = distance [u] + graph[u][v];
            }
        }
    }
    printdijkstra(distance);
}

int main()
{
    int graph [V][V]= { {0,4,3,0,0,0,0}, {4,0,0,0,12,5,0},{3,0,0,7,10,0,0}, {0,0,7,0,2,0,0},
                        {0,12,10,2,0,0,5}, {0,5,0,0,0,0,16},{0,0,0,0,5,16,0} };

    int arp;

    cout << "Source: ";
    cin >> arp;

    dijkstra (graph, arp);
    return 0;
}
