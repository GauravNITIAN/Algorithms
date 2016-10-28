#include<iostream>

using namespace std;

int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int LongestPalindromicSubsequence(string s)
{
 int n = s.length();
  int palindrome[n][n];
 // For One Letter Palindrome
 for(int i=0;i<n;i++)
   palindrome[i][i] = 1;
   
   // for 2 letter Palindrome
  for(int len =2;len<=n;len++) 
   {
        for(int i=0;i<n-len+1;i++)
        {
            int j =i+len-1;
            
            if(s.at(i)==s.at(j))
            {
            	palindrome[i][j] = palindrome[i-1][j-1]+2;
            	cout<<palindrome[i][j]<<" ";
            }
            else
            {
            	palindrome[i][j] = max(palindrome[i+1][j],palindrome[i][j-1]);
            }
        }
   }
   
   
   return palindrome[n-1][n-1];
   
   
   

}
int main()
{
string str = "hello";
cout<<LongestPalindromicSubsequence(str);
return 0;
}
