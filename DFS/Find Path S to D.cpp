#include <iostream>
#include <vector>
using namespace std;
vector <int> graph[10];
bool visited[10];
void dfs(int source, int end)
{
if(source == end)
return;
visited[source] = 1;
cout <<source<<" ";
for (int i = 0; i < graph[source].size(); i++)
{
int next = graph[source][i];
if (visited[next] == 0)
{
dfs(next,end);
}
}
}
int main()
{
int n, e,s,d;
cout << "Total vertex: ";
cin>>n;
cout << "Total edges: ";
cin>>e;
for (int i = 0; i < e; i++){
int u, v;
cin >> u >> v;

graph[u].push_back(v);
graph[v].push_back(u);
}
cout<<"\n";
cin >> s >> d;
dfs(s,d);
return 0;
}
