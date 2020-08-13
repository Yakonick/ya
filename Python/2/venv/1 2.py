n = int(input())
dictionary = set()

for i in range(n):
    dictionary.add(input().lower())

l = int(input())
answer = set()

for i in range(l):
    temp = input().lower().split()
    for j in range(len(temp)):
        if temp[j] not in dictionary:
            answer.add(temp[j])

for i in answer:
    print(i)