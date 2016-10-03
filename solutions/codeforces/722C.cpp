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

const int MAXN = 100002;

int n, p[MAXN];
lint a[MAXN], tree[MAXN], ans[MAXN];
set<int> s;

lint read(int i) {
    lint sum = 0;
    while(i > 0) sum += tree[i], i -= i & -i;
    return sum;
}
 
void update(int i, lint v) {
    while(i <= n) tree[i] += v, i += i & -i;
}

lint read(int i, int j) {
	return read(j) - read(i - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef HC_KOALAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
		clock_t start = clock();
	#endif
	
	while (cin >> n) {
		s.clear();
		tree[0] = tree[n + 1] = 0;
		s.insert(0);
		s.insert(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			tree[i] = 0;
			s.insert(i);
		}
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
		}
		lint mag = 0;
		for (int i = n; i >= 1; --i) {
			ans[i] = mag;
			update(p[i], a[p[i]]);
			s.erase(p[i]);
			auto sup = s.upper_bound(p[i]);
			auto low = sup;
			--low;
			mag = max(mag, read(*low + 1, *sup - 1));
		}
		for (int i = 1; i <= n; ++i)
			cout << ans[i] << '\n';
	}
	
	#ifdef HC_KOALAS
		fprintf(stderr, "\ntime=%.3fsec\n", 1. * (clock() - start) / CLOCKS_PER_SEC);
	#endif
	return 0;
}

