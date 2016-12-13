def fat(n):
	if n == 0:
		return 1
	else:
		return n*fat(n-1)
def main():
	while True:
		try:
			a = input()
			saida = fat(len(a))
			aux = ""
			for i in a:
				if(aux.find(i)==(-1)):
					saida /= fat(a.count(i))
					aux +=i
					print(aux)
			print(int(saida%(pow(10,9)+7)))
		except:
			break
main()