' DRUGI UVODNI KOLOKOVIJ GRUPE 3
' ZADATAK:
' Kreiraj program u kojem korisnik unosi znakove (implementiranje stajanja je bilo custom)
' onda se ti podaci koje je upisa ispisu u obrnutom redosljedu. Obavezno korisiti
' stukturu stack


Imports System

Module Program
    Sub Main(args As String())
        Dim stog As Stack = New Stack()

        While True
            Console.WriteLine("Dodaj znak: ")
            Dim input As String = Console.ReadLine()

            If input = "stop" Then
                Exit While
            End If

            stog.Push(input)

        End While

        For i As Integer = 0 To stog.Count - 1
            Console.WriteLine(stog.Pop())
        Next
    End Sub
End Module
