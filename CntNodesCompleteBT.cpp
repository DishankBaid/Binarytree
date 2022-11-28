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
int cntleft(Node* );
int cntright(Node* );
int cntNodes(Node* root){
    if(root==NULL)return 0;
    
    int lh=cntleft(root);
    int rh=cntright(root);
    
    if(lh==rh)return (1<<lh)-1;
    return 1+cntNodes(root->left)+cntNodes(root->right);
}
int cntleft(Node* root){
    int cnt=0;
    while(root){
        cnt++;
        root=root->left;
    }
    return cnt;
}
int cntright(Node* root){
    int cnt=0;
    while(root){
        cnt++;
        root=root->right;
    }
    return cnt;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);

    int ans=cntNodes(root);
    cout << ans << "\n";
    return 0;
}
