#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[6] { 1, -1, 0, 0, 0, 0 };
int dy[6] { 0, 0, 1, -1, 0, 0  };
int dz[6] { 0, 0, 0, 0, 1, -1  };

int main(void)
{
	int xL, yL, zL;
	cin >> xL >> yL >> zL;
	vector<vector<vector<int>>> box(zL, vector<vector<int>>(yL, vector<int>(xL, 0)));
	vector<vector<vector<bool>>> visited(zL, vector<vector<bool>>(yL, vector<bool>(xL, false)));

	int nowMax = 0;
	bool flag = false;
	queue<tuple<int, int, int>> q;

	for (int i = 0; i < zL; i++) {
		for (int j = 0; j < yL; j++) {
			for (int k = 0; k < xL; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) q.push({i,j,k});
			}
		}
	}


	while (!q.empty())
	{
		int z = get<0>(q.front());
		int y = get<1>(q.front());
		int x = get<2>(q.front());
		q.pop();
		
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			// 범위를 넘었거나
			if (nx >= xL || nx < 0 ||
				ny >= yL || ny < 0 ||
				nz >= zL || nz < 0) continue;
			// 익었거나, 없거나, 이미 방문 했거나
			// 익으면 왼쪽에서 걸러주는데 필요한가?
			if (box[nz][ny][nx] < 0 || box[nz][ny][nx] == 1 || visited[nz][ny][nx] == true) continue;

			if (nowMax < box[z][y][x] + 1) nowMax = box[z][y][x];

			box[nz][ny][nx] = box[z][y][x] + 1;
			visited[nz][ny][nx] = true;
			q.push(make_tuple(nz, ny, nx));
		}
	}


	for (int i = 0; i < zL; i++) {
		for (int j = 0; j < yL; j++) {
			for (int k = 0; k < xL; k++) {
				if (box[i][j][k] == 0)
					flag = true;
			}
		}
	}

	if (nowMax > 0 && flag == false) cout << nowMax;
	else if (flag == true) cout << -1;
	else cout << 0;
}