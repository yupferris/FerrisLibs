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
    let ``Regex parse basic sequence 00`` () = parseRegex "abc" |> should equal (SequenceAstNode [CharAstNode 'a'; CharAstNode 'b'; CharAstNode 'c'])

    // Basic sequence cases
    [<Fact>]
    let ``Regex parse basic sequence 01`` () = parseRegex "Jake" |> should equal (SequenceAstNode [CharAstNode 'J'; CharAstNode 'a'; CharAstNode 'k'; CharAstNode 'e'])

    // Basic sequence cases
    [<Fact>]
    let ``Regex parse basic sequence 02`` () = parseRegex "ääääääää" |> should equal (SequenceAstNode [for _ in 0 .. 7 -> CharAstNode 'ä'])

    // Basic zero-or-more cases
    [<Fact>]
    let ``Regex parse basic zero-or-more 00`` () = parseRegex "P*" |> should equal (ZeroOrMoreAstNode (CharAstNode 'P'))

    [<Fact>]
    let ``Regex parse basic zero-or-more 01`` () = parseRegex "ab*c" |> should equal (SequenceAstNode [CharAstNode 'a'; ZeroOrMoreAstNode (CharAstNode 'b'); CharAstNode 'c'])

    [<Fact>]
    let ``Regex parse basic zero-or-more 02`` () = parseRegex "ab*cd*" |> should equal (SequenceAstNode [CharAstNode 'a'; ZeroOrMoreAstNode (CharAstNode 'b'); CharAstNode 'c'; ZeroOrMoreAstNode (CharAstNode 'd')])

    // Basic one-or-more cases
    [<Fact>]
    let ``Regex parse basic one-or-more 00`` () = parseRegex "P+" |> should equal (OneOrMoreAstNode (CharAstNode 'P'))

    [<Fact>]
    let ``Regex parse basic one-or-more 01`` () = parseRegex "ab+c" |> should equal (SequenceAstNode [CharAstNode 'a'; OneOrMoreAstNode (CharAstNode 'b'); CharAstNode 'c'])

    [<Fact>]
    let ``Regex parse basic one-or-more 02`` () = parseRegex "ab+cd+" |> should equal (SequenceAstNode [CharAstNode 'a'; OneOrMoreAstNode (CharAstNode 'b'); CharAstNode 'c'; OneOrMoreAstNode (CharAstNode 'd')])

    // Basic zero-or-one cases
    [<Fact>]
    let ``Regex parse basic zero-or-one 00`` () = parseRegex "P?" |> should equal (ZeroOrOneAstNode (CharAstNode 'P'))

    [<Fact>]
    let ``Regex parse basic zero-or-one 01`` () = parseRegex "ab?c" |> should equal (SequenceAstNode [CharAstNode 'a'; ZeroOrOneAstNode (CharAstNode 'b'); CharAstNode 'c'])

    [<Fact>]
    let ``Regex parse basic zero-or-one 02`` () = parseRegex "ab?cd?" |> should equal (SequenceAstNode [CharAstNode 'a'; ZeroOrOneAstNode (CharAstNode 'b'); CharAstNode 'c'; ZeroOrOneAstNode (CharAstNode 'd')])

    // Basic or cases
    [<Fact>]
    let ``Regex parse basic or 00`` () = parseRegex "a|b" |> should equal (OrAstNode (CharAstNode 'a', CharAstNode 'b'))

    [<Fact>]
    let ``Regex parse basic or 01`` () = parseRegex "a|b|c" |> should equal (OrAstNode (CharAstNode 'a', OrAstNode (CharAstNode 'b', CharAstNode 'c')))

    // Complex cases
    [<Fact>]
    let ``Regex parse complex 00`` () =
        parseRegex "a*bb+c?|c*|bb"
        |> should equal
            (OrAstNode
                (SequenceAstNode
                    [ZeroOrMoreAstNode (CharAstNode 'a');
                    CharAstNode 'b';
                    OneOrMoreAstNode (CharAstNode 'b');
                    ZeroOrOneAstNode (CharAstNode 'c')],
                OrAstNode
                    (ZeroOrMoreAstNode (CharAstNode 'c'),
                    SequenceAstNode [CharAstNode 'b'; CharAstNode 'b'])))

    // Error cases
    [<Fact>]
    let ``Regex parse empty string 00`` () = testException (fun () -> parseRegex "")

    [<Fact>]
    let ``Regex parse bad zero-or-more 00`` () = testException (fun () -> parseRegex "*")

    [<Fact>]
    let ``Regex parse bad zero-or-more 01`` () = testException (fun () -> parseRegex "*a0000000 asd")

    [<Fact>]
    let ``Regex parse bad one-or-more 00`` () = testException (fun () -> parseRegex "+")

    [<Fact>]
    let ``Regex parse bad one-or-more 01`` () = testException (fun () -> parseRegex "+poasdfp")

    [<Fact>]
    let ``Regex parse bad zero-or-one 00`` () = testException (fun () -> parseRegex "?")

    [<Fact>]
    let ``Regex parse bad zero-or-one 01`` () = testException (fun () -> parseRegex "?asdf09s999")

    [<Fact>]
    let ``Regex parse bad or 00`` () = testException (fun () -> parseRegex "a|")

    [<Fact>]
    let ``Regex parse bad or 01`` () = testException (fun () -> parseRegex "|b")
