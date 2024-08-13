//
// Object: Visual
//
// Module: uDWM.dll
//
// Responsibility: Base class for visual elements.
//
// Song :3 -- Brackish - Kittie
//

// Size = { 240b, 60dw, 30qw }
class CVisual : public CBaseObject
{
public:
	//===================================================================================
	// Raw member functions:
	//
	
	/*
	 * Constructor.
	 *
	 * == Remarks ==
	 * This mostly consists of generated code.
	 */
	CVisual();
	
	/*
	 * Destructor.
	 */
	~CVisual();
	
	static HRESULT Create(OUT CVisual **pVisualOut);
	
	static HRESULT CreateFromSharedHandle(HANDLE hSharedHandle, OUT CVisual **pVisualOut);
	
	static HRESULT DoCanvasLayout(SIZE *a1, MARGINS *a2, SIZE *a3, POINT *a4, SIZE *a5);
	
	void GetLocalToParentVisualTransform(CVisual *pSomeOtherVisual, IN D2DMatrix *pDestMatrix);
	
	bool GetCurrentTransform(IN D2DMatrix *pDestMatrix);
	
	// `CVisual::SetHitTestVisibility(bool)` in symbols; extra argument seems to be an
	// artifact.
	HRESULT SetHitTestVisibility(bool a2);
	
	HRESULT SetInterpolationMode(MilBitmapInterpolationMode::Enum interpolationMode);
	
	HRESULT ConnectToParent(bool a2);
	
	HRESULT MoveToFront(bool a2);
	
	HRESULT InitializeVisualTreeClone(CVisual *pClonedVisual, DWORD a3);
	
	void SetScale(double a2, double a3);
	
	void SetRTLMirror(char a2);
	
	void PropagateDirtyChildren();
	
	void SetInsetFromParent(MARGINS *pMargins);
	
	void DisablePrefiltering();
	
	void SetOffset(POINT *pPoint);
	
	void SetInsetFromParentTop(int offset);
	
	void SetInsetFromParentLeft(int offset);
	
	void Hide();
	
	void Unhide();
	
	HRESULT SetIsCursor(bool bValue);
	
	HRESULT SetSamplingMode(CompositionResampleMode::Enum newMode);
	
	void ClearInterpolationMode();
	
	bool IsVisible();
	
	HRESULT SetBorderMode(MilBitmapBorderMode::Enum newMode);
	
	void SetCenter(double a2, double a3);
	
	void SetColorTransform(const MilColorTransform *pColorTransform);
	
	// `CVisual::SetIsMagnifier(bool)` in symbols; extra argument seems to be an
	// artifact.
	HRESULT SetIsMagnifier(INT64 a2, INT64 a3);
	
	void SetRotation(double a2);
	
	HRESULT UpdateTransform();
	
	//===================================================================================
	// Virtual function members:
	//
	
	// VFTable offset = 0
	virtual ~CVisual();
	
	// VFTable offset = { 8b, 2dw, 1qw }
	virtual HRESULT Initialize();
	
	// VFTable offset = { 16b, 4dw, 2qw }
	virtual HRESULT InitializeFromSharedHandle(HANDLE hSharedHandle);
	
	// VFTable offset = { 24b, 6dw, 3qw }
	virtual void SetDirtyFlags(ulong ulFlags);
	
	// VFTable offset = { 32b, 8dw, 4qw }
	virtual void SetDirtyChildren();
	
	// VFTable offset = { 40b, 10dw, 5qw }
	virtual HRESULT SetContent(CResourceProxy *pResource);
	
	// VFTable offset = { 48b, 12dw, 6qw }
	virtual HRESULT ValidateVisual();
	
	// VFTable offset = { 56b, 14dw, 7qw }
	virtual HRESULT ValidateVisualPostSubgraph();
	
	// VFTable offset = { 64b, 16dw, 8qw }
	virtual HRESULT RenderRecursive();
	
	// VFTable offset = { 72b, 18dw, 9qw }
	virtual HRESULT SetParent(CVisual *pNewParent);
	
	// VFTable offset = { 80b, 20dw, 10qw }
	virtual CVisual *GetTransformParent();
	
	// VFTable offset = { 88b, 22dw, 11qw }
	virtual HRESULT UpdateLayout(bool a2);
	
	// VFTable offset = { 96b, 24dw, 12qw }
	virtual HRESULT SetSize(SIZE *pNewSize);
	
	// VFTable offset = { 104b, 26dw, 13qw }
	virtual void SetOpacity(double newOpacity);
	
	// VFTable offset = { 112b, 28dw, 14qw }
	// [[ stub placeholder ]]
	
	// VFTable offset = { 120b, 30dw, 15qw }
	// [[ stub placeholder ]]
	
	// VFTable offset = { 128b, 32dw, 16qw }
	// [[ stub placeholder ]]
	
	// VFTable offset = { 136b, 34dw, 17qw }
	virtual bool DoHitTest(POINT *pPoint, OUT CVisual **a3, OUT int *a4);
	
	// VFTable offset = { 144b, 36dw, 18qw }
	// [[ stub placeholder ]]
	
	// VFTable offset = { 152b, 38dw, 19qw }
	virtual HRESULT CloneVisualTree(OUT CVisual **pClonedVisual, DWORD a3);
	
	// VFTable offset = { 160b, 40dw, 20qw }
	virtual HRESULT UpdateOpacity();
	
	// VFTable offset = { 168b, 42dw, 21qw }
	virtual void GetMirrorTransform(OUT D2DMatrix *pMirroredMatrix);
	
	// VFTable offset = { 176b, 44dw, 22qw }
	virtual HRESULT UpdateOffset();
	
	// VFTable offset = { 184b, 46dw, 23qw }
	virtual HRESULT SendSetOpacity(double newOpacity);
	
	//===================================================================================
	// Implicit class data members:
	//
	
	// own VFTable at 0
	
	// int m_refCount at { 8b, 2dw, qw } from CBaseObject
	
	// VisualCollection::`vftable' at { 32b, 8dw 4qw } from member
	//     VisualCollection m_visualCollection
	
	/*
	 * Offset = { 40b, 10dw, 5qw }
	 * Size   = {  8b,  2dw, 1qw }
	 */
	// CVisual *m_visualCollection.m_pOwnerVisual;
	
	/*
	 * Offset = { 48b, 12dw, 6qw }
	 * Size   = {  8b,  2dw, 1qw }
	 */
	// BYTE *m_visualCollection.m_dynArray.m_pData;
	
	/*
	 * Offset = { 56b, 14dw, 7qw }
	 * Size   = {  8b,  2dw, 1qw }
	 */
	// void * const m_visualCollection.m_dynArray.InitialAllocation;
	
	/*
	 * Offset = { 64b, 16dw, 8qw }
	 * Size   = { 4b, 1dw }
	 */
	// UINT const m_visualCollection.m_dynArray.AllocSize;
	
	/*
	 * Offset = { 68b, 17dw }
	 * Size   = { 4b, 1dw }
	 */
	// UINT const m_visualCollection.m_dynArray.Capacity;
	
	/*
	 * Offset = { 72b, 18dw }
	 * Size   = { 4b, 1dw }
	 */
	// UINT m_visualCollection.m_dynArray.Count;
	
	//===================================================================================
	// Class data members:
	//
	
	/*
	 * Offset = { 16b, 4dw, 2qw }
	 * Size   = {  8b, 2dw, 1qw }
	 *
	 * == Origin ==
	 * Created on the global CCompositor in our Initialize().
	 */
	CVisualProxy *m_pVisualProxy = nullptr;
	
	/*
	 * Offset = { 24b, 6dw, 3qw }
	 * Size   = {  8b, 2dw, 1qw }
	 *
	 * == Origin ==
	 * Created on the global CCompositor in our Initialize().
	 */
	CVisual *m_pParent = nullptr;
	
	/*
	 * Offset = { 32b,  8dw, 4qw }
	 * Size   = { 48b, 12dw, 6qw }
	 *
	 * == Remarks ==
	 * Structure data is copied into this class.
	 */
	VisualCollection m_visualCollection;
	
	// The huge gap here is because the members in between these are inherited members
	// from the VisualCollection.
	
	/*
	 * Offset = { 96b, 24dw, 12qw }
	 * Size   = {  8b,  2dw,  1qw }
	 *
	 * == Origin ==
	 * SetContent()
	 */
	CResourceProxy *m_pContent = nullptr;
};