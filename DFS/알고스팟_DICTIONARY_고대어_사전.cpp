/*
종만북 833페이지

인생 첫 위상정렬문제, 풀이 다 보고 구현만 1시간 걸림.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void dfs(const vector<vector<int> >& adj, vector<bool>& visited, int x, vector<char> & alpha) {
	visited[x] = true;
	for (int i = 0; i < adj.size(); i++) {
		if (adj[x][i] && !visited[i]) {
			dfs(adj, visited, i, alpha);
		}
	}
	alpha.push_back(x);
	return;
}

int main(void) {
	int tc = 0;
	cin >> tc;
	while (tc--) {
		int n = 0; cin >> n;
		vector<string> strs; //입력받는 str들이 저장되는 곳
		vector<vector<int> > adj(26, vector<int>(26,0)); //인접행렬 : 1이면 인접한 것
		vector<bool> visited(26, false);
		vector<char> alpha;
		string t = "";
		for (int i = 0; i < n; i++) {
			cin >> t;
			strs.push_back(t);
		}
		//인접한 모든 str들에 대해서 앞에서부터 다른 첫 번째 char를 찾아서 이를 adj에 기록한다.
		for (int j = 1; j < strs.size(); j++) {
			int i = j - 1; 
			int limit = min(strs[i].length(), strs[j].length());
			for (int k = 0; k < limit; k++) {
				if (strs[i][k] != strs[j][k]) {
					int a = strs[i][k] - 'a';
					int b = strs[j][k] - 'a';
					adj[a][b] = 1; //a가 b보다 앞에 와야함.
					break;
				}
			}
		}

		/*for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				cout << adj[i][j];
			}
			cout << "\n";
		}*/

		//모든 정점에 대해서 dfs를 진행하면서 vector에 알파벳을 넣는다.
		for (int i = 0; i < 26; i++) {
			if (!visited[i])
				dfs(adj, visited, i, alpha);
		}
		//위상정렬은 dfs를 뒤집어서 구현
		reverse(alpha.begin(), alpha.end());
		for (int i = 0; i < adj.size(); i++) {
			//cout << "i 수행?" << "\n";
			for (int j = i+1; j < adj.size(); j++) {a
				if (adj[alpha[j]][alpha[i]]) {
					cout << "INVALID HYPOTHESIS" << "\n";
					alpha = vector<char>();
					i = 300;
					break;
				}
			}
		}
		for (int i = 0; i < alpha.size(); i++) {
			cout << char(alpha[i]+'a');
		}
		cout << "\n";
	}
	return 0;
}