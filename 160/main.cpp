#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 不能逆序
        // 快慢指针
        // a -> c   b -> c 
        // a + c + b == b + c + a 
        //
        ListNode* curA = headA;
        ListNode* curB = headB;
        bool firstA = true;
        bool firstB = true;
        while(curA && curB) {
          cout << curA->val << curB->val << endl;
          if (curA == curB) return curA;
          curA = curA -> next;
          curB = curB -> next;
          if(!curA && firstA) {
            firstA = false;
            curA = headB;
          }

          if(!curB && firstB) {
            firstB = false;
            curB = headA;
          }
        }
        return NULL;
    }
};

ListNode* createLinkedList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

int main(int argc, char* argv[]){
  vector<int> aVals = {4, 1, 8, 4, 5};
  vector<int> bVals = {5, 6, 1, 8, 4, 5};

  ListNode* listA = createLinkedList(aVals);
  ListNode* listB = createLinkedList(bVals);

  Solution solu;
  ListNode* res = solu.getIntersectionNode(listA, listB);

  if (res) cout << res->val << endl;

}
