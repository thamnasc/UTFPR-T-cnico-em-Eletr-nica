import random
lan = [0]*100
pts = [0]*6
for i in range(100):
    lan[i] = random.randrange(1,7)
    x = 0
    for j in range(6):
        x += 1
        if(lan[i] == x):
            pts[j] += 1
for i in range(6):
    print ("O dado caiu no %d %d vezes" %(i + 1, pts[i]))
input()
