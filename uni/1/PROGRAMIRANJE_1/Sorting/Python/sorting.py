# Sorting algohoritams implematation for python

# Provjeravat cemo koliko je svaki alogoritam brz
import time 

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

        # Zamjeni brojeve u listi ako nisu jednaki
        if(min != i):
            niz[i], niz[min] = niz[min], niz[i]


# Function to test 
def main():
    niz = [54, 78, 34, 2, 3, 5, 23]

    # Bubble sort
    print("niz = ", niz)
    startTime = time.time() 
    bubbleSort(niz)
    endTime = time.time()
    print("niz = ", niz)
    print(f"bubbleSort-u je trebalo : {endTime - startTime}s")

    # Resetaj niz (unesi se pointer do arraya pa ga izmjeni)
    niz = [54, 78, 34, 2, 3, 5, 23]

    # Selection sort
    print("niz = ", niz)
    startTime = time.time() 
    selectionSort(niz)
    endTime = time.time()
    print("niz = ", niz)
    print(f"selectionSort-u je trebalo : {endTime - startTime}s")

main()