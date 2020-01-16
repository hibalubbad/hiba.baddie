
#include <iostream>
#include <queue>
#include "bsearch.cpp"

using namespace std; 

void BFS(Node *root) { 
    if (root == NULL)  
        return; 
  
    queue<Node *> myq; 
    myq.push(root->left); 
    myq.push(root->right);
  
    while (myq.empty() == false){ 
        Node *node = myq.front(); 
        cout << node->value << " "; 
        myq.pop(); 
  
        if (node->left != NULL) 
            myq.push(node->left); 
  
        if (node->right != NULL) 
            myq.push(node->right); 
    } 
} 




  

