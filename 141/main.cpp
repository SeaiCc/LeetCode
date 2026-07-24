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
      // 快慢指针 a + n * b = 
      // 在环内一定相遇的原因：相对速度slow不动 fast相对slow移动一格最终相遇
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
