#pragma once

#include "stdafx.h"

#include "FooBarOcx.h"
#include "Resource.h"

#include <atlctl.h>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


// CFoo
class ATL_NO_VTABLE CFoo :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CFoo, &CLSID_Foo>,
    public IDispatchImpl<IFoo, &IID_IFoo, &LIBID_FooBarOcxLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
    CFoo();

    DECLARE_REGISTRY_RESOURCEID(IDR_FOO)

    BEGIN_COM_MAP(CFoo)
        COM_INTERFACE_ENTRY(IFoo)
        COM_INTERFACE_ENTRY(IDispatch)
    END_COM_MAP()

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    HRESULT FinalConstruct();
    void FinalRelease();

public:
    STDMETHOD(SayHello)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(Foo), CFoo)

// CBar
class ATL_NO_VTABLE CBar :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CBar, &CLSID_Bar>,
    public IDispatchImpl<IBar, &IID_IBar, &LIBID_FooBarOcxLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
    CBar();

    DECLARE_REGISTRY_RESOURCEID(IDR_BAR)

    BEGIN_COM_MAP(CBar)
        COM_INTERFACE_ENTRY(IBar)
        COM_INTERFACE_ENTRY(IDispatch)
    END_COM_MAP()

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    HRESULT FinalConstruct();
    void FinalRelease();

protected:
    CComObject<CFoo> *m_pFoo;

public:
    STDMETHOD(GetFoo)(IFoo **ppFoo);
};

OBJECT_ENTRY_AUTO(__uuidof(Bar), CBar)
