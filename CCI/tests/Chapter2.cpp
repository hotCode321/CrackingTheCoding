#include "../include/Chapter2-LinkedLists.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

class LinkedListFixture : public testing::Test
{
public:
    LinkedList kLinkedList = LinkedList({0, 1, 2, 3, 4});
    LinkedList kllNull = LinkedList(nullptr);
    LinkedList kllOneItem = LinkedList(0);
    DoubleLinkedList kDoubleLinkedList = DoubleLinkedList({0, 1, 2, 3, 4});
    DoubleLinkedList kdllNull = DoubleLinkedList(nullptr);
    DoubleLinkedList kdllOneItem = DoubleLinkedList(0);
};

TEST_F(LinkedListFixture, single_printDefaultList)
{
    GTEST_ASSERT_EQ(kLinkedList.print(), "0 1 2 3 4");
    GTEST_ASSERT_EQ(kllNull.print(), "");
    GTEST_ASSERT_EQ(kllOneItem.print(), "0");
}

TEST_F(LinkedListFixture, double_printDefaultList)
{
    GTEST_ASSERT_EQ(kDoubleLinkedList.print(), "0 1 2 3 4");
    GTEST_ASSERT_EQ(kDoubleLinkedList.printReverse(), "4 3 2 1 0");

    GTEST_ASSERT_EQ(kdllNull.print(), "");
    GTEST_ASSERT_EQ(kdllNull.printReverse(), "");

    GTEST_ASSERT_EQ(kdllOneItem.print(), "0");
    GTEST_ASSERT_EQ(kdllOneItem.printReverse(), "0");
}

TEST_F(LinkedListFixture, single_appendToTail)
{
    kLinkedList.appendToTail(10);
    GTEST_ASSERT_EQ(kLinkedList.print(), "0 1 2 3 4 10");

    kllNull.appendToTail(10);
    GTEST_ASSERT_EQ(kllNull.print(), "10");

    kllOneItem.appendToTail(10);
    GTEST_ASSERT_EQ(kllOneItem.print(), "0 10");
}

TEST_F(LinkedListFixture, double_appendToTail)
{
    kDoubleLinkedList.appendToTail(10);
    GTEST_ASSERT_EQ(kDoubleLinkedList.print(), "0 1 2 3 4 10");
    GTEST_ASSERT_EQ(kDoubleLinkedList.printReverse(), "10 4 3 2 1 0");

    kdllNull.appendToTail(10);
    GTEST_ASSERT_EQ(kdllNull.print(), "10");
    GTEST_ASSERT_EQ(kdllNull.printReverse(), "10");

    kdllOneItem.appendToTail(10);
    GTEST_ASSERT_EQ(kdllOneItem.print(), "0 10");
    GTEST_ASSERT_EQ(kdllOneItem.printReverse(), "10 0");
}

TEST_F(LinkedListFixture, single_insertAtHead)
{
    kLinkedList.insert(10, 0);
    GTEST_ASSERT_EQ(kLinkedList.print(), "10 0 1 2 3 4");

    kllNull.insert(10, 0);
    GTEST_ASSERT_EQ(kllNull.print(), "10");

    kllOneItem.insert(10, 0);
    GTEST_ASSERT_EQ(kllOneItem.print(), "10 0");
}

TEST_F(LinkedListFixture, double_insertAtHead)
{
    kDoubleLinkedList.insert(10, 0);
    GTEST_ASSERT_EQ(kDoubleLinkedList.print(), "10 0 1 2 3 4");
    GTEST_ASSERT_EQ(kDoubleLinkedList.printReverse(), "4 3 2 1 0 10");

    kdllNull.insert(10, 0);
    GTEST_ASSERT_EQ(kdllNull.print(), "10");
    GTEST_ASSERT_EQ(kdllNull.printReverse(), "10");

    kdllOneItem.insert(10, 0);
    GTEST_ASSERT_EQ(kdllOneItem.print(), "10 0");
    GTEST_ASSERT_EQ(kdllOneItem.printReverse(), "0 10");
}

TEST_F(LinkedListFixture, single_insertAtMiddle)
{
    kLinkedList.insert(0, 3);
    GTEST_ASSERT_EQ(kLinkedList.print(), "0 1 2 0 3 4");
}

TEST_F(LinkedListFixture, double_insertAtMiddle)
{
    kDoubleLinkedList.insert(0, 3);
    GTEST_ASSERT_EQ(kDoubleLinkedList.print(), "0 1 2 0 3 4");
    GTEST_ASSERT_EQ(kDoubleLinkedList.printReverse(), "4 3 0 2 1 0");
}

TEST_F(LinkedListFixture, single_insertAtEnd)
{
    kLinkedList.insert(0, 5);
    GTEST_ASSERT_EQ(kLinkedList.print(), "0 1 2 3 4 0");

    kllOneItem.insert(10, 1);
    GTEST_ASSERT_EQ(kllOneItem.print(), "0 10");
}

TEST_F(LinkedListFixture, double_insertAtEnd)
{
    kDoubleLinkedList.insert(0, 5);
    GTEST_ASSERT_EQ(kDoubleLinkedList.print(), "0 1 2 3 4 0");
    GTEST_ASSERT_EQ(kDoubleLinkedList.printReverse(), "0 4 3 2 1 0");

    kdllOneItem.insert(10, 1);
    GTEST_ASSERT_EQ(kdllOneItem.print(), "0 10");
    GTEST_ASSERT_EQ(kdllOneItem.printReverse(), "10 0");
}

TEST_F(LinkedListFixture, single_insertOutOfBounds)
{
    kLinkedList.insert(0, 7);
    GTEST_ASSERT_EQ(kLinkedList.print(), "0 1 2 3 4");

    kllNull.insert(0, 7);
    GTEST_ASSERT_EQ(kllNull.print(), "");

    kllOneItem.insert(0, 7);
    GTEST_ASSERT_EQ(kllOneItem.print(), "0");
}

TEST_F(LinkedListFixture, double_insertOutOfBounds)
{
    kDoubleLinkedList.insert(0, 7);
    GTEST_ASSERT_EQ(kDoubleLinkedList.print(), "0 1 2 3 4");
    GTEST_ASSERT_EQ(kDoubleLinkedList.printReverse(), "4 3 2 1 0");

    kdllNull.insert(0, 7);
    GTEST_ASSERT_EQ(kdllNull.print(), "");
    GTEST_ASSERT_EQ(kdllNull.printReverse(), "");

    kdllOneItem.insert(0, 7);
    GTEST_ASSERT_EQ(kdllOneItem.print(), "0");
    GTEST_ASSERT_EQ(kdllOneItem.printReverse(), "0");
}

TEST_F(LinkedListFixture, single_deleteAtHead)
{
    kLinkedList.deleteNode(0);
    GTEST_ASSERT_EQ(kLinkedList.print(), "1 2 3 4");

    kllNull.deleteNode(0);
    GTEST_ASSERT_EQ(kllNull.print(), "");

    kllOneItem.deleteNode(0);
    GTEST_ASSERT_EQ(kllOneItem.print(), "");
    GTEST_ASSERT_EQ(kllOneItem.head, nullptr);
}

TEST_F(LinkedListFixture, double_deleteAtHead)
{
    kDoubleLinkedList.deleteNode(0);
    GTEST_ASSERT_EQ(kDoubleLinkedList.print(), "1 2 3 4");
    GTEST_ASSERT_EQ(kDoubleLinkedList.printReverse(), "4 3 2 1");

    kdllNull.deleteNode(0);
    GTEST_ASSERT_EQ(kdllNull.print(), "");
    GTEST_ASSERT_EQ(kdllNull.printReverse(), "");

    kdllOneItem.deleteNode(0);
    GTEST_ASSERT_EQ(kdllOneItem.print(), "");
    GTEST_ASSERT_EQ(kdllOneItem.printReverse(), "");
    GTEST_ASSERT_EQ(kdllOneItem.head, nullptr);
    GTEST_ASSERT_EQ(kdllOneItem.tail, nullptr);
}

TEST_F(LinkedListFixture, single_deleteAtMiddle)
{
    kLinkedList.deleteNode(2);
    GTEST_ASSERT_EQ(kLinkedList.print(), "0 1 3 4");
}

TEST_F(LinkedListFixture, double_deleteAtMiddle)
{
    kDoubleLinkedList.deleteNode(2);
    GTEST_ASSERT_EQ(kDoubleLinkedList.print(), "0 1 3 4");
    GTEST_ASSERT_EQ(kDoubleLinkedList.printReverse(), "4 3 1 0");
}

TEST_F(LinkedListFixture, single_deleteAtEnd)
{
    kLinkedList.deleteNode(4);
    GTEST_ASSERT_EQ(kLinkedList.print(), "0 1 2 3");
}

TEST_F(LinkedListFixture, double_deleteAtEnd)
{
    kDoubleLinkedList.deleteNode(4);
    GTEST_ASSERT_EQ(kDoubleLinkedList.print(), "0 1 2 3");
    GTEST_ASSERT_EQ(kDoubleLinkedList.printReverse(), "3 2 1 0");
}

TEST_F(LinkedListFixture, single_deleteNonExisting)
{
    kLinkedList.deleteNode(6);
    GTEST_ASSERT_EQ(kLinkedList.print(), "0 1 2 3 4");

    kllNull.deleteNode(6);
    GTEST_ASSERT_EQ(kllNull.print(), "");

    kllOneItem.deleteNode(6);
    GTEST_ASSERT_EQ(kllOneItem.print(), "0");
}

TEST_F(LinkedListFixture, double_deleteNonExisting)
{
    kDoubleLinkedList.deleteNode(6);
    GTEST_ASSERT_EQ(kDoubleLinkedList.print(), "0 1 2 3 4");
    GTEST_ASSERT_EQ(kDoubleLinkedList.printReverse(), "4 3 2 1 0");

    kdllNull.deleteNode(6);
    GTEST_ASSERT_EQ(kdllNull.print(), "");
    GTEST_ASSERT_EQ(kdllNull.printReverse(), "");

    kdllOneItem.deleteNode(6);
    GTEST_ASSERT_EQ(kdllOneItem.print(), "0");
    GTEST_ASSERT_EQ(kdllOneItem.printReverse(), "0");
}

TEST_F(LinkedListFixture, removeDups)
{
    LinkedList linkedList = LinkedList({1, 2, 2, 4, 5, 5});
    removeDups(linkedList);

    GTEST_ASSERT_EQ(linkedList.print(), "1 2 4 5");
}

TEST_F(LinkedListFixture, removeDupsNoBuffer)
{
    LinkedList linkedList = LinkedList({1, 2, 2, 4, 5, 5});
    removeDupsNoBuffer(linkedList);

    GTEST_ASSERT_EQ(linkedList.print(), "1 2 4 5");
}

TEST_F(LinkedListFixture, returnKthToLast)
{
    LinkedList linkedList = LinkedList({1, 2, 3, 4, 5, 6});
    auto &&node = returnKthToLast(linkedList, 2);

    GTEST_ASSERT_EQ(node->data, 4);
    GTEST_ASSERT_EQ(returnKthToLast(kllNull, 2), nullptr);
    GTEST_ASSERT_EQ(returnKthToLast(kllOneItem, 2), nullptr);
}

TEST_F(LinkedListFixture, fillKthToLast)
{
    LinkedList linkedList = LinkedList({1, 2, 3, 4, 5, 6});
    int data = 0;
    int dataNull = 0;
    int dataOneEl = 0;
    fillKthToLast(linkedList.head, 2, data);
    fillKthToLast(kllNull.head, 2, dataNull);
    fillKthToLast(kllOneItem.head, 2, dataOneEl);

    GTEST_ASSERT_EQ(data, 4);
    GTEST_ASSERT_EQ(dataNull, 0);
    GTEST_ASSERT_EQ(dataOneEl, 0);
}

TEST_F(LinkedListFixture, deleteMiddleNode)
{
    deleteMiddleNode(kLinkedList.head->next->next);
    GTEST_ASSERT_EQ(kLinkedList.print(), "0 1 3 4");
    deleteMiddleNode(kLinkedList.head->next);
    GTEST_ASSERT_EQ(kLinkedList.print(), "0 3 4");
}

TEST_F(LinkedListFixture, partitionLinkedList)
{
    LinkedList linkedList1 = LinkedList({3, 5, 8, 5, 10, 2, 1});
    partitionLinkedList(linkedList1, 5);
    GTEST_ASSERT_EQ(linkedList1.print(), "1 2 3 5 8 5 10");

    LinkedList linkedList2 = LinkedList({10, 2, 4, 2, 5, 3, 7});
    partitionLinkedList(linkedList2, 6);
    GTEST_ASSERT_EQ(linkedList2.print(), "3 5 2 4 2 10 7");

    partitionLinkedList(kllNull, 5);
    GTEST_ASSERT_EQ(kllNull.print(), "");

    partitionLinkedList(kllOneItem, 5);
    GTEST_ASSERT_EQ(kllOneItem.print(), "0");

    //////////////////////////////////////

    LinkedList linkedListCCI = LinkedList({3, 5, 8, 5, 10, 2, 1});
    partitionLinkedListCCI(linkedListCCI.head, 5);
    GTEST_ASSERT_EQ(linkedListCCI.print(), "1 2 3 5 8 5 10");
}

TEST_F(LinkedListFixture, sumLists_sumListsReverse)
{
    LinkedList l1 = LinkedList({7, 1, 6}); // 617
    LinkedList l2 = LinkedList({5, 9, 2}); // 295
    LinkedList result1 = sumLists(l1, l2);
    GTEST_ASSERT_EQ(result1.print(), "2 1 9"); // 912

    LinkedList l3 = LinkedList({1, 6});    // 61
    LinkedList l4 = LinkedList({5, 9, 2}); // 295
    LinkedList result2 = sumLists(l3, l4);
    GTEST_ASSERT_EQ(result2.print(), "6 5 3"); // 356
}

TEST_F(LinkedListFixture, bubbleHeadToTail)
{
    bubbleHeadToTail(kLinkedList);
    GTEST_ASSERT_EQ(kLinkedList.print(), "1 2 3 4 0");
}

TEST_F(LinkedListFixture, reverseList)
{
    reverseList(kLinkedList);
    GTEST_ASSERT_EQ(kLinkedList.print(), "4 3 2 1 0");
}

TEST_F(LinkedListFixture, isPalindrome_Stack1)
{
    LinkedList l1 = LinkedList({0, 1, 2, 1, 0});
    GTEST_ASSERT_TRUE(isPalindrome_Stack1(l1));

    // LinkedList l2 = LinkedList({0, 1, 2, 3, 2, 1, 0});
    // GTEST_ASSERT_TRUE(isPalindrome_Stack1(l2));

    // LinkedList l3 = LinkedList({0, 1, 2, 3, 1, 0});
    // GTEST_ASSERT_TRUE(isPalindrome_Stack1(l3));

    //     LinkedList l4 = LinkedList({0, 1, 2, 3, 1, 0});
    // GTEST_ASSERT_TRUE(isPalindrome_Stack1(l3));

    //     LinkedList l5 = LinkedList({0, 1, 2, 3, 1, 0});
    // GTEST_ASSERT_TRUE(isPalindrome_Stack1(l3));
}

TEST_F(LinkedListFixture, isPalindromeRecurse)
{
    LinkedList lOdd = LinkedList({0, 1, 2, 3, 2, 1, 0});
    GTEST_ASSERT_TRUE(isPalindromeRecurse(lOdd));

    LinkedList lPair = LinkedList({0, 1, 2, 3, 3, 2, 1, 0});
    GTEST_ASSERT_TRUE(isPalindromeRecurse(lPair));

    LinkedList lNotPalindrome = LinkedList({0, 1, 1, 3, 2, 1, 0});
    GTEST_ASSERT_FALSE(isPalindromeRecurse(lNotPalindrome));
}

TEST_F(LinkedListFixture, isPalindromeSlowRunner)
{
    LinkedList lOdd = LinkedList({0, 1, 2, 3, 2, 1, 0});
    GTEST_ASSERT_TRUE(isPalindromeSlowRunner(lOdd));

    LinkedList lPair = LinkedList({0, 1, 2, 3, 3, 2, 1, 0});
    GTEST_ASSERT_TRUE(isPalindromeSlowRunner(lPair));

    LinkedList lNotPalindrome = LinkedList({0, 1, 1, 3, 2, 1, 0});
    GTEST_ASSERT_FALSE(isPalindromeSlowRunner(lNotPalindrome));
}

TEST_F(LinkedListFixture, firstInterSectionNode)
{
    LinkedList longerList = LinkedList({3, 1, 5, 9, 7, 2, 1});
    LinkedList smallerList = LinkedList(longerList.head);
    popHead(smallerList);
    popHead(smallerList);
    popHead(smallerList);
    popHead(smallerList);
    smallerList.insert(6, 0);
    smallerList.insert(4, 0);
    GTEST_ASSERT_EQ(longerList.print(), "3 1 5 9 7 2 1");
    GTEST_ASSERT_EQ(smallerList.print(), "4 6 7 2 1");
    Node *seven = firstInterSectionNode_Set(longerList, smallerList);
    GTEST_ASSERT_EQ(seven->data, 7);
    seven = firstInterSectionNode_Chop(longerList, smallerList);
    GTEST_ASSERT_EQ(seven->data, 7);
}

TEST_F(LinkedListFixture, loopDetection)
{
    LinkedList list = LinkedList({3, 1, 5, 9, 7, 2, 1});
    Node *tail = returnTail(list);
    tail->next = list.head->next->next;
    GTEST_ASSERT_EQ(list.head->next->next, loopDetection_Set(list));
    GTEST_ASSERT_EQ(list.head->next->next, loopDetectionSlowRunner(list));
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}