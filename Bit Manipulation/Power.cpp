#include<iostream>

using namespace std;

int main()
{
//Check the Number is power of 2 or not
int n = 128;
/*
Note : - Here the Precedence of n&n-1 if is less than == hence we have to use brackets here
*/
if((n&n-1)==0)    
cout<<"Power of Two"<<endl;
else
cout<<"Not Power of Two"<<endl;

// Multiply A Number by Two
/*
It means left shift by the Power of two
10*4 = 40
10<<2 = 40
Caution : - Make sure there is no Integer overflow here
*/
int n1 = 10;
int k = 2;
int mul = n1<<k;

cout<<mul<<endl;

//Divide a Number by power of 2
/*

Right Shift will give the result
*/ 
int div = n1>>2;
cout<<div<<endl;

return 0;
}
