#include "CCI/include/Examples.hpp"
#include <iostream>

int main(){
    auto tree = getIncompleteBinaryTree();
    int result = sumNodes(tree);
    PRINT(result);
}