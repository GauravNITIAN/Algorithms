#include<iostream>

using namespace std;
/*

Rod Cutting Problem is to cut the rod given the prices of pieces of rods 
optimally so that the we maximimum benefit from it


*/
// ar[] ----> It is the array of prices of different pieces of length 1,2,3,...n
// n -----> length of the array
// len ----> It is given the length through which we need to calculate the max price by cutting
int RodCutting(int ar[],int n,int len)
{
 int arr[n+1][len+1];
 
 for(int i=0;i<n+1;i++)
 for(int j=0;j<len+1;j++)
   arr[i][j] = 0;    // Initalize it with zero
   
 for(int i=1;i<=n;i++)
 {
    for(int j=1;j<=len;j++)
    {
      	       
        if(j>=i)     // here it means arr[i][j-i]+ar[i-1] profit j-i value index plus current	
          arr[i][j] =max(arr[i][j-i]+ar[i-1],arr[i-1][j]);//arr[i-1][j] means above profit
       else
          arr[i][j] = arr[i-1][j];
        
       
      // cout<<arr[i][j]<<" ";	
    }	
    //cout<<"\n";
 }    
 
 //return the max value
 return arr[n][len];
}

int main()
{
  int ar[] = {2,5,7,8};
  
  int n = sizeof(ar)/sizeof(ar[0]);
  int len = 5;
  cout<<RodCutting(ar,n,len);
}
