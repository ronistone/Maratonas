def euclides_mdc(dividendo, divisor): #maximo divisor comum pelo metodo de euclides
    while divisor != 0:
        temp = divisor
        divisor = dividendo % divisor
        dividendo = temp    
    return dividendo
     
def euclides_recursivo_mdc(dividendo, divisor):
    if divisor == 0:
        return dividendo
    else:
        return euclides_recursivo_mdc(divisor, dividendo % divisor)
 
n = int(input())
for i in range(n):
	entrada = input()
	num = entrada.split(" ")
	a = euclides_recursivo_mdc(int(num[0]),int(num[1]))
	for i in range(int(num[0])+1,int(num[1])):
		if(i<int(num[0])+10):
			a = euclides_recursivo_mdc(a,i)
		else:
			break
	print(a)
