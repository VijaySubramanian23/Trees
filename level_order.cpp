#include<iostream>
#include<queue>
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
void level_order(node *root){
	if(root==NULL) 
		return;
	queue<node *> q;
	q.push(root);
	while(!q.empty()){
		struct node* t=q.front();
		q.pop();
		cout<<t->data<<" ";
		if(t->l)
			q.push(t->l);
		if(t->r)
			q.push(t->r);
	}
	
}
int main(){
	struct node *root = newNode(1);
	root->l        = newNode(2);
    root->r       = newNode(3);
    root->l->l  = newNode(4);
    root->l->r = newNode(5);
    root->r->l = newNode(6);
    level_order(root);
	return 0;
}
