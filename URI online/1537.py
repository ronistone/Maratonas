n = int(input())
fato = [1,1,2,6,24,120]

def fat(n):
	if n < len(fato):
		return fato[n]
	else:
		saida = fato[len(fato)-1]
		for i in range(len(fato),n+1):
			saida *= i
			fato.append(saida)
		return fato[n]

while n!=0:
	saida = int(fat(n)/2)
	saida = int(saida/3)
	print(saida%1000000009)
	n = int(input())
