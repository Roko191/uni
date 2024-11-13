Imports System


Module Zadaci
    Sub runZad1()
        ' ZADATAK 1
        Dim n As Integer
        Console.WriteLine("n:")
        n = Console.ReadLine() - 1
        Dim niz As Integer() = New Integer(n) {}
        For cnt As Integer = 0 To niz.GetUpperBound(0)
            Console.WriteLine($"Clan {cnt}: ")
            niz(cnt) = Console.ReadLine()
        Next
        For cnt As Integer = 0 To niz.GetUpperBound(0)
            If (niz(cnt) Mod 3) = 0 Then
                Console.WriteLine($"Indeks: {cnt}, broj: {niz(cnt)}")
            End If
        Next
    End Sub

    Sub runZad2()
        ' Test Zadatak 2
        Dim niz1 As Integer() = New Integer(3) {0, 1, 2, 3}
        Program.Ispis(niz1)
        Console.WriteLine("")
        Dim niz2 As Integer(,) = New Integer(1, 1) {}
        niz2(0, 0) = 1
        niz2(0, 1) = 1
        niz2(1, 0) = 1
        niz2(1, 1) = 1
        Program.Ispis(niz2)
    End Sub

    Sub runZad3()
        ' Test za zadatak 3
        Dim n As Integer
        Console.WriteLine("n:")
        n = Console.ReadLine() - 1
        Dim niz As Integer() = New Integer(n) {}
        For cnt As Integer = 0 To niz.GetUpperBound(0)
            Console.WriteLine($"Clan {cnt}: ")
            niz(cnt) = Console.ReadLine()
        Next
        Program.Ispis(niz)
        Console.WriteLine()
        Console.WriteLine($"Zbroj: {zbroj(niz)}")
        Console.WriteLine($"Prosjek: {prosjek(niz)}")
    End Sub

    Sub runZad4()
        ' Test za zadatak 4
        Dim n As Integer
        Console.WriteLine("n:")
        n = Console.ReadLine()
        Dim niz As Integer() = New Integer(n) {}
        niz = Program.random(n)
        Program.Ispis(niz)
        Console.WriteLine()
        Program.Ispis(Program.modRandom(niz))
    End Sub

    Sub runZad5()
        ' Test za zadatak 5

        Dim matrix1 As Integer(,) = New Integer(1, 1) {}
        matrix1(0, 0) = 2
        matrix1(0, 1) = 4
        matrix1(1, 0) = 5
        matrix1(1, 1) = 6
        Program.Ispis(matrix1)
        Console.WriteLine()

        Dim matrix2 As Integer(,) = New Integer(1, 1) {}
        matrix2(0, 0) = 1
        matrix2(0, 1) = 1
        matrix2(1, 0) = 1
        matrix2(1, 1) = 1
        Program.Ispis(matrix2)
        Console.WriteLine()

        Program.Ispis(Program.matrixCalc(matrix1, matrix2))
    End Sub
End Module

Module Program
    Sub Ispis(ByVal niz As Integer())

        For Each broj In niz
            Console.Write(broj & vbTab)
        Next

    End Sub
    Sub Ispis(ByVal niz As Integer(,))

        For rank As Integer = 0 To niz.GetUpperBound(0)
            For cnt As Integer = 0 To niz.GetUpperBound(1)
                Console.Write(niz(rank, cnt) & vbTab)
            Next
            Console.WriteLine("")
        Next
    End Sub

    Function zbroj(ByVal niz As Integer()) As Integer
        Dim zbrojClanova As Integer
        For Each broj In niz
            zbrojClanova += broj
        Next

        Return zbrojClanova

    End Function

    Function prosjek(ByVal niz As Integer()) As Integer

        Return (zbroj(niz) / (niz.GetUpperBound(0) + 1))

    End Function

    Function random(ByVal n As Integer) As Integer()
        Dim niz As Integer() = New Integer(n) {}

        For cnt = 0 To niz.GetUpperBound(0)
            Dim clan As Random = New Random
            niz(cnt) = clan.Next(-5, 5)
        Next

        Return niz
    End Function

    Function modRandom(ByVal niz As Integer()) As Integer()
        Dim finalNiz As Integer() = New Integer(niz.GetUpperBound(0)) {}

        For cnt As Integer = 0 To finalNiz.GetUpperBound(0)
            If niz(cnt) < 0 Then
                finalNiz(cnt) = Math.Pow(niz(cnt), 2)
            Else
                finalNiz(cnt) = Math.Sqrt(niz(cnt))
            End If
        Next

        Return finalNiz
    End Function

    Function matrixCalc(ByVal matrix1 As Integer(,), ByVal matrix2 As Integer(,)) As Integer(,)

        Dim finalMatrix As Integer(,) = New Integer(matrix1.GetUpperBound(0), matrix1.GetUpperBound(1)) {}

        For rank As Integer = 0 To matrix1.GetUpperBound(0)
            For cnt As Integer = 0 To matrix1.GetUpperBound(1)
                finalMatrix(rank, cnt) = matrix1(rank, cnt) + matrix2(rank, cnt)
            Next
        Next

        Return finalMatrix
    End Function

    Sub Main()
        Zadaci.runZad1()
        Zadaci.runZad2()
        Zadaci.runZad3()
        Zadaci.runZad4()
        Zadaci.runZad5()
    End Sub
End Module