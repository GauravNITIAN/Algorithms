#include<iostream>
#include<list>

using namespace std;
class Graph
{
   int v;  // no of vertices
   list<int> *adj; // adjancey list
   public:
     Graph(int);
     void addEdge(int,int);
     void DFS();
     void dfs(int,bool*);  
};

Graph::Graph(int v)
{
this->v = v;
adj = new list<int>[v];
}
// Here adding the edge to the  adj list[v] and the desination d
void Graph::addEdge(int v,int d)
{
 adj[v].push_back(d);
}

// BFS traversal we use stack here we will use recursive apprach
void Graph::DFS()
{
  // take a visited array for this
  bool visited[v];
  
  //make the visited to false for each 
  for(int i=0;i<v;i++)
  visited[i] = false;
  
  
  // iterate for each node if it is not visited
  for(int i=0;i<v;i++)
  {
     if(!visited[i])
     {
        // Recusive call for stack approach
       dfs(i,visited);
     }
  }
  
}
void Graph::dfs(int i,bool visited[])
{
  visited[i] = true;
  cout<<i<<"-->";
  //iterate while it is not empty
   list<int>::iterator it;
   for(it=adj[i].begin();it!=adj[i].end();it++)
   {
        if(!visited[*it])
        {
        	dfs(*it,visited);
        }
   }
}
int main()
{

Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    g.DFS();
return 0;
}
