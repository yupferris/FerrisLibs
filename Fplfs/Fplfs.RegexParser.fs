module Fplfs.RegexParser
    type RegexAstNode =
        | CharAstNode of char
        (*| OrAstNode of RegexAstNode * RegexAstNode
        | ZeroOrMoreAstNode of RegexAstNode
        | OneOrMoreAstNode of RegexAstNode
        | ZeroOrOneAstNode of RegexAstNode*)

    let parseRegex (s : string) = CharAstNode s.[0]
