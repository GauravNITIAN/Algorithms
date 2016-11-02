#include<iostream>
#include<malloc.h>

using namespace std;

/*
  Algorithm is used to costruct binary search Tree from sorted array
  
  Basic Idea : - The Basic Idea is to use a binary search where we first search
                check for left half and and right half but here we will go to both the 
	  half and insert the elements in a balanced way 

*/

// Structure to represent a node
struct BST 
{
int data;

struct BST *left ,*right;	
};


struct BST* CreateNode(int data)
{
  struct BST* temp = (struct BST*)malloc(sizeof(struct BST));
  temp->left = NULL;
  temp->right = NULL;
  temp->data = data;
  
  return temp;
}


struct BST* SortedToBST(int ar[],int start,int end)
{
      if(start > end )
      return NULL;
      
      // else we will compute the mid as
      int mid = (start+end)/2;
      
      // create a node and set as root;
      struct BST * root = CreateNode(ar[mid]);
      
      // recusively construct the left subtree
      root->left = SortedToBST(ar,start,mid-1);
      
      //recusively construct the right subtree
      root->right = SortedToBST(ar,mid+1,end);
      
      
      return root;
}

// Inorder traversal for BST
void Inorder(struct BST *node)
{
  if(node != NULL)
  {
      Inorder(node->left);
      cout<<node->data<<" --->";
      Inorder(node->right);
  }
  
    
}

int main()
{

    int ar[] = {1, 2, 4, 5, 6, 7,8,12};
    int n = sizeof(ar)/sizeof(ar[0]);
    
    struct BST *root = SortedToBST(ar,0,n-1);
     
    Inorder(root); 
	
return 0;
}
