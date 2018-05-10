open Jest;

open Expect;

describe("Tmp", () =>
  test("a custom tmp dir", () => {
    let path = Tmp.make();
    expect(path) |> toMatchRe([%bs.re {|/tmp\/tmp-(\w+)\.tmp/|}]);
  })
);
