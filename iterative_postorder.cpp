/*
pre-order traversal is root-left-right, and post order is left-right-root. modify the code for pre-order to make it root-right-left, and then reverse the output so that we can get left-right-root .

Create an empty stack, Push root node to the stack. Do following while stack is not empty.

2.1. pop an item from the stack and print it.

2.2. push the left child of popped item to stack.

2.3. push the right child of popped item to stack.

reverse the ouput.

*/

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int data;
	struct node *l;
	struct node *r;
};
struct node* newNode(int data){
	struct node *t=new struct node;
	t->data=data;
	t->l=NULL;
	t->r=NULL;
	return t;
}
void iterativePostorder_modified_preorder(node *root){
	vector<int> ans;
	if(root==NULL) return;
	stack<node*> s;
	s.push(root);
	while(!s.empty()){
		node* cur=s.top();
		ans.push_back(cur->data);
		s.pop();
		if(cur->l)
			s.push(cur->l);
		if(cur->r)
			s.push(cur->r);	
	}
	reverse(ans.begin(),ans.end());
	vector<int> :: iterator it;
	for(it=ans.begin();it!=ans.end();it++){
		cout<<*it<<" ";
	}
}
void iterativePostorder(node *root){
	if(root==NULL) 
		return;
	stack<node *> s;
	do{
		while(root!=NULL){
			if(root->r)
				s.push(root->r);
			s.push(root);
			root=root->l;
		}
		root=s.top();
		s.pop();           
		if(root->r && (!s.empty()) && (s.top()==root->r)){
			s.pop();
			s.push(root);
			root=root->r;
		}
		else{
			cout<<root->data<<" ";
			root=NULL;
		}
	}while(!s.empty());
	
}
int main(){
	struct node *root = newNode(1);
	root->l        = newNode(2);
    root->r       = newNode(3);
    root->l->l  = newNode(4);
    root->l->r = newNode(5);
    root->r->l = newNode(6);
	root->r->r = newNode(7);
    iterativePostorder(root);
    cout<<endl;
    iterativePostorder_modified_preorder(root);
	return 0;
}
/* 
void postOrderIterative(struct Node* root)
{
	// Check for empty tree
	if (root == NULL)
		return;
	//Algorithm : 
	
 
	//if current node has left and right child, push the children in right followed by left 
	//and mark the current node as visited using a map stl
	//if the current node is already visited then print the node data
	//and remove the current node from stack.
 
	
	stack<Node*> s;
	map<Node*,bool> m;
	s.push(root);
	while(!s.empty()){
	    Node* curr=s.top();
	    if(!m[curr]){
	        if(curr->right!=NULL){
	            s.push(curr->right);
	        }
	        if(curr->left){
	            s.push(curr->left);
	        }
	        m[curr]=1;
	    }
	    else{
	        cout<<curr->data<<" ";
	        s.pop();
	    }
	}
}
*/
