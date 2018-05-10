open Jest;

open Expect;

describe("Tmp", () => {
  test("system temp file", () => {
    let path = Tmp.make();
    expect(path) |> toMatchRe([%bs.re {|/\/tmp\/tmp-(\w+)\.tmp/|}]);
  });
  test("specified tmp dir", () => {
    let dirname: option(string) = [%bs.node __dirname];
    let dir =
      switch (dirname) {
      | None => "tmp"
      | Some(dirname) => dirname ++ "/tmp"
      };
    let path = Tmp.make(~dir, ());
    expect(path) |> toContainString(dir);
  });
});
