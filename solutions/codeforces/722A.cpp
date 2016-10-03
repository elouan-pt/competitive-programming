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

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef HC_KOALAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
		clock_t start = clock();
	#endif
	
	while (scanf("%d\n", &n) == 1) {
		int h, m;
		scanf("%d:%d\n", &h, &m);
		if (m >= 60)
			m %= 10;
		if (n == 12) {
			if (h % 10 == 0)
				h = 10;
			else if (h > 12)
				h %= 10;
		}
		if (n == 24 && h >= 24)
			h %= 10;
		if (h < 10)
			printf("0");
		printf("%d:", h);
		if (m < 10)
			printf("0");
		printf("%d\n", m);
	}
	
	#ifdef HC_KOALAS
		fprintf(stderr, "\ntime=%.3fsec\n", 1. * (clock() - start) / CLOCKS_PER_SEC);
	#endif
	return 0;
}

