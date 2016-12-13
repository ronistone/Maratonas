while True:
	try:
		entrada = input()
		maior = entrada.count(entrada[0])
		d = entrada[0]
		for i in entrada:
			if entrada.count(i)>maior:
				maior = entrada.count(i)
				d = i
			elif entrada.count(i)==maior:
				if i > d:
					d = i
		print(d)
	except:
		break;