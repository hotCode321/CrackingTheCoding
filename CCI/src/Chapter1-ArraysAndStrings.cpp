#include "Chapter1-ArraysAndStrings.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

std::vector<std::string> merge(std::vector<std::string> words, std::vector<std::string> more)
{
    std::vector<std::string> sentence;
    for (auto w : words)
    {
        sentence.push_back(w);
    }

    for (auto w : more)
    {
        sentence.push_back(w);
    }

    return sentence;
}

std::string joinWords(std::vector<std::string> words)
{
    std::string sentence = "";
    for (auto w : words)
    {
        sentence = sentence + w;
    }
    return sentence;
}

// 1.1
// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures?
bool isUniqueChars(std::string str)
{

    if (str.length() > 128)
        return false;

    std::vector<bool> char_set(128);
    for (int i = 0; i < str.length(); i++)
    {
        int val = str.at(i);
        if (char_set[val])
        { //Already found this char in string
            return false;
        }
        char_set[val] = true;
    }
    return true;
}

// 1.2
// Check Permutation: Given two strings, write a method to decide if one is a permutation of the
// other
//My solution
bool checkPermutation(std::string iLeft, std::string iRight)
{
    if (iLeft.size() != iRight.size() || iLeft.size() == 0)
    {
        return false;
    }

    std::unordered_map<char, int> left;
    std::unordered_map<char, int> right;
    for (int i = 0; i < iLeft.size(); i++)
    {
        left[iLeft[i]]++;
        right[iRight[i]]++;
    }

    return left == right;
}

// 1.3
// URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
// has sufficient space at the end to hold the additional characters, and that you are given the "true"
// length of the string. (Note: If implementing in Java, please use a character array so that you can
// perform this operation in place.)
// EXAMPLE
// Input: "Mr John Smith    ", 13
// Output: "Mr%20John%20Smith"
//My solution
std::string URLify(std::string str)
{
    std::string output;
    for (auto it = str.begin(); it != str.end(); it++)
    {
        if (*it == ' ')
        {
            output += "%20";
        }
        else
        {
            output += *it;
        }
    }

    auto rIt = output.rbegin();
    while (*rIt++ == '0' && *rIt++ == '2' && *rIt++ == '%')
    {
        output.erase(output.end() - 3, output.end());
    }

    return output;
}

// 1.4 Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palin­
// drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation
// is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
// EXAMPLE
// Input: Tact Coa
// Output: True (permutations: "taco cat", "atco eta", etc.)
// My solution
bool palindromePermutation(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c)
                   {
                       return std::tolower(c);
                   });

    auto itIn = str.begin();
    std::string filtered;
    for (; itIn != str.end(); itIn++)
    {
        if (*itIn != ' ' && *itIn != '.' && *itIn != '\'')
        {
            char c = *itIn;
            filtered += c;
        }
    }

    std::unordered_map<char, int> counter;
    for (auto c : filtered)
    {
        counter[c]++;
    }

    int countNonPairs(0);
    for (auto item : counter)
    {
        if (item.second % 2 != 0)
        {
            countNonPairs++;
        }
        if (countNonPairs > 1)
        {
            return false;
        }
    }
    return true;
}

// 1.5
// One Away: There are three types of edits that can be performed on strings: insert a character,
// remove a character, or replace a character. Given two strings, write a function to check if they are
// one edit (or zero edits) away.
// EXAMPLE
// ->
// pale, ple -> true
// pales, pale -> true
// pale, bale -> true
// pale, bake -> false
bool oneAway(std::string lh, std::string rh)
{
    if (lh.size() < rh.size())
    {
        std::string tmp = lh;
        lh = rh;
        rh = lh;
    }

    if (lh.size() - rh.size() > 1)
    {
        return false;
    }

    int counter(0);
    if (lh.size() == rh.size())
    {
        for (size_t i = 0; i < rh.size(); i++)
        {
            if (lh[i] != rh[i])
            {
                counter++;
                if (counter > 1)
                {
                    return false;
                }
            }
        }
    }
    else
    {
        auto itLh = lh.begin();
        auto itRh = rh.begin();
        for (; itLh != lh.end();)
        {
            if (*itLh != *itRh)
            {
                counter++;
                if (counter > 1)
                {
                    return false;
                }
                itLh++;
            }
            else
            {
                itLh++;
                itRh++;
            }
        }
    }

    return true;
}

// 1.6
// String Compression: Implement a method to perform basic string compression using the counts
// of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the
// "compressed" string would not become smaller than the original string, your method should return
// the original string. You can assume the string has only uppercase and lowercase letters (a - z).
std::string stringCompression(std::string str)
{
    int size = str.size();
    auto it = str.begin();
    int counter(1);
    std::string output;
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            output += str[i];
            output += std::to_string(counter);
        }
        else
        {
            if (str[i] == str[i + 1])
            {
                counter++;
            }
            else
            {
                output += str[i];
                output += std::to_string(counter);
                counter = 1;
            }
        }
    }
    return output.size() < size ? output : str;
}

// 1.7 Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
// bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
std::vector<std::vector<char>> rotateMatrix(std::vector<std::vector<char>> &matrix)
{
    int n = matrix.size();

    // transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reverse each column
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            std::swap(matrix[j][i], matrix[n - j - 1][i]);
        }
    }

    return matrix;
}

// 1.8 Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
// column are set to 0.
std::vector<std::vector<char>> zeroMatrix(std::vector<std::vector<char>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        if (std::find(matrix[i].begin(), matrix[i].end(), 0) != matrix[i].end())
        {
            std::transform(matrix[i].begin(), matrix[i].end(), matrix[i].begin(), [](char c)
                           { return 0; });
        }
    }
    return matrix;
}

// 1.9 String Rotation:Assume you have a method isSubstring which checks if one word is a substring
// of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one
// call to isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat"). //erbottlewaterbottlewat
bool stringRotation(std::string s1, std::string s2)
{
    int size = s1.size();
    std::string cycle = s1 + s1;

    for (int i = 0; i < size; i++)
    {
        std::string substr = cycle.substr(i, size);
        if (std::equal(s2.begin(), s2.end(), substr.begin()))
        {
            return true;
        }
    }
    return false;
}

// Extra
bool checkPalindrome(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });

    return std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());
}