// https://leetcode.com/problems/add-strings

// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

// Note:

// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string addStrings(string num1, string num2) {
    string *longest, *shortest;

    if (num1.size() > num2.size()) {
      longest = &num1;
      shortest = &num2;
    }
    else {
      longest = &num2;
      shortest = &num1;
    }

    int lsize, ssize;
    lsize = longest->size();
    ssize = shortest->size();

    int d1, d2, d3, r = 0;
    for (int pos = 1; pos <= lsize; pos++) {
      d1 = longest->at(lsize - pos) - '0';
      if (ssize - pos >= 0)
        d2 = shortest->at(ssize - pos) - '0';
      else
        d2 = 0;

      d3 = d1 + d2 + r;
      r = 0;
      if (d3 >= 10) {
        d3 -= 10;
        r = 1;
      }

      longest->at(lsize - pos) = '0' + d3;
    }

    if (r == 1) {
      *longest = "1" + *longest;
    }

    return *longest;
  }
};

// ===================================================

#include "stdafx.h"

#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

class Node {
public:
  int digit;
  Node *left, *right;

  Node(int n) {
    digit = n;
    left = nullptr;
    right = nullptr;
  }

  ~Node() {
    if (right != nullptr)
      delete right;
  }
};

class BigInt {
public:
  Node *head, *tail;

  BigInt() {
    head = nullptr;
    tail = nullptr;
  };

  BigInt(string num) {
    head = nullptr;
    tail = nullptr;

    // initialize list
    for (char c : num) {
      Node *n = new Node(c - '0');

      if (head == nullptr) {
        head = n;
      }
      else {
        n->left = tail;
        tail->right = n;
      }
      tail = n;
    }
  }

  string ToString() {
    string str = "";

    Node *n = head;

    while (n != nullptr) {
      str += '0' + n->digit;
      n = n->right;
    }

    return str;
  }

  // free all the Nodes before BigInt deletion
  void freeList() {
    if (head != nullptr)
      delete head;
  }

  ~BigInt() {
  }

};

class Solution {
public:
  BigInt* ListSumm(BigInt **l1, BigInt **l2) {
    BigInt *result = new BigInt();
    // start from the list tail and proceed to the head
    Node *n1 = (*l1)->tail, *n2 = (*l2)->tail;

    int residue = 0;

    while (residue != 0 || (n1 != nullptr && n2 != nullptr)) {
      int d1, d2;
      d1 = n1 == nullptr ? 0 : n1->digit;
      d2 = n2 == nullptr ? 0 : n2->digit;

      Node *tmp = new Node((d1 + d2 + residue) % 10);
      residue = (d1 + d2 + residue) / 10;

      // append new node to the resulted List
      if (result->tail == nullptr) {
        result->tail = tmp;
        result->head = tmp;
      }
      else {
        result->head->left = tmp;
        tmp->right = result->head;
        result->head = tmp;
      }

      if (n1 != nullptr)
        n1 = n1->left;
      if (n2 != nullptr)
        n2 = n2->left;
    }

    // we have processed the shorter list completely,
    // now cut the head part of the longer list and append to the <result>
    if (n1 != nullptr || n2 != nullptr) {
      Node *remain;

      // free memory of the shorter list
      if (n1 != nullptr) {
        remain = n1;
        (*l2)->freeList();
        delete *l2;
        delete *l1;
        *l2 = nullptr;
      }
      else {
        remain = n2;
        (*l1)->freeList();
        delete *l1;
        delete *l2;
        *l1 = nullptr;
      }

      // concatenate lists and free memory of the tail part of the longer list
      result->head->left = remain;
      delete remain->right;
      remain->right = result->head;

      // set correct head node for BigInt object
      while (remain != nullptr) {
        result->head = remain;
        remain = remain->left;
      }
    }

    return result;
  }

  string addStrings(string num1, string num2) {
    BigInt *b1 = new BigInt(num1);
    BigInt *b2 = new BigInt(num2);

    int *t = new int(5);
    delete t;

    BigInt *b3 = ListSumm(&b1, &b2);

    string s = b3->ToString();
    b3->freeList();
    delete b3;
    return s;
  }
};