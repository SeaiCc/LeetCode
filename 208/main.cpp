#include <stdio.h>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Trie {
private:
  vector<Trie*> children;
  bool isEnd;
public:
    //  Trie 视作树的节点
    //  使用ASCII 值 转换为int 
    Trie() {
        // 声明什么数据结构？
        children = vector<Trie*>(26);
        isEnd = false;
    }
    
    void insert(string word) {
        // 插入单词能不同吗
        Trie* node = this;
        for(auto ch : word) {
          ch -= 'a';
          if(node->children[ch] == nullptr) {
            // 创建新节点
            node->children[ch] = new Trie();
          }
          node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        // 区分前缀和存在，沿节点搜索
        // word最后一个单词对应的节点标志为true search成功
        Trie* node = searchPrefix(word);
        if(node == nullptr) return false;
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
      Trie* node = searchPrefix(prefix);
      if(node == nullptr) return false;
      return true;
    }

    Trie* searchPrefix(string word) {
      // 1. search failed - return nullptr
      // 2. search success - return node (isEnd is true)
      // 3. search success - return node (isEnd is false)
      Trie* node = this;
      for(auto ch : word) {
        ch -= 'a';
        if(node->children[ch] == nullptr) {
          return nullptr;
        }
        node = node->children[ch];
      }
      return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
