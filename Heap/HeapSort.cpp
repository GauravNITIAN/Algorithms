#include<iostream>

using namespace std;
/*

Heapsort by buiding the max heap
*/


/*
Heapify is a simple method which is an array and checks whether
the right subtree is bigger or left subtree is bigger then whichever
then it swaps it then it may happen that after swaping the swaped element may
be not satisfy the heap property in that case we need to call the heap again for this 
also I mean the swapped element 

*/

// Afunction to swap element
void swap(int &a,int &b)
{
 int temp = a;
 a = b;
 b= temp;
 
}

void Heapify(int ar[],int n,int i)
{
// stored in Array so
int lchild = 2*i+1;
int rchild = 2*i+2;

int largest = i;  // here is the largest we need 

// check it left child

if(lchild < n && ar[lchild] > ar[largest])
{
     largest = lchild;
}

// check it for rchild
if(rchild < n && ar[rchild] > ar[largest])
{
  largest = rchild;	
 } 

// if we largest have different value then exchange
if(largest != i)
{
	
 swap(ar[largest],ar[i]);
 
 // it may possible that the resultant subtree is not satisfy heap
 // by swapping hence we heapify
 Heapify(ar,n,largest); 
 
}

	
}

int HeapSort(int ar[],int n)
{

// Little Tricky is that the leaf is already a heap then we don't need to heapify 
// it so we heapify a non leaf node here
for(int i = n-1;i>=0;i--)
Heapify(ar,n,i);

// start sorting here
for(int i=0;i<n;i++)
{
 
  //now swap this to end and make the array smaller say n - 1
  // first element is largest so move to end 
  swap(ar[0],ar[n-i-1]);
  
  //heapify the first element as it not satisfy the heap property
  Heapify(ar,n-i-1,0);
   
  	
}


}


int main()
{
  
  int ar[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(ar)/sizeof(ar[0]);
 
    HeapSort(ar, n);
   
   for(int i=0;i<n;i++)
   cout<<ar[i]<<" ";
  
}
