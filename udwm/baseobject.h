//
// Object: BaseObject
//
// Module: uDWM.dll
//
// Responsibility: Reference counting and shit.
//
// Song :3 -- Skin o' My Teeth - Megadeth
//

// Size = { 4b, 1dw }
class CBaseObject
{
public:
	//===================================================================================
	// Raw member functions:
	//
	
	// Constructor: always inlined
	CBaseObject()
		: m_refCount(1)
	{}
	
	int Release();
	
	//===================================================================================
	// Class data members:
	//
	
	/*
	 * Offset = { 8b, 2dw, 1qw }
	 * Size   = { 4b, 1dw }
	 *
	 * == Remarks ==
	 * This is most likely offset at 1qw as a compiler optimisation, as most DWM objects
	 * that derive from this have their virtual function table pointer at 0qw.
	 */
	int m_refCount = 0;
};