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

		// queue��ȸ�ϸ鼭 Ÿ�̸� �߰�
		// ��ȸ�ϸ鼭 Ÿ�̸� if�� üũ
		// �����ϸ� pop���� ���ְ� truckWeight��ŭ nowBWeight �߰�
	// answer q��ȸ �� ������ �߰�
	// �ٸ�MaxWeight
	// �ٸ�NowWeight > truckWeight �� Ʈ���� �ٸ��� ����
	// q��ȸ timer ++ �߰��� if(�ٸ����� == Ÿ�̸�) 
	// bLength == timer ��
	// truck pop and �ٸ� Weight - truckWeight

}