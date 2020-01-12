#include <windows.h>

#include <napi.h>

Napi::Number KeyStateByScanCode(const Napi::CallbackInfo &info){
	auto env = info.Env();
	if(info.Length() != 1)
		Napi::TypeError::New(env, "Expected 1 parameter!").ThrowAsJavaScriptException();
	if(!info[0].IsNumber())
		Napi::TypeError::New(env, "Expected param 1 to be a uint!").ThrowAsJavaScriptException();
	uint32_t val = info[0].As<Napi::Number>().Uint32Value();

	UINT valAsVk = MapVirtualKeyA((UINT) val,(UINT)1);

	//Napi::TypeError::New(env, "Das ist es: "+std::to_string(valAsVk)).ThrowAsJavaScriptException();

	if(valAsVk==0)
		Napi::TypeError::New(env, "The ScanCode has no VK KeyCode").ThrowAsJavaScriptException();
	
	return Napi::Number::New(env,(double)GetAsyncKeyState(valAsVk));

}

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
	exports.Set("KeyStateByScanCode", Napi::Function::New(env, KeyStateByScanCode));
	return exports;
}

NODE_API_MODULE(win32_getkeystatebyscancode, InitAll)