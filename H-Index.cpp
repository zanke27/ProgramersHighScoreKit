#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> citations = { 0,1,2,3,4 };
	int answer = 0;

	sort(citations.begin(), citations.end(), greater<int>());

	if (citations[0] == 0) return 0;

	for (int i = 0; i < citations.size(); i++) {
		if (citations[i] <= answer) break;
		answer++;
	}

	cout << answer;

	// 0, 1, 3, 5, 6
	// �ڿ��� ���� �Ǻ�
	// Size - ���� �ε��� >= ���� ���� break; end

	// 6, 5, 3, 1, 0
	// 1 >= 6
	// 
	// �տ������� �Ǻ�
	// i+1 >= citations[i] = return citations[i];
}