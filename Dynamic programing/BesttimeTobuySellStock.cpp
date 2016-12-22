#include<iostream>

using namespace std;
/*

The Problem is sovle the best time to buy a stock and sell at the best time so that it gains maximum profilt

Idea : - the idea is to traverse the array choose the first element as to buy then check to next if it is
         greater than the previous then we get the profit otherwise if the next day has smaller stock value
         then we make that day as buy day and then traverse other in the same way. MeanWhile we update each profit
         with the max profit each day.
*/

int BestTimeToBuyStock(int ar[],int n)
{
   int buy = ar[0];              // making the first element as buy
   int profit = 0,max_profit = 0;	
   for(int i=1;i<n;i++)
   {
      if(buy <= ar[i])        // if the next element is smaller then we have a profit 
        profit = ar[i]-buy;
      else
      buy = ar[i];  // if next day is smaller value stock  then we buy the stock this day and sell it to another day
      
      if(profit > max_profit)        // update the max_profit each time
      max_profit = profit;
   }
   
   return max_profit;
}
int main()
{
int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price)/sizeof(price[0]);
 
    
    cout<<BestTimeToBuyStock(price, n);
}
