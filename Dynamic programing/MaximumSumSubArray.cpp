#include<iostream>

using namespace std;

/*
Longest Increasing Contiguous Sequence Using Dynamic Programing
Idea 
 1) We know one elememt is Increasing subsequence 
 2) Now for Second Element if it greater than the second then 
    it is included in the solution
*/


int MaximumSumSubArray(int ar[],int n)
{
//
int maxSum = INT_MIN;
int start=0,end=0;

for(int i=0;i<n;i++)
{
 // Start with i and add till n to see the greatest sum
 int curr = 0;   // Start with the current sum and go to n
  for(int j=i;j<n;j++)
  {
    curr += ar[j];  //(i ----n) or (i-1 to n) or (i-2 to n) ...... to get the max
    if(curr > maxSum)
    {
         start = i;       // Start index of SubArray
        maxSum = curr;
        end = j;          // End Index of SubArray
       
        }    
  }
  
 }
 
 cout<<start<<" "<<end<<endl;
 return maxSum; 
}

//Maximum Sum Using Dynamic Programing
int MaxContinousSumDP(int ar[],int n)
{
 int currSum = 0,maxSum = 0;
 
 for(int i=0;i<n;i++)
 {
  currSum += ar[i];
  if(currSum <0)
  {
    currSum = 0;
    continue;
  }
  if(currSum > maxSum)
  {
       maxSum = currSum;
  }
  
  
 }
 
 return maxSum;
}


int main()
{
// array 
int ar[]={1, 56, 58, 57, -90, 92, 94, 93, 91, 45};

int size = sizeof(ar)/sizeof(ar[0]);

int sum = MaximumSumSubArray(ar,size);

cout<<sum;

cout<<MaxContinousSumDP(ar,size);
return 0;
}
