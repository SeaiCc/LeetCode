#include <stdio.h>
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
      // 1.在环内一定相遇的原因：相对速度slow不动 fast相对slow移动一格最终相遇
      // 2. slow进圈时刻, fast相对位置若为k，
      // 当时间 i 时， fast位置 (k + 2 * i) % n = (k + i + i) % n
      // 找一个抵消k的 i : -k + n 
      // fast位置 ： （n + i） % n = i 与slow位置一致,一定相遇
      if (!head) return false;
      ListNode* fast = head->next;
      ListNode* slow = head;
      while(fast != nullptr && slow != nullptr) {
        if(fast == slow) {
          return true;
        }
        if(fast->next == nullptr) return false;
        slow = slow->next;
        fast = fast->next->next;
      }
      return false;
    }
};
