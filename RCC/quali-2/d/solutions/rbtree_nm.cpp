
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

const int N = 5e5 + 1;
int depth[N];
const int MOD = 1e9 + 7;
const int DEPTH = 19;
const int COLORS = 2;
int dp[N][DEPTH + 1][COLORS];

vector <int> g[N];

inline int add(int a, int b) 
{
	int sum = a + b;
	if (sum >= MOD)
		return sum - MOD;
	return sum;
}

inline void Plus(int& a, int b)
{
	a += b;
	if (a >= MOD)
		a -= MOD;
}

inline int mul(int a, int b) 
{
	return (1LL * a * b) % MOD;
}

void dfs(int v) 
{
	if (v == 0)
		return;
	for (auto to : g[v])
	{
		dfs(to);
		if (depth[v] < depth[to] + 1)
			depth[v] = depth[to] + 1;
	}
	if (depth[v] > DEPTH)
		depth[v] = DEPTH;
	int l = g[v][0];
	int r = g[v][1];
	for (int i = 0; i <= depth[v]; ++i)
	{
		if (i > 0)
		{
			dp[v][i][0] = mul(
				add(dp[l][i - 1][0], dp[l][i - 1][1]),
				add(dp[r][i - 1][0], dp[r][i - 1][1])
			);
		}
		dp[v][i][1] = mul(
			dp[l][i][0],
			dp[r][i][0]
		);
	}
}

int main() {
	int n = readInt();
	for (int i = 1; i <= n; ++i) {
		int u = readInt(), v = readInt();
		g[i].push_back(u);
		g[i].push_back(v);
	}
	dp[0][1][0] = 1; //leaves are always black
	depth[0] = 1;
	dfs(1);
	int sum = 0;
	for (int i = 0; i <= depth[1]; ++i)
		Plus(sum, dp[1][i][0]);
	writeInt(sum, '\n');
	return 0;
}