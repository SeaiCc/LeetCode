#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 1. 建立n个Node节点指向每一个list
        // 2. 挨个合并
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        int n = lists.size();


        // while(true) {
        //     // 遍历 lists的头部
        //     for(int i = 0; i < n; i++) {
        //         // 每次只能找一个，遍历浪费， 最小堆
        //     }
        // }

        auto cmp = [](ListNode* a, ListNode* b) {return a->val < b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        // 先把头节点加入
        for(int i = 0; i < n; i++) {
            minHeap.push(lists[i]);
        }

        while(!minHeap.empty()) {
            cur->next = minHeap.top();
            cur = cur->next;
            minHeap.pop();
            if(cur->next != nullptr)
                minHeap.push(cur->next);
        }
        return dummy->next;
    }
};
