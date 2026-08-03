#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
// splice(pos, *this, it)
// 将迭代器 it 指向的节点移动到 pos 位置之前（例如 pos = begin() 即为移到头部）

private:
    list<pair<int, int>> items; // 保存K v 用于同步
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int cap;
    int curNum;

public:
    // O(1): map
    // 最久未使用，每次访问移动到尾部 O（1），移出尾部元素
    LRUCache(int capacity) {
        curNum = 0;
        this->cap = capacity;
        cache = {};
        items = {};
    }
    
    int get(int key) {
        // cout << "get" << key <<endl;
        auto it = this->cache.find(key);
        if(it != cache.end()) {
            // list 移动到头部
            this->items.splice(this->items.begin(), this->items, it->second);
            return it->second->second;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        // cout << "put" << key << value <<endl;
        auto it = this->cache.find(key);
        if(it != cache.end()) {
            it->second->second = value;
            this->items.splice(this->items.begin(), this->items, it->second);
        }else{
            // 判断容量
            if(curNum == this->cap) {
                // cout << "remove" << this->items.back().first <<endl;
                // 移除list 清理map
                this->cache.erase(this->items.back().first);
                this->items.pop_back();
                curNum--;
            }
            // 在头部新增
            this->items.emplace_front(key, value);
            cache[key] = this->items.begin();
            curNum++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
