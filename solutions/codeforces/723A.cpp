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

int x[3];

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef HC_KOALAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
		clock_t start = clock();
	#endif
	
	while (cin >> x[0] >> x[1] >> x[2]) {
		int mig = min(x[0], min(x[1], x[2]));
		int mag = max(x[0], max(x[1], x[2]));
		int ans = 300;
		for (int i = mig; i <= mag; ++i) {
			int sum = 0;
			for (int j = 0; j < 3; ++j)
				sum += abs(x[j] - i);
			ans = min(ans, sum);
		}
		cout << ans << '\n';
	}
	
	#ifdef HC_KOALAS
		fprintf(stderr, "\ntime=%.3fsec\n", 1. * (clock() - start) / CLOCKS_PER_SEC);
	#endif
	return 0;
}

