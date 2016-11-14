#include<iostream>

using namespace std;

/*
Quick Sort Algorithm
*/

void print(int ar[],int n)
{
   for(int i=0;i<n;i++)
   cout<<ar[i]<<" ";
}


int swap(int &a,int &b)
{
 int temp = a;
 a = b;
 b = temp;
}



int partition(int ar[],int low,int high)
{
  int pivot = ar[high];  // pivot element
  int j = low-1; // left subarray is lesser and right are greater
  
  for(int i=low;i<=high-1;i++)
  {
    if(ar[i] <= pivot)  // if pivot is grater then it means this element belongs to 
    {                   // its left side so swap it
     swap(ar[j++],ar[i]);
     
    }
  }
  
  swap(ar[j+1],ar[high]);
  
  return j+1;
}

void QuickSort(int ar[],int low,int high)
{ 
  // call the partion algorithm
  	
 if(high > low)
 {
	  	
  int mid = partition(ar,low,high);
  
  QuickSort(ar,low,mid-1);
  QuickSort(ar,mid+1,high);
}

}
int main()
{
int ar[]={1,4,2,6,9,5,3};
int n = sizeof(ar)/sizeof(ar[0]);
QuickSort(ar,0,n-1);
print(ar,n);
return 0;
}
