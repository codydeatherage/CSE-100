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
    x = new Node();
    x -> parent = y;
    x -> val = toInsert;
    if (y == NULL) { //Tree was empty
      root = x;
    } else if (x -> val < y -> val) {
      y -> left = x;
    } else {
      y -> right = x;
    }
  }
}

void BST::Delete(int toDelete) {
  //Locates node and saves the node that is to be deleted
  Node* d = Search(toDelete);
  if (d == NULL) {
    return;
  }
  if (d -> left == NULL) {
    Transplant(d, d -> right);
  } else if (d -> right == NULL) {
    Transplant(d, d -> left);
  } else {
    //Tree-minimum in psudo code is the Minimum function
    Node *y = Minimum(d -> right);
    if (y -> parent != d) {
      Transplant(y, y-> right);
      y -> right = d -> right;
      y -> right -> parent = y;
    }
    Transplant(d,y);
    y -> left = d -> left;
    y -> left -> parent = y;
  }

}

void BST::Transplant(Node *u, Node *v) {
  if (u-> parent == NULL) {
    root = v;
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
  /*if (x->right != NULL) {
    return Minimum(x -> right);
  }
  Node *z = y -> parent;
  while (z != NULL && y == z -> right) {
    y = z;
    z = z -> parent;
  }
  return y;
}*/


Node *BST::Minimum(Node *x) {
  Node *m = x;
  while (m -> left != NULL) {
    m = m->left;
  }
  return m;
}

Node *BST::Maximum(Node *x) {
  Node *m = x;
  while (m->right != NULL) {
    m = m->right;
  }
  return m;
}

Node *BST::Search(int toFind) {
  // Node x; Begins search at the root
  Node *x = root;
 if (x != NULL) {
  // 
  if (toFind > x -> val) {
    return x -> right;

  } else if (toFind < x -> val) {
      x = x -> right;

  } else if (toFind == x -> val) {
      x = x -> left;
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
  if (x != NULL) {
    cout << x -> val << "\n";
    PreOrder(x -> left);
    PreOrder(x -> right);
  }
}

void BST::InOrder(Node *x) {
  if (x != NULL) {
    InOrder(x -> left);
    cout << x -> val << "\n";
    InOrder(x -> right);
  }
}

void BST::PostOrder(Node *x) {
  if (x != NULL) {
    cout << x -> val << "\n";
    PostOrder(x -> left);
    PostOrder(x -> right); 
  }
}

