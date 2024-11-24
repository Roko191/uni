' Option Explicit Off ' OVO OPCIJU KORISTITI SAMO KAD SE TREBA POKRENUTI ZADATAK 4

Imports System

Module Program

    ' Kod za ZADATAK 1
    Sub miliToCentiAndMeter()
        Dim mili as Double

        Console.WriteLine("Napisi broj u milimetrima")
        mili = Console.ReadLine()

        Console.WriteLine($"{mili}mm je {mili / 10}cm i {mili / 1000}m")
    End Sub

    ' Kod za ZADATAK 2
    Sub pow()
        Dim base as Double
        Dim expo as Double

        Console.WriteLine("Upisi bazu: ")
        base = Console.ReadLine()
        Console.WriteLine("Upisi eksponent: ")
        expo = Console.ReadLine()

        Console.WriteLine($"Baza {base} na potenciju {expo} iznsoi {Math.pow(base, expo)}")

    End Sub

    ' Kod za ZADATAK 3
    Sub VariableSwitch()
        Dim broj1 as Integer
        Dim broj2 as Integer

        Console.WriteLine("Unesi prvi broj: ")
        broj1 = Console.ReadLine()
        Console.WriteLine("") ' Stvranje praznog reda za ljepsi izgled

        Console.WriteLine("Unesi drugi broj: ")
        broj2 = Console.ReadLine()
        Console.WriteLine("")

        Console.WriteLine("Stanje u varijablama prije switcha: ")
        Console.WriteLine($"    broj1: {broj1}")
        Console.WriteLine($"    broj2: {broj2}")
        Console.WriteLine("")

        ' Kod za switch varibli
        broj1 += broj2
        broj2 = broj1 - broj2
        broj1 = broj1 - broj2

        Console.WriteLine("Stanje u varijablama prije switcha: ")
        Console.WriteLine($"    broj1: {broj1}")
        Console.WriteLine($"    broj2: {broj2}")

    End Sub

    ' Kod za ZADATAK 4
    Sub sqrt()
        Dim brojZaKorijen As Integer ' Ovo izkomentirati; Stoji tu da ne baca compalation err
        Console.WriteLine("Unesi broj koji zelis korjenovat: ")
        brojZaKorijen = Console.ReadLine()
        Console.WriteLine("")

        Console.WriteLine($"Korijen broja {brojZaKorijen} je {Math.sqrt(brojZaKorijen)}")

    End Sub

    Sub radijus()
        Dim radijus As Single
        Console.WriteLine("Upisi radijus:")
        radijus = Console.ReadLine()
        Console.WriteLine($"Oplosje: { 4 * Math.PI * Math.pow(radijus, 2) }, Volumen: { (4 * Math.PI * Math.pow(radijus, 3) ) / 3 }")
    End Sub

    Sub kibiMebiGibi()
        Console.WriteLine("kibi: {0}, Mebi: {1}, Gibi: {2}", Math.Pow(2, 10), Math.Pow(2, 20), Math.Pow(2, 30))
    End Sub

    Sub Main()
        ' miliToCentiAndMeter()
        ' pow()
        ' sqrt() 'Ako zelis pokrenit ovu funkcije obavezno odkomentirati prvu linuju
        ' radijus()
        ' kibiMebiGibi()
    End Sub'
End Module