module Fplfs.RegexParser
    type RegexAstNode =
        | CharAstNode of char
        | SequenceAstNode of RegexAstNode list

    let parseRegex (s : string) =
        match s.Length with
        | 0 -> failwith "String must not be empty"
        | _ ->
            let parseChar nodeAcc stringPos =
                CharAstNode s.[stringPos] :: nodeAcc

            match parseChar [] 0 with
            | [x] -> x
            | x -> SequenceAstNode x
