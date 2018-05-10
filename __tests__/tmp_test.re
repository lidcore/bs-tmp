open Jest;

open Expect;

describe("Tmp", () =>
  test("system temp file", () => {
    let path = Tmp.tempFile();
    expect(path) |> toMatchRe([%bs.re {|/\/tmp\/tmp-(\w+)\.tmp/|}]);
  })
);
