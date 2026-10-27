#include <iostream>
#include <vector>

using namespace std;

class Tree {
public:
  Tree() : root(nullptr) {}
  ~Tree() { delete root; }

  void insert(int v);
  vector<int> lsum();

private:
  struct node {
    node(int d, node *l, node *r) : data(d), left(l), right(r) {}
    ~node() { delete left; delete right; }

    int data;
    node *left, *right;
  };

  static node *insert(node *t, int v);

  node *root;
};

vector<int> Tree::lsum() {
  vector<int> result;
  
  return result;
}

// YOU DON'T NEED TO CHANGE THE REST. IF YOU DO, YOU'D BETTER
// KNOW WHAT YOU'RE DOING...

void Tree::insert(int v) { root = insert(root, v); }

Tree::node *Tree::insert(node *t, int v) {
  if (t == nullptr)
    return new node(v, nullptr, nullptr);
  if (v < t->data)
    t->left = insert(t->left, v);
  else
    t->right = insert(t->right, v);
  return t;
}