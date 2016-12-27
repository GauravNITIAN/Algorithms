#include<iostream>
#include<string.h>

using namespace std;

/*
This problem to find the longest Repeating subsequnce 
This is simmilar to LCS prblem but we only thing is that we need not check for
i and equal to j because at that position both the elements are same

*/

int LongestRepeatingSubsequence(string str)
{
  int n = str.length();
  int table[n+1][n+1];
  
  memset(table,0,sizeof(table));
  
  for(int i=1;i<n+1;i++)
  {
    for(int j=1;j<n+1;j++)
    {
      if(str[i-1] == str[j-1]  &&  i!=j)
         table[i][j] = 1+table[i-1][j-1];
      else
         table[i][j] = max(table[i-1][j],table[i][j-1]);   
    }
  }
  return table[n][n];
}

int main()
{
string str = "abba";	
cout<<LongestRepeatingSubsequence(str);	
return 0;
}
