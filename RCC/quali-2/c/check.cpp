#include "testlib.h"  
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 1;

int perm[N];
int rev[N];
int answ[N];
int taken[N];
int n;

int parse(InStream &answer) {
	for (int i = 1; i <= n; ++i)
		taken[i] = -1;
	for (int i = 1; i <= n; ++i) {
		answ[i] = answer.readInt(1, n);
		if (answ[i] != perm[i] && perm[i] != 0)
			quitf(_wa, "Incorrect permutation. %d-th number violates input rule.", i);
		if (taken[answ[i]] != -1)
			quitf(_wa, "Incorrect permutation. %d-th number is equal to %d-th.", i, taken[answ[i]]);
		taken[answ[i]] = i;
		rev[answ[i]] = i;
	}
	int counter = 0;
	for (int i = 1; i <= n; ++i) {
		if (rev[i] != i) {
			int id1 = rev[i];
			int id2 = i;
			swap(rev[answ[id1]], rev[answ[id2]]);
			swap(answ[id1], answ[id2]);
			++counter;
		}
	}
	return counter;
}

int check(int testnum)
{
	n = inf.readInt();
	for (int i = 1; i <= n; ++i) {
		perm[i] = inf.readInt();
	}
	int ja = ans.readInt();
	int ja2 = parse(ans);
	if (ja2 != ja) {
		quitf(_fail, "Testcase #%d: Jury has incorrect permutation", testnum);
	}
	int pa = ouf.readInt();
	int pa2 = parse(ouf);
	if (pa2 != pa) {
		quitf(_wa, "Testcase #%d: Expected %d swaps in permutation, found %d", testnum, pa, pa2);
	}
	if (ja > pa)
		quitf(_wa, "Testcase #%d: Jury has better answer. Expected %d, found %d", testnum, ja, pa);
	if (ja < pa)
		quitf(_fail, "Testcase #%d: Participant has better answer. Jury has %d, participant has %d", testnum, ja, pa);
}

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);
	int t = inf.readInt();
	for (int i = 0; i < t; ++i) {
		check(i);
	}
	quitf(_ok, "%d answers are OK", t);
	return 0;
}