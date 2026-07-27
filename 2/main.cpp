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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int inNum = 0;

      ListNode* res = new ListNode(-1);
      ListNode* cur = res;

      while(l1 != nullptr && l2 != nullptr) {
        int curVal = (l1->val + l2->val + inNum); 
        cur->next = new ListNode(curVal % 10);
        inNum = curVal / 10;
        l1 = l1->next;
        l2 = l2->next;
        cur = cur->next;
      }

      while (l1 != nullptr) {
        // 999 + 1 
        int curVal = l1->val + inNum;
        cur->next = new ListNode(curVal % 10);
        inNum = curVal / 10;
        l1 = l1->next;
        cur=cur->next;
      }

      while (l2 != nullptr) {
        int curVal = l2->val + inNum;
        cur->next = new ListNode(curVal % 10);
        inNum = curVal / 10;
        l2 = l2->next;
        cur= cur->next;
      }

      if (inNum != 0) {
        cur->next = new ListNode(inNum);
      }

      return res->next;

      // 单个循环实现
      // while(l1 || l2) {
      //   int n1 = l1 ? l1->val : 0;
      //   int n2 = l2 ? l2->val : 0;
      //
      //   int curVal = n1 + n2 + inNum;
      //
      //   cur->next = new ListNode(curVal % 10);
      //   cur = cur->next;
      //
      //   inNum = curVal / 10;
      //   if(l1) l1 = l1->next;
      //   if(l2) l2 = l2->next;
      // }
      // if(inNum > 0) 
      //   cur->next = new ListNode(inNum);
      //
      // return res->next;
    }
};
