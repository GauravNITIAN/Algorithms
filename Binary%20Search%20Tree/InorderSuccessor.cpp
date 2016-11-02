#include<iostream>
#include<malloc.h>


using namespace std;
/*
Binary Search Tree : -
This Program is to find the inorder succesor 
Inorder successor : - The element that comes just after a current element in sorted 
                      order;
                      
 Idea : - 1) we need to first find the element 
          2) Then if the right subtree is not null then inorder successor will 
             be leftmost element of right subtree
          3) if the right most is just null then return the jus above element                    

Note : - one case this code is not handling when we need to find the inorder succesor 
        of node which has both left and right sub tree as NULL
*/


struct BST   // Structure to represent a Tree
{
int data;
struct BST *left,*right;	
};




void InoderSuccessor(struct BST *root,int data,struct BST * &succ)
{
    // Base case 
    if(root == NULL)
    return ;
    
    // Use  the searching method of BST to find the element
    if(root->data > data)
    {
    	
     // The below code is very useful if right subtree is null then we still have 
     // the access to its parent and in that case its parent will be successor  	
         succ = root;    // This is the logic we keep the root of the current to track it
         InoderSuccessor(root->left,data,succ);
    	
    }
    else if(root->data < data)
    {
         succ = root;    // This is the logic we keep the root of the current to track it
         InoderSuccessor(root->right,data,succ);
    	
    }
    else 
    {
    	
      
    	// We found the element
    	if(root->right !=NULL)
    	{
    		
    	struct BST *tmp = root->right; // we have used tmp variable show that the 
			//value not changes with recursive call stack   	
              while(tmp->left != NULL)
	{
	      tmp = tmp->left;	
              }              
	 succ  = tmp;	
   
 	 	
    }
         if(succ->data < data)
          return;   	
    	
    }
    
    
   
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
 
struct BST *succ;  
   InoderSuccessor(root,30,succ);
   
   cout<<succ->data;
    
      
return 0;	
}
