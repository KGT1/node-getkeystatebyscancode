# getkeystatebyscancode

This module enables you to recieve the KeyState via `MapVirtualKeyA` (win32 api) and `GetAsyncKeyState` (win32 api) function. Therefore it is Windows only.

API is described by Typescript definition:

```
function GetKeyStateByScancode(ScanCode);
```
if it returns a negative value the Key is pressed down, otherwise its up.