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
	
	while (cin >> n) {
		cin >> s;
		int cnt = 0, mag = 0, words = 0;
		bool in_parentheses = 0;
		for (int i = 0; i < n; ++i) {
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
				++cnt;
			} else {
				if (in_parentheses && cnt > 0)
					++words;
				else
					mag = max(mag, cnt);
				if (s[i] == '(')
					in_parentheses = 1;
				else if (s[i] == ')')
					in_parentheses = 0;
				cnt = 0;
			}
		}
		mag = max(mag, cnt);
		cout << mag << ' ' << words << '\n'; 
	}
	
	#ifdef HC_KOALAS
		fprintf(stderr, "\ntime=%.3fsec\n", 1. * (clock() - start) / CLOCKS_PER_SEC);
	#endif
	return 0;
}

