Imports System
' Imports System.Diagnostics.Metrics

' KOD ZA ZADATAK 1
Module Display
    Sub jutro()
        Console.WriteLine("Dobro jutro!")
    End Sub

    Sub dan()
        Console.WriteLine("Dobar dan!")
    End Sub

    Sub vecer()
        Console.WriteLine("Dobra vecer!")
    End Sub
End Module

Module Number
    ' KOD ZA ZADATAK 2
    Function reverse(ByVal broj As Integer) As Integer
        Dim reverseNum As Integer
        reverseNum = 0
        While broj > 0
            ' Line za reverse broja ( 54 ==> 0 * 10 + 4 = 4 ==> 4 * 10 = 40  + 5 = 45 [brojevi su obrnuti])
            reverseNum = (reverseNum * 10) + (broj Mod 10)
            'Console.WriteLine($"reverseNum: {reverseNum}")
            broj = broj / 10
        End While

        Return reverseNum
    End Function

    Function digitNum(ByVal broj As Integer) As Integer
        Dim brojac As Integer
        While broj > 0
            brojac += 1
            broj = broj / 10
        End While

        Return brojac
    End Function

    ' KOD ZA ZADATAK 3
    Function palindrom(ByVal broj As Integer) As Integer
        Dim reverseNum As Integer

        reverseNum = reverse(broj)


        If broj = reverseNum Then
            Return True
        Else
            Return False
        End If

    End Function

    Function prosti(ByVal broj As Integer) As Integer
        ' Ako je broj 1 ili manji nije prost
        If broj <= 1 Then
            Return False
        Else
            ' Provjera s koliko je brojeva dijeljiv
            Dim divCount As Integer

            For brojac As Integer = 1 To broj Step 1
                If (broj Mod brojac) = 0 Then
                    divCount += 1
                End If
            Next

            ' Ako je broj s koliko je djeljiv veci od 2 onda nije prost
            If divCount > 2 Then
                Return False
            Else
                Return True
            End If

        End If
    End Function
    Sub potencija(ByVal baza As Integer, Optional ekspo As Integer = 2)
        Console.WriteLine($"Broj {baza} potenciran brojem {ekspo} iznosi: {Math.Pow(baza, ekspo)}")
    End Sub
    Sub randomNums()
        Dim n As Integer
        Dim a As Integer
        Dim b As Integer

        Console.WriteLine("N: ")
        n = Console.ReadLine()

        Console.WriteLine("A: ")
        a = Console.ReadLine()

        Console.WriteLine("B: ")
        b = Console.ReadLine()

        Console.WriteLine("")

        For i As Integer = 1 To n Step 1
            Dim num As Random = New Random
            Console.WriteLine($"Nasumicni broj {i}. je {num.Next(a, b)}")
        Next

    End Sub
End Module


Module Zadatci

    Sub runZad1()
        ' ZADATAK 1
        Display.jutro()
        Display.dan()
        Display.vecer()
    End Sub

    Sub runZad2()
        ' Zadatak 2
        Dim broj As Integer
        Console.WriteLine("Upisi broj: ")
        broj = Console.ReadLine()
        Console.WriteLine($"Razulata okretanja znamenki broja {broj} je {Number.reverse(broj)}")
        Console.WriteLine($"Broj znamenkih broja {broj} je {Number.digitNum(broj)}")  
    End Sub

    Sub runZad3()
        ' ZADATAK 3
        Dim broj As Integer
        Console.WriteLine("Upisi broj: ")
        broj = Console.ReadLine()
        If Number.palindrom(broj) = True Then
            Console.WriteLine($"Broj {broj} je palindrom")
        Else
            Console.WriteLine($"Broj {broj} nije palindrom")
        End If  
    End Sub

    Sub runZad4()
        ' ZADATAK 4
        For i As Integer = 1 To 1000
            If Number.prosti(i) = True Then
                Console.WriteLine($"{i}")
            End If
        Next 
    End Sub

    Sub runZad5()
        ' ZADATAK 5
        Dim baza As Integer
        Console.WriteLine("Upisi broj: ")
        baza = Console.ReadLine()
        Console.WriteLine("Zelis li unijeti potenciju: [Y if yes / Any key if not]")
        ' Primjer da se vidi rad s opcionalnim argumentom
        If Console.ReadLine() = "Y" Then
            Dim ekspo As Integer
            Console.WriteLine("Upisi potenciju: ")
            ekspo = Console.ReadLine()
            Number.potencija(baza, ekspo)
            Return
        End If
        Number.potencija(baza)
    End Sub

    Sub runZad6()
        ' ZADATAK 6
        Number.randomNums()
    End Sub
End Module

Module Program
    
    Sub Main(args As String())
    
        ' Zadatci.runZad1()
        ' Zadatci.runZad2()
        ' Zadatci.runZad3()
        ' Zadatci.runZad4()
        ' Zadatci.runZad5()
        ' Zadatci.runZad6()

    End Sub
End Module