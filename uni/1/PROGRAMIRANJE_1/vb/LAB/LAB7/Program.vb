Imports System

Module util
    Sub printStack(ByVal stack As Stack)
        For i As Integer = 0 To stack.Count - 1
            Console.WriteLine($"Element {i} stacka je: {stack.Pop()}")
        Next
    End Sub

    ' Funkcija za zadatak 2
    Function brackets(ByVal brac As String) As Boolean
        
        
        ' String input razdoviji kao niz
        Dim bracArray() As Char = brac.ToCharArray

        ' Dodaj sve elemente u Stack
        Dim bracStack As Stack = New Stack()
        For i As Integer = 0 To bracArray.GetUpperBound(0)
            bracStack.Push(brac(i))
        Next


    Dim element As String
    Dim nextElement As String
    For i As Integer = 0 To bracStack.Count - 2
        If i = 0 Then
            element = bracStack.Pop()
        Else
            element = nextElement
        End If
        
        nextElement = bracStack.Pop()


        ' Console.Write($"element: {element} ")
        ' Console.Write($"nextElement: {nextElement} ")
        Select Case element
            Case "}"
                If nextElement = "(" OrElse nextElement = "[" Then
                        return False
                End If
            Case "]"
                If nextElement = "{" OrElse nextElement = "(" Then
                        return False
                End If
            Case ")"
                If nextElement = "[" OrElse nextElement = "{" Then
                        return False
                End If

        End Select
    Next

    Return True

    End Function

    Public Structure Point
        Dim x As Integer
        Dim y As Integer
        Dim z As Integer

        Public Overrides Function ToString() As String
            Return String.Concat("( ", x,", ", y, ", ", z, " )" ) 
        End Function

        Public Function DistanceTo(ByVal otherX As Integer) As Integer
            If x > otherX Then
                Return x - otherX
            Else
                Return otherX - x 
            End If
        End Function
    End Structure
End Module

Module Zadaci
    Sub zad1()
        Dim stog As Stack = New Stack()
        Console.WriteLine("Unosenjem STOP zauzstavlje se loop")
        
        While True
            Console.WriteLine("Unesi znak: ")
            Dim input As String = Console.ReadLine()

            If input = "STOP" Then
                Exit While
            End If

            stog.Push(input)
        End While


        For i As Integer = 0 To stog.Count - 1
            Console.WriteLine(stog.Pop())
        Next

    End Sub

    Sub zad2()
        Console.WriteLine(util.brackets("[()]{}{[()()]()}"))
        Console.WriteLine(util.brackets("[(])"))
    End Sub

    Sub zad3()
        Dim point As util.Point

        point.x = 3
        point.y = 4
        point.z = 6

        Console.WriteLine(point.ToString())
    End Sub

    Sub zad4()
        ' Ne razumijem tocno tekst valjda je ovo to
        Dim point As util.Point
        Dim point2 As util.Point

        point.x = 4
        point.y = 2
        point.z = 6

        point2.x = 3
        point2.y = 6
        point2.z = 3

        Console.WriteLine(point.DistanceTo(point2.x))
        Console.WriteLine(point2.DistanceTo(point.x))

    End Sub
End Module

Module Program
    Sub Main(args As String())
        Console.WriteLine("LAB6")
        Console.WriteLine("----")


        ' Zadaci.zad1()
        ' Zadaci.zad2()
        ' Zadaci.zad3()
        ' Zadaci.zad4()
    End Sub
End Module
