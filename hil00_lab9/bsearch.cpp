

#include <iostream>
#include <queue>

using namespace std; 

class Node {				
    public:	
    int value;		
    Node* left; 
    Node* right;
    Node* parent;	
  
    Node(){};
};

class BST{
    private:
    Node*root;

    public:
    BST(){};

    Node* getRoot(){
        return root;
    }

    bool isEmpty(){
        if (root!=NULL){
            return false;
        }
        return true;
    }

    void Add(int value){
        if (root==NULL){
            Node* root= new Node;
            root->value=value;
            root->left=NULL;
            root->right=NULL;
        }

        else if (value< root->value){
            if(root->left != NULL){
			    Add(value);
            }
		    else{
			root->left = new Node;
			root->left->value = value;
			root->left->left = NULL;
			root->left->right = NULL;
		    }
        }

        else if (value> root->value){
            if(root->right != NULL){
			    Add(value);
            }
		    else{
			root->right = new Node;
			root->right->value = value;
			root->right->left = NULL;
			root->right->right = NULL;
		    }
        }
    }

    void Remove(Node* removeel){
        if (removeel->left==NULL && removeel->right==NULL){
            removeel=NULL;
        }
        else if (removeel->left!=NULL && removeel->right==NULL){
            removeel=removeel->left;
        }
        else if (removeel->left==NULL && removeel->right!=NULL){
            removeel=removeel->right;
        }
        else if(removeel->left!=NULL && removeel->right!=NULL){
            Node*temp = root->right;
            while (temp->left!=NULL){
                temp=temp->left;
            }
            removeel=temp;
            delete temp;
            Remove(temp);
            delete temp;
        }
    }
};

void BFS(Node *root) { 
    if (root == NULL)  
        return; 
  
    queue <Node *> myq; 
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

int main(){
    BST binarysearchtree;
    int arr[]={67,12,89,56,96,34,153,39,90,14,76};
    for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        binarysearchtree.Add(arr[i]);
    }
    //binarysearchtree.Remove(20);
    Node* root= binarysearchtree.getRoot();
    BFS(root);
    return 0;
}
