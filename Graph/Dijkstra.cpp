#include<iostream>

using namespace std;

/*
Dijkstras  Algorithm  we use the greedy approach
*/

//Function to get minimum

const int v = 9;  // No of nodes 


int getmin(bool visited[],int dist[])
{
   int min = INT_MAX,index;
   for(int i=0;i<v;i++)
   {
      if(visited[i] == false && min >= dist[i] )
      {
      	min = dist[i];
      	index = i;
      }
   }
   
   return index;
}

// Dijkstra Algorithm
void Dijkstra(int mat[][v],int src)
{
  // Distance to reach node
  int dist[v];
  //make then infinite distance initally later we will update
  for(int i=0;i<v;i++)
  dist[i] = INT_MAX;
  
  bool visited[v];
  //make all as unvisited
  for(int i=0;i<v;i++)
    visited[i] = false;
  
 
  
  //make the distance as zero
  dist[src] = 0;
  // For each vertices we compute the min distance then update for each vertices
  // We have been computing min cost to reach each vertex
  
  for(int i=0;i<v-1;i++)
  {
      // get the min unvisited vertex 	
      int u = getmin(visited,dist);
      
      //make them visted
      visited[u] =true;
      
      for(int j=0;j<v;j++)
      {
      	// Actual Algorithm is here
      /*
        Condtions Meaning is
        1) !visited[j] ----> It means that the node that is visited there is no need
                        to update its distance since we are using greedy algo so that is
                        already have the minimun distance
        2) mat[u][j] ----> Means that we can update the distance only if there is connection
                           between thesee two nodes
        3) dist[u]!=INT_MAX-----> Means that the node u should be not the isolated 
                            node since there is no way to reach there.
         4)dist[u] + mat[u][j] < dist[j] ----> thats the actual algorithm we upadte distance
                              when it is lesser than the already computed distance
       */
      	
      if(!visited[j] && mat[u][j] && dist[u]!=INT_MAX && dist[u] + mat[u][j] < dist[j])
      {
         // Update the results
         dist[j] = dist[u] + mat[u][j];
      }
      }
  }

// Print the distance matrix
for(int i=0;i<v;i++)
cout<<"min distace to reach vertex "<<i<<" "<<dist[i]<<endl;

}
int main()
{
int graph[v][v] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

Dijkstra(graph,0);
return 0;	       
	       	
}
