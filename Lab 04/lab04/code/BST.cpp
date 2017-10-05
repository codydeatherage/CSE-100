#include <iostream>
#include <string>
#include "BST.h"

using namespace std;


/****************************************************************
 * CONSTRUCTOR
 *   Creates an empty binary tree
 ****************************************************************/
BST::BST() {
}

/****************************************************************
 * DESTRUCTOR
 *   Free all memory used by current tree
 ****************************************************************/
BST::~BST() {
  // Write code to remove and deallocate all nodes in the tree
}

void BST::Insert(int toInsert) {
  //Took psudo code
 Node *y = NULL;
 Node *x = root;

 while (x != NULL) {
  y = x;
    if (toInsert < x -> val) {
      x = x->left;
    } else {
      x = x->right;
    }
    // x = new Node();
    x -> parent = y;
    if (y == NULL) { //Tree was empty
      root = x
    } else if (x -> val < y -> val) {
      y -> left = x;
    } else {
      y -> right = x;
    }
  }
}

void BST::Delete(int toDelete) {
  //Locates node and saves the node that is to be deleted
  node* d = Search(toDelete);
  if (d -> left == NULL) {
    Transplant(d, d -> right);
  } else if (d -> right = NULL) {
    Transplant(d, d -> left);
  } else {
    //Tree-minimum in psudo code is the Minimum function
    node *y = Minimum(d -> right);
    if (y -> parent != d) {
      Transplant(y, y-> right);
      //y -> right = d -> right;
      y -> right -> parent = d;
    }
    Transplant(d,y);
    y -> left = d -> left;
    y -> left -> parent = y;
  }

}

void BST::Transplant(Node *u, Node *v) {
  if (u-> parent = NULL) {
    root = u;
  } else if (u == u -> parent -> left) {
    u -> parent -> left = v;
  } else {
    u -> parent -> right = v;
  }
  if (v != NULL) {
    v -> parent = u -> parent;
  }
}

Node *BST::Successor(Node *x) {
  Node *y = x;

  if (x->right != NULL) {
    return Minimum(x -> right);
  }
  y = x -> parent;
  while (y != NULL && x = y -> right) {
    x = y;
    y = y -> parent;
  }
  return y;
}

Node *BST::Minimum(Node *x) {
  while (x.left != NULL) {
    x = x->left;
  }
  return x;
}

Node *BST::Maximum(Node *x) {
  while (x->right != NULL) {
    x = x->right;
  }
  return x;
}

Node *BST::Search(int toFind) {
  // Node x; Begins search at the root
  Node *x = root;
 if (x != NULL) {
  // 
  if (toFind > x -> val) {
    return x -> right;

  } else if (toFind < x -> val) {
    return x -> left;

  } else if (toFind == x -> val) {
    return x;
  }
  return NULL;
 }

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
  // Write your code here
}

void BST::InOrder(Node *x) {
  // Write your code here
}

void BST::PostOrder(Node *x) {
  // Write your code here
}

