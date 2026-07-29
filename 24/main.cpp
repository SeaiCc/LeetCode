#include <stdio.h>
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      ListNode* dummy = new ListNode(-1);
      dummy->next = head;

      ListNode* pre = dummy;

      while(pre->next && pre->next->next) {
        ListNode* node1 = pre->next;
        pre->next = node1->next;
        node1->next = pre->next->next;
        pre->next->next = node1;
        pre = node1;
      }

      return dummy->next;
    }
};
