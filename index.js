const Input = require('./build/Release/getkeystatebyscancode.node');

function GetKeyStateByScancode(val) {
    return Input.KeyStateByScanCode(val & 0xFFFF);
}
module.exports = { GetKeyStateByScancode }