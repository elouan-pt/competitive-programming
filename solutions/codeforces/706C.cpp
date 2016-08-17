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

typedef long long lint;

const int MAXN = 100000;
const lint INF = 1LL << 60;

int n;
string s[MAXN];
bool les[MAXN][2][2];
lint c[MAXN], dp[MAXN][2];

bool is_les(int i, bool m, bool o) {
	string a = s[i], b = s[i + 1];
	if (m)
		reverse(a.begin(), a.end());
	if (o)
		reverse(b.begin(), b.end());
	int len = min(a.length(), b.length());
	for (int i = 0; i < len; ++i) {
		if (a[i] != b[i])
			return a[i] <= b[i];
	}
	if (a.length() > b.length())
		return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef HC_KOALAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
		clock_t start = clock();
	#endif
	
	while (cin >> n) {
		for (int i = 0; i < n; ++i)
			cin >> c[i];
		for (int i = 0; i < n; ++i)
			cin >> s[i];
		for (int i = 0; i < n - 1; ++i) {
			les[i][0][0] = is_les(i, 0, 0);
			les[i][0][1] = is_les(i, 0, 1);
			les[i][1][0] = is_les(i, 1, 0);
			les[i][1][1] = is_les(i, 1, 1);
		}
		dp[n - 1][0] = dp[n - 1][1] = 0;
		for (int i = n - 2; i >= 0; --i) {
			for (int m = 0; m <= 1; ++m) {
				lint& ans = dp[i][m];
				ans = INF;
				if (les[i][m][0])
					ans = min(ans, dp[i + 1][0]);
				if (les[i][m][1])
					ans = min(ans, c[i + 1] + dp[i + 1][1]);
			}
		}
		lint ans = min(dp[0][0], c[0] + dp[0][1]);
		if (ans == INF)
			ans = -1LL;
		cout << ans << '\n';
	}
	
	#ifdef HC_KOALAS
		fprintf(stderr, "\ntime=%.3fsec\n", 1. * (clock() - start) / CLOCKS_PER_SEC);
	#endif
	return 0;
}

