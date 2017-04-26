
#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

namespace fastinput
{
	/** Interface */

	inline int readChar();
	template <class T = int> inline T readInt();
	template <class T = double> inline T readDouble();
	template <class T> inline void writeInt(T x, char end = 0);
	inline void writeChar(int x);
	inline void writeWord(const char *s);

	/** Read */

	static const int buf_size = 16384;

	inline int getChar() {
		static char buf[buf_size];
		static int len = 0, pos = 0;
		if (pos == len)
			pos = 0, len = fread(buf, 1, buf_size, stdin);
		if (pos == len)
			return -1;
		return buf[pos++];
	}

	inline int readChar() {
		int c = getChar();
		while (c <= 32)
			c = getChar();
		return c;
	}

	template <class T>
	inline T readInt() {
		int s = 1, c = readChar();
		T x = 0;
		if (c == '-')
			s = -1, c = getChar();
		while ('0' <= c && c <= '9')
			x = x * 10 + c - '0', c = getChar();
		return s == 1 ? x : -x;
	}

	template <class T>
	inline T readDouble() {
		int s = 1, c = readChar();
		T x = 0;
		if (c == '-')
			s = -1, c = getChar();
		while ('0' <= c && c <= '9')
			x = x * 10 + c - '0', c = getChar();
		if (c == '.')
			c = getChar();
		T y = 1;
		while ('0' <= c && c <= '9')
			y /= 10, x += y * (c - '0'), c = getChar();
		return s == 1 ? x : -x;
	}

	/** Write */

	static int write_pos = 0;
	static char write_buf[buf_size];

	inline void writeChar(int x) {
		if (write_pos == buf_size)
			fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
		write_buf[write_pos++] = x;
	}

	template <class T>
	inline void writeInt(T x, char end) {
		if (x < 0)
			writeChar('-'), x = -x;

		char s[24];
		int n = 0;
		while (x || !n)
			s[n++] = (char)('0' + x % 10), x /= 10;
		while (n--)
			writeChar(s[n]);
		if (end)
			writeChar(end);
	}

	inline void writeWord(const char *s) {
		while (*s)
			writeChar(*s++);
	}

	struct Flusher {
		~Flusher() {
			if (write_pos)
				fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
		}
	} flusher;
}

using namespace fastinput;

const int N = 1e5 + 1;

int Rr[2 * N + 1]; auto R = Rr + N + 1;
int Ll[2 * N + 1]; auto L = Ll + N + 1;
int ps[2 * N + 1]; auto pos = ps + N + 1;

int nxt[N];
int prv[N];
int pref[N];

struct Query {
	int l, r, block;
};

bool cmp(const Query &a, const Query &b) {
	if (a.block != b.block)
		return a.block < b.block;
	return a.r < b.r;
}

Query Q[N];
int curl, curr;
int answer = 0;

void addLeft(int position) {
	int l = L[pref[position]];
	int r = R[pref[position]];
	if (r != -1)
	{
		l = position;
		answer = max(answer, r - l);
	}
	else
	{
		r = l = position;
	}
	L[pref[position]] = l;
	R[pref[position]] = r;
}

void addRight(int position) {
	int l = L[pref[position]];
	int r = R[pref[position]];
	if (r != -1)
	{
		r = position;
		answer = max(answer, r - l);
	}
	else
	{
		r = l = position;
	}
	L[pref[position]] = l;
	R[pref[position]] = r;
}

void rollLeft(int position) {
	int l = L[pref[position]];
	int r = R[pref[position]];
	l = nxt[l];
	if (l != -1 && l <= curr);
	else
		l = r = -1;
	L[pref[position]] = l;
	R[pref[position]] = r;
}

void clearLeft(int position) {
	L[pref[position]] = R[pref[position]] = -1;
}

void clear(int n) {
	fill(pref, pref + n + 1, 0);
	fill(nxt,  nxt  + n + 1, -1);
	fill(pos - n, pos + n + 1, -1);
	while (curl <= curr)
		clearLeft(curl++);
}

int main() {
	int t = readInt();
	for (int i = 0; i < t; ++i) {
		int n = readInt();
		int k = sqrt(n); 
		clear(n);
		fill(R - n, R + n + 1, -1);
		fill(L - n, L + n + 1, -1);
		for (int j = 0; j < n; ++j)
			pref[j + 1] = pref[j] + readInt();
		for (int j = 0; j <= n; ++j)
		{
			int p = pos[pref[j]];
			if (p != -1)
				nxt[p] = j;
			prv[j] = p;
			pos[pref[j]] = j;
		}
		int q = readInt();
		int m = 0;
		long long totalans = 0;
		for (int j = 0; j < q; ++j)
		{
			int l = readInt() - 1, r = readInt();
			if (r - l < k) 
			{
				curl = l;
				curr = l - 1;
				answer = 0;
				while (curr < r)
					addRight(++curr);
				totalans += answer;
				while (curl <= curr)
					clearLeft(curl++);
			}
			else
			{
				Q[m++] = { l, r, (l + k) / k * k};
			}
		}
		sort(Q, Q + m, cmp);
		curl = Q[0].block;
		answer = 0;
		curr = Q[0].block - 1;
		int last = -1;
		int border = -1;
		for (int j = 0; j < m; ++j)
		{
			int l = Q[j].l;
			int r = Q[j].r;
			if (Q[j].block != last)
			{
				while (curl <= curr)
					clearLeft(curl++);
				border = 0;
				for (int q = j; q < m && Q[j].block == Q[q].block; ++q)
					if (border < Q[q].l)
						border = Q[q].l;
				curl = border;
				curr = curl - 1;
				answer = 0;
				last = Q[j].block;
			}
			while (curr < r)
				addRight(++curr);

			int keep = answer;
			
			while (curl > l)
				addLeft(--curl);

			totalans += answer;

			while (curl < border)
				rollLeft(curl++);

			answer = keep;
		}
		//cout << "Answer: " << totalans << endl;
		writeInt(totalans, '\n');		
	}
	
	return 0;
}