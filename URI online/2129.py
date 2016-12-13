count = 0
def fatorial(n):
	final = 1
	for i in range(1,n+1):
		final = final * i 
		while(final%10==0):
			final = int(final /10)
	return final%10
		

def saida(n):
	final = fatorial(n)
	if count != 1:
                print()
	print("Instancia",count)
	print(final)

while True:
	try:
		fat = int(input())
		count= count+1
		saida(fat)
	except:
		break
