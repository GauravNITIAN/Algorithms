#include<iostream>
#include<malloc.h>


using namespace std;
/*
Lowest common ancestor

Idea : -
   Idea is start from root then traverse through and check the condition 
   that if n1 and n2 (two elements) be greater than root->data then our
   result is in left sub tree and if n1 and n2 is smaller than root->data
   then traverse through the right sub tree
   once both the condition satisfied then n1 < n <n2 then this is our 
   lowest common ancesstor
    
   
*/



struct BST   // Structure to represent a Tree
{
int data;
struct BST *left,*right;	
};


struct BST * LowestCommonAncestor(struct BST * root,int n1,int n2)
{
  // base case
  if(root == NULL)
  return NULL;	
	
      // if both n1 and n2 is lesser
      if(n1 < root->data && n2 < root->data)
      return LowestCommonAncestor(root->left,n1,n2);
      
      // if both n1 and n2 is greater that root->data then our sol is in left subtree
      else if(n1 > root->data && n2 > root->data)
      return LowestCommonAncestor(root->right,n1,n2);
      
      // else root is the ancestor
      
      
      return root;
        
}


// Function to create a node
struct BST *newNode(int data)
{
   struct BST *temp = (struct BST *)malloc(sizeof(struct BST));
   temp->data = data;
   temp->left = NULL;
   temp->right = NULL;
   
  return temp; 	
}

// Function to insert in BST 

struct BST *insert(struct BST *node,int data)
{
   // if node is null then create a new one at this position because we cannot travel
   // any more
    if(node == NULL)
   	return newNode(data);
   	
     else if(node->data > data) // means we need to travel to left side
         	node->left = insert(node->left,data);
      else if(node->data < data)  // Means we need to travel right side
      	node->right = insert(node->right,data);
  // Note: - we not considering when the node  data is equal
  
  
  return node;
  
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
// Binary search tree search function
bool Search(struct BST *root,int data)
{
   if(root == NULL)
   return false;	
   else if(root->data > data) // go to left side
   Search(root->left,data);
   else if(root->data > data)
   Search(root->right,data);
   else                   //  It means that the data is equal
   return true;   
   
   return false;	
}

int main()
{

struct BST *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);


struct BST *node = LowestCommonAncestor(root,20,30);  
  
    cout<<node->data;
      
return 0;	
}
