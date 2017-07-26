#include<iostream>
#include<stack>
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
void iterativeInorder(node *root){
	stack<node *> s;
	struct node *cur=root;
	while(cur!=NULL || s.empty()==false){
		if(cur!=NULL){
			s.push(cur);
			cur=cur->l;
		}
		else{
			cur=s.top();
			s.pop();
			cout<<cur->data<<" ";
			cur=cur->r;
		}
	}
}
int main(){
	struct node *root = newNode(10);
	root->l        = newNode(8);
    root->r       = newNode(2);
    root->l->l  = newNode(3);
    root->l->r = newNode(5);
    root->r->l = newNode(2);
    iterativeInorder(root);
	return 0;
}
