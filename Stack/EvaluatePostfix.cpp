#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

/*

Evalute the Postfix Expression
In a ostfix we have <operand> <operand> <operator>
it is very simple we compute the arithmetic operation then push that in to the stack;

--->>> The last left Element is our Solution

*/

// utillity function to evalute the expression
char Evalute(char a,char b,char op)
{
  int n1 = a - '0';
  int n2 = b - '0';
  int ans = 0;
  
  switch(op)
  {
   case '^':
   ans = pow(n1,n2); 
   break;	
   case '*':
   ans = n1 + n2;
   break;
   case '/':
   ans = n1*n2;
   break;
   case '+' : 
   ans = n1+n2;
   break;
   case '-':
   ans = n1-n2;
   break;

   
  }
  
   cout<<ans<<" ";
  return ans;
}

char EvalutePostFix(string ar)
{
  // put every thing on to the stack
  // so the elements are in the postfix form hence the fist element should appear at the 
  // top so put it in the reverse order
  stack<int> postfix;
  for(int i=ar.length() -1 ;i>=0;i--)
    postfix.push(ar[i]);
    
  while(postfix.size() >= 3)
  {
   // first operand	
   int n1 = postfix.top();
   postfix.pop();
   // second operand
   int n2 = postfix.top();
   postfix.pop();
   // operator
   char op = postfix.top();
   postfix.pop();
    
    int cal = Evalute(n1,n2,op);
    
    // push the res in the stack
    postfix.push(cal);
  }
  return postfix.top();
}


int main()
{
	
string ar = "85+4*32*3/-";

cout<<EvalutePostFix(ar);	
return 0;
}
