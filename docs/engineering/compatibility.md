# Compatibility policy

## Product targets

The upstream project advertises Skyrim Special Edition runtimes from 1.5.97
through 1.6.1179. Runtimes older than 1.6.1130 require Backported Extended ESL
Support. This fork's first qualification target is Skyrim 1.6.1170 with its
matching SKSE release.

Support claims are earned per runtime and input device. A successful all-runtime
CommonLib build does not by itself qualify every runtime.

## Required runtime dependencies

- Skyrim Script Extender (SKSE64)
- Address Library for SKSE Plugins
- SkyUI
- PapyrusUtil SE
- Microsoft Visual C++ Redistributable for Visual Studio 2022

Inventory Interface Information Injector is optional. Compatibility claims for
optional integrations require the integration to be present in the test matrix.

## User-interface compatibility

QuickLootIE uses `LootMenuIE.swf`. Reskins made for QuickLootEE's older menu are
not compatible unless explicitly ported for QuickLootIE's interface and feature
level. A legacy `LootMenu.swf` warning is diagnostic, not proof that all
overwriting interface files have been removed.

## Scripted activators and containers

QuickLootIE directly transfers items and synthesizes activation and open/close
events. Containers or activators whose scripts require normal activation may
need one of the following:

- a `containerBlacklist` entry in `QuickLootIE.json`;
- the `QuickLootIE_Exclude` keyword;
- coordination through the public API;
- a dedicated compatibility patch.

Known exclusions must record mod name, form identifier, reason, reporter, and
verification procedure. Unknown quest and alternate-start integrations are not
implicitly guaranteed by one successful blacklist entry.

## Input devices

Keyboard/mouse, Xbox-compatible controllers, DualShock/DualSense controllers,
and Steam Input are separate qualification targets. A binding that works on one
controller family is not assumed to work on another.

## Skyrim VR

VR currently compiles but is experimental and is not stability-qualified. It
must not be advertised as supported until its object layout, raw offsets,
threading, lifecycle, transforms, input behavior, and enchanted-weapon handling
have dedicated verification and all VR release blockers are closed.
