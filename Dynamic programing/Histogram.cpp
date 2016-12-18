#include<iostream>
#include<stack>
using namespace std;

int Histogram(int hist[],int n)
{
 int max=-1,max_area;
 stack<int> st;
 int i=0;
 
 while(n>i)
 {
   // if the histogram bar is greater  than thetop of stack or the stack is empty
   // it means max area can be found towards the right side
   if(st.empty() || hist[i] >= hist[st.top()])
        st.push(i++);
   
   else
   {
      // you can pop the stack say you can calcuate the area till no 
      //because the next bar is clearly smaller hence it must not contibute 
      // to max area till now
      int top = st.top();
      st.pop();
      
      if(st.empty())
      {
             max_area = hist[top]*i;
      }
      else
          max_area = hist[top]*(i-1-st.top());
          
          
       // update the max Area
       
       if(max_area > max)
       max = max_area;
          
      
   }
   
 }
 
 // Do for the rest of the elements
 while(st.empty() == false)
 {
   int top = st.top();
      st.pop();
      
      if(st.empty())
      {
             max_area = hist[top]*i;
      }
      else
          max_area = hist[top]*(i-1-st.top());
          
          
       // update the max Area
       
       if(max_area > max)
       max = max_area;
          
	 }	
    
    return max;
}

int main()
{
   int hist[] = {1};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << "Maximum area is " << Histogram(hist, n);
}
