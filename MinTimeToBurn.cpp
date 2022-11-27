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
Node* mark_parent(Node* root,unordered_map<Node*,Node*>&parent_node,int target){
    Node* tp;
    
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp->data==target)tp=temp;
        if(temp->left){
            parent_node[temp->left]=temp;
            q.push(temp->left);
        }
        if(temp->right){
            parent_node[temp->right]=temp;
            q.push(temp->right);
        }
    }
    return tp;
}
 int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*>parent_node;
        Node* tp=mark_parent(root,parent_node,target);
    
        unordered_map<Node*,int>visited;
        queue<Node*>q;
        q.push(tp);
        
        visited[tp]=1;
        int time = 0;
        while(!q.empty()){
            int size=q.size();
            int br=0;
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    br=1;
                    q.push(temp->left);
                    visited[temp->left]=1;
                }
                if(temp->right && !visited[temp->right]){
                    br=1;
                    q.push(temp->right);
                    visited[temp->right]=1;
                }
                if(parent_node[temp] && !visited[parent_node[temp]]){
                    br=1;
                    q.push(parent_node[temp]);
                    visited[parent_node[temp]]=1;
                }
            }
            if(br)time++;
        }
        return time;
    }
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    
    int ans=minTime(root,4);
    cout<< ans << "\n";
    return 0;
}
