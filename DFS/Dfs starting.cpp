#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int n,e,a,b,t;
vector<int>*adj;
vector<int>::reverse_iterator j ;
void dfs(int i)
{
vector<bool> visited(n,0);
stack<int> stack;
stack.push(i);
while(!stack.empty()){
i = stack.top();
stack.pop();
if(!visited[i]){
cout<<i<<" ";
visited[i] = 1;
}
for(j=adj[i].rbegin(); j!=adj[i].rend();j++)
if(!visited[*j]){
stack.push(*j);
}
}
}
int main()
{
int t;
cout << "Total vertex: ";
cin>>n;
cout << "Total edges: ";

cin>>e;
adj = new vector<int>[n];
for(int i=0;i<e;i++){
cin>>a>>b;
adj[b].push_back(a);
adj[a].push_back(b);
}
cout<<"\nStarting from vertex : ";
cin>>t;
cout<<"Traversal of the graph is : ";
dfs(t);
cout<<"\n";
return 0;
}
