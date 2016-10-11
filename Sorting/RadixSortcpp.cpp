#include<iostream>
using namespace std;

void RadixSort(int *,int );
void countSort(int *,int ,int );
int main()
{

int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    RadixSort(arr, n);
return 0;
}

void RadixSort(int ar[],int n)
{
	
int max =  802;        //Maximum number of  Input Array 	
// sort based on digits
for(int i=1;max/i>0;i=i*10)
countSort(ar,n,i);

// Print Sorted numbers
for(int i =0;i<n;i++)
{
  cout<<ar[i]<<" ";
}

}

void countSort(int ar[],int n,int exp)
{

//count Array to store the count of numbers
int count[10]={0};  // Intialized with zero
for(int i=0;i<n;i++)
count[(ar[i]/exp)%10]++;

// store How many no are less than equal to this number
for(int i =1;i<10;i++)
count[i] = count[i-1] + count[i];

// sort the Array by decrement its index
int B[n]; // Auxliary array
for(int i=n-1;i>=0;i--)
{
   B[count[(ar[i]/exp)%10]-1] = ar[i];  // count[ar[i]] stores the location of element
   count[(ar[i]/exp)%10]--;    
}

//Save back
for(int i=0;i<n;i++)
{
   ar[i] = B[i];
}
	
	
}

