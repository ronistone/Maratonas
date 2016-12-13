count = 1
while True:
	try:
		num = input()
		entrada = input()
		lista = entrada.split(" ")
		t = 0
		f = 0
		m = 0
		for i in range(len(lista)):
			if(lista[i]==num):
				t += 1
				if(lista[i+1]=='F'):
					f+=1
				else:
					m+=1
		if count!=1:
			print()
		print("Caso %d:"%(count))
		print("Pares Iguais:",t)
		print("F:",f)
		print("M:",m)

		count+=1
	except:
		break
