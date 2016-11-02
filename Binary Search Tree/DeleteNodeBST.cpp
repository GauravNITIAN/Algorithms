#include<iostream>
#include<malloc.h>

using namespace std;

/*

This algorithm mainly focuses in deleting a node from a Binary Search Tree
Idea : - There can be three cases while deleleting a node
         1) The left or right subtree is empty then in this case 
             we can delete the node and put the first element of left or right subtree
         2) If the element is the last element to delete then simply delete it 
            and return null
         3) If the element has right subtree and left subtree then delelte the element
          and find the inorder successor that just greater element to the current element
          
*/

struct BST   // Structure to represent a Tree
{
int data;
struct BST *left,*right;	
};

// Helper function to get the inorder succesor

struct BST * getmin(struct BST * node)
{
   // Go through the left side till we get null
   struct BST * temp = node;
   
   while(temp->left != NULL)
   temp = temp->left;
   
   
   return temp; 
   
}


//Function to delete the node;

struct BST * deleteNode(struct BST * root,int data)
{
  // Need to check the base case that is if there no element or no matching found 
  // and our search has been exhausted
  if(root == NULL)
  return root;
  
  // First we need to find the element to be deleted we use same searching apprach 
  
  if(root->data > data)
     root->left = deleteNode(root->left,data);
   else if(root->data < data)
    root->right =  deleteNode(root->right,data);
   else // We find the element we need to consider the three cases
   {
      // Case if root left is null or both is null
      if(root->left == NULL)
      {
      	// then the root right may be null or not
	//  Both cases it works
	struct BST *temp  = root->right;
	free(root);
	
	return temp;  
	  
      }
      // same as above
      else if(root->right == NULL)
       {
       	struct BST *temp  = root->left;
	free(root);
	
	return temp;
             }      
             
             
        // Last and the important case if both root right and the left is not null
        // find the min from the right subtree and place it there as root and
         // aslo delete that element to
        
       struct BST *t = getmin(root->right);  
        
        // once find the element then copy that element in the present root
        // delete the inorder succesor that is just find
        root->data = t->data;
        
        // delete the node
        root->right = deleteNode(root->right,t->data);
        
        
        
             
     }  
     
  // return thr updated root
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
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    printf("Inorder traversal of the given tree \n");
    Inorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 40);
    printf("Inorder traversal of the modified tree \n");
    Inorder(root);
 
return 0;
}
