#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
	vector<int> progress = { 93, 30, 55 };
	vector<int> speeds = { 1, 30, 5 };
	vector<int> answer;

	queue<int> q;

	int index, day, num;
	index = day = num = 0;

	for (int i = 0; i < progress.size(); i++)
		q.push(progress[i]);

	while (!q.empty())
	{
		while (!q.empty() && q.front() + day * speeds[index] >= 100)
		{
			q.pop();
			index++;
			num++;
		}

		if (num > 0)
		{
			answer.push_back(num);
			num = 0;
		}
		day++;
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i];
	}
}