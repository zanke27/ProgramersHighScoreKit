#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void)
{
	vector<vector<int>> maps = { { 1, 1, 1, 1, 0}, {0, 0, 0, 1, 1} };
	int answer = -1;

	int hor = maps.size(); // y // 1번 문제 x, y축 이슈 
	int ver = maps[0].size(); // x

	vector<vector<bool>> visited(hor, vector<bool>(ver, false));
	vector<vector<int>> distance(hor, vector<int>(ver, 0));
	distance[0][0] = 1;

	queue<pair<int, int>> q;

	q.push(make_pair(0, 0));
	visited[0][0] = true;

	// BFS
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= hor || nx < 0 || ny >= ver || ny < 0) continue;
			if (visited[nx][ny] == true) continue;
			if (maps[nx][ny] == 0) continue;
			
			if (nx == hor - 1 && ny == ver - 1)
				cout << distance[x][y] + 1; // 2번 문제 목적지를 바로 찾는 것이기 때문에 x, y기준으로 + 1해줘야함

			distance[nx][ny] = distance[x][y] + 1;
			q.push(make_pair(nx, ny));
			visited[nx][ny] = true;

			//if (nx == hor - 1 && ny == ver - 1) cout << distance[nx][ny] + 1;
		}
	}

	//if (!distance[hor - 1][ver - 1]) answer = -1;
	//else answer = distance[hor - 1][ver - 1] + 1;

	cout << answer;
}