#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(const vector<vector<int> >& adj, vector<bool>& visited, int start) {
	visited[start] = true;
	cout << start<<" ";
	for (int i = 0; i < adj[start].size(); i++ ) {
		int next = adj[start][i];
		if(!visited[next])
			dfs(adj, visited, next);
	}
	return;
}

void bfs(const vector<vector<int> >& adj, vector<bool>& visited, int start) {
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int front = q.front();
		cout << front << " ";
		q.pop();
		for (int i = 0; i < adj[front].size(); i++) {
			int next = adj[front][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
	return;
}

int main(void) {
	int n = 0, m = 0, v = 0;
	cin >> n >> m >> v;
	vector<vector<int> > adj(n+1, vector<int>());
	vector<bool> visited(n+1, false);
	int es = 0, ee = 0;//edge start, edge end
	for (int i = 0; i < m; i++) {
		cin >> es >> ee;
		adj[es].push_back(ee);
		adj[ee].push_back(es);
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(adj, visited, v); cout << "\n";
	visited.assign(n + 1, false);
	bfs(adj, visited, v); cout << "\n";
	return 0;
}
