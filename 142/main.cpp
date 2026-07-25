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
    ListNode *detectCycle(ListNode *head) {
      // 不允许修改链表
      // 快慢指针，两次相遇位置
      // 分清：第k个节点， 走了 k - 1 步
      // slow入环时，走了k-1步，两者相距k，再走i步之后相遇，则：
      // （k + 2 * i） % n = i， 只要令 i = n - k 即可 n为环中节点个数
      // 如果这时让slow再走一步，然后fast和slow再走k-1步，就都会回到入口点

      if(head == nullptr) return nullptr;
      ListNode* fast = head->next;
      ListNode* slow = head;

      while(fast != nullptr && fast->next != nullptr) {
        if(fast == slow) break;
        slow=slow->next;
        fast = fast->next->next;
      }
      if(slow != fast) return nullptr;
      slow=slow->next;

      fast = head;
      while(fast != slow){
        fast=fast->next;
        slow=slow->next;
      }

      return fast;
    }
};
