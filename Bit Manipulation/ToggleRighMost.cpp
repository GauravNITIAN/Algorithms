#include<iostream>

using namespace std;

int main()
{
	
// Isolate the right most 1 th bit
// Means if n = 01001010 then ans is 00000010	
 int n = 74;
 /*
 Logic is if we negate it then it is 2's complement that toggle all 
 the bits and add 1 to it
 here n = 01001010 
     -n = 10110101+1 = 10110110
 Note : - Here the last 1 th Bit of n and -n always be same 
 */
 
 n = n&-n;
 cout<<n<<endl;
 
 // Problem 2
 // Isolate the right most 0 th bit
// Means if n = 00001001 then ans is 00000010
 n = 9;
 int n1 = ~n;  // 11110110 All 1's are 0 ans 0's are 1 then 
 n1 = n1&-n1;              //the problem is resolved to above one
 cout<<n1<<endl;
 // method 2
 int n2 = ~n;
 n = n+1; // if the last bit is 1 then will move the 1 left side 
          // then problem resolved to find the right most 1 as above
n2 = n2&n;

cout<<n2;
          
 
 

 
 
}
