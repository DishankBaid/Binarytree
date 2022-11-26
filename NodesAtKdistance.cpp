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
Node* getNode(Node* root,int target){
        queue<Node*>q;
        q.push(root);
        Node* tp;
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            
            if(temp->data==target)tp=temp;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        return tp;
}
 void markParent(Node* root,unordered_map<Node*,Node*>&parent_node){
       queue<Node*>q;
       q.push(root);
       Node* t;
       while(!q.empty()){
           Node* temp=q.front();
           q.pop();
           if(temp->left){
               parent_node[temp->left]=temp;
               q.push(temp->left);
           }
           if(temp->right){
               parent_node[temp->right]=temp;
               q.push(temp->right);
           }
       }
 }
vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int>ans;
        if(root==NULL)return ans;
       unordered_map<Node*,Node*>parent_node;
       markParent(root,parent_node);
       Node* tp=getNode(root,target);
       unordered_map<Node*,bool>visited;
       
       queue<Node*>q;
       q.push(tp);
       visited[tp]=true;
       int curr=0;
       while(!q.empty()){
           if(curr++ ==k)break;
           int size=q.size();
           for(int i=0;i<size;i++){
               Node* temp=q.front();
               q.pop();
               if(temp->left && !visited[temp->left]){
               q.push(temp->left);
               visited[temp->left]=true;
               }
               if(temp->right && !visited[temp->right]){
                   q.push(temp->right);
                   visited[temp->right]=true;
               }
               if(parent_node[temp] && !visited[parent_node[temp]]){
                   q.push(parent_node[temp]);
                   visited[parent_node[temp]]=true;
               }
           }
       }
       while(!q.empty()){
           Node* p=q.front();
           q.pop();
           ans.push_back(p->data);
       }
       sort(ans.begin(),ans.end());
       return ans;
}
int main(){
    Node* root=new Node(20);
    root->left=new Node(7);
    root->right=new Node(24);
    root->left->left=new Node(4);
    root->left->right=new Node(3);
    root->left->right->left=new Node(1);
   vector<int>ans;
    ans=KDistanceNodes(root,7,2);
    for(auto it:ans)cout << it << " ";
    return 0;
}
