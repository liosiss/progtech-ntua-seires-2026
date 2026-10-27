#include <iostream>
#include <map>
using namespace std;

struct node {
    char v;
    node *left, *right;
};


void help(node *t, map<char, int> &mpp) {
    if(t == nullptr) return;
    mpp[t->v]++;
    help(t->left, mpp);
    help(t->right, mpp);
    return;
}

void exercise3 (node *root){
    map<char, int> mp;
    help(root, mp);
    for(const auto &it : mp) {
        cout << it.first << "(" << it.second << ") ";
    }
    return;
}