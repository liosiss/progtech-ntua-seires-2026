#include <iostream>
#include<vector>
#include <queue>

vector<int> Tree::lsum() {
  vector<int> result;
  queue<node> lvl;
  lvl.insert(root);
  int i = 0;
  node *n = root;
  while(!lvl.empty()) {
    result[i++] = lvlsum(lvl);
    lvl.
  }



  return result;
}

void Isum_help (queue<int> q) {
    if (!queue.empty()) 
}



int lvlsum (queue<int> &q) {
    int sum = 0;
    for (auto &it : q) {
        sum += it;
        q.pop();
    }
    retrun sum;
}