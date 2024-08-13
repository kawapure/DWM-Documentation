//
// Object: Resource
//
// Module: uDWM.dll
//
// Responsibility: 
//
// Song :3 -- Circle - Mitski
//

class CResource : public CBaseObject
{
public:
	//===================================================================================
	// Raw member functions:
	//
	static HRESULT Create(DwmResourceType::Enum a1, IDwmChannel *pMilChannel, OUT CResource **ppOut);
	static HRESULT WrapExistingResource(IDwmChannel *pMilChannel, DwmResourceType::Enum a2, uint a3, OUT CResource **ppOut);
	
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
	IDwmChannel *m_pMilChannel;
	
	/*
	 * Offset = { 16b, 4dw, 2qw }
	 * Size   = {  8b, 2dw, 1qw }
	 */
	IDwmChannel *m_pMilChannel;
};