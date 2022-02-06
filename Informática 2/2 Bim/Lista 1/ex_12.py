str1 = input("Insira um texto: ")
str2 = input("Insira outro texto: ")
print ("\nA String 1: '%s' possui %d caracteres!" %(str1, len(str1)))
print ("A String 2: '%s' possui %d caracteres!" %(str2, len(str2)))
if (len(str1) == len(str2)):
    print ("As duas strings possuem tamanhos iguais!")
else:
    print ("As duas strings não possuem tamanhos iguais!")
if (str1 == str2):
    print ("As duas strings são iguais!")
else:
    print ("As duas strings não são iguais!")
input()
