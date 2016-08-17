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

const int MAXN = 100000;

int n, q, x[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef HC_KOALAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
		clock_t start = clock();
	#endif
	
	while (cin >> n) {
		for (int i = 0; i < n; ++i)
			cin >> x[i];
		sort(x, x + n);
		cin >> q;
		for (int i = 0, m; i < q; ++i) {
			cin >> m;
			int ans = upper_bound(x, x + n, m) - x;
			cout << ans << '\n';
		}
	}
	
	#ifdef HC_KOALAS
		fprintf(stderr, "\ntime=%.3fsec\n", 1. * (clock() - start) / CLOCKS_PER_SEC);
	#endif
	return 0;
}

