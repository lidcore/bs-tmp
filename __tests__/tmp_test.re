open Jest;

open Expect;

describe("Tmp", () =>
  test("a temp file", () =>
    expect(1 + 2) |> toBe(3)
  )
);
