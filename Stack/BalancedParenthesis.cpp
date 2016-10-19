#include<iostream>
#include<stack>

using namespace std;

/*
Solution
-> If the character is not the parenthesis then ignore that char
-> If the character is opening parenthesis then push it on to the stack
-> If the character is closing parenthesis ],),} then pop a elemnent from the stack and check 
    it whether is matches with current element if no return false else its ok 

*/

int isBalanced(string s)
{

stack<char> st;

for(int i =0;i<s.length();i++)
{

if(s.at(i) == '('|| s.at(i) == '['|| s.at(i) == '{')
st.push(s.at(i));


// Checking for each parenthesis
else if(s.at(i) == ')' )
{    
 if(!st.empty() && st.top() != '(' )
 return 0;	 
 st.pop();
}


else if(s.at(i) == ']')
{
int top = st.top();
          
if(!st.empty() &&top != '[')
 return 0;
 
 // anyway pop
 st.pop();	
}


else if(s.at(i) == '}')
{
int top = st.top();

if(!st.empty() &&top != '{')
 return 0;
 
 // anyway pop
 st.pop();	
}

}
// check whether the stack is empty or not
if(st.empty())
{
 // means balanced
 return 1;
}

// means the string is not balanced as parenthesis is still left
return 0;


}

int main()
{
string balanced = "(A+B+(A*B))";
string unbalanced = "(A+B)*(A/B+(B+E)))";

cout<<isBalanced(balanced)<<endl;
cout<<isBalanced(unbalanced);



return 0;
}
