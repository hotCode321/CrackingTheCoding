#include "../include/Chapter1-ArraysAndStrings.hpp"
#include <gtest/gtest.h>

TEST(Chapter1, merge)
{
    std::vector<std::string> words {"yellow", "orange", "blue"};
    std::vector<std::string> more {"car", "tank", "bus"};
    std::vector<std::string> sentence = merge(words, more);
    std::vector<std::string> expected {"yellow", "orange", "blue", "car", "tank", "bus"};
    GTEST_ASSERT_EQ(sentence, expected);
}

TEST(Chapter1, joinWords)
{
    std::vector<std::string> words {"yellow", "orange", "blue"};
    std::vector<std::string> more {"car", "tank", "bus"};
    std::vector<std::string> concatenated = merge(words, more);
    std::string sentence = joinWords(concatenated);
    std::string expected = "yelloworangebluecartankbus";
    GTEST_ASSERT_EQ(sentence, expected);
}

TEST(Chapter1, 1_isUniqueChars)
{
    std::string chars1 = "qwertyuiopasdfghajkl";
    std::string chars2 = "qwertyuiopasdfgjklzxcvbnm";
    GTEST_ASSERT_FALSE(isUniqueChars(chars1));
    GTEST_ASSERT_TRUE(isUniqueChars(chars2));
}

TEST(Chapter1, 2_checkPermutation)
{
    std::string word1 = "Amalgama";
    std::string word2 = "Amaglama";
    std::string word3 = "Amaglaaa";
    GTEST_ASSERT_TRUE(checkPermutation(word1, word2));
    GTEST_ASSERT_FALSE(checkPermutation(word1, word3));
}

TEST(Chapter1, 3_checkURLify)
{
    std::string word1 = "Mr John Smith    ";
    GTEST_ASSERT_EQ(URLify(word1), "Mr%20John%20Smith");
}

TEST(Chapter1, 4_checkPalindromePermutation)
{
    std::string word1 = "Tact Coa";
    std::string word2 = "Tact Coaa";
    GTEST_ASSERT_TRUE(palindromePermutation(word1));
    GTEST_ASSERT_FALSE(palindromePermutation(word2));
}

TEST(Chapter1, 5_checkOneAway)
{
    GTEST_ASSERT_TRUE(oneAway("pale", "ple"));
    GTEST_ASSERT_TRUE(oneAway("pales", "pale"));
    GTEST_ASSERT_TRUE(oneAway("pale", "pales"));
    GTEST_ASSERT_TRUE(oneAway("pale", "bale"));
    GTEST_ASSERT_FALSE(oneAway("pale", "bake"));
}

TEST(Chapter1, 6_stringCompression)
{
    std::string output1 = stringCompression("aabcccccaaa");
    std::string output2 = stringCompression("aabccccca");
    std::string output3 = stringCompression("aabc");
    GTEST_ASSERT_EQ(output1, "a2b1c5a3");
    GTEST_ASSERT_EQ(output2, "a2b1c5a1");
    GTEST_ASSERT_EQ(output3, "aabc");
}

TEST(Chapter1, 7_rotateMatrix)
{
    std::vector<std::vector<char>> input1 = {{1,1,1},{2,2,2},{3,3,3}};
    std::vector<std::vector<char>> input2 = {{1,2,3},{4,5,6},{7,8,9}};
    std::vector<std::vector<char>> expected1 = {{1,2,3},{1,2,3},{1,2,3}};
    std::vector<std::vector<char>> expected2 = {{3,6,9},{2,5,8},{1,4,7}};
    GTEST_ASSERT_EQ(rotateMatrix(input1), expected1);
    GTEST_ASSERT_EQ(rotateMatrix(input2), expected2);
}

TEST(Chapter1, 8_zeroMatrix)
{
    std::vector<std::vector<char>> input1 = {{1,1,1},{2,2,2},{3,0,3}};
    std::vector<std::vector<char>> input2 = {{0,2,3},{4,5,6},{7,0,9}};
    std::vector<std::vector<char>> expected1 = {{1,1,1},{2,2,2},{0,0,0}};
    std::vector<std::vector<char>> expected2 = {{0,0,0},{4,5,6},{0,0,0}};
    GTEST_ASSERT_EQ(zeroMatrix(input1), expected1);
    GTEST_ASSERT_EQ(zeroMatrix(input2), expected2);
}

TEST(Chapter1, 9_stringRotation)
{
    GTEST_ASSERT_TRUE(stringRotation("waterbottle", "erbottlewat"));
    GTEST_ASSERT_FALSE(stringRotation("waterbottle", "ezbottlewat"));
}

TEST(Chapter1, checkPalindrome)
{
    std::string word1 = "Radar";
    std::string word2 = "shift";
    std::string word3 = "MadaminEdenImAdam";
    std::string word4 = "Madam, in Edek, I’m Adam";
    GTEST_ASSERT_TRUE(checkPalindrome(word1));
    GTEST_ASSERT_FALSE(checkPalindrome(word2));
    GTEST_ASSERT_TRUE(checkPalindrome(word3));
    GTEST_ASSERT_FALSE(checkPalindrome(word4));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}