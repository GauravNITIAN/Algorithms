#include<iostream>
#include<list>
#include<stack>

using namespace std;
/*
This is a topological sort algorithm we need to print the vertices which have indegree
zero.

There is a wide application of this toplogigical sort
1) In building the project the dependency which is required first hence we 
   required topological sort
2) In finding out prequites of any course

Idea:- The Idea is to use stack of traversed nodes and print it
     -> When we push a element in stack here and use dfs traversal
     -> A/c to properpty of dfs we visit a node then the node from this node
     -> Again we keep on going until we get a node with no more child
     ->Hence at the top we get the node which has indegree zero and this is the first
     ->element in topological sorting

*/

class Graph
{
   int v;  // no of vertices
   list<int> *adj; // adjancey list
   public:
     Graph(int);
     void addEdge(int,int);
     void Topological();
     void SortHelper(int,bool *,stack<int>&);  
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
void Graph::Topological()
{
  // take a visited array for this
  bool visited[v];
 
  // Stack for the ordering in toplogical sorting
  stack<int> topo;
   
  //make the visited to false for each 
  for(int i=0;i<v;i++)
  visited[i] = false;
  
  
  // iterate for each node if it is not visited
  for(int i=0;i<v;i++)
  {
     if(!visited[i])
     {
        // Recusive call for stack approach
       SortHelper(i,visited,topo);
     }
  }
  
  // After stack for toplogical sorting
  while(!topo.empty())
  {
  cout<<topo.top()<<" ---> ";
 topo.pop(); 	
  }
  
}
//This is a helper function for topological sort
void Graph::SortHelper(int i,bool visited[],stack<int> &s)
{
  visited[i] = true;
 
  //iterate while it is not empty
   list<int>::iterator it;
   for(it=adj[i].begin();it!=adj[i].end();it++)
   {
        if(!visited[*it])
        {
        	SortHelper(*it,visited,s);
        }
   }
   // Push the elements in stack
   s.push(i);
   
}
int main()
{


   Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    
    g.Topological();
return 0;
}
