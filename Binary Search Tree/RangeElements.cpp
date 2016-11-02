#include<iostream>
#include<malloc.h>


using namespace std;
/*

Print the range of sorted elements 
Idea : - Basic Idea is use Inorder Traversal 
 Suppose k1 < k2 then first k1 will be checked in the left subtree if k1 greater than 
 left subtree data then it we include this in our result but k2 must be less than right
 subtree data 
   
*/



struct BST   // Structure to represent a Tree
{
int data;
struct BST *left,*right;	
};


// Function to get Range of Sorted elements
void RangeElements(struct BST *root,int k1,int k2)
{
    
    // Use in order traversal
    
    if(root!=NULL)
     {
     	if(root->data > k1)
     	RangeElements(root->left,k1,k2);  // Recur left side
     	
     	
     	// Check the ellemets in range
     	if(root->data >=k1 && root->data <=k2)
     	cout<<root->data<<" ";
     	
     	
     	if(root->data < k2)
     	RangeElements(root->right,k1,k2);
     	
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


 RangeElements(root,40,80);
  
    
      
return 0;	
}
