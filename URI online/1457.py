nTests = int(raw_input())
for nt in xrange(nTests):
    n = raw_input()
    k = n.count('!')
    n = int(n.rstrip('!'))

    fact = n
    mult = 1
    while True:
        if n - (mult * k) < 1:
        	break
        else:
        	fact *= n - (mult * k)
        	mult += 1	    



	print fact
