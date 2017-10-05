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
  //recursively calls teh function until all ndoes have no values
  if (root != NULL) {
    BST::Delete(root -> val);
  }
}

void BST::Insert(int toInsert) {
  //Psudo
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
  //Psudo
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
  //Psuo
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
  //Psduo
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
  //Psudo
  Node *m = x;
        while(m -> left != NULL)
                m = m -> left;
        return m;

}

Node *BST::Maximum(Node *x) {
  //Psudo
  Node *m = x;
  while(m -> right != NULL)
    m = m -> right;
  return m;
    
}

Node *BST::Search(int toFind) {
  //Psudo
  Node *s = root;
  while(s != NULL)
  {
    if(toFind == s -> val)
      return s;
    else if(toFind > s -> val)
    {
      s = s -> right;
    }
    else
    {
      s = s -> left;
    }
  } 
  return NULL;
}

void BST::Print(TraversalOrder Order) {
  //Psudo
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

