entrada = input()
valor = entrada.split(" ")
num = [int(numero) for numero in valor]
ini,fim = num

aux = ""
cont = 0
for i in range(ini,fim+1):
	aux = str(i)
	verifica = True
	for j in range(aux):
		if(aux.count(j)>1):
			verifica = False
			break
		if verifica:
			cont+=1
			
print(cont)
