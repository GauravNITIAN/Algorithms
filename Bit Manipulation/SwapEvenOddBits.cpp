#include<iostream>

using namespace std;

int main()
{
 // Exchange the odd bits with Even bits
 /*
 oxAA = 10101010  Even postion set bits
 0x55 = 01010101  Odd position set bits
 
 1) We right shfit the Even set bits by 1
 2) We left shift the  odd set bits by 1
 
 This step will ensure that the even bits in n goes to odd 
 And the odd bits will shift to even positions
 i.e left side bits goes to right and right to left 
 */
 
 unsigned int n = 10,even,odd,ans;
  
 even = n&0xAAAAAAAA; // here A has 101010... bits hence at even positon
 odd = n&0x55555555;  // 01010101.... hence it is odd position
 
 // cout<<sizeof(n)<<endl;  size is 4 bit
 even = even>>1;
 odd = odd<<1;
 
 ans = even|odd;  // number are exchanged with odd and even
  
 cout<<ans; 
return 0;
}
