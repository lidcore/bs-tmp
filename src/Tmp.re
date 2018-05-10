type params;

[@bs.val] [@bs.module "fs"] external existsSync : string => bool = "";

[@bs.val] [@bs.module "fs"] external mkdirSync : string => unit = "";

[@bs.obj]
external params :
  (
    ~discardDescriptor: bool=?,
    ~dir: string=?,
    ~prefix: string=?,
    ~postfix: string=?,
    unit
  ) =>
  params =
  "";

type tmp = {. "name": string};

[@bs.module "tmp"] external fileSync : params => tmp = "";

[@bs.module "tmp"] external dirSync : params => tmp = "";

let make = (~dir=?, ~prefix=?, ~postfix=?, ()) => {
  let params =
    params(~discardDescriptor=true, ~dir?, ~prefix?, ~postfix?, ());
  let tmp =
    switch (dir) {
    | None => fileSync(params)
    | Some(dir) =>
      existsSync(dir) ? () : mkdirSync(dir);
      dirSync(params);
    };
  let path = tmp##name;
  path;
};
