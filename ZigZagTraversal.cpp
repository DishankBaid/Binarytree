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
//Approach 1
void levelOrder(Node* root,vector<vector<int>>&ans){
    if(root==NULL)return ;
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        int size=q.size();
        vector<int>l;
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            l.push_back(temp->data);
            if(temp->left!=NULL)q.push(temp->left);
            if(temp->right!=NULL)q.push(temp->right);
        }
        ans.push_back(l);
    }
}
// Approach 2-
void zigzag(vector<vector<int>>&ans1,Node* root){
    	if(root==NULL)return ;
    	
    	queue<Node*>q;
    	q.push(root);
    	bool leftToRight=true;
    	
    	while(!q.empty()){
            int size=q.size();
           vector<int>level(size);
            
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                int ind=(leftToRight ? i : size-1-i);
                level[ind] = temp->data;
                
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
            }
            leftToRight=!leftToRight;
            ans1.push_back(level);
        }
}
void print(vector<vector<int>>ans){
     for(auto it:ans){
        for(auto i:it){
            cout << i <<" ";
        }
    }
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(6);
    root->right->left=new Node(7);
    
//Approach 1- level order and then reversal...
    vector<vector<int>>ans;
    levelOrder(root,ans);
    for(int i=1;i<ans.size();i+=2)reverse(ans[i].begin(),ans[i].end());
   print(ans);
   cout << "\n";
  
// Approach 2-level order traversal and flag variable...
    vector<vector<int>>ans1;
   zigzag(ans1,root);
   print(ans1);
  
    return 0;
}
