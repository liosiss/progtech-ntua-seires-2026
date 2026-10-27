#include <iostream>
using namespace std;


struct node{
    int value;
    node *right, *left;
};


bool thema21 (int k, node *root) {
    int sum = 0;
    return help_thema21(k, root, sum);
}

bool help_thema21(int k, node *root, int sum) {
    if(sum > k || root == nullptr) return false;
    if(root->right == nullptr && root->left == nullptr) {
        if(k == sum) return true;
        else return false;
    }
    sum += root->value;
    return help_thema21(k, root->right, sum) || help_thema21(k, root->left, sum);
}
