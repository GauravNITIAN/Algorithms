#include<iostream>

using namespace std;
int Toggle(int n,int k)
{
 // Get the Kth bit by left shft 1 by k-1 times
 int kth = 1<<k-1;
 // Xor with n to toggle the bit
 return n^kth;
 
}
int main()
{
 // Toggle the Kth bit
 
 int n = 12;
 int k = 4;
 
 cout<<Toggle(n,k);
 return 0;
}
