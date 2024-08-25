#include <bits/stdc++.h>
#include <vector>
#include <tuple>
#include "Utils.hpp"

#define PRINT(x) std::cout << #x"=" << x << std::endl

int sum(int n);

std::tuple<int, int> findMinMax(std::vector<int> array);

void reverse(std::vector<int> &vec);

int sumNodes(NodeTree* node);