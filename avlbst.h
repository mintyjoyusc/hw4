#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include "bst.h"

struct KeyError { };

/**
* A special kind of node for an AVL tree, which adds the balance as a data member, plus
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
    // Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    int8_t getBalance () const;
    void setBalance (int8_t balance);
    void updateBalance(int8_t diff);

    // Getters for parent, left, and right. These need to be redefined since they
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    int8_t balance_;    // effectively a signed char
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
* An explicit constructor to initialize the elements by calling the base class constructor
*/
template<class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value> *parent) :
    Node<Key, Value>(key, value, parent), balance_(0)
{

}

/**
* A destructor which does nothing.
*/
template<class Key, class Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* A getter for the balance of a AVLNode.
*/
template<class Key, class Value>
int8_t AVLNode<Key, Value>::getBalance() const
{
    return balance_;
}

/**
* A setter for the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::setBalance(int8_t balance)
{
    balance_ = balance;
}

/**
* Adds diff to the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::updateBalance(int8_t diff)
{
    balance_ += diff;
}

/**
* An overridden function for getting the parent since a static_cast is necessary to make sure
* that our node is a AVLNode.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key, Value>*>(this->parent_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key, Value>*>(this->left_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key, Value>*>(this->right_);
}


/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/


template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
    virtual void insert (const std::pair<const Key, Value> &new_item); // TODO
    virtual void remove(const Key& key);  // TODO
protected:

    void rotateLeft(AVLNode<Key, Value>* node);
    void rotateRight(AVLNode<Key, Value>* node);
    void rotateLeftRight(AVLNode<Key, Value>* node);
    void rotateRightLeft(AVLNode<Key, Value>* node);
    void insertFix(AVLNode<Key, Value>* parent, AVLNode<Key, Value>* node);
    void removeFix(AVLNode<Key, Value>* node, int diff);

    void rebalance(AVLNode<Key, Value>* node);

    AVLNode<Key, Value>* castNode(Node<Key, Value>* node) const;
    int getBalance(AVLNode<Key, Value>* node) const;
    int getHeight(AVLNode<Key, Value>* node) const;

    virtual void nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2);

    // Add helper functions here
    


};

/*
 * Recall: If key is already in the tree, you should 
 * overwrite the current value with the updated value.
 */
template<class Key, class Value>
void AVLTree<Key, Value>::insert (const std::pair<const Key, Value> &new_item)
{
  Node<Key, Value>* rawNode = this->internalFind(new_item.first);
  if (rawNode) {
    rawNode->setValue(new_item.second);
    return;
  }

  // Perform standard BST insert
  AVLNode<Key, Value>* insertedNode = new AVLNode<Key, Value>(new_item.first, new_item.second, nullptr);
  AVLNode<Key, Value>* parent = nullptr;
  AVLNode<Key, Value>* node = static_cast<AVLNode<Key, Value>*>(this->root_);

  while (node != nullptr) {
    parent = node;  
    if (new_item.first < node->getKey()) {
      node = node->getLeft();
    } 
    else {
      node = node->getRight();
    }
  }

  insertedNode->setParent(parent);

    if (parent == nullptr) {
      this->root_ = insertedNode;
    } 
    else if (new_item.first < parent->getKey()) {
      parent->setLeft(insertedNode);
    } else {
      parent->setRight(insertedNode);
    }

   
  insertedNode->setBalance(0);
  insertFix(parent, insertedNode); 

template<class Key, class Value>
void AVLTree<Key, Value>::insertFix(AVLNode<Key, Value>* parent, AVLNode<Key, Value>* node) {
  while (parent != nullptr) {
    if (node == parent->getLeft()) {
      parent->updateBalance(-1);
    } 
    else {
      parent->updateBalance(1);
    }

    if (parent->getBalance() == 0) break;  // Tree has balanced out, no further action needed

      if (abs(parent->getBalance()) == 2) {
        rebalance(parent);  // Tree needs rebalancing
        break;  // Tree height hasn't increased, no need to continue
      }

     node = parent;  // Move up the tree
    parent = parent->getParent();
  }
}

/*
 * Recall: The writeup specifies that if a node has 2 children you
 * should swap with the predecessor and then remove.
 */
template<class Key, class Value>
void AVLTree<Key, Value>::remove(const Key& key)
{
    // TODO
    AVLNode<Key, Value>* node = static_cast<AVLNode<Key, Value>*>(this->internalFind(key));
    if (!node) return; // Node not found
    //std::cout << node->getKey()<< std::endl;
    // If node has two children, swap with in-order successor and then delete
    if (node->getLeft() != nullptr && node->getRight() != nullptr) {
      AVLNode<Key, Value>* successor = static_cast<AVLNode<Key, Value>*>(this->successor(node));
      AVLNode<Key, Value>* predecessor = static_cast<AVLNode<Key, Value>*>(this->predecessor(node));
      //std::cout << successor->getKey()<< std::endl;
      if(node->getRight()->getLeft()==nullptr){
        nodeSwap(node, predecessor);
      }
      else{
        nodeSwap(node, successor);
      }
      
      //node = successor; 
      //std::cout << node->getKey()<< std::endl;
    }

    AVLNode<Key, Value>* child = (node->getLeft() != nullptr) ? node->getLeft() : node->getRight();
    //std::cout << child->getKey()<< std::endl; null
    AVLNode<Key, Value>* parent = node->getParent();
    // std::cout << parent->getKey()<< std::endl; null
    int diff = 0;
    if (parent != nullptr) {
      diff = (node == parent->getLeft()) ? 1 : -1; // Determine diff based on which child was removed
    }
    //std::cout << node->getKey()<< std::endl;
    // Delete node and update pointers
    if (parent == nullptr) {
      this->root_ = child;
      std::cout << node->getKey()<< std::endl;
    } 
    else {
      //std::cout << node->getKey()<< std::endl;
      if (node == parent->getLeft()){
        parent->setLeft(child);
      } 
      else{
        parent->setRight(child);
      } 
    }
   // std::cout << node->getKey()<< std::endl;
    if (child){
      child->setParent(parent);
    } 
    //std::cout << child->getKey()<< std::endl;
    delete node;
    removeFix(parent, diff);
    std::cout << diff << std::endl;
}

template<class Key, class Value>
void AVLTree<Key, Value>::removeFix(AVLNode<Key, Value>* node, int diff) {
  while (node != nullptr) {
    node->updateBalance(diff);

    if (node->getBalance() == -2 || node->getBalance() == 2) {
      AVLNode<Key, Value>* child = (node->getBalance() == -2) ? node->getLeft() : node->getRight();

      if (node->getBalance() == -2) {
        if (child->getBalance() >= 0) {
          rotateLeft(child->getRight());
        }
        // Left-Left case
        rotateRight(node);
      } 
      else {
        if (child->getBalance() <= 0) {
          // Right-Left case
          rotateRight(child->getLeft());
        }
        // Right-Right case
        rotateLeft(node);
      }
      if (node->getParent() && node->getParent()->getBalance() == 0) {
        diff = (node->getParent()->getLeft() == node) ? -1 : 1;
        node = node->getParent();
        continue;
      }
      break;
    }

    if (node->getBalance() == 0) {
      if (node->getParent() != nullptr) {
        diff = (node->getParent()->getLeft() == node) ? -1 : 1;
        node = node->getParent();
      } 
      else {
        break;
      }
    } 
    else {
      break;
    }
  } 
}


template<class Key, class Value>
void AVLTree<Key, Value>::rotateLeft(AVLNode<Key, Value>* node) {
  if (!node) return;  

  AVLNode<Key, Value>* rightChild = node->getRight();
  if (!rightChild) return;  

  node->setRight(rightChild->getLeft());
  if (rightChild->getLeft()) {
    rightChild->getLeft()->setParent(node);
  }

  rightChild->setParent(node->getParent());
  if (!node->getParent()) {
    this->root_ = rightChild;
  } 
  else if (node == node->getParent()->getLeft()) {
    node->getParent()->setLeft(rightChild);
  } 
  else {
    node->getParent()->setRight(rightChild);
  }

  rightChild->setLeft(node);
  node->setParent(rightChild);

  int rightChildBalance = rightChild->getBalance();
  node->setBalance(node->getBalance() - 1 - (rightChildBalance > 0 ? rightChildBalance : 0));
  rightChild->setBalance(rightChild->getBalance() - 1 + (node->getBalance() < 0 ? node->getBalance() : 0));
}


template<class Key, class Value>
void AVLTree<Key, Value>::rotateRight(AVLNode<Key, Value>* node) {
  if (!node) return; 

  AVLNode<Key, Value>* leftChild = node->getLeft();
  if (!leftChild) return; 

  node->setLeft(leftChild->getRight());
  if (leftChild->getRight() != nullptr) {
    leftChild->getRight()->setParent(node);
  }

  leftChild->setParent(node->getParent());
  if (node->getParent() == nullptr) {
    this->root_ = leftChild;
  } 
  else if (node == node->getParent()->getLeft()) {
    node->getParent()->setLeft(leftChild);
  } 
  else {
    node->getParent()->setRight(leftChild);
  }

  leftChild->setRight(node);
  node->setParent(leftChild);

  int leftChildBalance = leftChild->getBalance();
  node->setBalance(node->getBalance() + 1 - (leftChildBalance < 0 ? leftChildBalance : 0));
  leftChild->setBalance(leftChild->getBalance() + 1 + (node->getBalance() > 0 ? node->getBalance() : 0));
}

template<class Key, class Value>
void AVLTree<Key, Value>::rotateLeftRight(AVLNode<Key, Value>* node) {
    if (!node) return; 
    rotateLeft(node->getLeft());
    rotateRight(node);
}

template<class Key, class Value>
void AVLTree<Key, Value>::rotateRightLeft(AVLNode<Key, Value>* node) {
    if (!node) return; 
    rotateRight(node->getRight());
    rotateLeft(node);
}



template<class Key, class Value>
void AVLTree<Key, Value>::rebalance(AVLNode<Key, Value>* node) {
    if (node->getBalance() == -2) {
      
      if (node->getLeft()->getBalance() <= 0) {
        
        rotateRight(node);
      } 
      else {
        rotateLeftRight(node);
      }
    } 
    else if (node->getBalance() == 2) {
      //std::cout << node->getBalance() << std::endl;
      if (node->getRight()->getBalance() >= 0) {
        rotateLeft(node);
      } 
      else {
        rotateRightLeft(node);
      }
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>::nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2)
{
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    int8_t tempB = n1->getBalance();
    n1->setBalance(n2->getBalance());
    n2->setBalance(tempB);
}


#endif
