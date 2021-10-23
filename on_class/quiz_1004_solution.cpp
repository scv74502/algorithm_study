#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution1(int no, vector<int> works)
{
    int ans = 0;
    priority_queue<int> Q(works.begin(), works.end());

    while (no--) {  // while-loop가 no만큼 돌아야 한다
        int k = Q.top();
        Q.pop();
        if (k < 1) return 0;
        Q.push(k - 1);
    }

    while (!Q.empty()) {
        int k = Q.top();
        ans += k * k;
        Q.pop();
    }

    return ans;
}

int solution2(int no, vector<int> works)
{
    int ans = 0;
    priority_queue<int> Q(works.begin(), works.end());

    while (no > 0)
    {
        int k = Q.top();
        Q.pop();
        int sub = 1;
        if (!Q.empty()) sub = Q.top();
        int diff = min(k - sub + 1, no);
        no -= diff;
        Q.push(k - diff);
    }

    while (!Q.empty()) {
        int k = Q.top();
        ans += k * k;
        Q.pop();
    }
    return ans;
}

int main(void) {
    int sol = 3;
    vector<int> vec = {3, 4, 3};
    cout << solution1(sol, vec);
    return 0;
}