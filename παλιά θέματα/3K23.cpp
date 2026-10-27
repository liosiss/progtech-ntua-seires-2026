#include <iostream>
using namespace std;

template <typename T>
struct node { 
    T val;
    node *left, *right;
};


//πρεπει να ορισω ΠΡΩΤΑ την βοηθητικη συναρτηση αλλιως θα πεταξει error!!!!!!!!!!!!!!!
template <typename T>
void help (node<T> *t, T x, int h, int ch, int &cnt) {
    if (t == nullptr || h < ch || (ch == h && x != t->val)) return; 
    else if (h == ch && x == t->val) {
        cnt++;
        return;
    }
    else {
        help(t->left, x, h, ch + 1, cnt);
        help(t->right, x, h, ch + 1, cnt);
    }
    return;
}

template <typename T>
int exercise3 (node<T> *root, T x, int h) {
    int cnt = 0;
    help(root, x, h, 1, cnt);
    return cnt;
}

