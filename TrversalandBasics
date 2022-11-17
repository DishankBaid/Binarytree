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
void preOrder(vector<int>&ans,Node* root){
    if(root==NULL)return ;
    ans.push_back(root->data);
    preOrder(ans,root->left);
    preOrder(ans,root->right);
}
void postOrder(vector<int>&a,Node* root){
    if(root == NULL)return ;
    postOrder(a,root->left);
    postOrder(a,root->right);
    a.push_back(root->data);
}
void inOrder(vector<int>&b,Node* root){
    if(root==NULL)return ;
    inOrder(b,root->left);
    b.push_back(root->data);
    inOrder(b,root->right);
}
void LevelOrder(vector<int>&level,Node* root){
    if(root==NULL)return ;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        level.push_back(temp->data);
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
}
int height(Node* root){
    if(root==NULL)return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return 1+max(lh,rh);
}
int depthofTree(Node* root){
    if(root==NULL)return 0;
    int cnt=0;
    
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left!=NULL)q.push(temp->left);
            if(temp->right!=NULL)q.push(temp->right);
        }
        cnt++;
    }
    return cnt;
}
int BalancedBT(Node* root){
    if(root==NULL)return 0;
    int lh=BalancedBT(root->left);
    int rh=BalancedBT(root->right);
    if(lh==-1 || rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;
    else return 1+max(lh,rh);
}
void print(vector<int>ans){
    for(auto it:ans)cout << it << " ";
    cout << endl;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    // 1->2,1->3,2->4,2->5,3->6,3->7
    vector<int>ans;
    preOrder(ans,root);
    print(ans);//preOrder Traversal
    
    vector<int>a;
    postOrder(a,root);
    print(a);//Postorder Traversal
    
    vector<int>b;
    inOrder(b,root);
    print(b);//Inorder Traversal
    
    vector<int>level;
    LevelOrder(level,root);
    print(level);//LevelOrder Trversal
    
    int depth=height(root);
    cout << "Depth of Tree using Recursion - "<< depth << "\n";
    
    depth=depthofTree(root);
    cout << "Depth of Tree (Iterative Method) - "<< depth << "\n";
    
    int bal=BalancedBT(root);
    bal==-1?cout<<"false" <<"\n":cout <<"True" <<"\n";
    
    return 0;
}
