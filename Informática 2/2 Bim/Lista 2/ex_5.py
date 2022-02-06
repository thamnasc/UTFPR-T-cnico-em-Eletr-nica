nome = input ("Insira seu nome: ")
if (len (nome) >= 3):
    ida = int (input ("Isira sua idade: "))
    if (ida > 0 and ida < 150):
        sal = float (input ("Insira seu salario: "))
        if (sal > 0):
            sex = input ("Insira seu genero (F/M): ")
            sex = sex.upper()
            if (sex == 'F'):
                est = input ("Insira seu estado civil (S/C/V/D): ")
                est = est.upper()
                if ((est != 'S') and (est != 'C') and (est != 'V') and (est != 'D')):
                    print ("Estado civil invalido!")
                else:
                    print ("\n\n%s tem %d anos, recebe R$%.2f por mês, é %s e possui estado civil: %s" %(nome, ida, sal, sex, est))          
                    input()
            elif (sex == 'M'):
                est = input ("Insira seu estado civil: ")
                est = est.upper()
                if ((est != 'S') and (est != 'C') and (est != 'V') and (est != 'D')):
                    print ("Estado civil invalido!")
                else:
                    print ("\n\n%s tem %d anos, recebe R$%.2f por mês, é %s e possui estado civil: %s" %(nome, ida, sal, sex, est))
                    input()
            else:
                print ("Genero invalido!")
        else:
            print ("Salario invalido!")
    else:
        print ("Idade invalido!")
else:
    print ("Nome invalido!")
