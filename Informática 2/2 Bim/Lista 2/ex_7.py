x = int (input ("Insira um valor inteiro (n): "))
print ("\nS = 1/1 + 2/3 + 3/5 + 4/7 + 5/9 + ... + n/m")
tot = 0
y = -1
for i in range (x):
    y += 2
    tot += (i+1)/(y)
    
print ("\nSoma total: %.2f" %tot)
input()
