open LidcoreBsNode;

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

type t = (option(string), Queue.t((bool, string)));

let init = (~dir=?, ()) => (dir, Queue.create());

let update = (~dir, (_, queue)) => (Some(dir), queue);

let make = (~makeDir=false, ~prefix=?, ~postfix=?, (dir, queue)) => {
  let params =
    params(~dir?, ~prefix?, ~postfix?, ~discardDescriptor=true, ());
  let tmp =
    if (makeDir) {
      dirSync(params);
    } else {
      fileSync(params);
    };
  let path = tmp##name;
  Queue.push((makeDir, path), queue);
  path;
};

let cleanup = ((_, queue)) =>
  Queue.iter(
    ((isDir, path)) =>
      try (
        if (isDir) {
          Fs.rmdirSync(path);
        } else {
          Fs.unlinkSync(path);
        }
      ) {
      | _ => ()
      },
    queue,
  );
