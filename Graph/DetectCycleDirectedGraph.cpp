#include<iostream>
#include<list>

using namespace std;

/*

Problem : - It is the problem to detect cycle in a directed graph

Approach :- There is cycle if there is back edge present in the graph 
            That means if in the recusion stack if we are using DFS traversal
            then if that edge is already present in the stack 
            
            BACK edge means there may be edge form it self or edge to one of its 
            ancestor that lead to a cycle

*/
class Graph
{
  int v;
  list<int> *adj;
  public:
     // This Constrctor will Create the graph  	
     Graph(int v);
     //Function to Edge in the list and weight associated with
     void addEdge(int v,int d);
     bool isCycle( );
     bool IsCycleHepler(int,bool*,bool*);
     
};
// Create a Graph with V no. of Vertices
Graph::Graph(int v)
{
  //Created the AdjList
  adj = new list<int>[v];
  this->v = v;
}
void Graph::addEdge(int v,int d)
{
// it means we need to add Edge to this adjList with d as desination	
  adj[v].push_back(d);
}

//  Use DFS traversal to see whether there is a cycle or not

bool Graph::isCycle()
{
   //take a visited array to keep track of all visited nodes
   bool visited[v];
   //This will be used in recusion stack to dectect a cycle
   bool recStack[v];
   
   //Make all of them as unvisited
   for(int i=0;i<v;i++)
   {
      visited[i] = false;
      recStack[i] = false;
   }
   
   // start Traversing each nodes using DFS
   for(int i=0;i<v;i++)
   {
      if(IsCycleHepler(i,visited,recStack))
      return true;
   }
   return false;
}

bool Graph::IsCycleHepler(int i,bool visited[],bool recStack[])
{
   visited[i] = true;
   recStack[i] = true;
   
   list<int>::iterator it;
   
   for(it=adj[i].begin();it!=adj[i].end();it++)
   {
        if(!visited[*it])  // if it is not visited then visit it
        {
       // There will be no chance of cycle if it is not visited	         	
       IsCycleHepler(*it,visited,recStack) ; 
   }
   // else if it is visited then there is chance of cycle if it is present in recStack
   else if(recStack[*it])
   return true;
}

// If nothing happens then it means that there is no back edge from this edge remove
// from recusion stack   
   recStack[i] = false;
   
   // means no cycle
   return false;
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
    
    if(g.isCycle())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
