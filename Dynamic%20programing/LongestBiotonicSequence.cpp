#include<iostream>

using namespace std;
/*
  Problem : - The Problem of Longest BioTonic Sequence is to find a sequence that increase
              then decrease
  Note: -This is similar to LIS Problem but only difference is that here increasing as well 
         as decreasing is added in it.
  Approach: - 1)The approach is very much simmilar here we will find LIS from 0...n 
              2)Then find the LIS from last that is n...0 
	3) This will give the Longest increaing in forward also longest decreasing 
	   from forward direction
	4) After we need to add the two to get actual longest sequence that will be
	nothing but max of addition of both -1 beacuse one element will be 
	included in both the direction.
*/
int LongestBiotonicSequence(int ar[],int n)
{
     int LIS[n]={0};
     int DIS[n]={0};
     
     //For Longest Increaing sub Sequence
     LIS[0] = 1;         // One Element will always be in the sequence
     for(int i=1;i<n;i++)
     {
        for(int j=0;j<i;j++)
        {
        	// Here LIS[i] < LIS[j]+1 means adding the LIS[j] increasing the length 
        	// of Sequence hence we need to update
        	if(ar[i] >= ar[j] && LIS[i] < LIS[j]+1 )
        	{
        	    LIS[i] = LIS[j]+1;
	        }
        }
     }
     
     // For Longest Increasing Sub Sequence in Reverse Order
     DIS[n-1]=1;    // Last one will be 1 to indicate one element in the sequence
     
     for(int i=n-2;i>=0;i--)
     {
         for(int j=n-1;j>i;j--)
         {
         	if(ar[i] >= ar[j] && DIS[i] <DIS[j]+1)
         	{
         	  DIS[i] = DIS[j]+1;
	         }
         }
     }

//Check for the Longest BioTonic sub Sequence
int max = 1;
for(int i=0;i<n;i++)
{
  if(max < LIS[i]+DIS[i]-1)
  {
           	max  = LIS[i]+DIS[i]-1;
  }
}
     return max;
}
int main()
{
 int ar[]={1, 11, 2, 10, 4, 5, 2, 1};
 int size = sizeof(ar)/sizeof(ar[0]);
 
 cout<<LongestBiotonicSequence(ar,size);
 
}
