//
// Object: ResourceProxy
//
// Module: uDWM.dll
//
// Responsibility: Proxy for resource communication between MIL channels.
//
// Song :3 -- Circle - Flyleaf
//

class CResourceProxy : public CBaseObject
{
public:
	//===================================================================================
	// Raw member functions:
	//
	HRESULT InitializeFromSharedHandle(DwmResourceType::Enum a2, IDwmChannel *pMilChannel, HANDLE hSharedHandle);
	
	//===================================================================================
	// Implicit class data members:
	//
	
	// generated VFTable at 0
	
	// int m_refCount at { 8b, 2dw, qw } from CBaseObject
	
	//===================================================================================
	// Class data members:
	//
	
	/*
	 * Offset = { 16b, 4dw, 2qw }
	 * Size   = {  8b, 2dw, 1qw }
	 */
	CResource *m_pResource;
};