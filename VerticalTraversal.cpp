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
vector<vector<int>>verticalTraversal(Node* root) {
        queue<pair<Node*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>nodes;
        
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            
            Node* node=p.first;
            int x=p.second.first;
            int y=p.second.second;
            
            nodes[x][y].insert(node->data);
            if(node->left)q.push({node->left,{x-1,y+1}});
            if(node->right)q.push({node->right,{x+1,y+1}});
        }
        
        vector<vector<int>>ans;
        for(auto p:nodes){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(7);
    root->left->left=new Node(3);
    root->left->left->left=new Node(4);
    root->left->left->left->left=new Node(5);
    root->left->left->left->right=new Node(6);
    root->right->right=new Node(8);
    root->right->right->left=new Node(9);
    root->right->right->left->left=new Node(10);
    root->right->right->left->right=new Node(11);
    
   vector<vector<int>>ans1;
   ans1=verticalTraversal(root);
   for(auto it:ans1){
      for(auto i:it)cout << i << " ";
      }
    return 0;
}
