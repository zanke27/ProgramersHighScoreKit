#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xLen, yLen;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int main(void)
{
	cin >> yLen >> xLen;

	vector<vector<int>> map(xLen, vector<int>(yLen, 0)); // 맵
	vector<vector<int>> dist(xLen, vector<int>(yLen, 0)); // 이동 거리
	vector<vector<bool>> visited(xLen, vector<bool>(yLen, false)); // 이동 여부

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;

	for (int i = 0; i < yLen; i++) {
		string temp = "";
		cin >> temp;
		for (int j = 0; j < xLen; j++) {
			map[j][i] = temp[j] - '0';
		}
 	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= xLen || nx < 0 || ny >= yLen || ny < 0) continue;
			if (visited[nx][ny] == false && map[nx][ny] > 0)
			{
				visited[nx][ny] = true;
				map[nx][ny] = map[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	cout << map[xLen - 1][yLen - 1];
}