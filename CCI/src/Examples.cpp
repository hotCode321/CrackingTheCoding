#include "Examples.hpp"
#include <iterator>

int sum(int n){
    if(n <= 0){
        return 0;
    }
    return n + sum(n-1);
}

int sumNodes(NodeTree* node){
  if (node == nullptr) {
    return 0;
  }
  return sumNodes(node->left) + node->value + sumNodes(node->right);
}

std::tuple<int, int> findMinMax(std::vector<int> array){
    int min = INT_MAX;
    int max = INT_MIN;

    for (int x : array){
        if(x < min) min = x;
        if(x > max) max = x;
    }
    return std::make_tuple(min, max);
}

void reverse(std::vector<int> &vec){
  
  int size = vec.size();
  for(int i = 0; i < size / 2; i++){
    int other = size - i - 1;
    int temp = vec[i];
    vec[i] = vec[other];
    vec[other] = temp;
  }
}