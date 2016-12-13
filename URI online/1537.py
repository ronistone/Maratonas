#fat = [1,1,1,4,20,120,840,6720,60480,604800]
fat = [1,1,1]
atual = 1
#saida = 1
#for i in range(4,10000,1):
#	saida *= i
#	fat+=[saida%1000000009]
n = int(input())
while(n!=0):
	tam = len(fat)
	if tam<n:
		saida = atual
#		saida = fat[tam-1]
		for i in range(tam,n):
			atual = atual*(i+1)
			fat+=[atual]   #fat[i-1]*(i+1)]
	saida = fat[n-1]
#	saida = 1
#	for i in range(n,3,-1):
#		saida *= i
#	print(saida%1000000009)
	print(fat[n-1]%1000000009)
	n = int(input())
