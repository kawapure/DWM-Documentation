//
// Object: Compositor
//
// Module: uDWM.dll
//
// Responsibility: Proxies information from uDWM over to the MIL server (DWMCore.dll).
//
// Song :3 -- DIM SCENE - the GazettE
//

// Size = { 32b, 8dw, 4qw }
class CCompositor : public CBaseObject
{
public:
	//===================================================================================
	// Raw member functions:
	//
	
	HRESULT Create(HMIL_CONNECTION *pConnection, OUT CCompositor **pCompositorOut);
	HRESULT Initialize(HMIL_CONNECTION *pConnection);
	void Shutdown();
	
	template <class T>
	HRESULT CreateProxy(OUT T **pProxyOut);
	
	template <class T>
	HRESULT CreateProxyFromSharedHandle(HANDLE hSharedHandle, OUT T **pProxyOut);
	
	//===================================================================================
	// Virtual function members:
	//
	
	// VFTable offset = 0
	virtual ~CCompositor();
	
	//===================================================================================
	// Implicit class data members:
	//
	
	// own VFTable at 0
	// int m_refCount at { 8b, 2dw, 1qw } from CBaseObject
	
	//===================================================================================
	// Class data members:
	//
	
	/*
	 * Offset = { 16b, 4dw, 2qw }
	 * Size   = {  8b, 2dw, 1qw }
	 *
	 * == Origin ==
	 * From call to `MilConnection_CreateChannel` import from module DWMCore.dll in
	 * `Initialize()`.
	 *
	 * == Remarks ==
	 * The interface definition to IDwmChannel is unavailable.
	 */
	IDwmChannel *m_pMilChannel = nullptr;
	
	/*
	 * Offset = { 24b, 6dw, 3qw }
	 * Size   = {  8b, 2dw, 1qw }
	 *
	 * == Origin ==
	 * From call to `DCompositionCreateDevice3` import from module DComp.dll in
	 * `Initialize()`.
	 *
	 * == Remarks ==
	 * This stores a pointer to some undocumented DComp device interface with IID
	 * {CB139649-6D80-48E7-B54D-09737D84DB47}. This cannot be found in the
	 * Windows registry, from a Google search, or on GitHub. It is only known
	 * between DComp and uDWM (and ApplicationFrame.dll lol).
	 *
	 * As such, the type IDirectCompositionDevice is probably incorrect to use.
	 */
	IDirectCompositionDevice *m_pDcompDevice = nullptr;
};