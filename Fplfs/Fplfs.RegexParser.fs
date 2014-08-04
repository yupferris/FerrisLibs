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
                    let acc' =
                        match s.[pos] with
                        | '*' ->
                            match acc with
                            | [] -> failwith "'*' found with no preceding expression"
                            | head :: tail -> ZeroOrMoreAstNode head :: tail

                        | x -> CharAstNode x :: acc

                    parseChars acc' (pos + 1)

            match parseChars [] 0 with
            | [x] -> x
            | x -> SequenceAstNode (List.rev x)
