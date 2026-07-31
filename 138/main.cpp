#include <stdio.h>
#include <isotream>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 1. map 记录节点
        // 2. 利用原链表
        // 在原列表每个节点之后复制一个节点
        if(head == nullptr) return nullptr;
        Node* cur = head;
        while(cur != nullptr) {
            Node* temp = new Node(cur->val);
            temp->next = cur->next;
            cur->next = temp;
            // 此时链表没有构造好，先不处理random 
            cur = temp->next;
        }

        
        cur = head;
        // cur 不为空 cur->next 不为空
        while(cur != nullptr) {
            Node* temp = cur->next;
            if (cur->random == nullptr) {
                temp->random = nullptr;
            }
            else{
                temp->random = cur->random->next;
            }
            cur = temp->next;
        }

        Node* dummyHead = new Node(-1);
        dummyHead->next = head->next;
        cur = head;
        while(cur != nullptr) {
            Node* temp = cur->next;
            cur->next = temp->next;
            if (temp->next != nullptr){
                temp->next = temp->next->next;
            }
            cur = cur->next;
        }

        return dummyHead->next;

    }
};
