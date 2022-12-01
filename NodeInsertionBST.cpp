#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    
    Node(int v){
        val=v;
        left=right=NULL;
    }
};
Node* insertion(Node* root,int t){
    if(root==NULL)return new Node(t);
    
    while(root){
        if(root->val>t){
            if(root->left!=NULL)root=root->left;
            else{
                root->left=new Node(t);
                break;
                }
            }
            else{
                if(root->right!=NULL)root=root->right;
                else{
                    root->right=new Node(t);
                    break;
            }
        }
    }
    return root;
}
int main(){
    Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(7);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
   
   insertion(root,5);
   
    return 0;
}
