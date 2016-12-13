memo = [0,1]
soma = [0,1]
topo = 1
n = int(input())

for i in range(n):
	entrada = input()
	e = entrada.split(" ")
	num = [int(numero) for numero in e]
	
	if(topo<num[1]):
		for j in range(topo+1,num[1]+1):
			aux= memo[0]+memo[1]
			memo[0] = memo[1]
			memo[1] = aux
			if memo[1]>99:
				memo[1] = memo[1]%100
			soma += [(soma[topo]+memo[1])]
			topo+=1	
	print(soma[num[1]]-soma[num[0]-1])
