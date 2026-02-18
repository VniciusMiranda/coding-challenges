sleepTime = []

while(True):

    H1, M1, H2, M2 = map(int, input().split(" "))

    if H1 == M1 == H2 == M2 == 0: break

    if H1 == 0: H1 = 24
    if H2 == 0: H2 = 24

    endTime = H2*60 + M2
    startTime = H1*60 + M1

    if endTime <= startTime: endTime += 24*60
    
    sleepTime.append(abs(endTime - startTime))


for i in sleepTime:
    print(i)
