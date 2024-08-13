//
// Object: VisualCollection
//
// Module: uDWM.dll
//
// Responsibility: Collection of visual elements.
//
// Song :3 -- I Speak Astronomy - Jinjer
//

/*
 * Size = { 48b, 12dw, 6qw }
 *
 * == Remarks ==
 * This class does not exist outside of CVisual, where it is inlined.
 */
struct VisualCollection
{
	//===================================================================================
	// Raw member functions:
	//
	
	HRESULT InsertRelative(CVisual *a2, CVisual *a3, unsigned char a4, bool a5);
	HRESULT Remove(CVisual *pVisual);
	HRESULT RemoveAll();
	
	//===================================================================================
	// Implicit class data members:
	//
	
	// generated VFTable at 0
	// (This contains a scalar deleting destructor, and was generated because of the
	//  dynamic array member.)
	
	/*
	 * Offset = { 16b, 4dw, 2qw }
	 * Size   = {  8b, 2dw, 1qw }
	 */
	// BYTE *m_dynArray.m_pData;
	
	/*
	 * Offset = { 24b, 6dw, 3qw }
	 * Size   = {  8b, 2dw, 1qw }
	 */
	// void * const m_dynArray.InitialAllocation;
	
	/*
	 * Offset = { 32b, 8dw, 4qw }
	 * Size   = {  4b, 1dw }
	 */
	// UINT const m_dynArray.AllocSize;
	
	/*
	 * Offset = { 36b, 9dw }
	 * Size   = {  4b, 1dw }
	 */
	// UINT const m_dynArray.Capacity;
	
	/*
	 * Offset = { 40b, 10dw }
	 * Size   = {  4b,  1dw }
	 */
	// UINT m_dynArray.Count;
	
	//===================================================================================
	// Virtual function members:
	//
	
	// implicit VisualCollection *`scalar deleting destructor'(char a2);
	
	//===================================================================================
	// Class data members:
	//
	
	/*
	 * Offset = { 8b, 2dw, 1qw }
	 * Size   = { 8b, 2dw, 1qw }
	 *
	 * == Origin ==
	 * `(this + 5qw) = this` operations in visual element (CVisual and children)
	 * constructors.
	 *
	 * == Remarks ==
	 * Backreference to the owning CVisual class.
	 */
	CVisual *m_pOwnerVisual;
	
	/*
	 * Offset = { 16b, 4dw, 2qw }
	 * Size   = { 32b, 8dw, 4qw }
	 *
	 * == Remarks ==
	 * Inlined.
	 *
	 * This is possibly a `DynArray<CVisual, false>` instead, but I can't tell for sure
	 * from the disassembly.
	 *
	 * Upon being constructed, the DynArray constructor will set some of its members
	 * 
	 */
	DynArray<CVisual *, false> m_dynArray;
};