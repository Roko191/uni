Imports System

Module util
    Sub reverse(ByVal input As String)
        Dim counter As Integer
        Dim reverseArray(input.Length) As Char

        For i As Integer = (input.Length - 1) To 0 Step - 1
            reverseArray(counter) = input(i)

            counter += 1
        Next 

        Dim reverse As New String(reverseArray)

        Console.WriteLine(reverse)
    End Sub

    Function samoglasnici(ByVal text As String) As Integer
        Dim samoglasniciVar As Integer

        ' Manje provjera ako je sve tiskanim
         text = text.ToUpper()
        

        For i As Integer = 0 to text.Length -1
            Select Case text(i)
                Case "A"
                    samoglasniciVar += 1
                Case "E"
                    samoglasniciVar += 1
                Case "I"
                    samoglasniciVar += 1
                Case "O"
                    samoglasniciVar += 1
                Case "U"
                    samoglasniciVar += 1
            End Select
        Next

        Return samoglasniciVar
    End Function

    Sub printByLength(ByVal texts() As String)
        ' Bubble sort the array 
        For i As Integer = texts.GetUpperBound(0) To 0 Step -1 
            For j As Integer = 0 To i -1
                If texts(j).Length > texts(j + 1).Length
                    Dim tempStore As String
                    tempStore = texts(j)
                    texts(j) = texts(j + 1)
                    texts(j + 1) = tempStore
                End If
            Next
        Next

        For i As Integer = 0 To texts.GetUpperBound(0)
            Console.WriteLine(texts(i))
        Next
    End Sub

    Sub protect(ByVal input As String, ByVal words As String)
        Dim wordsList As String() = words.Split(New Char() {" "c})

        For Each word As String In wordsList
            Console.WriteLine("SECRET WORD: {0}", word)
        Next

        For Each word As String in wordsList
            input = input.replace(word, "*")
        Next

        Console.WriteLine(input)

    End Sub


End Module

Module zadaci
    Sub zad1()
        Console.WriteLine("Unesi bilo kakav tekst: ")
        Dim input As String = Console.ReadLine()
        reverse(input)
    End Sub

    Sub zad2()
        Console.WriteLine("Unesi bilo kakav tekst: ")
        Dim input As String = Console.ReadLine()
        Console.WriteLine(samoglasnici(input))
    End Sub

    Sub zad3()
        Dim texts = New String() {"Marko", "Ovo je recenica","Roko"}
        printByLength(texts)
    End Sub

    Sub zad4() 
        Console.WriteLine("Unesi poruku: ")
        Dim input As String = Console.ReadLine()
        Console.WriteLine("Rijeci se odvajaju spaceom!")
        Console.WriteLine("Unesi rijeci koje zelis sakrit: ")
        Dim words As String = Console.ReadLine()
        
        protect(input, words)
    End Sub
End Module

Module Program
    Sub Main(args As String())
        ' zadaci.Zad1()
        ' zadaci.Zad2()
        ' zadaci.Zad3()
        zadaci.Zad4()
    End Sub
End Module
