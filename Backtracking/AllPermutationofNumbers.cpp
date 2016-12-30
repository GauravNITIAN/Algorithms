#include<iostream>
#include<vector>

using namespace std;
/*
This problem is to find the all permuation of the given numbers 
suppose 123
permuations possible will be 123,132,213,231,312,321

Idea :- The Idea is to use a backtrack method first we fix first number 
        i.e 1 then fix second upto n-1 then once l==r we print the numbers
        After that we backtrack to previous to swap again the numbers and this goes 
        on.... 

*/

void permutation(vector<int> &a,int l,int r)
{
    if(l == r)
    {
        for(int i=0;i<a.size();i++)
         cout<<a[i]<<" ";
         cout<<endl;
    }
    else
    {
        for(int i=l;i<r;i++)
        {
            swap(a[l],a[i]);         // Fixing the posistion of the number
            permutation(a,l+1,r);  // Rercusive call here
            swap(a[l],a[i]);   // here We backtrack to our previous
        }
    }   
}


int main()
{
vector<int> res;
res.push_back(1);
res.push_back(2);
res.push_back(3);

permutation(res,0,res.size());

return 0;	
}  
