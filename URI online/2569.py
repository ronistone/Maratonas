e = input("")
print(e)
e = e.replace("7","0")		
print(e)
x = e.split(' ')
print(x)
a = x[0]
o = x[1]
b = x[2]

if o == '+':
	ans = int(a) + int(b)
	print(ans)
elif o == 'X' or o == 'x':
	ans = int(a) * int(b)
	print(ans)

ans = str(ans)
ans = ans.replace("7","0")	

print(int(ans))
