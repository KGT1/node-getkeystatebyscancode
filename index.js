const Input = require('./build/Release/getkeystatebyscancode.node');

function GetKeyStateByScancode(val) {

    if (val > 0xFFFF || val < 0x0000) {
        return null;
    } else {
        return Input.KeyStateByScanCode(val & 0xFFFF);
    }
}
module.exports = { GetKeyStateByScancode }