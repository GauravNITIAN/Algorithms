#include<iostream>
#include<vector>
#include<string.h>

using namespace std;
/*
This Program is to find that is there is way to reach the end of the array
given the maximum jump in the array;

Idea : - The idea is to use the array of same size to indicate we can reach there
          by putting 1 in that array.
          
Sol : - We traverse the array for each A[i] we mark ar[i] as 1 to indicate that
        we can reach there from A[i] 
        
        Then we again Traverse ar[i] if any of them is 0 it means that we cannot 
        reach there and we say solution is not possible
*/

int canJump(vector<int> &A) {
    
 int ar[A.size()];
 
 memset(ar,0,sizeof(ar));  // Intialize with zero
 
 
 for(int i=0;i<A.size();i++)
 {
     if(A[i] !=0)        // if there is valid number to traverse should be greater than zero
     for(int j=i+1;j<A.size() && j<=A[i]+i;j++)
     {
         ar[j] = 1;  // mark it as 1 to indicate we can reach there
     }
 }
 
 bool flag = true;       // boolean variable 
 
 
 for(int i=1;i<A.size();i++)
 {
     
 //cout<<ar[i]<<" ";
  if(ar[i]!=1)      // To check we can reach each of the path from begining
  {
      flag = false;
      break;
  }
 }
if(flag)
return 1;
else
return 0;
    
    
}
int main()
{
 vector<int> ar;  // array = {2,3,1,1,4}
 ar.push_back(2);
 ar.push_back(3);
 ar.push_back(1);
 ar.push_back(1);
 ar.push_back(4);
 
 // 1 to indicate it is possible to reach there
 cout<<canJump(ar);
 
 
 	
return 0;
}
