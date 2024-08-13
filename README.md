# DWM Documentation

This repository serves to document the internals of Windows's Desktop Window Manager (DWM).

The files provided are pseudo-C++ header files with comments documenting the sizes and offsets of each member of each class. Sometimes, code that doesn't really exist in the final binary (either due to inlining or code generation) will be thrown in. These will be marked accordingly.

Sizes and offsets are often given in units in brackets. These are multiple readings of the same number for reference: i.e. if you're working with a tool like IDA which will give you a bunch of different ones.

The suffixes map to the following meanings:

- `b`: byte
- `w`: word (2 bytes)
- `dw`: double word (4 bytes)
- `qw`: quadruple word (8 bytes)

Because this is quite frankly boring work, I have taken the liberty of sharing music with you in each one of the pseudo-C++ files.

## Files used

The contents of this repository are based on analysis of the following binaries:

- `uDWM.dll` version 10.0.19041.2075 (MD5 checksum: `436796AF7DE9FA609D92D42D51A7259B`)
- `dwmcore.dll` version 10.0.19041.2311 (MD5 checksum: `0986CB3CF33A9A96128035DB3D6E89EF`)

They should be mostly applicable for any Vibranium release (Windows 10 versions 2004 through 22H2). In other cases, you may have to consider that offsets have changed due to restructurings, or the introduction or removal of structure members.

## History of the Desktop Window Manager

The Desktop Window Manager (DWM) was introduced in Windows Vista to update the visual backend of the Windows desktop. Up until this point, the Windows desktop manager had not been significantly updated since Windows 2.0 (or NT 3.1—pick your poison).

DWM was developed alongside Windows Presentation Foundation (WPF, codenamed Avalon), and the two share many technologies. One of these technologies is the **Media Integration Layer** (MIL), the shared visual backend. The source code to MIL was released alongside WPF, which serves as a valuable reference for this project.

In Windows Vista, DWM shared the same MIL binary (`milcore.dll`) with WPF programs. Windows 7 forked the MIL codebase used for DWM into a separate codebase (internally located at `windows/dwm/dwmcore`) stored in the `dwmcore.dll` binary.

## Differences between open-source MIL and DWMCore

As the MIL codebase used for WPF and the MIL codebase used for DWM have diverged, there are quite a few differences. Here is a comparison of the source trees. [The DWMCore source tree is taken from this Windows 10 build 9364 source tree dump by Alex Ionescu](https://windows-internals.com/source/files.html). Please note that the source code for DWMCore is unavailable.

`windows/dwm/dwmcore` maps mostly to `wpf/src/Microsoft.DotNet.Wpf/src/WpfGfx/core` (the open-source WPF-MIL codebase) or `wpf/src/graphics/core` (the private WPF-MIL codebase), but there are some significant differences.

- [ ] `api`
- [x] `bitmaps` (DWMCore-specific) (*)
- [x] `common` (contents moved to `common/core` subdirectory)
- [x] `dll`
- [x] `effects` (*)
- [x] **`engine`** (renamed from `uce` in WPF-MIL) (*)
- [ ] `fxjit`
- [x] `geometry` (*)
- [ ] `glyph`
- [x] `hw` (*)
- [x] `input` (DWMCore-specific)
- [ ] `log` (private WPF-MIL only)
- [ ] `meta`
- [x] `renderer` (DWMCore-specific) (*)
- [x] `resources` (*)
- [ ] `sw`
- [x] `targets` (*)
- [ ] *`uce`* (renamed to `engine` in DWMCore)

(*) denotes that contents are placed in a `native` subdirectory in DWMCore, but not in WPF-MIL if applicable.