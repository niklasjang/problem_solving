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
		vector<string> strs; //�Է¹޴� str���� ����Ǵ� ��
		vector<vector<int> > adj(26, vector<int>(26,0)); //������� : 1�̸� ������ ��
		vector<bool> visited(26, false);
		vector<char> alpha;
		string t = "";
		for (int i = 0; i < n; i++) {
			cin >> t;
			strs.push_back(t);
		}
		//������ ��� str�鿡 ���ؼ� �տ������� �ٸ� ù ��° char�� ã�Ƽ� �̸� adj�� ����Ѵ�.
		for (int j = 1; j < strs.size(); j++) {
			int i = j - 1; 
			int limit = min(strs[i].length(), strs[j].length());
			for (int k = 0; k < limit; k++) {
				if (strs[i][k] != strs[j][k]) {
					int a = strs[i][k] - 'a';
					int b = strs[j][k] - 'a';
					adj[a][b] = 1; //a�� b���� �տ� �;���.
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

		//��� ������ ���ؼ� dfs�� �����ϸ鼭 vector�� ���ĺ��� �ִ´�.
		for (int i = 0; i < 26; i++) {
			if (!visited[i])
				dfs(adj, visited, i, alpha);
		}
		//���������� dfs�� ����� ����
		reverse(alpha.begin(), alpha.end());
		for (int i = 0; i < adj.size(); i++) {
			//cout << "i ����?" << "\n";
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