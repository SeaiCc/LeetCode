#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

struct Node{
  int value;
  Node* next;
};

// 方法二：辅助堆栈
class MinStack {
  // 并能在常数时间内检索到最小元素的栈。
  // pop出最小值时，如何找到第二小
  // 维护大小顺序的结构 链表
private:
  stack<int> stk;
  stack<int> stkMin;
public:
    MinStack() {
      stkMin.push(INT_MAX);
    }
    
    void push(int value) {
      if(value < stkMin.top()) {
        stkMin.push(value);
      }else{
        stkMin.push(stkMin.top());
      }
      stk.push(value);
    }
    
    void pop() {
      stk.pop();
      stkMin.pop();
    }
    
    int top() {
      return stk.top();
    }
    
    int getMin() {
      return stkMin.top();
    }
};

// class MinStack {
//   // 并能在常数时间内检索到最小元素的栈。
//   // pop出最小值时，如何找到第二小
//   // 维护大小顺序的结构 链表
// private:
//   stack<Node*> stk;
//   Node* head;
// public:
//     MinStack() {
//         head = new Node(-1);
//     }
//
//     void push(int value) {
//         // 从head 遍历找到对应的位置插入
//         Node* temp = new Node(value);
//         stk.push(temp);
//         Node* cur = head;
//         while(cur->next != nullptr) {
//           if(cur->next->value >= value) break;
//           cur = cur->next;
//         }
//         // 插入
//         temp->next = cur->next;
//         cur->next = temp;
//     }
//
//     void pop() {
//         Node* temp = stk.top();
//         // 判断 是否为head后面
//         Node* cur = head;
//         while(cur->next != nullptr) {
//           if(cur->next == temp) break;
//           cur = cur->next;
//         }
//         // 移除
//         cur->next = cur->next->next;
//         stk.pop();
//     }
//
//     int top() {
//       if(stk.empty()) return -1;
//       return stk.top()->value;
//     }
//
//     int getMin() {
//       if(head->next == nullptr) return -1;
//       return head->next->value;
//     }
// };
