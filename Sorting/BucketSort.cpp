#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Bucket sort is used basically when we have range of values
*/

int main()
{
 
 // sort using Bucket sort;
 int n = 6;
 vector<float> bucket[n];
 float ar[]={0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
 int k =0;
 // put the elements in bucket
 
 
 int size = sizeof(ar)/sizeof(ar[0]);
 for(int i =0;i<size;i++)
 {
      int index  =  n*ar[i];
      bucket[index].push_back(ar[i]);
 }
 
 
 // sort the Array
 for(int i=0;i<n;i++)
 sort(bucket[i].begin(),bucket[i].end());
 
 for(int i=0;i<n;i++)
 for(int j=0;j<bucket[i].size();j++)
 {
     ar[k++] = bucket[i][j];   
 }
 
 for(int i=0;i<k;i++)
 cout<<ar[i]<<" ";
 
 
 return 0;
}
