Imports System

Module Program
    Sub Main(args As String())
        For i As Integer = 1 To 5 Step 1
            Dim broj As Integer
            Dim znamenka As Integer
            Dim zbroj As Integer
            Dim sredina As Integer
            Console.WriteLine("Unesi broj:")
            broj = Console.ReadLine()
            Console.WriteLine()
            Dim brojac As Integer
            While broj > 0
                Console.WriteLine($"Broj: {broj}")
                znamenka = broj Mod 10
                Console.WriteLine($"Znamenka: {znamenka}")
                zbroj += znamenka
                Console.WriteLine($"Zbroj: {zbroj}")
                brojac += 1
                Console.WriteLine($"Brojac: {brojac}")
                Console.WriteLine()
                broj = broj \ 10
            End While

            sredina = zbroj / brojac ' \
            Console.WriteLine($"Arihmeticka sredina znamenki broja je {sredina}")

        Next
    End Sub
End Module