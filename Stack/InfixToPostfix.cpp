#include<iostream>
#include<stack>

using namespace std;
/*
Evaluate Expression using stack
*/

char ar[100];
int k =0;
// Driver function to check operand

bool isOperand(char a)
{
  int x = a-'0';
  
  if(x >= 0 && x<=9)
  return true;
  else
  return false;
  
}

// to check priority
int priority(char a)
{
  if(a >=48 && a<=57) // highest priority
  return 8;
  else if(a == '^')
  return 5;
  else if(a == '*' || a == '/')
  return 4;
  else if(a == '+' || a == '-')
  return 2;
  else 
  return 0;
}


char * InfixTopostfix(string str)
{
 // push the a ( in stack
 stack<char> st;
 st.push('(');
 
 
  
 for(int i=0;i<str.length();i++)
 {
   // first we need to pop the first element
   char top = st.top();
   // check if it is operand
   if(isOperand(str[i]))          //case 1
   {
      // output this 
      ar[k++] = str.at(i);
     
      }   
      
      
   else if(str[i] == '(')            //case 2
   {
       st.push(str[i]);
       	
   }
   
   
   else if(str[i] == ')')   //case 3 pop till we get closing brace
   {
       while(!st.empty() && st.top() != '(')
       {
       ar[k++] = st.top();
       st.pop();
   }
    if(st.top() == '(')
    st.pop();
 
  
}
       

   
   // case 4 to check priority of operands
   else if(priority(top) >= priority(str[i]))
   {
     // pop till we get the lower priority
     while(!st.empty() && priority(top) >= priority(str[i])) 
     {
	     	
    ar[k++] = st.top();
    st.pop(); 
    top = st.top();
}

st.push(str[i]);
   }
   
 
 else if(priority(top) < priority(str[i]))
 {
    st.push(str[i]);
 }
 else
 {
  cout<<"Invalid Expresion";
  exit(0);
  } 
  
}

while(!st.empty())
{
 ar[k++] = st.top();
 st.pop();  
}
return ar;
}
int main()
{

string str = "(8+5)^4-(3*2)/3";
InfixTopostfix(str);

// print the postfix form
for(int i=0;i<k-1;i++)
{
  cout<<ar[i];
}

return 0;
}
