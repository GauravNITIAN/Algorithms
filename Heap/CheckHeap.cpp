#include<iostream>

using namespace std;

/*
This function is to check whether the tree represents a tree or not


*/

bool CheckHeap(int ar[],int i,int n)
{
  
  // base case from here all is leaf
  if(i>(n-2)/2)
  return true;
  
  // need to check the left Subtree and right subtree smaller than root4
  // Then iterate it right subtree and left subtree
  if(ar[i] >= ar[2*i+1] && ar[i] >= ar[2*i+2] && CheckHeap(ar,2*i+1,n) && CheckHeap(ar,2*i+2,n))
  {
      return true;	
  }
  //else you need to return false
  
  return false;
}

int main()
{

int ar[] = {90, 15, 10, 7, 12, 2, 7, 3};
    int n = sizeof(ar) / sizeof(int);
    
    if(CheckHeap(ar,0,n))
    cout<<"Satisfies Heap";
    else
    cout<<"Not Satisfies Heap";


return 0;
}
