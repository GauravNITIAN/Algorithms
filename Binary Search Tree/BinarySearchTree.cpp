#include<iostream>
#include<malloc.h>


using namespace std;
/*

Binary Search Tree is used to Search a element in log n 
Several benefits are we can get the sorted elements in just Inorder traversal    
Its good data struture when we data the closet element between two element or 
range of sorted elements;

   
*/



struct BST   // Structure to represent a Tree
{
int data;
struct BST *left,*right;	
};




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


 Inorder(root);
  
    
      
return 0;	
}
