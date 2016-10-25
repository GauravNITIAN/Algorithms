#include<iostream>
#include<math.h>
using namespace std;

int main()
{
 //Check Kth Bit is Set or not
 // Method 1
 int n = 12;
  int k = 4;
  
  // left shift 1 by 3 i.e k-1 times bit
  // AND it with n if is not not zero then the bit is set otherwise not
  // 1<<(k-1) = 00001000 for 8 Bit
  // n = 12 00001010  
  
  if(n & 1<<(k-1))
    cout<<k<<" Bit is Set";
   else
    cout<<k<<"Bit is Not Set";
   
 // method 2 
 
  if(n & (int)pow(2,k-1))
     cout<<k<<" Bit is Set";
   else
    cout<<k<<"Bit is Not Set";
  
return 0;
}
