module Fplfs.Tests.RegexPerserTests
    open Xunit
    open FsUnit.Xunit
    open Fplfs.RegexParser

    // Single character cases
    [<Fact>]
    let ``Regex parse single character 00`` () = parseRegex "a" |> should equal (CharAstNode 'a')

    [<Fact>]
    let ``Regex parse single character 01`` () = parseRegex "Q" |> should equal (CharAstNode 'Q')
