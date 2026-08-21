#include <stdio.h>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
  vector<vector<int>> edges;
  vector<int> vis;
  bool hasLoop = false;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      // 不能学完 有环
      // 有一对多情况 [0,1] [0,2]
      // 也有多对一 [2,1] [3,1]
      // bfs 什么时候算有环？vis = true x 一次遍历只能判断一个节点 且要恢复状态
      // 从第二个元素b开始
      // 找出无环图中末尾节点 没有依赖的课程
      int n = prerequisites.size();
      if(n == 0) return true;
      vector<vector<int>> map(numCourses, vector<int>());
      for(int i = 0; i < n; i++) {
        map[prerequisites[i][0]].push_back(prerequisites[i][1]);
      }
      vector<int> depCnt(numCourses, 0);
      // 统计 i 需要的课程 和 i被依赖的次数
      for(int i = 0; i < n; i++) {
        depCnt[prerequisites[i][0]]++; // 依赖数量
      }
      // numCount[i][0] == 0 表示不需要依赖，
      // 从头开始遍历，遇到 numCount[i][0] == 0 的节点就可以结束该分支
      // 1. bfs 超时
      // vector<int> vis(numCourses, 0);
      // for(int i = 0; i < n; i++) {
      //   vis[i] = 1;
      //   if(findLoop(prerequisites[i][1], map, vis)) return false;
      //   vis[i] = 0;
      // }

      // 2. 从 numCount[i][0] == 0 开始逐步加入不是环的点, 超时
      // bool updateFlag = false;
      // while(updateFlag) {
      //   updateFlag = false;
      //   for(int i = 0; i < numCourses; i++) {
      //     // 如果 map[i] 里的依赖节点都是0 ，则把i也更新成0
      //     // 这里可以优化成 从依赖节点 逆向找 
      //     if(depCnt[i] == 0) continue;
      //     int j = 0;
      //     for(; j < map[i].size(); j++) {
      //       if(depCnt[map[i][j]] != 0) break;
      //     }
      //     if(j != map[i].size()) continue;
      //     depCnt[j] = 0;
      //     updateFlag = true;
      //   }
      // }
      //
      // // 无法继续更新了，检查depCnt是否还有依赖
      // for(int i = 0; i < numCourses; i++) {
      //   if(depCnt[i] != 0) return false;
      // }
      // return true;

      // 3. 
      //  bool updateFlag = true;
      // while(updateFlag) {
      //   updateFlag = false;
      //   for(auto& [k, deps] : map) {
      //     int i = 0;
      //     for(; i < deps.size(); i++) {
      //       if(depCnt[dep[i]] != 0 ) break;
      //     }
      //     if(i == deps.size()) {
      //       depCnt[k] == 0;
      //       map.earse(k);
      //       updateFlag = true;
      //     }
      //   }
      // }
      // // 无法继续更新了，检查depCnt是否还有依赖
      // for(int i = 0; i < numCourses; i++) {
      //   if(depCnt[i] != 0) return false;
      // }
      // return true;
      //
    
      // 4. vis 扩展一个值 0 未遍历 该条路径 1遍历过 2 遍历完 
      vis.resize(numCourses);
      edges.resize(numCourses);
      for(const auto& pre : prerequisites) {
        edges[pre[0]].push_back(pre[1]);
      }

      for(int i = 0; i < numCourses && !hasLoop; i++) {
        if(vis[i] == 0) dfs(i);
      } 
      return !hasLoop;
      
    }

    void dfs(int i) {
      vis[i] = 1;
      for(auto v: edges[i]) {
        if(vis[v] == 1) {
          hasLoop = true;
          return;
        }else if(vis[v]== 0) {
          dfs(v);
          if(hasLoop) return;
        }
      }
      vis[i] = 2;
    }

    bool findLoop(int j, vector<vector<int>>& map, vector<int>& vis) {
      if(vis[j] == 1) return true; // 又遍历到之前的节点说明有环
      vis[j] = 1;
      for(auto next : map[j]) {
        if(findLoop(next, map, vis)) return true;
      }
      vis[j] = 0;
      return false;

    }
};
