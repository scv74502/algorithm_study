#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int digit16(int v, int d) {
    // ���� ���� v �� 16���� d ��° ���ڸ� ��ȯ�ϴ� �Լ�
    // ���� ��� v �� ���� 78320238 (= 0x04ab126e) �̰� d �� 1 �̶�� 6 �� ��ȯ
    // ���� ��� v �� ���� 78320238 (= 0x04ab126e) �̰� d �� 4 ��� 11 (= 0xb) �� ��ȯ
    v = v >> d * 4;
    return v & 0xf;
}

void countingSort16(vector<pair<int, string> >& v, int d)
{
    vector<pair<int, string> > b(v.size());
    int c[16];
    for (int i = 0; i < 16; i++)
        c[i] = 0;

    for (int j = 0; j < v.size(); j++)
    {
        c[digit16(v[j].first, d)] = c[digit16(v[j].first, d)] + 1;
    }

    for (int i = 1; i < 16; i++)
    {
        c[i] = c[i] + c[i - 1];
    }

    for (int j = v.size()-1; j >= 0; j--)
    {
        b[c[digit16(v[j].first, d)]] = v[j];
        c[digit16(v[j].first, d)] = c[digit16(v[j].first, d)] - 1;
    }
}

int main(void) {
    int n;
    vector<pair<int, string> > v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int d;
        string s;
        cin >> d >> s;
        v.push_back(pair<int, string>(d, s));
    }
    //radixsort
    for (int d = 0; d < 8; d++) countingSort16(v, d);

    for (int i = 0; i < n; i++) {
        cout << v[i].first << ' ' << v[i].second << endl;
    }
    return 0;
}