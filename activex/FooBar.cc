#include "stdafx.h"
#include "FooBar.h"

#include <iostream>

CFoo::CFoo()
{
}

HRESULT CFoo::FinalConstruct()
{
    return S_OK;
}

void CFoo::FinalRelease()
{
}

HRESULT CFoo::SayHello()
{
    std::cout << "Hello, world!" << std::endl;

    return S_OK;
}

//////////////////////////////////////////////////////////////////////////////

CBar::CBar()
    : m_pFoo(NULL)
{
}

HRESULT CBar::FinalConstruct()
{
    HRESULT hr = S_OK;

    if (!m_pFoo) {
        hr = CComObject<CFoo>::CreateInstance(&m_pFoo);
    }

    if (SUCCEEDED(hr)) {
        m_pFoo->AddRef();
    }

    return hr;
}

void CBar::FinalRelease()
{
    if (m_pFoo) {
        m_pFoo->Release();
        m_pFoo = NULL;
    }
}

HRESULT CBar::GetFoo(IFoo **ppFoo)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState())
    if(!(ppFoo))
        return E_POINTER;

    *ppFoo = NULL;

    HRESULT hr = m_pFoo->QueryInterface(ppFoo);
    if (FAILED(hr))
        *ppFoo = NULL;

    return hr;
}
