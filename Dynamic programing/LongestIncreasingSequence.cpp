#include<iostream>

using namespace std;
/*Length of Longest Increasing SubSequence
 In this We compute the increasing SubSequence and the 
 Sequence need not be continous
 */
int lcs(int ar[],int n)
{
 // We can say one element is always longest Increasing subsequence hence
 int lis[n];
 for(int i=0;i<n;i++)  //Initalize it with 1
 lis[i] = 1;
 
 for(int i=0;i<n;i++)
 {
   // We check it Whether upto i we have increasing subsequence 
   // if it is then we add 1 to lis to indicate the length of longest subsequence upto i
   for(int j=0;j<i;j++)
   {
      // Condition is that element at right should be greater and lis[i]
      // must be less than upto lis[j]+1	
      if(ar[i]>ar[j] && lis[i]<lis[j]+1)
      {
         lis[i] = lis[j] + 1;
         
      }
   }
 }
 
 // We will get array where each element will represent max increasing upto that index
 int max = 1;
 for(int i=0;i<n;i++)
 if(max < lis[i])
 max = lis[i];
 
 
 return max;
}
int main()
{
int ar[]={1, 56, 58, 57, -90, 92, 94, 93, 91, 45};
int size = sizeof(ar)/sizeof(ar[0]);
cout<<lcs(ar,size);
return 0;
}	
