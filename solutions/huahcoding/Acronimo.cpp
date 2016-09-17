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

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef HC_KOALAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
		clock_t start = clock();
	#endif
	
	int T;
	string s;
	cin >> T;
	getline(cin, s);
	for (int tc = 1; tc <= T; ++tc) {
		getline(cin, s);
		string ans = "";
		istringstream is(s);
		string p;
		while (is >> p) {
			if (p == "and" || p == "of" || p == "the") {
				continue;
			}
			ans += toupper(p[0]);
		}
		cout << ans << '\n';		
	}
	
	#ifdef HC_KOALAS
		fprintf(stderr, "\ntime=%.3fsec\n", 1. * (clock() - start) / CLOCKS_PER_SEC);
	#endif
	return 0;
}

