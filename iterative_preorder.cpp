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
void iterativePreorder(node *root){
	if(root==NULL) 
		return;
	stack<node *> s;
	s.push(root);
	while(s.empty()==false){
		struct node *t=s.top();
		cout<<t->data<<" ";
		s.pop();
		if(t->r)
			s.push(t->r);
		if(t->l)
			s.push(t->l);
	}
}
int main(){
	struct node *root = newNode(10);
	root->l        = newNode(8);
    root->r       = newNode(2);
    root->l->l  = newNode(3);
    root->l->r = newNode(5);
    root->r->l = newNode(2);
    iterativePreorder(root);
	return 0;
}
