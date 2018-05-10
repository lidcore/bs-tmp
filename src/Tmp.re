type params;

[@bs.obj]
external params :
  (
    ~dir: string=?,
    ~prefix: string=?,
    ~postfix: string=?,
    ~discardDescriptor: bool=?,
    unit
  ) =>
  params =
  "";

type tmp = {. "name": string};

[@bs.module "tmp"] external fileSync : params => tmp = "";

[@bs.module "tmp"] external dirSync : params => tmp = "";

let make = (~dir=?, ~prefix=?, ~postfix=?, ()) => {
  let params =
    params(~dir?, ~prefix?, ~postfix?, ~discardDescriptor=true, ());
  let tmp =
    switch (dir) {
    | None => fileSync(params)
    | Some(_) => dirSync(params)
    };
  let path = tmp##name;
  path;
};
