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

const int MAXN = 100;
const string AEIOUY = "aeiouy";

int n, p[MAXN];
string s;

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef HC_KOALAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
		clock_t start = clock();
	#endif
	
	while (cin >> n) {
		getline(cin, s);
		for (int i = 0; i < n; ++i)
			cin >> p[i];
		getline(cin, s);
		string ans = "YES";
		for (int i = 0; i < n; ++i) {
			getline(cin, s);
			int len = s.length(), cnt = 0;
			for (int j = 0; j < len; ++j) 
				if (AEIOUY.find(s[j]) != string::npos)
					++cnt;
			if (cnt != p[i])
				ans = "NO";
		}
		cout << ans << '\n';
	}
	
	#ifdef HC_KOALAS
		fprintf(stderr, "\ntime=%.3fsec\n", 1. * (clock() - start) / CLOCKS_PER_SEC);
	#endif
	return 0;
}

