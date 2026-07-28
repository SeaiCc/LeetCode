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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* fooHead = new ListNode(-1);
        fooHead->next = head;
        head = fooHead;
      for(int i = 0; i < n; i++) {
          head = head->next;
      }

      // 此时head位于第n个节点 再移动 sz - n步后到
      // 末尾节点
      // 同时从fooHead开始移动 到sz-n 个节点，删除下一个节点即可
      // 1 2 3 4 
      // n = 2 第n个 2 倒数第sz - n个 是 3
      // n = 3 第n个 3 倒数第sz - n个 是 4
      // 移动sz - n 后
      ListNode* nodeDel = fooHead;
      while(head->next) {
        head = head->next;
        nodeDel = nodeDel->next;
      }

      nodeDel->next = nodeDel->next->next;

      return fooHead->next;
    }
};
