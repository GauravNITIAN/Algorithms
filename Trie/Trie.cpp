#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

#define ALPHABET 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
struct TrieNode
{
  struct TrieNode *children[ALPHABET];
  bool isleaf;
 }; 
struct TrieNode* getNode()
{
  struct TrieNode *pnode;
  pnode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
  
  if(pnode)
  {
  	
    pnode->isleaf = false;
  for(int i = 0;i<ALPHABET ; i++)
  {
  
  	pnode->children[i] = NULL;
	  }
	  //	cout<<"Aa";	
  }
  return pnode;
}

void Insert(struct TrieNode *root,char *ch)
{
   int index;
   int length = strlen(ch);
   struct TrieNode *pcrawl = root;
   for(int i = 0 ;i<length ; i++)
   {
      index = CHAR_TO_INDEX(ch[i]);
     // cout<<index<<endl;
      if(!pcrawl->children[index])
      	pcrawl->children[index] = getNode();
	      
       pcrawl=pcrawl->children[index];
       	        	
   }
  
   pcrawl->isleaf = true;
   // cout<<"aaaa";
}
bool search(struct TrieNode *root,char *key)
{
   int level;
   int length = strlen(key);
   struct TrieNode *pnode = root;
   for(int i=0;i<length;i++)
   {
      int index = CHAR_TO_INDEX(key[i]);
      if(pnode->children[index] == NULL)
         return false;
     pnode = pnode->children[index];
   }
   return (pnode != NULL && pnode->isleaf);
}
int main()
{
     int n = 8;
     char s[][n]={"the", "an", "there", "answer", "any",
                     "by", "bye", "their"};
      struct TrieNode *root = getNode();
      for(int i=0;i<n;i++)
           Insert(root,s[i]);   
                       
       bool b = search(root,"theree");
       if(b)
       cout<<"Yes";
       else
       cout<<"No";
     return 0;
}
