#include<iostream>

using namespace std;

/*
Insertion sort  is like sorting the deck of already partially sorted 
And then insert it at in the appropiate place

*/
void print(int *ar,int n)
{
   for(int i=0;i<n;i++)
   cout<<ar[i]<<" ";
}
void insertionSort(int ar[],int n)
{
for(int i=1;i<n;i++) 
{
  int key = ar[i];
  int j = i-1;
  
  while(j>=0 && ar[j] > key)
  {
  	ar[j+1] = ar[j];
  	j--;
   } 
   
   ar[j+1] = key;
}

print(ar,n);
}

int main()
{
int ar[]={1,4,2,6,9,5,3};
int n = sizeof(ar)/sizeof(ar[0]);
insertionSort(ar,n);

return 0;
}
