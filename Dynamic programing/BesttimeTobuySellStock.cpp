#include<iostream>

using namespace std;

int BestTimeToBuyStock(int ar[],int n)
{
   int buy = ar[0];
   int profit = 0,max_profit = 0;	
   for(int i=1;i<n;i++)
   {
      if(buy <= ar[i])
        profit = ar[i]-buy;
      else
      buy = ar[i];  
      
      if(profit > max_profit)
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
