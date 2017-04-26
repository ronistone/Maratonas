    
#include <iostream>
#include <string>
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

const int N = 1e6 + 1;
int perm[N];
int rev[N];
bool visited[N];

vector <pair <int, int> > chains;

void answer(int n) {
    vector <int> questions;
    for (int i = 1; i <= n; ++i) {
        if (perm[i] == 0)
            questions.push_back(i);
    }
    for (int i = 0; i < questions.size(); ++i)
    {
        int from = questions[i];
        int to = questions[(i + 1) % questions.size()];
        perm[from] = to;
    }
    fill(visited + 1, visited + n + 1, 0);
    int answer = n;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            --answer;
            for (int j = i; !visited[j]; j = perm[j])
                visited[j] = true;
        }
    }
    writeInt(answer, '\n');
    for (int i = 1; i <= n; ++i)
        writeInt(perm[i], " \n"[i == n]);
}

int solve()
{
    int n = readInt();
    chains.clear();
    for (int i = 1; i <= n; ++i)
        rev[i] = 0,
        visited[i] = 0;
    for (int i = 1; i <= n; ++i)
        perm[i] = readInt(),
        rev[perm[i]] = i,
        visited[i] = 0;
    for (int i = 1; i <= n; ++i) {
        if (rev[i] == 0 && perm[i] != 0 && !visited[i])
        {
            int end = i;
            for (; perm[end] != 0; end = perm[end])
                visited[end] = true;
            chains.push_back({i, end});
        }
    }                      
    if (chains.size() == 0)
    {                      
        answer(n);
        return 0;
    }                      
    while (chains.size() > 1) {
        auto it2 = chains[chains.size() - 1];
        auto it = chains[chains.size() - 2];
        int e2 = it2.second;
        int s2 = it2.first;
        int e1 = it.second;
        int s1 = it.first;
        chains.pop_back();
        chains.pop_back();
        perm[e1] = s2;
        chains.push_back({s1, e2});
    }
    vector <int> questions;
    auto lr = *chains.begin();
    int chain_start = lr.first;
    int chain_end = lr.second;
    for (int i = 1; i <= n; ++i) {
        if (perm[i] == 0 && i != chain_end)
            questions.push_back(i);
    }
    while (!questions.empty()) {
        chain_end = perm[chain_end] = questions.back();
        questions.pop_back();
    }
    perm[chain_end] = chain_start;
    answer(n);
    return 0;
}

int main() {
    int t = readInt();
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}