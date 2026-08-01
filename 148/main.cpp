#include <stdio.h>
#include <iostream>
#include <unordered_map>

using namespace std;

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = head;
        while(true) {
            // 找到第一个逆序位置
            while (cur->next != nullptr && cur->val <= cur->next->val) {
                cur = cur->next;
            }
            if (cur->next == nullptr) break;
            
            head = dummy;
            while(head->next != nullptr && head->next->val < cur->next->val) 
                head = head->next;
            // 插入到head节点之后
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            temp->next = head->next;
            head->next = temp;
            // 移动cur节点
        }

        return dummy->next;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}