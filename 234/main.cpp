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
    bool isPalindrome(ListNode* head) {
      if (!head) return false;
      if(head->next == nullptr) return true;

      ListNode* slow = head;
      ListNode* fast = head->next;
      // 1 2 2 1 fast: 2 -> 1 slow: 1 -> 2
      // 12321 fast: 2 -> 2 slow: 1 -> 2 
      vector<int> half;
      while(fast != nullptr && fast->next != nullptr) {
        half.push_back(slow->val);
        slow = slow->next;
        fast = fast->next->next;
      }
      
      if (fast) 
        half.push_back(slow->val);
      slow = slow->next;

      for(int i = half.size() - 1; i >= 0; i--){
        if (slow->val != half[i]) return false;
        slow = slow->next;
      }
      return true;
    }
};
