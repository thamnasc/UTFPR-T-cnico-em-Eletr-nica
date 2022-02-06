nt = [0]*2
tot = 0
for i in range (len (nt)) :
    nt[i] = float (input ("Insira a sua %dº nota (0 - 10): " %(i +1)))
    tot += nt[i]
if ((tot / 2) == 10) :
    print ("Aprovado com Distinção!")
elif ((tot / 2) >= 7) :
    print ("Aprovado!")
else :
    print ("Reprovado!")
input()
