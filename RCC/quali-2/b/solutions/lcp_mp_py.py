from math import gcd

def solve():
	a, b, c, d = map(int, input().split())
	q = b*d // gcd(b, d)
	a *= q // b
	c *= q // d
	p = a // gcd(a, c) * c
	g = gcd(p, q)
	print(p // g, q // g)

t = int(input())
for _ in range(t):
	solve()
