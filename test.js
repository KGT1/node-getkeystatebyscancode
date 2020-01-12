const { GetKeyStateByScancode } = require("./index.js");


var lol = GetKeyStateByScancode(
    0xe037
);

console.log(lol < 0 ? "down" : "up");