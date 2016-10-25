#include<iostream>

using namespace std;

int main()
{

  int n = 12;
  int k = 4;  // Want to clear 4th bit
// Clearing kth bit
   /*
   Basic Idea to set the kth bit to zero and rest with 1
   */
   // set kth bit to 1;
   int kth = 1<<(k-1);
   kth = ~kth;  // negate to make kth bit 0 and rest to 1
   
   int ans = n&kth;
   
   cout<<ans;
   
   
   
return 0;
}
