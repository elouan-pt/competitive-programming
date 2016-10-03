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

const int MAXN = 101;

int n, k, cnt[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef HC_KOALAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
		clock_t start = clock();
	#endif
	
	while (cin >> n >> k) {
		string s;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			++cnt[s.length()];
		}
		cin >> s;
		int target = s.length(), sum = 0;
		for (int i = 0; i < MAXN; ++i) {
			sum += cnt[i];
			if (i == target) {
				int mig = sum - cnt[i], mag = sum - 1;
				mig += mig / k * 5 + 1;
				mag += mag / k * 5 + 1;
				cout << mig << ' ' << mag << '\n';
				break;
			}
		}
	}
	
	#ifdef HC_KOALAS
		fprintf(stderr, "\ntime=%.3fsec\n", 1. * (clock() - start) / CLOCKS_PER_SEC);
	#endif
	return 0;
}

