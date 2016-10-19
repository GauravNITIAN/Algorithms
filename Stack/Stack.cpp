#include<iostream>
#include<stdlib.h>
using namespace std;



struct Stack
{
int top;
int capacity;
int *array;


};

// A global variable to Create Stack;
struct Stack *S;

// Create Stack function
struct Stack *CreateStack(int capacity)
{
 
 S = (struct Stack*)malloc(sizeof(struct Stack));
 S->capacity = capacity;
 S->array = (int *)malloc(capacity*sizeof(int));
 S->top = -1;
 
 return S;
}

// fuction to check stack is empty or not
int IsEmpty()
{
   // if top = -1 means no more elements in stack	
   if(S->top==-1)
   {
      return 1;
   }
   
   return 0;
}

// funtion to push a element in stack
void push(int data)
{
  if(S->top == S->capacity -1)
  {
      cout<<"Overflow";
      return;
  }
  S->array[++S->top] = data; 
  
}

// Function to pop a element in stack
int pop()
{
 if(IsEmpty())
 {
       cout<<"Underflow";
       return 0;
}

return S->array[S->top--];
	
}

// Function to get top element

int top()
{
  if(IsEmpty())
  {
     cout<<"Underflow";
     return 0;
  }
  
  
  return S->array[S->top];
}

int main()
{

 CreateStack(10);
 // here underflow
 pop();	
 push(10);
 push(11);
 push(11);
 push(10);
 push(11);
 push(11);
 push(10);
 push(9);
 push(11);
 push(10);
 // Overflow
 push(11);
 
 pop();
 pop();

 
 cout<<top();
 

 return 0;
}

