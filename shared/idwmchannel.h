//
// Object: DwmChannel
//
// Module: uDWM.dll, dwmcore.dll
//
// Responsibility: 
//
// Song :3 -- Townie - Mitski
//

/*
 UNFINISHEDDDDDDDDDDDDDDD!!!!!!

 * == Remarks ==
 * This is an interface shared between uDWM and DWMCore which defines the API
 * for CChannel implemented in DWMCore.
 */
struct IDwmChannel : public IUnknown
{
	//===================================================================================
	// Implicit virtual function members:
	//
	
	// VTable offset = 0
	// from IUnknown
	virtual HRESULT QueryInterface(IID *riid, OUT void **ppOut) = 0;
	
	// VTable offset = { 8b, 2dw, 1qw }
	// from IUnknown
	virtual int AddRef() = 0;
	
	// VFTable offset = { 16b, 4dw, 2qw }
	// from IUnknown
	virtual int Release() = 0;

	//===================================================================================
	// Virtual function members:
	//
	
	virtual HRESULT Commit() = 0;
	virtual HRESULT SynchronizedCommit(void *a2) = 0;
	virtual HRESULT Destroy() = 0;
	virtual HANDLE /* probably */ GetKernelHandle() = 0;
	virtual bool PeekNextMessage(MIL_MESSAGE *pMsg, size_t cbSize) = 0;
	virtual void SetReceiveBroadcastMessages(bool fReceiveBroadcast) = 0;
	virtual HRESULT SyncFlush() = 0;
	virtual HRESULT WaitForNextMessage(IMessageLoopExtensions *a2, DWORD nCount, const HANDLE *pHandles, BOOL bWaitAll, DWORD waitTimeout) = 0;
	virtual HRESULT AddRefResource(HMIL_RESOURCE *ph) = 0;
	
	/*
	 * == Remarks ==
	 * The type is explicitly converted from a "DWM type" to a MIL type by the
	 * aptly-named function, CChannel::MilTypeFromDwmType (in DWMCore).
	 */
	virtual HRESULT CreateResource(DwmResourceType::Enum dwmResourceType, DWORD *a3) = 0;
	
	virtual HRESULT CreateSharedResource(DwmResourceType::Enum dwmResourceType, DWORD *a3, OUT HANDLE *phSharedHandle) = 0;
	
	virtual HRESULT DuplicateSharedResource(HANDLE hSharedResource, DwmResourceType::Enum dwmResourceType, DWORD *a5) = 0;
	
	virtual HRESULT ReleaseResource(DWORD a2) = 0;
	
	virtual HRESULT CreateRenderDataBuilder(OUT IRenderDataBuilder **ppOut) = 0;
	
	virtual HRESULT RoundTripRequest(DWORD a2) = 0;
	
	virtual HRESULT AsyncFlush(DWORD a2, DWORD a3) = 0;
	
	virtual HRESULT PartitionRegisterForNotifications(bool a2) = 0;
	
	virtual HRESULT PartitionForceRender(bool a2, bool a3, DwmHardwareTeardown::Enum a4, bool a5) = 0;
	
	virtual HRESULT PartitionSetCurrentMmTask(DWM_MMTASK *pDwmMmTask) = 0;
	
	virtual HRESULT PartitionTelemetryTouchInteractionBegin(TOUCH_TELEMETRY_BEGIN_INFO *pInfo) = 0;
	
	virtual HRESULT PartitionTelemetryTouchInteractionUpdate(TOUCH_TELEMETRY_UPDATE_INFO *pInfo) = 0;
	
	virtual HRESULT PartitionTelemetryTouchInteractionEnd(TOUCH_TELEMETRY_END_INFO *pInfo) = 0;
	
	virtual HRESULT PartitionTelemetryInputActivity(DWORD a2, void *a3) = 0;
	
	virtual HRESULT PartitionTelemetryAnimationScenarioBegin(const void *a2, DWORD a3, GUID *a4) = 0;
	
	virtual HRESULT PartitionTelemetryAnimationScenarioReference(const GUID *a2, void *a3) = 0;
	
	virtual HRESULT PartitionTelemetryAnimationScenarioUnreference(const GUID *a2, void *a3) = 0;
	
	virtual HRESULT PartitionUpdateCursorMouseMove() = 0;
	
	virtual HRESULT PartitionSwitchRemotingMode(DwmRemotingMode::Enum remotingMode) = 0;
	
	virtual HRESULT PartitionSetCursor(HANDLE a2, bool a3) = 0;
	
	virtual HRESULT PartitionSetMagnifier(DWORD a2, bool a3) = 0;
	
	virtual HRESULT PartitionSetExcludeFromDDA(HANDLE a2, bool a3) = 0;
	
	virtual HRESULT PartitionToggleHolographicSuspension(bool a2) = 0;
	
	virtual HRESULT BitmapSource(HANDLE a2, IWICBitmap *a3) = 0;
	
	virtual HRESULT DoubleResourceUpdate(HANDLE a2, double a3) = 0;
	
	virtual HRESULT RectResourceUpdate(HANDLE a2, MilRectF *a3) = 0;
	
	virtual HRESULT SizeResourceUpdate(HANDLE a2, MilSizeD *a3) = 0;
	
	virtual HRESULT ColorTransformResourceUpdate(HANDLE a2, MilColorTransform *a3) = 0;
	
	virtual HRESULT RedirectVisualSetRedirectedVisual(HANDLE a2, void *a3) = 0;
	
	virtual HRESULT RenderDataUpdate(HANDLE a2, IRenderDataBuilder *a3) = 0;
	
	virtual HRESULT SyncLegacyVisualCaptureRenderTargetCaptureBits(
		HANDLE a2,
		HANDLE a3,
		float a4,
		int a5,
		int a6,
		int a7,
		int a8,
		void *a9,
		DXGI_FORMAT *a10,
		void **a11
	) = 0;
	
	virtual HRESULT VisualSetOffset(HANDLE a2, double a3, double a4, double a5) = 0;
	
	virtual HRESULT VisualSetSize(HANDLE a2, double a3, double a4) = 0;
	
	virtual HRESULT VisualSetRelativeSize(HANDLE a2, double a3, double a4) = 0;
	
	virtual HRESULT VisualSetTouchTargetRect(HANDLE a2, RECT *a3) = 0;
	
	virtual HRESULT VisualSetTransform(HANDLE a2, void *a3) = 0;
	
	virtual HRESULT VisualSetEffect(HANDLE a2, void *a3) = 0;
	
	virtual HRESULT VisualSetClip(HANDLE a2, void *a3) = 0;
	
	virtual HRESULT VisualSetRenderOptions(HANDLE a2, MilRenderOptions *a3) = 0;
	
	virtual HRESULT VisualSetOptions(HANDLE a2, bool a3, bool a4) = 0;
	
	virtual HRESULT VisualProtectContent(HANDLE a2, bool a3) = 0;
	
	virtual HRESULT VisualSetContent(HANDLE a2, void *a3) = 0;
	
	virtual HRESULT VisualRemoveAllChildren(HANDLE a2) = 0;
	
	virtual HRESULT VisualRemoveChild(HANDLE a2, void *a3) = 0;
	
	virtual HRESULT VisualInsertChildAt(HANDLE a2, void *a3, void *a4) = 0;
	
	virtual HRESULT VisualMoveChild(HANDLE a2, void *a3, void *a4) = 0;
	
	virtual HRESULT VisualSetColorTransform(HANDLE a2, void *a3) = 0;
	
	virtual HRESULT VisualTopLevelNode(HANDLE a2, HWND *a3, bool a4) = 0;
	
	virtual HRESULT VisualSetInteraction(HANDLE a2, void *a3) = 0;
	
	virtual HRESULT VisualSetPassiveUpdateMode(HANDLE a2, bool a3) = 0;
	
	virtual HRESULT VisualSetExcludeSubtree(HANDLE a2, bool a3) = 0;
	
	
};