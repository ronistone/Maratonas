n = int(input());
f = 1
for i in range(1,n+1):
	f = f*i
s = str(f)
cont = 0
for i in range(len(s)-1,0,-1):
	if s[i]!='0':
		break;
	cont = cont+1
print(f)
print(cont)