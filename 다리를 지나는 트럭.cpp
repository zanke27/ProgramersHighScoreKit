#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	int bridge_length = 10;
	int weight = 12;
	vector<int> truck_weights = { 4,4,4,2,2,1,1,1,1 };
	int answer = 0;

	int size = 0;
	int nowBWeight = weight;
	pair<int, int> truck;
	queue<int> qRestTruck;
	queue<pair<int, int>> qMoveTruck;

	for (int i = 0; i < truck_weights.size(); i++)
		qRestTruck.push(truck_weights[i]);

	while (!qRestTruck.empty() || !qMoveTruck.empty())
	{
		if (!qRestTruck.empty() && nowBWeight - qRestTruck.front() >= 0)
		{
			nowBWeight -= qRestTruck.front();
			qMoveTruck.push(make_pair(qRestTruck.front(), 0));
			qRestTruck.pop();
		}

		size = qMoveTruck.size();

		for (int i = 0; i < size; i++)
		{
			qMoveTruck.front().second++;
			if (qMoveTruck.front().second == bridge_length)
			{
				nowBWeight += qMoveTruck.front().first;
				qMoveTruck.pop();
			}
			else
			{
				qMoveTruck.push(qMoveTruck.front());
				qMoveTruck.pop();
			}
		}
		answer++;
	}
	answer++;

	cout << answer;

		// queue순회하면서 타이머 추가
		// 순회하면서 타이머 if문 체크
		// 성공하면 pop으로 빼주고 truckWeight만큼 nowBWeight 추가
	// answer q순회 할 때마다 추가
	// 다리MaxWeight
	// 다리NowWeight > truckWeight 이 트럭이 다리에 진입
	// q순회 timer ++ 추가로 if(다리길이 == 타이머) 
	// bLength == timer ↑
	// truck pop and 다리 Weight - truckWeight

}