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

int n;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef HC_KOALAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
		clock_t start = clock();
	#endif
	
	while (cin >> n >> s) {
		int cur = 0, cnt = 0;
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'B') {
				++cur;
			} else {
				if (cur != 0)
					ans.push_back(cur);
				cur = 0;
			}
		}
		if (cur != 0)
			ans.push_back(cur);
		int sz = ans.size();
		cout << sz << '\n';
		for (int i = 0; i < sz; ++i)
			cout << ans[i] << ' ';
		cout << '\n';
	}
	
	#ifdef HC_KOALAS
		fprintf(stderr, "\ntime=%.3fsec\n", 1. * (clock() - start) / CLOCKS_PER_SEC);
	#endif
	return 0;
}

