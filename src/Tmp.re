type params;

[@bs.obj]
external params :
  (~discardDescriptor: bool=?, ~prefix: string=?, ~postfix: string=?, unit) =>
  params =
  "";

type tmp = {. "name": string};

[@bs.module "tmp"] external fileSync : params => tmp = "";

[@bs.module "tmp"] external dirSync : params => tmp = "";

let make = (~prefix=?, ~postfix=?, ()) => {
  let params = params(~prefix?, ~postfix?, ~discardDescriptor=true, ());
  let tmp = fileSync(params);
  let path = tmp##name;
  path;
};
