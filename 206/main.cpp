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
    ListNode* reverseList(ListNode* head) {
      ListNode* curHead = head;
      ListNode* curTail = head;
      while(curTail->next != NULL) {
        // curTail 拆下放到curHead 头部

        ListNode* tmp = curTail->next;
        curTail->next = curTail->next->next;
        // 移动到头部并更新头
        tmp->next = curHead;
        curHead = tmp;
      }

      return curHead;
    }
};
