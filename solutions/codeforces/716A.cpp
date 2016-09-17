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

int n, c;

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef HC_KOALAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
		clock_t start = clock();
	#endif
	
	while (cin >> n >> c) {
		int prev, cur, ans = 1;
		cin >> prev;
		for (int i = 0; i < n - 1; ++i) {
			cin >> cur;
			if (cur - prev <= c)
				++ans;
			else
				ans = 1;
			prev = cur;
		}
		cout << ans << '\n';
	}
	
	#ifdef HC_KOALAS
		fprintf(stderr, "\ntime=%.3fsec\n", 1. * (clock() - start) / CLOCKS_PER_SEC);
	#endif
	return 0;
}

