/*
  n is number of vertices
  m is number of edges
  vertices are numbered 0, 1, ..., n-1
  graph[u] contains pairs {weight, neighbor}
  
  Time Complexity: O(m log n)
  Memory Complexity: O(n + m)

  NOTE: This code is not overflow safe, C++ int type can store number from -2^31 to 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, int m, int start, vector<vector<pair<int, int>>> graph) {
  int inf = 2'000'000'000;  // 2 * 10^9
  
  vector<int> dist(n, inf);
  dist[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.push({0, start});
  
  while(!pq.empty()) {
    auto [w, u] = pq.top();
    pq.pop();
    
    if(w > dist[u]) continue;
    
    for(auto &[nw, v] : graph[u]) {
      if(dist[u] + nw < dist[v]) {
        dist[v] = dist[u] + nw;
        pq.push({dist[v], v});
    }
  }
  return dist;
}
