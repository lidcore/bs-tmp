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

let make = (~dir=?, ~prefix=?, ~postfix=?, ()) => {
  let params =
    params(~dir?, ~prefix?, ~postfix?, ~discardDescriptor=true, ());
  let tmp = fileSync(params);
  tmp;
};
