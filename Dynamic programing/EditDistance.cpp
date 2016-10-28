#include<iostream>
#include<string>
using namespace std;
/*
  The Problem is to find the minimum No of Operation to make string1 equal to 
  String2 with insertion,deletion,replace operations

*/

int minmum(int a,int b,int c)
{
  if(a<b)
  {
      if(a<c)
      return a;
      else
      return c;
      }
   else
    {
       if(b<c)
       return b;
       else
       return c;
      }  
  }

int EditDistance(string str1,string str2)
{
 int n1 = str1.length()+1;  // One Extra to compute if we have zero length word
 int n2 = str2.length()+1;
 
 int ar[n1][n2];
 
 for(int i=0;i<n1;i++)
 {
     for(int j=0;j<n2;j++)
     {
        if(i==0)
        {
        	// it means the first string is empty and we need to insert each element
        	ar[i][j] = j;  // As the no of element increases the no of operation increase
        }
        else if(j==0)
        {
        	// it means the second element is zero and we need to
              // delete each element to be equal to second element
	ar[i][j] = i; 
        }
        // IN THIS case the both the char is same so no need for any operation
        // Hence whatever in its diagonal we write it here
        // Reason for wrting from diagonal is that as the elements are same so after trim
        // then min no of operation required will be in its diagonal
        else if(str1.at(i-1) == str2.at(j-1))
        {
        	ar[i][j] = ar[i-1][j-1];
        }
        // If they don't match then it means that we need one more operation 
        // Hence we will check min no of operation around it and 1 to it
        
        else
        {
        	//                     insert    delele    replace
        	ar[i][j] = 1+minmum(ar[i][j-1],ar[i-1][j],ar[i-1][j-1]);
        }
        
     }
 }
 
 
 return ar[n1-1][n2-1];
}

int main()
{
 string str1 = "audio";
 string str2 = "radio";
 
 cout<<EditDistance(str1,str2);
return 0;
}
