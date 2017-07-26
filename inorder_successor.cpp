#include<iostream>
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
node* find(node* root,int data){
    if(root){
        if(root->data==data)
            return root;
        else if(data < root->data)
            find(root->l,data);
        else    
            find(root->r,data);
    }
    else
        return NULL;
}
node* min(node* root){
    if(root==NULL) return NULL;
    while(root->l)
        root=root->l;
    return root;
}
struct node* inorder_successor(struct node* root,int data){   //time complexity O(h)
	node* cur=find(root,data);
    if(cur==NULL)
        return NULL;
    //Node has right subtree
    if(cur->r!=NULL){
        return min(cur->r);
    }
    else{
        node *suc=NULL,*anc=root;
        while(anc!=cur){
            if(cur->data < anc->data){
                suc=anc;            //so far this is thedeepest node for which cur node is in left
                anc=anc->l;
            }
            else
                anc=anc->r;
        }
        return suc;
    }
}
int main(){
	struct node *root = newNode(11);
	root->l        = newNode(9);
    root->r       = newNode(12);
    root->l->l  = newNode(8);
    root->l->r = newNode(10);
    root->r->r = newNode(13);
    struct node* suc=inorder_successor(root,8);
	cout<<suc->data;
	return 0;
}
