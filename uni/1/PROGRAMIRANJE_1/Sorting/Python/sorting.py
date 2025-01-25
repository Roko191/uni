# Sorting algohoritams implematation for python

import time 
import random

# Implementacija za bubble sort
# O: N^2
def bubbleSort(niz):
    # Vanjski loop za prolazenje kroz listu
    # Kako brojevi zavrasaju na tocnim mjestim tako mi smanjumo broj iteracija
    for n in range(len(niz) - 1, 0 , -1):
        # Unutarnji loop da provjerimo elemente
        for i in range(n):
            # Zamjeni elemente ako je element veci od elementa ispred sebe
            if niz[i] > niz[i + 1]:
                niz[i], niz[i+1] = niz[i+1], niz[i]

# Implemetacija za selection sort
# O: N^2
def selectionSort(niz):
    # Prolazimo kroz sve elemente liste
    for i in range(0, len(niz) - 1):
        # Postavi indeks za najmanju vrijednost na trenutni i
        min = i
        # Provjeravamo jedan broj iza indeksa pa dalje 
        for j in range(i + 1, len(niz)):
            # Ako element koji gledamo manji od minimalnog postavi taj element kao minimalni
            if(niz[j] < niz[min]):
                min = j

        # Stavi broj na indeksu min na najnize moguce mjesto (svako koje nije vec sortirano)
        if(min != i):
            niz[i], niz[min] = niz[min], niz[i]

# Implementacija za insertion sort
# O: N^2
def insertionSort(niz):
    # Listaj kroz niz od 1
    for i in range(1, len(niz) - 1):
        j = i

        # Dok nedodemo do kraja i dok je elemnt nalijevo veci zamjenjuj brojeve
        while ( j > 0 and niz[j - 1] > niz[j]):
            niz[j] = niz[j - 1]
            j = j - i

# !!! BONUS !!!
# Funkcija koja generira array s zadanmi brojem clanova
# Nasumicni brojevi su u rangu od 1 do 1000
def arrayGen(nNumber: int, niz):
    for i in range(0, nNumber):
        niz.append(random.randint(1, 1000))


# Function to test 
def main():
    nNumber = 10

    niz = []
    arrayGen(nNumber, niz)

    # Bubble sort
    print("niz = ", niz)
    startTime = time.time() 
    bubbleSort(niz)
    endTime = time.time()
    print("niz = ", niz)
    print(f"bubbleSort-u je trebalo : {endTime - startTime}s")

    # Resetaj niz (unesi se pointer do arraya pa ga izmjeni)
    niz = []
    arrayGen(nNumber, niz)

    # Selection sort
    print("niz = ", niz)
    startTime = time.time() 
    selectionSort(niz)
    endTime = time.time()
    print("niz = ", niz)
    print(f"selectionSort-u je trebalo : {endTime - startTime}s")

    niz = []
    arrayGen(nNumber, niz)

    # Insertion sort
    print("niz = ", niz)
    startTime = time.time() 
    selectionSort(niz)
    endTime = time.time()
    print("niz = ", niz)
    print(f"inesrtionSort-u je trebalo : {endTime - startTime}s")

main()