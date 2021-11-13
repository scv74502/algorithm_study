#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<int> c, int money)
{
	// 동전이 최대 10개에 금액이 최대 1000원, 1-10 x 1-1000 접근 가능한 인덱스 생성
	int dp[11][1001] = {0};
	dp[0][0] = 1;	// 0원 동전의 0원 거슬러주는 제일 초기 케이스는 1

	// 0부터 동전개수 + 1까지 반복함
	for (int idx = 0; idx <= c.size(); idx++)

		// 1부터 동전개수 -1까지, 사실상 0원 제외한 모든 동전에 경우의 수에 대하여 실행
		for (int i = 1; i <= c.size() - 1; i++)
		{
			int coinval = c[i];
			for (int j = 0; j <= money; j++)
			{
				// 이중 반복문에서 i번째에 i번째 동전의 경우, j에서 j원을 거슬러 줄 때의 수를 생각함
				// j가 i번 동전(현재 동전)모다 작으면 이전 동전으로 거슬러주는 경우의 수를 가져옴
				if (j < coinval)
					dp[i][j] = dp[i - 1][j];
				else
					// j == coinval 시에는 이전 동전으로 거슬러주는 수 + 현 동전으로 0원을 거슬러주는 수
					dp[i][j] = dp[i][j - coinval] + dp[i - 1][j];
			}
		}
	return dp[c.size()-1][money];
}

int main()
{
	int rpt;
	cin >> rpt;	// rpt만큼 반복함
	for (int i = 0; i < rpt; i++)
	{
		int n, money;
		cin >> money;	// 금액 입력받기
		cin >> n;
		vector<int> coins = {0};	// 처음에 0 포함하는 벡터로 동전 저장, 0은 동잔이 0원 의미

		for (int i = 0; i < n; i++)
		{

			int value;
			cin >> value;
			coins.push_back(value);
		}
		// 벡터에 동전들 값 입력받고, 그 동전값들 벡터와 금액을 solution함수에 투입
		cout << solution(coins, money) << "\n";
	}
	return 0;
}