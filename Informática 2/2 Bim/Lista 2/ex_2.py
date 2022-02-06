nt = [0]*3
tot = 0
for i in range (len (nt)) :
    nt[i] = float (input ("Insira o %dº lado do triângulo: " %(i +1)))
if ( (nt[0] + nt[1] > nt[2]) and (nt[2] + nt[1] > nt[0]) and (nt[0] + nt[2] > nt[0])):
    if ( (nt[0] == nt[1] ) and (nt[1] == nt[2]) ):
	    print ("Equilátero!")
    elif ( (nt[0] == nt[1] ) or (nt[1] == nt[2]) or (nt[0] == nt[2])):
	    print ("Isósceles!")
    else:
	    print ("Escaleno!")
else:
    print ("Não é um triângulo!")
input()
