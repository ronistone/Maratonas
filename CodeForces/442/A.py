

a = input()

ans = 0
if a.find("Danil") != -1:
	ans +=1
	if a[a.find("Danil")+1:len(a)].find("Danil") != -1:
		ans+=1
if a.find("Olya") != -1:
	ans += 1
	if a[a.find("Olya")+1:len(a)].find("Olya") != -1:
		ans += 1
if a.find("Slava") != -1:
	ans += 1
	if a[a.find("Slava")+1:len(a)].find("Slava") != -1:
		ans += 1
if a.find("Ann") != -1:
	ans += 1
	if a[a.find("Ann")+1:len(a)].find("Ann") != -1:
		ans += 1
if a.find("Nikita") != -1:
	ans += 1
	if a[a.find("Nikita")+1:len(a)].find("Nikita") != -1:
		ans += 1

if ans == 1:
	print("YES")
else:
	print("NO")
