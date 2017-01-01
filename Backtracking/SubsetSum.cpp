#include<iostream>
#include<vector>

using namespace std;
/*

This Problem is to solve whether it is possible to get the given target sum
from the given set of integers and returns 1 or 0 depending on the situation

Key Ideas : -
1) We use a backtracking approach 
vector<int> ar ---- > Array stores actually elements
int target     ---- > target sum
int i         ----- > store the index
int sum       ----  > Sum till now

*/
bool SubsetSum(vector<int> ar,int target,int i,int sum)
{
    if(sum == target)  //If it is equal the return 1	
      return 1;
    if(sum+ar[i] > target || i == ar.size() )   //COndition to return 
      return 0; 
      
    bool with =  SubsetSum(ar,target,i+1,sum+ar[i]);  // Left Subtree include it to current sum
    bool without = SubsetSum(ar,target,i+1,sum);  // Right Subtree exclude it to current sum
    
    return (with | without);
    
}
int main()
{
  vector<int> ar;
  
  ar.push_back(2);
  ar.push_back(4);
  ar.push_back(8);
  ar.push_back(10);
  
  //Function call
  cout<<SubsetSum(ar,14,0,0);
  
  return 0;
}
