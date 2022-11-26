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

int MaxWidth(Node* root){
    if(root==NULL)return 0;
    int width=0;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    
    while(!q.empty()){
        int size=q.size();
        int min_id=q.front().second;
        int first,last,ans;
        for(int i=0;i<size;i++){
            int ind=q.front().second-min_id;
            Node* node=q.front().first;
            q.pop();
            if(i==0)first=ind;
            if(i==size-1)last=ind;
         
            if(node->left)q.push({node->left,(ind*2)+1});
            if(node->right)q.push({node->right,(ind*2)+2});
        }
        width=max(width,last-first+1);
    }
    return width;
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(7);
    
    int ans=MaxWidth(root);
    cout << ans <<"\n";
    
    return 0;
}
