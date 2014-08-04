module Fplfs.RegexParser
    type RegexAstNode =
        | CharAstNode of char
        (*| OrAstNode of RegexAstNode * RegexAstNode
        | ZeroOrMoreAstNode of RegexAstNode
        | OneOrMoreAstNode of RegexAstNode
        | ZeroOrOneAstNode of RegexAstNode*)

    let parseRegex (s : string) =
        match s.Length with
        | 0 -> failwith "String must not be empty"
        | _ -> CharAstNode s.[0]
