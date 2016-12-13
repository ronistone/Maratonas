
n = int(input())
while n != 0:
	og = filho = 0

	for i in range(n):
		a = int(input())
		b = int(input())
		if a > b:
			og +=1
		elif b > a :
			filho += 1
	print(og,filho"\n")
	n = int(input())