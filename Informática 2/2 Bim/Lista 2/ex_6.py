import sys
gb = [0]*10
print ("Professor!")
for i in range (len (gb)):
    gb[i] = input("Insira o gabarito da %d° questão: " %(i + 1))
    gb[i] = gb[i].upper()
    if (gb[i] != 'A' and gb[i] != 'B' and gb[i] != 'C' and gb[i] != 'D' and gb[i] != 'E'):
        print ("Só é possivel colocar (A/B/C/D/E) no gaberito!")
        input()
        sys.exit()
qt = int (input ("Quantos alunos vão corrigir a prova: "))
not_aluno = [[0]*10]*qt
tot = [0]*qt
for i in range (qt):
    print ("\n"*100)
    print ("%d° aluno!" %(i + 1))
    for j in range (len (gb)):
        not_aluno[i][j] = input ("Qual sua resposta da questao %d: " %(j + 1))
        not_aluno[i][j] = not_aluno[i][j].upper()
        if (not_aluno[i][j] == gb[j]):
            tot[i] += 1
print ("Em %d alunos, a maior nota foi: %d, a menor: %d e a media: %.2f " %(qt, max(tot), min(tot), (sum(tot)/qt)))
input()
