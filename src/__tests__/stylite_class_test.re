open Jest;

open ExpectJs;

open Stylite_class;

describe
  "combine"
  (
    fun () => {
      test
        "combine with empty list"
        (
          fun () => {
            let classes = [];
            let combined = combine classes;
            expect combined |> toEqual ""
          }
        );
      test
        "combine"
        (
          fun () => {
            let classes = ["btn", "btn-primary", "btn-sm"];
            let combined = combine classes;
            expect combined |> toEqual "btn btn-primary btn-sm"
          }
        )
    }
  );

describe
  "combine_conditions"
  (
    fun () => {
      test
        "combine_conditions with empty list"
        (
          fun () => {
            let conditions = [];
            let combined = combine_conditions conditions;
            expect combined |> toEqual ""
          }
        );
      test
        "combine_conditions"
        (
          fun () => {
            let conditions = [
              Ok "btn",
              Cond true "btn-primary",
              Cond false "btn-default",
              Option (Some "btn-option-some"),
              Option None,
              OptionCond true (Some "btn-option-cond-true-some"),
              OptionCond false (Some "btn-option-cond-false-some"),
              OptionCond true None,
              OptionCond false None,
              Option None,
              Ok "btn-sm"
            ];
            let combined = combine_conditions conditions;
            expect combined |> toEqual "btn btn-primary btn-option-some btn-option-cond-true-some btn-sm"
          }
        )
    }
  );