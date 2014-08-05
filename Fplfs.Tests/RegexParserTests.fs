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

    // Basic paren cases
    [<Fact>]
    let ``Regex parse basic parens 00`` () = parseRegex "a(b)c" |> should equal (SequenceAstNode [CharAstNode 'a'; CharAstNode 'b'; CharAstNode 'c'])

    [<Fact>]
    let ``Regex parse basic parens 01`` () = parseRegex "a(b|c)d" |> should equal (SequenceAstNode [CharAstNode 'a'; OrAstNode (CharAstNode 'b', CharAstNode 'c'); CharAstNode 'd'])

    [<Fact>]
    let ``Regex parse basic parens 02`` () = parseRegex "a(bcd)" |> should equal (SequenceAstNode [CharAstNode 'a'; SequenceAstNode [CharAstNode 'b'; CharAstNode 'c'; CharAstNode 'd']])

    // Basic escape sequences
    [<Fact>]
    let ``Regex parse escape seq 00`` () = parseRegex "\\\\" |> should equal (CharAstNode '\\')

    [<Fact>]
    let ``Regex parse escape seq 01`` () = parseRegex "\\t" |> should equal (CharAstNode '\t')

    [<Fact>]
    let ``Regex parse escape seq 02`` () = parseRegex "\\r" |> should equal (CharAstNode '\r')

    [<Fact>]
    let ``Regex parse escape seq 03`` () = parseRegex "\\n" |> should equal (CharAstNode '\n')

    [<Fact>]
    let ``Regex parse escape seq 04`` () = parseRegex "\\(" |> should equal (CharAstNode '(')

    [<Fact>]
    let ``Regex parse escape seq 05`` () = parseRegex "\\)" |> should equal (CharAstNode ')')

    [<Fact>]
    let ``Regex parse escape seq 06`` () = parseRegex "\\|" |> should equal (CharAstNode '|')

    [<Fact>]
    let ``Regex parse escape seq 07`` () = parseRegex "\\*" |> should equal (CharAstNode '*')

    [<Fact>]
    let ``Regex parse escape seq 08`` () = parseRegex "\\+" |> should equal (CharAstNode '+')

    [<Fact>]
    let ``Regex parse escape seq 09`` () = parseRegex "\\?" |> should equal (CharAstNode '?')

    [<Fact>]
    let ``Regex parse escape seq 10`` () = parseRegex "\\$" |> should equal (CharAstNode '$')

    [<Fact>]
    let ``Regex parse escape seq 11`` () = parseRegex "\\[" |> should equal (CharAstNode '[')

    [<Fact>]
    let ``Regex parse escape seq 12`` () = parseRegex "\\." |> should equal (CharAstNode '.')

    // Basic character classes
    [<Fact>]
    let ``Regex parse character classes 00`` () = parseRegex "." |> should equal (CharacterClassAstNode AnyCharacter)

    [<Fact>]
    let ``Regex parse character classes 01`` () = parseRegex "((((((((.))))))))" |> should equal (CharacterClassAstNode AnyCharacter)

    [<Fact>]
    let ``Regex parse character classes 02`` () = parseRegex "a.*b" |> should equal (SequenceAstNode [CharAstNode 'a'; ZeroOrMoreAstNode (CharacterClassAstNode AnyCharacter); CharAstNode 'b'])

    [<Fact>]
    let ``Regex parse character classes 03`` () = parseRegex "[abc]" |> should equal (CharacterClassAstNode (CharacterSet (false, ['a'; 'b'; 'c'])))

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

    [<Fact>]
    let ``Regex parse complex 01`` () =
        parseRegex "(;|//)(ab\|c)*"
        |> should equal
            (SequenceAstNode
                [OrAstNode
                    (CharAstNode ';',
                    SequenceAstNode [CharAstNode '/'; CharAstNode '/']);
                ZeroOrMoreAstNode
                    (SequenceAstNode [CharAstNode 'a'; CharAstNode 'b'; CharAstNode '|'; CharAstNode 'c'])])

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

    [<Fact>]
    let ``Regex parse bad parens 00`` () = testException (fun () -> parseRegex "(")

    [<Fact>]
    let ``Regex parse bad parens 01`` () = testException (fun () -> parseRegex ")")

    [<Fact>]
    let ``Regex parse bad parens 02`` () = testException (fun () -> parseRegex "(s(d(dsss+(d)d))")

    [<Fact>]
    let ``Regex parse bad parens 03`` () = testException (fun () -> parseRegex "((sdf)ff)f)")

    [<Fact>]
    let ``Regex parse bad escape seq 00`` () = testException (fun () -> parseRegex "\\")

    [<Fact>]
    let ``Regex parse bad escape seq 01`` () = testException (fun () -> parseRegex "asdfasdfasf\\")

    [<Fact>]
    let ``Regex parse bad escape seq 02`` () = testException (fun () -> parseRegex "\\j")

    [<Fact>]
    let ``Regex parse bad character class 00`` () = testException (fun () -> parseRegex "[")

    [<Fact>]
    let ``Regex parse bad character class 01`` () = testException (fun () -> parseRegex "[abc")
