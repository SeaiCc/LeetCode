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
    ListNode* reverseKGroup(ListNode* head, int k) {
      // 翻转链表
      ListNode* dummy = new ListNode(-1);
      dummy->next = head;
      ListNode* curHead = dummy;

      while(true){

        // 定位到下一段的第一个节点
        head = curHead->next;
        
        bool endFlag = false;

        for(int i = 0; i < k;i++){
          if(head == nullptr) {
            endFlag = true;
            break;
          }
          head = head->next;
        }
        if (endFlag == true) break;
        head = curHead->next;

        // 每次取一个节点放到curHead之后
        for(int i = 0; i < k - 1; i++){
          ListNode* move = head->next;
          head->next = head->next->next;
          //  move 放到curHead之后
          move->next = curHead->next;
          curHead->next = move;
          // 更新 head 
          // head = head->next;
        }
        curHead = head;

      }

      return dummy->next;
    }
};
