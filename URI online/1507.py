n = int(input())

for i in range(n):
    P = str(input())
    z = int(input())
    for j in range(z):
        T = str(input())
        if  P.find(T) != -1:
            print("Yes")
        else:
            print("No")
