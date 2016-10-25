#include<iostream>

using namespace std;

int main()
{
/*

Reversing the binary number
Idea : -
1) We can take a variable b = 0;
2) Then let n be the number then we extact or check the last 
   one bit in n if it is 1 then we OR it with result then left shit
   to move towards left
3) And the n is right shifted to get the next 1;

*/

unsigned int n =1; // Get the reverse as 2147483648 as only 32 th bit is set
unsigned int b =0;
unsigned int n1 = n;
for(int i=0;i<32;i++) // loop will run 32 times if we have 32 bit numbers
{
 b = b<<1; // left shift 
 b = b|(n&1); // here if A has last bit set or not 
 n=n>>1; // right shift
 
 //cout<<b<<endl;
}

//results

cout<<b;



return 0;
}
