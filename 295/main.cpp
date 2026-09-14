#include <cstdio>
#include <iostream>

// struct Node {
//   int val;
//   Node* pre;
//   Node* next;
// };
//
// class MedianFinder {
//   // 每次只加入一个元素，数组数量奇偶交替
//   // 1. 当前奇数 加入一个值 新的中位数为 当前中位数 + 另一个值平均
//   // 2. 当前偶数 新中位数为 原先两个值 以及新值三选一
//   // 数组插入 O（n）
//   // 双向链表 维护两个节点，大于等于中位数的最小节点 小于等于中位数的最大节点
// private:
//   Node* head ;
//   Node* l;
//   Node* r;
// public:
//     MedianFinder() {
//       head = new Node(-1);
//       l = head;
//       r = head;
//     }
//
//     void addNum(int num) {
//       Node* temp = new Node(num);
//       if (head == l && head == r) {
//         head->next = temp;
//         temp->pre = head;
//         l = temp;
//         r = temp;
//         return;
//       }
//
//       // 加入的值在l 左边， l左移
//       if (num <= l->val) {
//         // 向左找位置
//         Node* cur = l;
//         while(cur->pre != head && cur->pre->val >= num) {
//           cur = cur->pre;
//         }
//         // 插入
//         temp->pre = cur->pre;
//         temp->next = cur;
//         cur->pre->next = temp;
//         cur->pre = temp;
//         if (l == r) 
//           l = l->pre;
//         else
//           r = l;
//       }else if (num >= r->val) {
//         // 向左找位置
//         Node* cur = l;
//         while(cur->next != nullptr && cur->next->val <= num) {
//           cur = cur->next;
//         }
//         //插入
//         temp->next = cur->next;
//         temp->pre = cur;
//         if(cur->next != nullptr) cur->next->pre = temp;
//         cur->next = temp;
//         if (l == r) 
//           r = r->next;
//         else
//           l = r;
//       }else {
//         // 此时l 和 r必然不相等， 插入到中间
//         temp->next = r;
//         temp->pre = l;
//         l->next = temp;
//         r->pre = temp;
//         l = temp;
//         r = temp;
//       }
//     }
//
//     double findMedian() {
//       if (l == r) {
//         return l->val;
//       }else{
//         return (l->val + r->val) / 2.0;
//       }
//     }
// };
//
//  双堆法
class MedianFinder {
  // 每次只加入一个元素，数组数量奇偶交替
  // 1. 当前奇数 加入一个值 新的中位数为 当前中位数 + 另一个值平均
  // 2. 当前偶数 新中位数为 原先两个值 以及新值三选一
  // 数组插入 O（n）
  // 双向链表 维护两个节点，大于等于中位数的最小节点 小于等于中位数的最大节点
private:
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
      maxHeap.push(num); // 重新排序 
      minHeap.push(maxHeap.top());
      maxHeap.pop();
      // 保证size max >= min 
      if (maxHeap.size() < minHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop;
      }
    }
    
    double findMedian() {
      if (minHeap.size() < maxHeap.size()) return maxHeap.top();
      return (minHeap.top() + maxHeap.top()) / 2.0;
    }
};

// 3. 有序集合+双指针（平衡二叉搜索树addNum  o logn）
