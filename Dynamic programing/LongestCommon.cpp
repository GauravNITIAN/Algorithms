#include<iostream>
#include<vector>
using namespace std;
/*

This Problem is to find the longest common substring between two substrings efficiently
Idea : - The idea is to use a two dimensional array 
         We are given S1 is fixed then we are given s2 then we need to find the 
         longest matching sequence
         Sol :- if the char match at s1.at(i) == s2.at(j) then we need to check
         after triming means just diagonally what is the value and just add 1 to it.
         
         otherwise if they don't match they are just zero
          

*/

string CommomString(string s1,string s2)
{
 
 int max = INT_MIN;
 string result;
 int match[s1.length()][s2.length()]={0};
 
 for(int i=0;i<s1.length();i++)
 {
      for(int j=0;j<s2.length();j++)
      {
      	if(s1.at(i) == s2.at(j))
      	{
      		
      	  //It means that the character is matching and the length is one 
	  // because either the value of i or j is zero	
      	  if(i==0 || j==0)
      	  match[i][j]=1;
      	  else{
		  
      		// Trim this and see the value in its just diagonal
      		match[i][j]=match[i-1][j-1]+1;
      	}
      		
	      } 
	      
	      // If the char does not match then 
	      else
                      match[i][j]=0;
        // Here we update the maximum value of matching substring
       if(match[i][j]>=max)
       {
       	max = match[i][j];
       	
      	result = s1.substr(i-max+1,i+1);
       	cout<<i-max<<" "<<i<<endl;
	 }
      	      
     	      	      
      }
      
      
 }
 
 
 
 return result;
}
int main()
{
string s1 = "lclc";
string s2 = "clcl";
cout<<CommomString(s1,s2);
return 0;
}
