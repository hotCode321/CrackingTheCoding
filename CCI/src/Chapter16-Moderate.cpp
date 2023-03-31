// #include <bits/stdc++.h>
#include "Chapter16-Moderate.hpp"

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

/* 16.1  Number Swapper: Write a function to swap a number in place (that is, without temporary vari­
ables). Hints: #492, #716, #737 */
void swapNumber(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

/* 16.2 Word Frequencies: Design a method to find the frequency of occurrences of any given word in a
book. What if we were running this algorithm multiple times? */
int wordFrequency(const std::string &iPage, const std::string &iWord)
{
    std::unordered_set<char> endOfWordChars = {' ', '.', '!', '?', ':', ';', '\''}; 
    std::unordered_map<std::string, size_t> counter;
    std::string word;
    for (auto it = iPage.begin(); it != iPage.end(); ++it)
    {
        if (endOfWordChars.count(*it))
        {
            counter[word]++;
            word = "";
        }
        else
        {
            word += *it;
        }
    }
    return counter[iWord];
}

/* 16.3 Intersection: Given two straight line segments (represented as a start point and an end point),
compute the point of intersection, if any.*/

// std::tuple<float, float> intersection(const std::vector<std::tuple<int, int>> &v1, const std::vector < std::tuple<int, int> & v2)
// {
    
// }