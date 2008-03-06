// ZorbaCOMApi.cpp : Implementation of DLL Exports.


#include "stdafx.h"
#include "resource.h"
#include "ZorbaCOMApi.h"


class CZorbaCOMApiModule : public CAtlDllModuleT< CZorbaCOMApiModule >
{
public :
	DECLARE_LIBID(LIBID_ZorbaCOMApiLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ZORBACOMAPI, "{8B935DBB-3385-4EDE-BA96-4B2F9F5596BA}")
};

CZorbaCOMApiModule _AtlModule;


#ifdef _MANAGED
#pragma managed(push, off)
#endif

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
    return _AtlModule.DllMain(dwReason, lpReserved); 
}

#ifdef _MANAGED
#pragma managed(pop)
#endif




// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}

