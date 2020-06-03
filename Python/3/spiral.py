import math

n = int(input())

vect = [float(i) for i in input().split()]
num_of_plech = int(input())
answer = []
for j in range(num_of_plech):
    plech = [int(i) for i in input().split()]
    sum = float(0)
    for i in range(plech[0], plech[1] + 1):
        sum += vect[i] * vect[i]
    sum = math.sqrt(sum / (plech[1] - plech[0] + 1))
    answer[j - 1] = sum


for j in range(len(answer)):
    print(answer[j - 1])

