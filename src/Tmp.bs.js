// Generated by BUCKLESCRIPT VERSION 3.0.0, PLEASE EDIT WITH CARE
'use strict';

var Tmp = require("tmp");

function tempFile(prefix, postfix, _) {
  var tmp = {
    discardDescriptor: true
  };
  if (prefix) {
    tmp.prefix = prefix[0];
  }
  if (postfix) {
    tmp.postfix = postfix[0];
  }
  var params = tmp;
  return Tmp.fileSync(params).name;
}

exports.tempFile = tempFile;
/* tmp Not a pure module */
