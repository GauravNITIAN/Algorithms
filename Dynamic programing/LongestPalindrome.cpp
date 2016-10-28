#include<iostream>

using namespace std;

/*
  The problem is to find the longest Palindrome that must be continuous 
  Idea 
  : - One character is always a palindrome here we will take a boolean array to indicate 
      that
      
*/
string LongestPalindrome(string ar)
{
  bool palindrome[ar.length()][ar.length()]; 
  int palindromeBegin = 0;
  int maxlength = 2;
  //One character is a Palindrome
  for(int i=0;i<ar.length();i++)
  palindrome[i][i] = true;
  
  // Check for two char if the first one is equal to second
  for(int i=0;i<ar.length()-1;i++)
  if(ar.at(i)==ar.at(i+1))
  {
        palindrome[i][i+1] = true;
        palindromeBegin = i;
        maxlength = 2;
  }
  
  // Iterate for the rest of the Characters i.e for 3 letter or more palindrome
   for(int len=3;len<ar.length();len++)
   {
      // if the two letter at two index are same then we need to check whether 
      // Excluding these two elements will also give a Palindrome or not
      
      // This loop will iterate through string length - len because we are considering the 
   // or finding the palindrome of length "len". hence the last digits need not consdered. 
      for(int i=0;i<ar.length()-len+1;i++)
      {
       // We need to check the equality first and first+len char hence the logic is 
        int j = i+len-1;
        //if they are equal then after trimming it we will have
        if(ar.at(i) == ar.at(j) && palindrome[i+1][j-1])
        {
          palindrome[i][j] = true;
          palindromeBegin = i;
          maxlength = len;
        }
      }
      
   }
  return ar.substr(palindromeBegin,palindromeBegin+maxlength);
}

int main()
{
 string ar="BANANA";
 
 
 cout<<LongestPalindrome(ar);
 
return 0;
}
