open Jest;

open Expect;

describe("Tmp", () =>
  test("system temp file", () => {
    let path = Tmp.make();
    expect(path) |> toMatchRe([%bs.re {|/\/tmp\/tmp-(\w+)\.tmp/|}]);
  })
);
