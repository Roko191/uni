Imports System

Module Program

    Sub Zadatak1()
        ' KOD ZA ZADATAK 1
        Dim brojKrugova As Integer
        Dim suma As Integer
        Console.WriteLine("Unesi broj krugova:")
        brojKrugova = Console.ReadLine()
        Console.WriteLine("")
        For brojac As Integer = 1 To brojKrugova Step 1
            Dim broj As Integer
            Console.WriteLine($"Unesi {brojac} broj: ")
            broj = Console.ReadLine()
            suma += broj
        Next
        Console.WriteLine($"Arihmeticka sredina unesni brojeva je {suma / brojKrugova}")
    End Sub

    Sub Zadatak2()
        ' KOD ZA ZADATAK 2
        Dim brojKrugova As Integer
        Dim najmanji As Integer
        Dim najveci As Integer
        Console.WriteLine("Unesi broj krugova: ")
        brojKrugova = Console.ReadLine()
        For brojac As Integer = 1 To brojKrugova Step 1
            Dim broj As Integer
            Console.WriteLine("Upisi broj: ")
            broj = Console.ReadLine()
            If brojac = 1 Then
                najmanji = broj
                najveci = broj
            Else
                If broj < najmanji Then
                    najmanji = broj
                End If
                If broj > najveci Then
                    najveci = broj
                End If
            End If
        Next
        Console.WriteLine($"Najveci od upisanih brojeva je {najveci}, a najmanji od upisanih brojeva je {najmanji}")
    End Sub

    Sub Zadatak3()
        'KOD ZA ZADATAK 3

        Dim brojKrugova As Integer
        Dim suma As Integer
        Dim n As Integer
        Console.WriteLine("Upisi broj krugova: ")
        brojKrugova = Console.ReadLine()
        For brojac As Integer = 1 To brojKrugova Step 1
            Dim broj As Integer
            Console.WriteLine("Upisi broj: ")
            broj = Console.ReadLine()
            If (broj Mod 2) = 0 Then
                Console.WriteLine("Upisao si broj koji je paran s 2")
                Exit For
            End If
            If broj > 10 AndAlso broj < 50 Then
                suma += broj
                n += 1
            End If
        Next
        Console.WriteLine($"Arihmeticka sredina zadanih brojeva je {suma / n}")

    End Sub

    Sub Zadatak4()
        ' KOD ZA ZADATAK 4
        Dim brojKrugova As Integer
        Dim counter As Integer
        Console.WriteLine("Upisi broj krugova: ")
        brojKrugova = Console.ReadLine()
        For brojac As Integer = 1 To brojKrugova Step 1
            Dim broj As Integer
            Dim pola As Integer
            Dim brojFaktora As Integer
            Console.WriteLine($"Upsi {brojac} broj: ")
            broj = Console.ReadLine()
            pola = broj \ 2
            If broj < 0 Then
                Exit For
            End If
            For n As Integer = 1 To pola Step 1
                If (broj Mod pola) = 0 Then
                    brojFaktora += 1
                End If
            Next
            If brojFaktora > 1 Then
                Console.WriteLine("Broj nije paran")
            Else
                counter += 1
            End If
        Next
        Console.WriteLine($"Korisnik je upisao {counter} prostih brojeva")

    End Sub

    Sub Zadatak5()
        ' KOD ZA ZADAAK 5
        Dim broj As Integer
        Console.WriteLine("Unesi broj: ")
        broj = Console.ReadLine()
        If broj < 0 Then
            Console.WriteLine("Broj koji je unesen nije prirodan!")
            Return
        End If
        For digit As Integer = 0 To 9 Step 1
            Dim temp As Integer
            temp = broj
            While temp > 0
                If (temp Mod 10) = digit Then
                    Console.Write(digit)
                End If
                temp = temp \ 10
            End While
        Next
    End Sub

    Sub Zadatak6()
        'KOD ZA ZADATAK 6
        Dim N As Integer
        N = Console.ReadLine()
        While N > 0
            Dim count As Integer
            count = N
            For brojac As Integer = 1 To count Step 1
                Console.Write("+")
            Next
            Console.WriteLine("")
            N = N - 1
        End While
    End Sub

    Sub Zadatak7()
        'KOD ZA ZADATAK 7
        Dim m As Integer
        Dim n As Integer
        Dim b As Integer
        For i As Integer = m To n
            If i Mod b = 0 Then
                Console.WriteLine(i)
            End If
        Next
    End Sub

    Sub Zadatak8()
        'KOD ZA ZADATAK 8
    End Sub    
    Sub Main()
        ' Zadatak1()
        ' Zadatak2()
        ' Zadatak3()
        ' Zadatak4()
        ' Zadatak5()
        ' Zadatak7()

        ' CLEAN EXIT
        Console.WriteLine()
        Return
    End Sub
End Module