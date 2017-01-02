#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

/*
This is famous Backtracking Algoritm for NQueens problem We use backtracking apprach to 
minimize the time complexity a little.

Key Ideas: -

-> The key idea is to insert at the first place in the first row and insert in the next row
   and use safeCheck to ensure that it is safe to insert at the current position.

-> When we are not able to insert in the current row then we backtrack from here we say 
   that solution does not exits. So We go one step back and try to place the Queen 
   to the next location. 
                 Then we again start from here and try to find the solution from here.

*/
// This is a function to print the array where we have placed Queens in non attacking 
// Position 
void print(vector<vector<int> > ar)
{
   cout<<endl;	
  for(int i=0;i<ar.size();i++)
  {
    for(int j=0;j<ar[i].size();j++)
     cout<<ar[i][j]<<" ";
     cout<<endl;
  }
}
bool isSafe(vector<vector<int> > ar,int row,int col)
{
   // Check in the same column and all its previous row if there is some element in it or not
   for(int i=0;i<row;i++)
     if(ar[i][col])
       return false;
   
   // Check in the left diagonals from the current element;
  int i,j;
  for(i=row,j=col;i>=0 && j>=0; i--,j--)
     if(ar[i][j])
       return false;
       
  //Check the Right Diagonals from here columns will increase and rows will decrease     
  for(i=row,j=col; i>=0 && j<ar.size();j++,i--)
     if(ar[i][j])
      return false;        
   
  //If all the Condition Satisfies then return true;
   return true;
}

bool NQueens(vector<vector<int> > &ar,int row)
{
   if(row >= ar.size())	// We have exhausted all the row and inserted the queen at all 
    return true;          // the row once if the solution exits      
    
  for(int i=0;i<ar.size();i++)
  {
     if(isSafe(ar,row,i))  // Check whether it is safe to insert in the current row and column
     {
        ar[row][i] = 1;  // Insert the Queen at the current position
      
        if(NQueens(ar,row+1))  // We Try to insert the element in the next row
        {  	
           return true;
        }
        // Here it will come if the solution does not exits
        ar[row][i] = 0;   // Backtrack right from here
     }
  }
  
  return false;     
}

int main()
{
// Size of the Chess board to insert the Queens	
  int size = 16;	
  vector<int> temp(size);
  
  vector<vector<int> > res;
  //Make all array as zeros
  for(int i=0;i<size;i++)
     res.push_back(temp);
  
  cout<<NQueens(res,0);
  //Print the new array
  print(res);
       
  return 0;
}
