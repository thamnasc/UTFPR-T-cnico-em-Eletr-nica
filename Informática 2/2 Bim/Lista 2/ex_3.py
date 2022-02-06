li = [0]*5
li[0] = input ("Telefonou para a vítima? (S/N): ")
li[1] = input ("Esteve no local do crime? (S/N): ")
li[2] = input ("Mora perto da vítima? (S/N): ")
li[3] = input ("Devia para a vítima? (S/N): ")
li[4] = input ("Já trabalhou com a vítima? (S/N): ")
sn = 0
print ("\n")
for i in range (5):
    li[i] = li[i].upper()
    if (li[i] == 'S'):
        sn += 1
if (sn == 5):
    print ("Assassino!")
elif ((sn == 4) or (sn == 3)):
    print ("Cúmplice!")
elif (sn == 2):
    print ("Suspeita!")
else:
    print("Inocente!")

input()
