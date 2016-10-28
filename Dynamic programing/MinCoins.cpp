#include<iostream>

using namespace std;
/*

The Idea of dynamic programing is that 
  -> If we can get the Sum 1,2... in the minimun no of coins
  -> Then extending the problem or using the previous result we can get the sum
      optimally 
   
*/
int MinimumCoins(int values[],int n,int sum)
{
  // it indicates if minCoins[1] = 1 then we can get the value 1 by only 1 coin. 
 int minCoins[sum+1]; // min no of coins to get sum upto it.
 int min = 0;
// here minimum no of coins to get the sum 0 is zero hence
 minCoins[0] = 0;
 
 for(int i=1;i<=sum;i++)
 {
   int min = INT_MAX;  
   for(int j=0;j<n;j++)
   {
     // It means that this coin can be included
     if(i >= values[j])
     {
         // After Including this coin then we compute the minimum 
         // Between the min and minCoins[] after subtracting the current value sum
         min = (min>minCoins[i-values[j]])?minCoins[i-values[j]]:min;
         
         // Here minCoins[i-values[j]]) means current value is subtracted from here
     }
   }
   // Write the min no of Coins to get
   if(min !=INT_MAX)
     minCoins[i] = min+1;  // here it means we need to add one or this coin to result
     else
     minCoins[i] = INT_MAX;
   
 }
 return minCoins[sum];
}
int main()
{
int values[]={1,2,5,10,100,500,1000};
int sum = 610;
int size = sizeof(values)/sizeof(values[0]);

cout<<MinimumCoins(values,size,sum);

return 0;
}
