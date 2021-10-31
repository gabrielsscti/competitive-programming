# Using modified QuickSort

def sort(v):
    sort_3way(v, 0, len(v)-1)


def sort_3way(v, ini, fim):
    if (fim <= ini):
        return
    lt = ini
    i = ini+1
    gt = fim
    a = v[ini]
    while i <= gt:
        if (v[i] < a):
            v[lt], v[i] = v[i], v[lt]
            lt += 1
            i += 1
        elif(v[i] > a):
            v[i], v[gt] = v[gt], v[i]
            gt -= 1
        else:
            i += 1
    sort_3way(v, ini, lt-1)
    sort_3way(v, gt+1, fim)


answer = []

while True:
    n = int(input())
    if n == 0:
        break
    v = [int(x) for x in input().split()]
    sort(v)
    for i in range(len(v)):
        if (i != len(v)-1):
            print(v[i], end=' ')
        else:
            print(v[i])

# Using count sort

MAX_N = 2000000
MAX_INTEGER = 99

while True:
    n = int(input())
    if n == 0:
        break
    count = [0]*(MAX_INTEGER+1)
    v = [int(x) for x in input().split()]
    for number in v:
        count[number] += 1

    ans = []
    for i in range(1, MAX_INTEGER+1):
        for j in range(count[i]):
            ans.append(i)

    for i in range(len(ans)):
        if (i != len(ans)-1):
            print(ans[i], end=' ')
        else:
            print(ans[i])
