#include<iostream>
#include<string.h>

using namespace std;

/*

This problem is to solve the word break problem which means you are given a sentence 
without spaces then you need to check whether that sentence exists after breaking them in 
words. Basically we need to check that all characters that forms a word are valid or not .

Idea : - Basic idea is to check the first character in the dictionary then the remaining 
        and mark them in the table as true to indicate that this is valid word
        

*/

//This is a function to check in dictionary
bool matchDictionary(string word)
{
  string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
           return true;
    return false; 
}


bool wordBreak(string str)
{
  int n = str.length();
  bool table[n+1]; // a boolean array to indicate the words are valid
  
  memset(table,0,sizeof(table)); // intialize with false
  
  for(int i=1;i<n;i++)
    {
        if(table[i] == false && matchDictionary(str.substr(0,i)))
         table[i] = true;  
         
         
        if(table[i] == true)
        {
        	if(i == n)
        	 return true;
        	 
               for(int j=i+1;j<n+1;j++)
	 {
	      // str.substr(start index, length from start index) 	
	      if(table[j] == false && matchDictionary(str.substr(i,j-i)))
	      table[j] = true;
	      
	      if(j ==n && table[j]==true)
	      return true;	
               }	 
         } 
    }
  
}
int main()
{
 
 cout<<wordBreak("ilikesamsung");
 return 0;
}
