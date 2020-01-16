#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <list>
#include <algorithm>
using namespace std; 

class Node {				
    public:	
    string value;		
    Node* left; 
    Node* right;
    Node* parent;	
  
    Node(){};
};

class BinaryTree{
    private:
    Node*root;
    int count;

    public:
    BinaryTree(){};

    string left(Node* p){
        if (isExternal(p)){
            throw invalid_argument("The node is a leaf!");  
        }
        else{
            return p->left->value;
        }
    }

    string right(Node* p){
        return p->right->value;
    }

    Node* parent(Node *p){
        return p->parent;
    }

    bool isRoot(Node* v){
        return(v->parent==NULL);
    } 
    
    bool isExternal(Node* v){
        return (v->left==NULL && v->right==NULL);
    }

    int size(){
        return count;
    } 
    
    bool is_empty(){
        return count==0;
    } 
    
    Node* getroot(){
        if (is_empty()){
            cout<<"Error!"<<endl;
        } 
        else{
            return root;
        }
    }


    void expandExternal(Node* v){
        if (!isExternal(v)){
            cout<<"Error!"<<endl;
        }
        else{
            v->left=new Node;
            v->left->parent=v;
            v->right=new Node;
            v->right->parent=v;
            count += 2;
        }
    }

    void removeAboveExternal(Node* p){
        if (isRoot(p) || !isExternal(p)){
            cout<<"Error!"<<endl;
        }
        else{
            Node* v = p->parent; 
            Node* sibling = (p == v->left ? v->right  : v->left);
            if(v== root){ 
                root = sibling;
                sibling->parent = NULL;
            }
            else{
            Node* grandpar = v->parent;
            if (v == grandpar->left) 
                grandpar->left = sibling; 
            else 
                grandpar->right = sibling;
            sibling->parent = grandpar;
            }
            delete p; 
            delete v; 
            count -= 2;
        }
    }

    int getleafcount(Node* v){  
        if(v == NULL)      
            return 0;  
        if(v->left == NULL && v->right == NULL)  
            return 1;         
        else
            return getleafcount(v->left);
    }
    bool findPath(Node *root,vector<string> &path, Node* k) 
{ 
    if (root == NULL) return false; 
   
    path.push_back(root->value); 
  
    if (root->value == k->value) 
        return true; 
  
    if ( (root->left && findPath(root->left, path, k)) || 
         (root->right && findPath(root->right, path, k)) ) 
        return true; 

    path.pop_back(); 
    return false;
    }
    string LCA(Node* root,Node *v, Node *w){
        vector<string> path1, path2; 
        if ( !findPath (root,path1, v) || !findPath(root, path2, w)) 
          return "error"; 
  
    int i; 
    for (i = 0; i < path1.size() && i < path2.size() ; i++) 
        if (path1[i] != path2[i]) 
            break; 
    return path1[i-1]; 
    }
};

int main(){
    
}
