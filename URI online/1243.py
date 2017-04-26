try:
	while(1):
		e = input()
		e = e.split(' ')
		ans = 0
		count = 0
		for a in e:
			sum = 0
			falha = False
			if a.count('.') > 1 or len(a) < 1 or (a.count('.')==1 and len(a) == 1):
				continue
			for i in range(0,len(a)):
				x = a[i]
				if i!= len(a)-1 and x == '.':
					falha = True
					break
				elif x >= '0' and x <= '9':
					falha = True
					break
				elif (x >= 'a' and x <= 'z') or (x >= 'A' and x <= 'Z'):
					sum +=1
			if not falha:
				ans += sum
				count += 1
		if count != 0:
			ans = int(ans/count)
		else:
			ans = 0
		
		if ans <= 3:
			print("250")
		elif ans <= 5:
			print("500")
		else:
			print("1000")
except Exception as error:
	pass
					
			
				
