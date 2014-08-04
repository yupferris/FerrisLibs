module Fplfs.Tests.RegexPerserTests
    open System
    open Xunit
    open FsUnit.Xunit
    open Fplfs.RegexParser

    // TODO: Move to helpers when I have more test modules
    let testSpecificException t f = (fun () -> f() |> ignore) |> should throw t
    let testException f = testSpecificException typeof<Exception> f

    // Single character cases
    [<Fact>]
    let ``Regex parse single character 00`` () = parseRegex "a" |> should equal (CharAstNode 'a')

    [<Fact>]
    let ``Regex parse single character 01`` () = parseRegex "Q" |> should equal (CharAstNode 'Q')

    [<Fact>]
    let ``Regex parse single character 02`` () = parseRegex "ø" |> should equal (CharAstNode 'ø')

    // Basic sequence cases
    [<Fact>]
    let ``Regex parse basic sequence 00`` () = parseRegex "abc" |> should equal (SequenceAstNode [(CharAstNode 'a'); (CharAstNode 'b'); (CharAstNode 'c')])

    // Basic sequence cases
    [<Fact>]
    let ``Regex parse basic sequence 01`` () = parseRegex "Jake" |> should equal (SequenceAstNode [(CharAstNode 'J'); (CharAstNode 'a'); (CharAstNode 'k'); (CharAstNode 'e')])

    // Basic sequence cases
    [<Fact>]
    let ``Regex parse basic sequence 02`` () = parseRegex "ääääääää" |> should equal (SequenceAstNode [for _ in 0 .. 7 -> CharAstNode 'ä'])

    // Error cases
    [<Fact>]
    let ``Regex parse empty string`` () = testException (fun () -> parseRegex "")
