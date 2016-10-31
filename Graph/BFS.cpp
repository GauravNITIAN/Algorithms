#include<iostream>
#include<list>
#include<queue>
#include<iterator>
using namespace std;

/*

Graph Traversal using BFS Traversal
*/
class Graph
{
  int v;
  list<int> *adj;
  public:
     // This Constrctor will Create the graph  	
     Graph(int v);
     //Function to Edge in the list and weight associated with
     void addEdge(int v,int weight);
     void BFS(int startEdge);
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
//Function for Graph BFS Traversal 
// s is the start vertex
void Graph::BFS(int s)
{
//take an array of visited nodes so that it does not be visited again
bool visited[v];

// make all the visited as false

for(int i=0;i<v;i++)
visited[i] = false;

// make the start vertex as visited
visited[s] = true; 

// Very important for BFS is the Use of Queue data surcture for label order traversal
queue<int> qu;

qu.push(s);

//iterate while the queue is not empty
list<int>::iterator it;
while(!qu.empty())
{
      // Pop the current element and the connected node of it
      int level =  qu.front();
      
      //print the BFS Trversal
      cout<<level<<" --> ";
      qu.pop();
      
      for(it = adj[level].begin();it!=adj[level].end();it++)
      {
       if(!visited[*it])
       {
       	// if it is not visited then push it in the queue and say it is visited
       	qu.push(*it);
       	visited[*it] = true;
	       }	
      }
      
}
}

int main()
{
    //Create a graph
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    cout<<"Start from this vertex"<<endl;
     g.BFS(2);
    return 0;
}
