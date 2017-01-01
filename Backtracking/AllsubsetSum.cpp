#include<iostream>
#include<vector>

using namespace std;
/*
 There is two condition to backtrack
 
 1) sum till now either included or not + elements left < desired sum 
 2) sum till now either include or not + next element > desired sum
  
  Key Ideas : -
  -> The key Ideas is to use a backtracking approach to solve or to get all 
     possible subset to get the required sum.
  -> We use two condition to return to say that no solution exits from here
  
  Parameters : -
     vector<int> &a --- it holds a binary value whether to include a element 
                        or not;
     vector<int> ar --- It is the actual array which hold the set of elements
     int target  ------ It is the target or desired sum to get
     int i   ---------- It is the current index either to add this element or not
     int sum  --------  It is the sum till now 
     int remSum ------  It is the remaining sum of the array that will also act as 
                        the breaking condtion 2 if not satisfied
   
*/
void SubsetSum(vector<int> &a,vector<int> ar,int target,int i,int sum,int remSum)
{
    if(sum == target)	
      {
       for(int i=0;i<ar.size();i++)
         if(a[i] == 1)
         {
            cout<<ar[i]<<" ";   // Print the included elements	
         }
         cout<<endl;
      }
      //Conditon 1                             Condition 2     if satisfies return
    if(sum+ar[i] > target || i == ar.size() || remSum+sum < target)  
      return; 
      
     a[i] = 1;      // Include the Current Element
      
     remSum = remSum - ar[i];    // Subtract the current sum either included or not
                                 // From Current level
     
    SubsetSum(a,ar,target,i+1,sum+ar[i],remSum);  // Function Call for the left Subtree
     a[i] = 0;            // Exclude the Current Element
     remSum = remSum + ar[i];
    SubsetSum(a,ar,target,i+1,sum,remSum); // Function call for the right sub tree
    
    
    return;
    
}

int main()
{
  vector<int> ar;
  
  ar.push_back(2);
  ar.push_back(3);
  ar.push_back(4);
  ar.push_back(6);
  ar.push_back(8);
  ar.push_back(10);
  
  vector<int> a(ar.size());
  int remsum = 0;  // Total Sum of the array;
  for(int i=0;i<ar.size();i++)
  remsum+=ar[i];
  
   // Function Call
  SubsetSum(a,ar,14,0,0,remsum);
  
  return 0;
}
