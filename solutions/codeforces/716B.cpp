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

const int ALPHA = 26;

bool was[ALPHA];
string s;

string check(int l, int h) {
	memset(was, 0, sizeof was);
	string ret = "", need = "";
	int cnt = 0;
	for (int i = l; i < h; ++i) {
		if (s[i] != '?')
			was[s[i] - 'A'] = 1;
		else
			++cnt;
		ret += s[i];
	}
	for (int i = 0; i < ALPHA; ++i)
		if (!was[i]) need += 'A' + i;
	if (cnt == need.length()) {
		int pos = 0;
		for (int i = 0; i < ALPHA; ++i) {
			if (ret[i] == '?')
					ret[i] = need[pos++];
		}
	} else
		ret = "-1";
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef HC_KOALAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
		clock_t start = clock();
	#endif
	
	while (cin >> s) {
		int len = s.length();
		if (len < ALPHA)
			cout << "-1\n";
		else {
			string ans = "";
			int pos = -1;
			for (int i = 0; i < len - ALPHA + 1; ++i) {
				ans = check(i, i + ALPHA);
				if (ans != "-1") {
					pos = i;
					break;
				}
			}
			if (pos == -1)
				cout << "-1\n";
			else {
				for (int i = 0; i < pos; ++i)
					cout << (s[i] == '?' ? 'A' : s[i]);
				cout << ans;
				for (int i = pos + ALPHA; i < len; ++i)
					cout << (s[i] == '?' ? 'A' : s[i]);
				cout << '\n';
			}
		}
	}
	
	#ifdef HC_KOALAS
		fprintf(stderr, "\ntime=%.3fsec\n", 1. * (clock() - start) / CLOCKS_PER_SEC);
	#endif
	return 0;
}

