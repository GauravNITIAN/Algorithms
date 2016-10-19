#include<iostream>
#include<stack>

using namespace std;

int main()
{
  
  int stock[] = {100,90,70,50,80,90};
  int n = sizeof(stock)/sizeof(stock[0]);
  int span[n];
  stack<int> s;
  
  // first element has always span 1 
  s.push(0);
  span[0]  = 1;
  
  // for the rest of the elements
  for(int i=1;i<n;i++)
  {
      // if previous element is smaller than the current element then it is in the span
      // pop it to compute the difference of largest element which is greater than it
      // we used index to indicate a element in the stack 
      while(!s.empty() && stock[s.top()] <= stock[i] )
      s.pop();
      
      // it means that the current smaller is larger than previous pushed element in stack
      // or it may be chance that the array is empty
      
      if(s.empty())
      {
         span[i] = i+1;
            }      
        else
        {
        	span[i] = i - s.top();	
        }
        
        s.push(i);
      
  }
  
  // print span 
  for(int i=0;i<n;i++)
  {
     cout<<span[i]<<" ";
  }
  
  
}
