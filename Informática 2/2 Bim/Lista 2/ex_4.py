kg = 0
tot = 0
pkg = 0
sn = ""
des = 0
print ("""	            Até 5 Kg	              Acima de 5 Kg
Filé Duplo       R$ 4,90 por Kg          R$ 5,80 por Kg - Digite 1
Alcatra          R$ 5,90 por Kg          R$ 6,80 por Kg - Digite 2
Picanha          R$ 6,90 por Kg          R$ 7,80 por Kg - Digite 3""")
car = input ("Escolha a carne: ")


if (car == '1'):
    kg = float (input ("Insira a quantidade de Filé Duplo (Kg): "))
    if (kg <= 5):
        pkg = 4.9
    else:
        pkg = 5.8
    sn = input ("Utiliza cartão Tabajara? (S/N): ")
    sn = sn.upper()
    if (sn == 'S'):
        des =  (0.05 * kg * pkg)
        tot = (pkg * kg) - des
    else :
        tot = (pkg * kg)
    print ("\n\nFilé Duplo - %.2fKg \nCartão Tabajara: %s \nDesconto: R$%.2f\nValor total R$%.2f" %(kg, sn, des, tot))


	
elif (car == '2'):
    kg = float (input ("Insira a quantidade de Alcatra (Kg): "))
    if (kg <= 5):
        pkg = 5.9
    else:
        pkg = 6.8
    sn = input ("Utiliza cartão Tabajara? (S/N): ")
    sn = sn.upper()
    if (sn == 'S'):
        des =  (0.05 * kg * pkg)
        tot = (pkg * kg) - des
    else :
        tot = (pkg * kg)
    print ("\n\nAlcatra - %.2fKg \nCartão Tabajara: %s \nDesconto: R$%.2f\nValor total R$%.2f" %(kg, sn, des, tot))


elif (car == '3'):
    kg = float (input ("Insira a quantidade de Picanha (Kg): "))
    if (kg <= 5):
        pkg = 6.9
    else:
        pkg = 7.8
    sn = input ("Utiliza cartão Tabajara? (S/N): ")
    sn = sn.upper()
    if (sn == 'S'):
        des =  (0.05 * kg * pkg)
        tot = (pkg * kg) - des
    else :
        tot = (pkg * kg)
    print ("\n\nPicanha - %.2fKg \nCartão Tabajara: %s \nDesconto: R$%.2f\nValor total R$%.2f" %(kg, sn, des, tot))
