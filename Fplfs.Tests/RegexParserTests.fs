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

    // Error cases
    [<Fact>]
    let ``Regex parse empty string`` () = testException (fun () -> parseRegex "")
