// CMPT 225 - D100
// Name: Ian Gihwan Hwang
// Student #: 301461304
// Assignment 5

#pragma once

#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Template NodeT class
template <class T1, class T2>
class NodeT {
 public:
  T1 key;
  T2 value;
  NodeT<T1, T2> *left;
  NodeT<T1, T2> *right;
  NodeT<T1, T2> *parent;
  bool isBlack;
  // Default constructor setting its attributes
  NodeT(T1 keyInput, T2 valInput) {
    key = keyInput;
    value = valInput;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    isBlack = false;
  }
};

// Template RedBlackTree class
template <class T1, class T2>
class RedBlackTree {
 private:
  NodeT<T1, T2> *root;  // Pointer to the root of the tree
  int curSize;          // Stores the current number of nodes
  // ==================== Helper methods ========================================
  bool isBlack(NodeT<T1, T2> *nd) const;                         // Test of node being either black or nullptr
  bool isLeft(NodeT<T1, T2> *nd) const;                          // Test of node being a left child
  NodeT<T1, T2> *copyTree(NodeT<T1, T2> *nd, NodeT<T1, T2> *p);  // Creates a deep copy of the entire tree
  NodeT<T1, T2> *bstInsert(T1 keyInput, T2 valueInput);          // Insertion method of binary search tree
  void deleteAllNode(NodeT<T1, T2> *nd);                         // Deletes every node in a tree
  void leftRotate(NodeT<T1, T2> *nd);                            // Left rotation
  void rightRotate(NodeT<T1, T2> *nd);                           // Right rotation
  NodeT<T1, T2> *findNode(T1 keyTarget) const;                 // Finds the node containing the key parameter
  NodeT<T1, T2> *getPredecessor(NodeT<T1, T2> *target) const;  // Finds the predecessor of a node
  void rbFix(NodeT<T1, T2> *x, NodeT<T1, T2> *y, bool isXLeft);          // Fixes the structure of tree
  vector<T2> searchHelper(NodeT<T1, T2> *root, T1 key1, T1 key2) const;  // Recursive range search helper
  T1 findClosestNode(T1 keyTarget) const;  // Finds the node containing the value closest to the key parameter
  // ==================== End of helper methods ========================================

 public:
  RedBlackTree();                                                    // Default constructor
  RedBlackTree(const RedBlackTree<T1, T2> &rbt);                     // Copy constructor
  RedBlackTree<T1, T2> &operator=(const RedBlackTree<T1, T2> &rbt);  // Overloaded operator assignment
  ~RedBlackTree();                                                   // Destructor
  // Insert method
  // PRE: Checks a duplicate before insertion
  // PARAM: 2 parameters of key & value
  // POST: Inserts a node while maintainig the red-black tree structure and returns a boolean
  bool insert(T1 keyInput, T2 valueInput);
  // Remove method
  // PARAM: Key
  // POST: Removes the node containing the key parameter and returns a boolean
  bool remove(T1 keyTarget);
  // Search method
  // PARAM: Key
  // POST: Returns true if the node containing the key exists, false otherwise
  bool search(T1 keyTarget) const;
  // Range search method
  // PARAM: 2 key values
  // POST: Returns a vector containing the values between 2 key parameters
  // If there's no exact match, finds the nodes containing the closest key
  vector<T2> search(T1 key1, T1 key2) const;
  // Value method
  // POST: Returns a vector containing the values in ascending key order
  vector<T2> values() const;
  // Keys method
  // POST: Returns a vector containing all the keys in ascending order
  vector<T1> keys() const;
  // Size method
  // POST: Returns the current size (# of nodes) of the tree
  int size() const;
  // getRoot method
  // POST: Returns a pointer to the tree's node
  NodeT<T1, T2> *getRoot();
};

// ========================================================
// ==================== Class methods =====================
// ========================================================

// Default constructor
template <class T1, class T2>
RedBlackTree<T1, T2>::RedBlackTree() {
  root = nullptr;
  curSize = 0;
}

// Copy constructor (deep copy)
template <class T1, class T2>
RedBlackTree<T1, T2>::RedBlackTree(const RedBlackTree<T1, T2> &rbt) {
  root = copyTree(rbt.root, nullptr);
  curSize = rbt.curSize;
}

// Overloaded operator assignment (deep copy)
template <class T1, class T2>
RedBlackTree<T1, T2> &RedBlackTree<T1, T2>::operator=(const RedBlackTree<T1, T2> &rbt) {
  if (this != &rbt) {
    deleteAllNode(this->root);
    this->root = copyTree(rbt.root, nullptr);
    this->curSize = rbt.curSize;
  }
  return *this;
}

// Destructor
template <class T1, class T2>
RedBlackTree<T1, T2>::~RedBlackTree() {
  deleteAllNode(root);
}

// Insert method
// PARAM: 2 parameters of key & value
// POST: Inserts a node while maintainig the red-black tree structure
template <class T1, class T2>
bool RedBlackTree<T1, T2>::insert(T1 keyInput, T2 valueInput) {
  if (search(keyInput) == false) {
    NodeT<T1, T2> *newNode = bstInsert(keyInput, valueInput);
    while (newNode != root && isBlack(newNode->parent) == false) {
      if (newNode->parent == newNode->parent->parent->left) {
        NodeT<T1, T2> *uncle = newNode->parent->parent->right;
        if (isBlack(uncle) == false) {
          newNode->parent->isBlack = true;
          uncle->isBlack = true;
          newNode->parent->parent->isBlack = false;
          newNode = newNode->parent->parent;
        } else {
          if (newNode == newNode->parent->right) {
            newNode = newNode->parent;
            leftRotate(newNode);
          }
          newNode->parent->isBlack = true;
          newNode->parent->parent->isBlack = false;
          rightRotate(newNode->parent->parent);
        }
      } else {
        NodeT<T1, T2> *uncle = newNode->parent->parent->left;
        if (isBlack(uncle) == false) {
          newNode->parent->isBlack = true;
          uncle->isBlack = true;
          newNode->parent->parent->isBlack = false;
          newNode = newNode->parent->parent;
        } else {
          if (newNode == newNode->parent->left) {
            newNode = newNode->parent;
            rightRotate(newNode);
          }
          newNode->parent->isBlack = true;
          newNode->parent->parent->isBlack = false;
          leftRotate(newNode->parent->parent);
        }
      }
    }
    root->isBlack = true;
    curSize++;
    return true;
  }
  return false;
}

// Remove method
// PARAM: Key
// POST: Removes the node containing the key parameter and returns a boolean
template <class T1, class T2>
bool RedBlackTree<T1, T2>::remove(T1 keyTarget) {
  NodeT<T1, T2> *x = nullptr;
  NodeT<T1, T2> *y = nullptr;
  NodeT<T1, T2> *target = findNode(keyTarget);

  if (target == nullptr) {
    return false;
  }

  if (target->left == nullptr || target->right == nullptr) {
    y = target;
  } else {
    y = getPredecessor(target);
  }

  if (y->left != nullptr) {
    x = y->left;
  } else {
    x = y->right;
  }

  if (x != nullptr) {
    x->parent = y->parent;
  }

  if (y->parent == nullptr) {
    root = x;
  } else {
    if (y == y->parent->left) {
      y->parent->left = x;
    } else {
      y->parent->right = x;
    }
  }

  if (y != target) {
    target->key = y->key;
    target->value = y->value;
  }

  if (isBlack(y) == true) {
    if (x == root) {
      rbFix(x, y->parent, false);
    } else if (x == y->parent->left) {
      rbFix(x, y->parent, true);
    } else if (x == y->parent->right) {
      rbFix(x, y->parent, false);
    }
  }

  curSize--;
  delete y;
  return true;
}

// Search method
// PARAM: Key
// POST: Returns true if the node containing the key exists, false otherwise
template <class T1, class T2>
bool RedBlackTree<T1, T2>::search(T1 keyTarget) const {
  NodeT<T1, T2> *temp = root;
  while (temp != nullptr) {
    if (keyTarget == temp->key) {
      return true;
    } else if (keyTarget < temp->key) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }
  return false;
}

// Range search method
// PARAM: 2 key values
// POST: Returns a vector containing the values between 2 key parameters
// If there's no exact match, finds the node
template <class T1, class T2>
vector<T2> RedBlackTree<T1, T2>::search(T1 key1, T1 key2) const {
  T1 temp;
  if (key1 > key2) {
    temp = key1;
    key1 = key2;
    key2 = temp;
  }
  vector<T2> ret = searchHelper(root, key1, key2);
  return ret;
}

// Value method
// POST: Returns a vector containing the values in ascending key order
template <class T1, class T2>
vector<T2> RedBlackTree<T1, T2>::values() const {
  vector<T2> ret;
  NodeT<T1, T2> *cur = root;
  NodeT<T1, T2> *prev = nullptr;

  if (root == nullptr) {
    return ret;
  } else {
    while (cur != nullptr) {
      if (cur->left == nullptr) {
        ret.push_back(cur->value);
        cur = cur->right;
      } else {
        prev = cur->left;
        while (prev->right != nullptr && prev->right != cur) prev = prev->right;
        if (prev->right == nullptr) {
          prev->right = cur;
          cur = cur->left;
        } else {
          prev->right = nullptr;
          ret.push_back(cur->value);
          cur = cur->right;
        }
      }
    }
  }
  return ret;
}

// Keys method
// POST: Returns a vector containing all the keys in ascending order
template <class T1, class T2>
vector<T1> RedBlackTree<T1, T2>::keys() const {
  vector<T1> ret;
  NodeT<T1, T2> *cur = root;
  NodeT<T1, T2> *prev = nullptr;

  if (root == nullptr) {
    return ret;
  } else {
    while (cur != nullptr) {
      if (cur->left == nullptr) {
        ret.push_back(cur->key);
        cur = cur->right;
      } else {
        prev = cur->left;
        while (prev->right != nullptr && prev->right != cur) prev = prev->right;
        if (prev->right == nullptr) {
          prev->right = cur;
          cur = cur->left;
        } else {
          prev->right = nullptr;
          ret.push_back(cur->key);
          cur = cur->right;
        }
      }
    }
  }
  return ret;
}

// Size method
// POST: Returns the current size (# of nodes) of the tree
template <class T1, class T2>
int RedBlackTree<T1, T2>::size() const {
  return curSize;
}

// getRoot method
// POST: Returns a pointer to the tree's node
template <class T1, class T2>
NodeT<T1, T2> *RedBlackTree<T1, T2>::getRoot() {
  return root;
}
// ==================== End of class implementation =====================

// ========================================================
// ==================== Helper methods ====================
// ========================================================

// Tests if a node is either black or nullptr
template <class T1, class T2>
bool RedBlackTree<T1, T2>::isBlack(NodeT<T1, T2> *nd) const {
  return nd == nullptr || nd->isBlack;
}

// Tests if a node is a left child
template <class T1, class T2>
bool RedBlackTree<T1, T2>::isLeft(NodeT<T1, T2> *nd) const {
  return nd == nullptr || nd == nd->parent->left;
}

// Creates a deep copy of the entire tree
template <class T1, class T2>
NodeT<T1, T2> *RedBlackTree<T1, T2>::copyTree(NodeT<T1, T2> *sourcenode, NodeT<T1, T2> *parentnode) {
  NodeT<T1, T2> *copynode;
  if (sourcenode != nullptr) {
    copynode = new NodeT<T1, T2>(sourcenode->key, sourcenode->value);
    copynode->parent = parentnode;
    copynode->isBlack = sourcenode->isBlack;
    copynode->left = copyTree(sourcenode->left, copynode);
    copynode->right = copyTree(sourcenode->right, copynode);
    return copynode;
  }
  return nullptr;
}

// Deletes every node in the tree
template <class T1, class T2>
void RedBlackTree<T1, T2>::deleteAllNode(NodeT<T1, T2> *nd) {
  if (nd != nullptr) {
    deleteAllNode(nd->left);
    deleteAllNode(nd->right);
    delete nd;
  }
  root = nullptr;
  curSize = 0;
}

// Insertion for binary search tree
template <class T1, class T2>
NodeT<T1, T2> *RedBlackTree<T1, T2>::bstInsert(T1 keyInput, T2 valueInput) {
  NodeT<T1, T2> *newNode = new NodeT<T1, T2>(keyInput, valueInput);
  NodeT<T1, T2> *parent = root;
  NodeT<T1, T2> *next = root;

  newNode->isBlack = false;

  if (curSize == 0) {
    root = newNode;
  } else {
    while (next != nullptr) {
      parent = next;
      if (keyInput < parent->key) {
        next = parent->left;
      } else {
        next = parent->right;
      }
    }
    if (keyInput < parent->key) {
      parent->left = newNode;
      newNode->parent = parent;
    } else {
      parent->right = newNode;
      newNode->parent = parent;
    }
  }
  return newNode;
}

// Left rotation
template <class T1, class T2>
void RedBlackTree<T1, T2>::leftRotate(NodeT<T1, T2> *nd) {
  NodeT<T1, T2> *y = nd->right;
  nd->right = y->left;
  if (y->left != nullptr) {
    y->left->parent = nd;
  }
  y->parent = nd->parent;
  if (nd->parent == nullptr) {
    root = y;
  } else if (nd == nd->parent->left) {
    nd->parent->left = y;
  } else {
    nd->parent->right = y;
  }
  y->left = nd;
  nd->parent = y;
}

// Right rotation
template <class T1, class T2>
void RedBlackTree<T1, T2>::rightRotate(NodeT<T1, T2> *nd) {
  NodeT<T1, T2> *y = nd->left;
  nd->left = y->right;
  if (y->right != nullptr) {
    y->right->parent = nd;
  }
  y->parent = nd->parent;
  if (nd->parent == nullptr) {
    root = y;
  } else if (nd == nd->parent->right) {
    nd->parent->right = y;
  } else {
    nd->parent->left = y;
  }
  y->right = nd;
  nd->parent = y;
}

// Finds the node containing the key parameter
template <class T1, class T2>
NodeT<T1, T2> *RedBlackTree<T1, T2>::findNode(T1 keyTarget) const {  // Review this
  NodeT<T1, T2> *cur = root;

  while (cur != nullptr) {
    if (keyTarget == cur->key) {
      break;
    } else if (keyTarget < cur->key) {
      cur = cur->left;
    } else {
      cur = cur->right;
    }
  }
  return cur;
}

// Finds the predecessor of a node
template <class T1, class T2>
NodeT<T1, T2> *RedBlackTree<T1, T2>::getPredecessor(NodeT<T1, T2> *target) const {
  NodeT<T1, T2> *pre = nullptr;

  if (target != nullptr) {
    if (target->left == nullptr) {
      pre = nullptr;
    } else {
      pre = target->left;
      while (pre->right != nullptr) {
        pre = pre->right;
      }
    }
  }
  return pre;
}

// Fixes the structure of tree after replacing the target node's key and value
template <class T1, class T2>
void RedBlackTree<T1, T2>::rbFix(NodeT<T1, T2> *x, NodeT<T1, T2> *xParent, bool isXLeft) {
  NodeT<T1, T2> *y = nullptr;

  while (x != root && isBlack(x) == true) {
    if (x != nullptr) {
      isXLeft = isLeft(x);
    }

    if (isXLeft == true) {
      if (x == nullptr) {
        y = xParent->right;
      } else {
        y = x->parent->right;
      }
      if (isBlack(y) == false) {  // x sibling is y and it's red
        if (x == nullptr) {
          y->isBlack = true;
          xParent->isBlack = false;
          leftRotate(xParent);
          y = xParent->right;
        } else {
          y->isBlack = true;
          x->parent->isBlack = false;
          leftRotate(x->parent);
          y = x->parent->right;
        }
      }
      if (isBlack(y->left) == true &&
          isBlack(y->right) == true) {  // x sibling y is black and y's children are black
        y->isBlack = false;
        if (x == nullptr) {
          x = xParent;
        } else {
          x = x->parent;
        }
      } else {  // x sibling is y and it's black and y left is red and y right is black
        if (isBlack(y->right) == true) {
          if (x == nullptr) {
            y->left->isBlack = true;
            y->isBlack = false;
            rightRotate(y);
            y = xParent->right;
          } else {
            y->left->isBlack = true;
            y->isBlack = false;
            rightRotate(y);
            y = x->parent->right;
          }
        }
        // x sibling y is black and y right child is red
        if (x == nullptr) {
          y->isBlack = xParent->isBlack;
          xParent->isBlack = true;
          y->right->isBlack = true;
          leftRotate(xParent);
          x = root;
        } else {
          y->isBlack = x->parent->isBlack;
          x->parent->isBlack = true;
          y->right->isBlack = true;
          leftRotate(x->parent);
          x = root;
        }
      }
    } else {
      if (x == nullptr) {
        y = xParent->left;
      } else {
        y = x->parent->left;
      }
      if (isBlack(y) == false) {
        if (x == nullptr) {
          y->isBlack = true;
          xParent->isBlack = false;
          rightRotate(xParent);
          y = xParent->left;
        } else {
          y->isBlack = true;
          x->parent->isBlack = false;
          rightRotate(x->parent);
          y = x->parent->left;
        }
      }
      if (isBlack(y->right) == true && isBlack(y->left) == true) {
        y->isBlack = false;
        if (x == nullptr) {
          x = xParent;
        } else {
          x = x->parent;
        }
      } else {
        if (isBlack(y->left) == true) {
          if (x == nullptr) {
            y->right->isBlack = true;
            y->isBlack = false;
            leftRotate(y);
            y = xParent->left;
          } else {
            y->right->isBlack = true;
            y->isBlack = false;
            leftRotate(y);
            y = x->parent->left;
          }
        }
        if (x == nullptr) {
          y->isBlack = xParent->isBlack;
          xParent->isBlack = true;
          y->left->isBlack = true;
          rightRotate(xParent);
          x = root;
        } else {
          y->isBlack = x->parent->isBlack;
          x->parent->isBlack = true;
          y->left->isBlack = true;
          rightRotate(x->parent);
          x = root;
        }
      }
    }
  }

  if (x == root && x == nullptr) {
    return;
  } else {
    x->isBlack = true;
  }
}

// Recursively traverses the tree and stores values between key1 and key2
template <class T1, class T2>
vector<T2> RedBlackTree<T1, T2>::searchHelper(NodeT<T1, T2> *root, T1 key1, T1 key2) const {
  vector<T2> ret;

  if (!root) {
    return ret;
  }
  NodeT<T1, T2> *curr = root;
  while (curr) {
    if (curr->left == nullptr) {
      if (curr->key <= key2 && curr->key >= key1) {
        ret.push_back(curr->value);
      }
      curr = curr->right;
    } else {
      NodeT<T1, T2> *pre = curr->left;
      while (pre->right != nullptr && pre->right != curr) {
        pre = pre->right;
      }
      if (pre->right == nullptr) {
        pre->right = curr;
        curr = curr->left;
      } else {
        pre->right = nullptr;
        if (curr->key <= key2 && curr->key >= key1) {
          ret.push_back(curr->value);
        }
        curr = curr->right;
      }
    }
  }
  return ret;
}
