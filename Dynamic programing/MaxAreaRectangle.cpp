#include<iostream>
#include<vector>
#include<stack>

using namespace std;
/*

Max area in the binary 2d Matrix 

Idea - the idea is to use Histogram for each row and calculate the area of each
       after calcuating update the max area
       
       Then for each next ar[i][j] if it is zero then make it zero otherwise add 
       it as ar[i][j]+1 to say that it will contribute to max area  
 
*/


int Histogram(int ar[],int n)
{
   stack<int> st;
   int max=-1;
   int max_area = 0;
   int i=0;
   while(i<n)
   {
      if(st.empty() || ar[i] >= ar[st.top()])
         st.push(i++);
      else
      {
          int top = st.top();
          st.pop();	
         if(st.empty())
           max_area = ar[top]*i;
         else
            max_area = ar[top]*(i-1-st.top());
            
            
      if(max_area > max)
         max = max_area;     
         	
      }   
   }
   
   while(!st.empty())
   {
      int top = st.top();
          st.pop();	
         if(st.empty())
           max_area = ar[top]*i;
         else
            max_area = ar[top]*(i-1-st.top());
            
            
      if(max_area > max)
         max = max_area;  
   }
   return max;
}
/*
Here vector<vector<int>> contains Zeros ans ones we need to calculate the max rectagle 
area.
Here the trick is to use Histogram per row and calcuate the max area for each row 
and return the max


*/
int MaxAreaRectangle(vector<vector<int> > ar)
{
  int len = ar[0].size();
  int max_area,max = -1;
  int arr[len] = {0};  //initialize it with zero
  
  for(int i=0;i<ar.size();i++)
  {
     for(int j=0;j<ar[0].size();j++)
     {
     // cout<<ar[i][j]<<" "; 	
        if(ar[i][j]!=0) 	
        arr[j] = arr[j]+1;
        else
        arr[j] = 0;  
     }
    // cout<<"\n";
     
     max_area = Histogram(arr,len);
     
     if(max_area > max)
      max = max_area;
  }
  
  
  return max;
  
}

int main()
{


/*

Matrix is like this

                   { {0, 1, 1, 0},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 0, 0},
                 };
*/
vector<vector<int> > ar;

vector<int> temp1,temp2,temp3,temp4;
temp1.push_back(0);
temp1.push_back(1);
temp1.push_back(1);
temp1.push_back(0);
ar.push_back(temp1);

temp2.push_back(1);
temp2.push_back(1);
temp2.push_back(1);
temp2.push_back(1);
ar.push_back(temp2);

temp3.push_back(1);
temp3.push_back(1);
temp3.push_back(1);
temp3.push_back(1);
ar.push_back(temp3);

temp4.push_back(1);
temp4.push_back(1);
temp4.push_back(0);
temp4.push_back(0);
ar.push_back(temp4);

cout<<MaxAreaRectangle(ar);
return 0;
}
