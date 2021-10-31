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


def sortDegree(s):
    ret = count_swaps(s)
    # calcule aqui para string s o n m e r o
    # total de trocas necess rias para ficar ordenada
    return ret


m = int(input())
for tests in range(m):
    input()  # pula uma linha em branco da entrada
    col, lin = map(int, input().split())
    # l coluna e linha
    v = []
    for i in range(lin):
        s = str(input())
        v.append((sortDegree(list(s)), s))

    # como adicionar o s no v?
    # vai precisar usar a f u n o sortDegree!
    # como manter e s t v e l as strings quando elas tiverem o mesmo sortDegree ?
    # tem que ordenar o v
    # agora imprimir as strings de v ordenadas
    # esse c d i g o abaixo para imprimir uma linha em branco a p s todos, menos o ltimo caso de teste
    v.sort(key=lambda x: x[0])
    for pair in v:
        print(pair[1])
    if tests < m-1:
        print()
