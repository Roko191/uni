Imports System

Module func
    Sub Ispis(ByRef niz As Integer())
        For index As Integer = 0 To niz.GetUpperBound(0)
            ' Ako je zadnji element liste ne ispisuj zvjezdicu
            If index = niz.GetUpperBound(0)
                Console.Write(niz(index))
                Exit For 
            End If
            Console.Write($"{niz(index)} * ")
        Next
        ' Nova linija samo da izgleda ljepse
        Console.WriteLine()
    End Sub
End Module


Module Zadaci
    Sub runZad1()
        ' ZADATAK 1
        Dim broj As String
        broj = Console.ReadLine()
        While True
            If broj <> CInt(broj):
                Console.WriteLine($"Broj {broj} nije prirodan broj. Pokusaj ponovno: ")
                broj = Console.ReadLine() 
                Continue While
            Else
                If CInt(broj) Mod 3 = 0 AndAlso CInt(broj) Mod 7  = 0:
                    Console.WriteLine($"Broj {broj} je djeljiv s 7 i 3")
                    Exit While
                Else
                    Console.WriteLine($"Broj {broj} je prirodan ali nije djeljiv s 7 i 3")
                    Exit While
                End If
            End If
        End While
    End Sub

    Sub runZad2()
        ' Dvije primjer liste
        Dim niz1 As Integer() = New Integer(2) {1, 2, 3}
        Dim niz2 As Integer() = New Integer(5) {1, 2, 3, 4, 5, 6}

        'Pozivanje funkcije
        func.Ispis(niz1)
        func.Ispis(niz2)
    End Sub

    Sub runZad3()
        Dim broj As Integer
        Console.WriteLine("Upsi broj redova: ")
        broj = Console.ReadLine()
        
        ' Za svaki rad napisi odgovrajuci broj zvjezdica
        ' Broj redova je odreden broj varijablom
        For linesNum As Integer = 1 To broj
            For starsNum As Integer = 1 To linesNum
                Console.Write("*")
            Next

            'Kad je ispisano dovoljno zvjezdica prebaci u novi red
            Console.WriteLine()
        Next

        ' Nova linija da izgleda ljepse
        Console.WriteLine()
    End Sub
End Module


Module Program
    Sub Main()
        ' Zadaci.runZad1()
        ' Zadaci.runZad2()
        ' Zadaci.runZad3()
    End Sub
End Module
