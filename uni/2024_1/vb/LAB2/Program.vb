Imports System

Module Program
    Sub biggest()
        ' KOD ZA ZADATAK 1
        Dim broj1 As Integer
        Dim broj2 As Integer
        Dim broj3 As Integer
        Console.WriteLine("Upisi prvi broj: ")
        broj1 = Console.ReadLine()
        Console.WriteLine("")
        Console.WriteLine("Upisi prvi broj: ")
        broj2 = Console.ReadLine()
        Console.WriteLine("")
        Console.WriteLine("Upisi prvi broj: ")
        broj3 = Console.ReadLine()
        Console.WriteLine("")
        If broj1 > broj2 AndAlso broj1 > broj3 Then
            Console.WriteLine($"Najveci broj od unesenan 3 je: {broj1}")
        ElseIf broj2 > broj3 Then
            Console.WriteLine($"Najveci broj od unesena 3 je: {broj2}")
        Else
            Console.WriteLine($"Najveci broj od unesena 3 je: {broj3}")
        End If
    End Sub

    Sub najvecaZnamTrozna()
        'KOD ZA ZADATAK 2
        Dim broj1, broj2, broj3 As Integer
        Dim znamenka1, znamenka2, znamenka3 As Integer
        Console.WriteLine("Upsi broj (troznamenkasti): ")
        broj1 = Console.ReadLine()
        ' Provjera jeli troznamnkasti broj
        If broj1 \ 100 = 0 OrElse broj1 \ 100 >= 10 Then
            Console.WriteLine($"Uneseni broj {broj1} nije tronznamenkast! Pokreni ponobno program i unesi tronznamenkasti broj!")
            Return
        End If
        Console.WriteLine("Upsi broj (troznamenkasti): ")
        broj2 = Console.ReadLine()
        ' Provjera jeli troznamnkasti broj
        If broj1 \ 100 = 0 OrElse broj1 \ 100 >= 10 Then
            Console.WriteLine($"Uneseni broj {broj1} nije tronznamenkast! Pokreni ponobno program i unesi tronznamenkasti broj!")
            Return
        End If
        Console.WriteLine("Upsi broj (troznamenkasti): ")
        broj3 = Console.ReadLine()
        ' Provjera jeli troznamnkasti broj
        If broj1 \ 100 = 0 OrElse broj1 \ 100 >= 10 Then
            Console.WriteLine($"Uneseni broj {broj1} nije tronznamenkast! Pokreni ponobno program i unesi tronznamenkasti broj!")
            Return
        End If
        znamenka1 = broj1 Mod 10
        znamenka2 = broj2 Mod 10
        znamenka3 = broj3 Mod 10
        If znamenka1 > znamenka2 AndAlso znamenka1 > znamenka3 Then
            Console.WriteLine($"Najveci znamenka od 3 unesena broja je: {znamenka1}")
        ElseIf znamenka2 > znamenka3 Then
            Console.WriteLine($"Najveci znamenka od 3 unesena broja je: {znamenka2}")
        Else
            Console.WriteLine($"Najveci znamenka od 3 unesena broja je: {znamenka3}")
        End If
    End Sub

    Sub bit8weight()
        ' KOD ZA ZADATAK 3
        Dim broj, noviBroj As Integer
        Console.WriteLine("Unesi neki broj: ")
        broj = Console.ReadLine()
        If (broj And 8) = 8 Then
            Console.WriteLine($"Binarni zapis broja {broj} sadrzi bit tezine 8")
        Else
            noviBroj = broj Or 8
            Console.WriteLine($"Novi broj je {noviBroj}")
        End If
    End Sub

    Sub paranOrS3()
        ' KOD ZA ZADATAK 4
        Dim broj As Integer
        Console.WriteLine("Unesi broj: ")
        broj = Console.ReadLine()
        If (broj Mod 2) = 0 Then
            Console.WriteLine($"Broj {broj} je paran!")
        ElseIf (broj Mod 3) = 0 Then
            Console.WriteLine($"Broj {broj} je djeljiv s 3!")
        Else
            Console.WriteLine($"Broj {broj} nije paran i nije djeljiv s 3")
        End If
    End Sub

    Sub trokutType()
        ' KOD ZA ZADATAK 5
        Dim stranica1, stranica2, stranica3 As Integer
        Console.WriteLine("Upisi stranicu: ")
        stranica1 = Console.ReadLine()
        Console.WriteLine("Upisi stranicu: ")
        stranica2 = Console.ReadLine()
        Console.WriteLine("Upisi stranicu: ")
        stranica3 = Console.ReadLine()
        If (stranica1 + stranica2) > stranica3 AndAlso (stranica1 + stranica3) > stranica2 AndAlso (stranica2 + stranica3) > stranica1 Then
            Console.WriteLine("Stranica mogu formirati trokut")
        Else
            Console.WriteLine("3 stranice koje su unesene ne mogu formirati trokut. Pokusajte ponovno")
            Return
        End If
        If stranica1 <> stranica2 AndAlso stranica1 <> stranica3 AndAlso stranica2 <> stranica3 Then
            Console.WriteLine("Trokut je raznostranican")
        ElseIf stranica1 = stranica2 AndAlso stranica1 = stranica3 AndAlso stranica2 = stranica3 Then
            Console.WriteLine("Trokut je jednakostanican")
        Else
            Console.WriteLine("Trokut je jednakokracan")
        End If
    End Sub

    Sub division7or11or13()
        ' KOD ZA ZADATAK 6
        Dim broj, stat As Integer
        stat = 0
        Console.WriteLine("Unesi broj: ")
        broj = Console.ReadLine()
        If (broj Mod 7) = 0 Then
            stat += 1
            Console.WriteLine($"Broj {broj} je djeljiv s 7")
        End If
        If (broj Mod 11) = 0 Then
            stat += 1
            Console.WriteLine($"Broj {broj} je djeljiv s 11")
        End If
        If (broj Mod 13) = 0 Then
            stat += 1
            Console.WriteLine($"Broj {broj} je djeljiv s 13")
        End If
        If stat = 0 Then
            Console.WriteLine("Broj nije djeljiv ni s 7 ni s 11 ni s 3")
        End If
    End Sub

    Sub calc()
        ' KOD ZA ZADATAK 7
        Dim broj1, broj2 As Integer
        Dim matOperator As String
        Console.WriteLine("broj1: ")
        broj1 = Console.ReadLine()
        Console.WriteLine("broj2: ")
        broj2 = Console.ReadLine()
        Console.WriteLine("Koju operaciju zelis izvrsit: ")
        matOperator = Console.ReadLine()
        Select Case matOperator
            Case "+"
                Console.WriteLine(broj1 + broj2)
            Case "-"
                Console.WriteLine(broj1 - broj2)
            Case "*"
                Console.WriteLine(broj1 * broj2)
            Case "/"
                Console.WriteLine(broj1 / broj2)
        End Select
    End Sub

    Sub Main()
        ' biggest()
        ' najvecaZnamTrozna()
        ' bit8weight()
        ' paranOrS3()
        ' trokutType()
        ' division7or11or13()
        ' calc()
    End Sub
End Module
