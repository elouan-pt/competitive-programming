#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 2001;

int n, m, a[MAXN];
vector<int> b[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef HC_KOALAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
		clock_t start = clock();
	#endif
	
	while (cin >> n >> m) {
		for (int i = 0; i <= m; ++i)
			b[i].clear();
		for (int i = 0, aa; i < n; ++i) {
			cin >> aa;
			a[i] = aa;
			if (aa >= 1 && aa <= m)
				b[aa].push_back(i);
			else
				b[0].push_back(i);
		}
		int ans = n / m, cnt = 0;
		for (int i = 1; i <= m; ++i) {
			while (b[i].size() < ans) {
				int idx = 0, mag = 0;
				if (!b[0].empty()) {
					idx = 0;
				} else {
					for (int j = 0; j <= m; ++j) {
						if (b[j].size() > mag) {
							mag = b[j].size();
							idx = j;
						}
					}
				}
				b[i].push_back(b[idx][0]);
				b[idx].erase(b[idx].begin());
				++cnt;
			}
		}
		for (int i = 1; i <= m; ++i) {
			int sz = b[i].size();
			for (int j = 0; j < sz; ++j)
				a[b[i][j]] = i;
		}
		cout << ans << ' ' << cnt << '\n';
		for (int i = 0; i < n; ++i)
			cout << a[i] << ' ';
		cout << '\n';
	}
	
	#ifdef HC_KOALAS
		fprintf(stderr, "\ntime=%.3fsec\n", 1. * (clock() - start) / CLOCKS_PER_SEC);
	#endif
	return 0;
}

