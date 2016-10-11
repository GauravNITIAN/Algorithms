#include<iostream>
#include<string.h>
using namespace std;
int main()
{
   
   // counting sort
   int ar[]={2,4,1,0,0,1,2,3,4,6,2,6,3};
   int count[7];
   int n = sizeof(ar)/sizeof(ar[0]);
   memset(count,0,sizeof(count));
   
   int c = sizeof(count)/sizeof(count[0]);
   
   for(int i=0;i<=n;i++)
   {
        count[ar[i]]++;
   }
   

   
   // store the index
   
   for(int i =1;i<=c;i++)
   { 
       count[i] = count[i-1] + count[i];
   }
   
  
   // sorting starts here
   int B[n];
   for(int i=n;i>=0;i--)
   {
        B[count[ar[i]]] = ar[i];
        count[ar[i]]--;
        
        
   }
   
  for(int i=0;i<n;i++)
  cout<<B[i]<<" "; 
    
   
   return 0;
}
