#include <iostream>
#include <string>
#include "BST.h"

using namespace std;


/****************************************************************
 * CONSTRUCTOR
 *   Creates an empty binary tree
 ****************************************************************/
BST::BST() {
  root = NULL;
}

/****************************************************************
 * DESTRUCTOR
 *   Free all memory used by current tree
 ****************************************************************/
BST::~BST() {
  // Write code to remove and deallocate all nodes in the tree
}

void BST::Insert(int toInsert) {
  Node *y = NULL;
  Node *x = root;
  while(x!=NULL)
  {
    y=x;
    if(toInsert<x->val)
    {
      x = x->left;
    }
    else
      x = x->right;
  }
  x = new Node();
  x->parent = y;
  x->val = toInsert;
  if(y==NULL)
    root = x;
  else if(x->val<y->val)
    y->left = x;
  else
    y->right = x;
}

void BST::Delete(int toDelete) {
  Node *z = Search(toDelete);
  if(z== NULL)
    return;

  if(z->left == NULL)
    Transplant(z,z->right);
  else if (z->right==NULL)
    Transplant(z,z->left);
  else
  {
    Node *y = Minimum(z->right);
    if(y->parent!=z)
    {
      Transplant(y,y->right);
      y->right = z->right;
      y->right->parent = y;
    }
    Transplant(z,y);
    y->left = z->left;
    y->left->parent = y;
  
  }
}

void BST::Transplant(Node *u, Node *v) {
  if(u->parent == NULL)
    root = v;
  else if(u == u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;
  if(v!=NULL)
    v->parent = u->parent;
}

Node *BST::Successor(Node *x) {
  Node* z = x;
  if(x->right!=NULL)
    return Minimum(x->right);
  Node *y = z->parent;
  while(y!=NULL&&z==y->right)
  {
    z = y;
    y = y->parent;
  }
  return y;
  
}

Node *BST::Minimum(Node *x) {
  Node *r = x;
        while(r->left!=NULL)
                r = r->left;
        return r;

}

Node *BST::Maximum(Node *x) {
  Node *r = x;
  while(r->right!=NULL)
    r = r->right;
  return r;
    
}

Node *BST::Search(int toFind) {
  Node *r = root;
  while(r!=NULL)
  {
    if(toFind==r->val)
      return r;
    else if(toFind>r->val)
    {
      r = r->right;
    }
    else
    {
      r = r->left;
    }
  } 
  return NULL;
}

void BST::Print(TraversalOrder Order) {
  if(Order==InOrderTrav)
    InOrder(root);
  else if(Order==PreOrderTrav)
    PreOrder(root);
  else if(Order==PostOrderTrav)
    PostOrder(root);
}

void BST::PreOrder(Node *x) {
  if(x==NULL)
    return;
  cout<<x->val<<endl;
  PreOrder(x->left);
  PreOrder(x->right);
}


void BST::InOrder(Node *x) {
  if(x==NULL)
    return;
  InOrder(x->left);
  cout<<x->val<<endl;
  InOrder(x->right);
}

void BST::PostOrder(Node *x) {
  if(x==NULL)
    return;
  PostOrder(x->left);
  PostOrder(x->right);
  cout<<x->val<<endl;
}


