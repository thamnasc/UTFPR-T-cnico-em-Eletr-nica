qt_vend = int (input ("Insira a quantidade de vendedores: "))
ganh = [0]*qt_vend
tot = [0]*qt_vend
ganho = [0]*9


for i in range (qt_vend):
    ganh[i] = float (input ("Vendedor %d, insira em R$ as vendas da semana: " %(i + 1)))
    tot[i] = 200 + (ganh[i] * 0.09)
    vl = 100
    for j in range(9):
        vl += 100
        if (tot[i] >= vl and tot[i] <= (vl+99)):
            ganho[j] += 1
        elif (tot[i] >= 1000):
            ganho[8] += 1
            break   
x = 200
print ("\n" *100)
for i in range(9):
    print ("R$%d - R$%d %d vendedores" %(x, (x+99), ganho[i]))
    x += 100
input()
