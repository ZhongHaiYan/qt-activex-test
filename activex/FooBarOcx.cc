#include "stdafx.h"

#include "FooBarOcx.h"
#include "Resource.h"

class CFooBarOcxModule : public CAtlDllModuleT< CFooBarOcxModule >
{
public :
    DECLARE_LIBID(LIBID_FooBarOcxLib)
    DECLARE_REGISTRY_APPID_RESOURCEID(IDR_FOOBAROCX, "{78D5193F-B90E-4F6A-A87F-33F7CA98D146}")
};

CFooBarOcxModule _AtlModule;

class CFooBarOcxApp : public CWinApp
{
public:

    // Overrides
    virtual BOOL InitInstance();
    virtual int ExitInstance();

    DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CFooBarOcxApp, CWinApp)
END_MESSAGE_MAP()

CFooBarOcxApp theApp;

BOOL CFooBarOcxApp::InitInstance()
{
    return CWinApp::InitInstance();
}

int CFooBarOcxApp::ExitInstance()
{
    return CWinApp::ExitInstance();
}


// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState())
    return (AfxDllCanUnloadNow()==S_OK && _AtlModule.GetLockCount()==0) ? S_OK : S_FALSE;
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
