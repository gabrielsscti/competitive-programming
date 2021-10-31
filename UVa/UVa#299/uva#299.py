def merge(v, aux, ini, meio, fim):
    aux = v.copy()
    i = ini
    j = meio+1
    inv_count = 0

    for k in range(ini, fim+1):
        if (i > meio):
            v[k] = aux[j]
            j += 1
        elif(j > fim):
            v[k] = aux[i]
            i += 1
        elif(aux[j] < aux[i]):
            v[k] = aux[j]
            j += 1
            inv_count += (meio-i + 1)
        else:
            v[k] = aux[i]
            i += 1

    return inv_count


def merge_sort(v, aux, ini, fim, inv_count=0):
    if (fim <= ini):
        return 0
    meio = ini + int((fim-ini)/2)
    inv_count += merge_sort(v, aux, ini, meio)
    inv_count += merge_sort(v, aux, meio+1, fim)
    return inv_count + merge(v, aux, ini, meio, fim)


def count_swaps(v):
    aux = v.copy()
    return merge_sort(v, aux, 0, len(v)-1)


cases = int(input())
for tests in range(cases):
    l = int(input())
    v = [int(x) for x in input().split()]
    swaps = count_swaps(v)
    print(f"Optimal train swapping takes {swaps} swaps.")
