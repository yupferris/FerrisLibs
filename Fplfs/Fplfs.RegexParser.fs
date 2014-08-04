module Fplfs.RegexParser
    type RegexAstNode =
        | CharAstNode of char
        | SequenceAstNode of RegexAstNode list

    let parseRegex (s : string) =
        match s.Length with
        | 0 -> failwith "String must not be empty"
        | _ ->
            let parseChar pos =
                CharAstNode s.[pos]

            let rec parseChars pos =
                if pos < s.Length then parseChar pos :: parseChars (pos + 1) else []

            match parseChars 0 with
            | [x] -> x
            | x -> SequenceAstNode x
