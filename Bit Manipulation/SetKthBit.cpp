#include<iostream>
#include<math.h>
using namespace std;

int main()
{
 
  int n = 12;
  int k = 5;
 //Setting the Kth bit
 // left shift by 1 by k-1 times
 // 1<<(k-1) = 00001000 for 8 Bit
  // n = 12 00001010
  // final value 0f n 28
  n = n | 1<<(k-1);
  cout<<n<<endl;
 // Method 2
 
 n = n | (int)pow(2,k-1);
 cout<<n<<endl; 
  
  
   
 return 0;
}
