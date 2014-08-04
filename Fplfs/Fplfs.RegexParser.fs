module Fplfs.RegexParser
    type RegexAstNode =
        | CharAstNode of char
        | SequenceAstNode of RegexAstNode list
        | ZeroOrMoreAstNode of RegexAstNode
        | OneOrMoreAstNode of RegexAstNode
        | ZeroOrOneAstNode of RegexAstNode
        | OrAstNode of RegexAstNode * RegexAstNode

    let parseRegex (s : string) =
        let rec parseExpression pos =
            let finishExpression = function
                | [] -> failwith "Expression cannot be empty"
                | [x] -> x
                | x -> SequenceAstNode (List.rev x)

            let rec parseChars acc pos =
                if pos >= s.Length then (acc, pos)
                else
                    let pos' = pos + 1

                    let handleModifierChar c f = function
                        | [] -> failwith (sprintf "'%c' found with no preceding expression" c)
                        | head :: tail -> parseChars (f head :: tail) pos'

                    match s.[pos] with
                    | '*' -> handleModifierChar '*' ZeroOrMoreAstNode acc
                    | '+' -> handleModifierChar '+' OneOrMoreAstNode acc
                    | '?' -> handleModifierChar '?' ZeroOrOneAstNode acc
                    | '|' ->
                        let left = finishExpression acc
                        let right, pos' = parseExpression pos'
                        ([OrAstNode (left, right)], pos')
                    | '(' -> // TODO: right paren :P
                        let expr, pos' = parseExpression pos'
                        parseChars (expr :: acc) pos'
                    | x -> parseChars (CharAstNode x :: acc) pos'

            let contents, pos' = parseChars [] pos
            (finishExpression contents, pos')

        fst (parseExpression 0)
