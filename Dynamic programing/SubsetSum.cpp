#include<iostream>

using namespace std;

/*
  We take 2D matrix the upper rows indicate the sum that 0,1,2,3,...n
  The colums indicate the elements we have in the set
   suppose
     Sum
   0 1 2 3 5  Here We want to get whether we can get sum to 5 or not
0  T F  F F F
1  T            We fill Intially this
3  T
9  T
2  T

Step 2-> After Including the next Element can we get the sum 
         Without including if We are getting the Sum then also it is true
*/

bool SubsetSum(int ar[],int n,int sum)
{
  bool Sum[n+1][sum+1]={0}; // Array to indicate whether we can get the sum
 // we If the sum == 0 then without including any element we can get the sum
 for(int i=0;i<n;i++)
   Sum[i][0] = true;
   
// We cannot get any sum if we have only zero element hence put false every where
for(int j=1;j<=sum;j++)
  Sum[0][j];
  
  
// For the rest of element

for(int i=1;i<=n;i++)
{
	
  for(int j=1;j<=sum;j++)
  {
    // it Means WhatEver the value of Sum[i-1][j] then we put it here 
    // if it is True it means we can get the sum without including it 
    Sum[i][j] = Sum[i-1][j];
    
    // check if we cannot get the sum
  // j>=ar[i-1] means that we can subtract the element or the element is less than sum till
    if(Sum[i][j] == false && j >=ar[i-1])
    {
      // it means that by Subtracting the Current included element we can get the sum or not
       Sum[i][j] = Sum[i][j] | Sum[i][j-ar[i-1]];
       //Sum[i][j-ar[i-1]] means that subtract j it will shift left ward to get the sum
       // And check whether it is true or false    
    }
    
           
  }
  }  
     
 return Sum[n][sum];
}
int main()
{
int ar[] = {1,3,9,2};
int sum = 5;
int size = sizeof(ar)/sizeof(ar[0]);
cout<<SubsetSum(ar,size,sum);
return 0;
}
