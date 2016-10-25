#include<iostream>

using namespace std;

int main()
{
// No of set of Bits
int n = 128;
int count = 0;
while(n)
{
  n = n&n-1;
  count++;
}
cout<<count;
}
