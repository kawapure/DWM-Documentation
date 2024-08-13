//
// Object: DynArrayImpl
//
// Module: uDWM.dll
//
// Responsibility: Dynamic array allocation.
//

// This module is open-source:
// https://github.com/dotnet/wpf/blob/bdec3d515f52c55bc3a6431e71db97c88f868215/src/Microsoft.DotNet.Wpf/src/WpfGfx/common/shared/dynarrayimpl.cpp
// https://github.com/dotnet/wpf/blob/bdec3d515f52c55bc3a6431e71db97c88f868215/src/Microsoft.DotNet.Wpf/src/WpfGfx/common/shared/dynarrayimpl.h

// If you don't want to look at the implementation details, here is a quick abstract
// of members:

/*
 * Size = { 32b, 8dw, 4qw }
 */
template <bool fZeroMemory = false>
struct DynArrayImpl
{
	/*
	 * Offset = 0
	 * Size   = { 8b, 2dw, 1qw }
	 */
	BYTE *m_pData;
	
	/*
	 * Offset = { 8b, 2dw, 1qw }
	 * Size   = { 8b, 2dw, 1qw }
	 */
	void * const InitialAllocation;
	
	/*
	 * Offset = { 16b, 4dw, 2qw }
	 * Size   = { 4b, 1dw }
	 *
	 * == Remarks ==
	 * Offset for alignment.
	 */
	UINT const AllocSize;
	
	/*
	 * Offset = { 20b, 5dw }
	 * Size   = {  4b, 1dw }
	 */
	UINT const Capacity;
	
	/*
	 * Offset = { 24b, 6dw }
	 * Size   = {  4b, 1dw }
	 */
	UINT Count;
};

template <typename T, bool fZeroMemory = false>
struct DynArray : public DynArrayImpl<fZeroMemory>;