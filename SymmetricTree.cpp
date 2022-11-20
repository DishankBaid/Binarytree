#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
bool isSymetricHelp(Node* left,Node* right){
        if(left==NULL || right==NULL)return left==right;
        if(left->data!=right->data)return false;
        
        return isSymetricHelp(left->left,right->right)&&isSymetricHelp(left->right,right->left);
}
bool isSymmetric(Node* root) {
        return root==NULL||isSymetricHelp(root->left,root->right);
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->right->left=new Node(4);
    root->right->right=new Node(3);
    
    bool ans=isSymmetric(root);
    ans==0?cout<<"False"<<"\n":cout<<"True"<<"\n";
    
    Node* root1=new Node(1);
    root1->left=new Node(2);
    root1->right=new Node(2);
    root1->left->right=new Node(3);
    root1->right->right=new Node(3);
    bool ans1=isSymmetric(root1);
    ans1==0?cout<<"False"<<"\n":cout<<"True"<<"\n";
    return 0;
}
