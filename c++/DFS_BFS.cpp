#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
//
int n, m, v;
queue<int> q;
stack<int> s;
vector<int> vec[1001];
// int graph[1001][1001] = { 0, };
int visited[1001] = {
    0,
};
//
// void dfs(int cur) {
//	cout << cur << " ";
//	for (int next = 1; next <= n; next++) {
//		if (graph[cur][next] == 1 && visited[next] == 0) {
//			visited[next] = 1;
//			dfs(next);
//		}
//	}
//}
// int main() {
//
//	cin >> n >> m >> v;
//	for (int i = 0; i < m; i++) {
//		int a, b;
//		cin >> a >> b;
//		graph[a][b] = 1;
//		graph[b][a] = 1;
//	}
//	visited[v] = 1;
//	dfs(v);
//	cout << "\n";
//	memset(visited, 0, sizeof(visited));
//
//	visited[v] = 1;
//	q.push(v);
//
//	while (!q.empty()) {
//		int cur = q.front(); q.pop();
//		cout << cur << " ";
//		for (int next = 1; next <= n; next++) {
//			if (graph[cur][next] == 1 && visited[next] == 0) {
//				visited[next] = 1;
//				q.push(next);
//			}
//		}
//	}
//
//}

void dfs(int cur) {
  cout << cur << " ";
  sort(vec[cur].begin(), vec[cur].end());
  for (int i = 0; i < vec[cur].size(); i++) {
    int next = vec[cur][i];
    if (visited[next] == 0) {
      visited[next] = 1;
      dfs(next);
    }
  }
}
int main() {
  cin >> n >> m >> v;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  visited[v] = 1;
  dfs(v);
  cout << "\n";
  memset(visited, 0, sizeof(visited));

  visited[v] = 1;
  q.push(v);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    cout << cur << " ";
    sort(vec[cur].begin(), vec[cur].end());
    for (int i = 0; i < vec[cur].size(); i++) {
      int next = vec[cur][i];
      if (visited[next] == 0) {
        visited[next] = 1;
        q.push(next);
      }
    }
  }
}