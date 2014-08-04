module Fplfs.RegexParser
    type RegexAstNode =
        | CharAstNode of char
        | SequenceAstNode of RegexAstNode list
        | ZeroOrMoreAstNode of RegexAstNode

    let parseRegex (s : string) =
        match s.Length with
        | 0 -> failwith "String must not be empty"
        | _ ->
            let rec parseChars acc pos =
                if pos >= s.Length then acc
                else
                    let nextPos = pos + 1

                    match s.[pos] with
                    | '*' ->
                        match acc with
                        | [] -> failwith "'*' found with no preceding expression"
                        | head :: tail -> parseChars (ZeroOrMoreAstNode head :: tail) nextPos

                    | x -> parseChars ((CharAstNode x) :: acc) nextPos

            match parseChars [] 0 with
            | [x] -> x
            | x -> SequenceAstNode (List.rev x)
