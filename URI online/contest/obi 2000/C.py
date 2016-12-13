n = -1
cout = 1
while n!=0:
	n = int(input())
	for i in range(n):
		aux = int(input())
		if aux == i+1:
			print("Teste ",count)
			print(aux)
			print()
	cout+=1