#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

void merge(vector<pair<int, string> >& v, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<pair<int, string> > v1;
    vector<pair<int, string> > v2;

    for (int i = 0; i < n1; i++) {
        v1.push_back(v[p + i]);
    }

    for (int j = 0; j < n2; j++) {
        v2.push_back(v[q + j]);
    }

    //v1.insert(v1.begin(), pair<int, string>(-INT_MAX, ""));
    //v2.insert(v2.begin(), pair<int, string>(-INT_MAX, ""));
    v1.push_back(pair<int, string>(INT_MAX, ""));
    v2.push_back(pair<int, string>(INT_MAX, ""));

    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++) {
        if (v1[i].first <= v2[j].first) {
            v[k] = v1[i];
            i = i + 1;
        }
        else {
            v[k] = v2[j];
            j = j + 1;
        }
    }
};

void mergesort(vector<pair<int, string> >& v, int p, int r) {
    if (p < r) {
        int q = ((p + r) / 2);
        mergesort(v, p, q);
        mergesort(v, q + 1, r);
        merge(v, p, q, r);
    }
};

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

    // merge sort
    mergesort(v, 0, v.size() - 1);

    for (int i = 0; i < n; i++) {
        cout << v[i].first << ' ' << v[i].second << endl;
    }

    return 0;
}