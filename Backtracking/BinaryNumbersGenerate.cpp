#include<iostream>
#include<vector>

using namespace std;
/*
This problem 
*/
void BinaryNumbers(vector<int> &ar,int n)
{
   if(n<1)
   {
     for(int i=ar.size()-1;i>=0;i--)        // prints the array
     cout<<ar[i]; 
     cout<<endl;	
   }
   else
   { 
      ar[n-1] = 0;
      BinaryNumbers(ar,n-1);
      
      ar[n-1] = 1;  // backtrack here
      BinaryNumbers(ar,n-1);
   }
}

int main()
{

vector<int> res;

res.push_back(0);
res.push_back(0);
res.push_back(0);
res.push_back(0);

BinaryNumbers(res,res.size());
return 0;	
}

