#include<iostream>

using namespace std;


/*

Program to find the kth largest using Heap sort 
First we need to make then apply k times removal of max element to 
get kth largest element
*/

void swap(int &a,int &b)
{
 int temp = a;
 a = b;
 b = temp;
}

void Heapify(int ar[],int i,int n)
{
 
  // Left subtree index
  int left = i*2+1;
  // right subtree index
  int right = i*2+2;
  int largest = i;
  
  
  if(left <n && ar[left] > ar[largest])
    largest = left;
  
  if(right < n && ar[right] > ar[largest])
    largest = right;
  
  
  // check if there is change in it
  if(largest != i)
  {
    // need to swap
    swap(ar[i],ar[largest]);
    
    //heapify the swapped to check whether it staisfies the heap property
    
    Heapify(ar,largest,n);
    
  }
  
}

void HeapSort(int ar[],int n)
{
  for(int i = n/2;i>=0;i--)
  {
    Heapify(ar,i,n);
  }
}

void kthLargest(int ar[],int n,int k)
{
	
// make it heap first
  	
   // swap with the last element
   for(int i=0;i<k-1;i++)
   {
   
    swap(ar[0],ar[n-i-1]); //  make it to the end so that it excluded form the heap
    // heapify the first element
    Heapify(ar,0,n-i-1);

    
}
  cout<<ar[0];  
    
    
}



int main()
{
 
 int ar[] = {90, 15, 10, 7, 12, 2, 7, 3};
    int n = sizeof(ar) / sizeof(int);
    HeapSort(ar,n);
    
    kthLargest(ar,n,6);
return 0;
}
