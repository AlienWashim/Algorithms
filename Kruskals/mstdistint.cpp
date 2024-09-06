#include<bits/stdc++.h>
using namespace std;

vector<int> NodesSet;
vector<int> MstChecker;
vector<int> tST;
int edgeCount;

struct Graph
{
  int nA, nB , weight;
} graph[100005];

bool comparator(Graph a, Graph b)
{
  return a.weight < b.weight;
}

void CreateSet(int nodes)
{
  for(int i = 1 ; i <= nodes; i++)
  NodesSet[i] = i;
}

int Find( int a )
{
  if( NodesSet[a] == a )
  return a;
  return NodesSet[a] = Find( NodesSet[a] );
}

int UnionForMST(int edge,int cost)
{
  int a,b;
  a = Find( graph[edge].nA);
  b = Find( graph[edge].nB );

if( a != b )
{
  NodesSet[a] = b;
  MstChecker.push_back(edge);
  cost += graph[edge].weight;
}
  return cost;
}

int UnionForOST(int edge,int cost)
{
  int a,b;
  a = Find( graph[edge].nA );
  b = Find( graph[edge].nB );

if( a != b )
{
  NodesSet[a] = b;
  edgeCount++;
  cost += graph[edge].weight;
}
  return cost;
}

void MST(int edges)
{
  int cost = 0;
  for(int i = 0; i < edges;i++)
  {
  cost = UnionForMST(i,cost);
  }
  tST.push_back(cost);
}

void OST(int nodes, int edges)
{
  int cost = 0;
  for(int j=0; j < MstChecker.size(); j++)
  {
   CreateSet(nodes);
   edgeCount = 0;

   for(int i = 0; i < edges; i++)
    {
    if(i == MstChecker[j])
     continue;
    cost = UnionForOST(i,cost);
    }
    if(edgeCount != nodes-1)
    {
    cost = 0;
    continue;
    }
tST.push_back(cost);
cost = 0;
   }
}

void InputGraph(int edges)
{
  for( int i = 0; i < edges; i++ )
  {
   int vA, vB, weight ;
   cin >> vA >> vB >> weight;
   graph[i].nA = vA;
   graph[i].nB = vB;
   graph[i].weight = weight;
  }
}

void PrintAST()
{
  for(int i = 0 ; i < tST.size(); i++)
  {
   cout << tST[i] << "\n";
  }
}

int main()
{
  int nodes, edges;
  cout<<"Number of Nodes and Edges : ";
  cin >> nodes >> edges;

  NodesSet.assign(nodes+1, 0);
  CreateSet(nodes);
  InputGraph(edges);
  sort( graph, graph + edges , comparator );
  MST(edges);
  OST(nodes, edges);

  cout <<endl<< "The total number of Spanning Trees : " << tST.size() << endl;
  cout << "All the Distinct Spanning trees are: "<< endl;

  PrintAST();
}
