#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
This problem is the backtracking Problem Here we find all the subsets in others words 
we compute the power set of the given set of integers using the backtracking method.

   Here we have taken the approach to take or not to take it at one branch
   Example : - 1,2,3
                         (Incuded)    3    (Not Include)
                                2             2
                            1       1       1      1
                        0      0  0    0  0    0 0    0
                        |      |  |    |  |    | |     |
                   (1,2,3) (3,2)(3,1) (3)(2,1)(2)(1)  (empty set)
 */

void print(vector<int> ar)
{
   
   sort(ar.begin(),ar.end());
   for(int i=0;i<ar.size();i++)
   {
     //Print the power Sets
    cout<<ar[i]<<" ";
    }
    
}

void powerSet(vector<int> ar,int n,vector<int> &included)
{
       if(n<1)       //condtion to break and print power Set
       {
       	print(included);
       	cout<<endl;
       
       }
       else
       {
       included.push_back(ar[n-1]);      //Include the element in the power Set
       powerSet(ar,n-1,included);       // Recursive call to the left subtree
       included.pop_back();           // Exclude the element from the power Set for right subtree
       powerSet(ar,n-1,included);    //  Recursive call to the right subtree
       }
      
}

int main()
{
// array in sorted order
vector<int> ar;
ar.push_back(1);
ar.push_back(2);
ar.push_back(3);

vector<int> res;
powerSet(ar,ar.size(),res);	 // function call


return 0;
}
