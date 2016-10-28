#include<iostream>

using namespace std;
/*
 Problem is to minimun cost to reach the end starting from the begining i.e from ar[0][0]
 The array is given the weights 
 
 Approach :- We can compute the minimum cost to reach last of first column and last of
             first row because the minimum cost will always be in the straight line in
             a straight row and Straight column .
Idea : - The Basic Idea is to compute the minimum cost to reach each block
*/
int min(int a,int b,int c)
{ 
if(a<b)
{
   if(a<c)
    return a;
   else
   return c ;
 }
 else
 {
   if(b<c)
   return b;
   else
   return c;
	 }	
}

int MiniMumCost(int ar[][3],int n)
{
  // cost to reach the block in the first row
  int result[n][3];
  result[0][0] = ar[0][0];
  for(int i=1;i<n;i++)
   result[0][i] =result[0][i-1] + ar[0][i];
   
   //cost to reach each block in the first column
  for(int i=1;i<n;i++)
    result[i][0] = result[i-1][0]+ar[i][0];
    
  // For the rest of the element logic to get the minimum between the three
  // I.E Upper, Left and upper diagonal which ever is min we start from there
  
   
  for(int i=1;i<n;i++)
  {
      for(int j=1;j<n;j++)
      {                 //     upper         diagonal        left
          result[i][j] = min(result[i-1][j],result[i-1][j-1],result[i][j-1])+ar[i][j];
      }
    }  
    
  
    
    return result[n-1][n-1];
}


int main()
{
int ar[][3]={{3,2,8},{1,9,7},{6,4,3}};

cout<<MiniMumCost(ar,3);

return 0;
}
