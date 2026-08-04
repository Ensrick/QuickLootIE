# Initial source and release audit — 2026-08-04

## Scope

This review examined fork commit `ce1b8f0555c38a38dba7d10464d28a353be16d7b`,
based on upstream commit `2c0c878dea1776928a15ce906bac9209f9d33f1c`.
It covered native source, Papyrus source, serialized plugin input, packaged files,
GitHub Actions workflows, current upstream issues, and published compatibility
and permission statements.

The DLL, ESP, Papyrus, and packaging jobs compiled successfully. Compilation was
treated as build evidence only; no in-game qualification was inferred.

## Verified source defects

### QLIE-AUD-001 — string-pool member is destroyed twice

`UniversalMenu::~UniversalMenu` explicitly invokes
`menuName.~BSFixedString()`. `menuName` is a normal member of `IMenuVR` and is
destroyed again automatically after the derived destructor body. CommonLib's
`BSFixedString` destructor releases the stored string-pool pointer without
clearing it. This is undefined behavior and a credible intermittent corruption
or crash source during menu teardown.

### QLIE-AUD-002 — resolved item ownership is discarded

`ItemStack::IsStealing` resolves `itemOwner` from entry ownership, actor, or
container ownership and uses it for the permission check. Its return expression
instead tests `owner`, the container owner. An individually owned item in an
otherwise unowned container can therefore be reported and processed as not
stolen. The result also controls removal reason and `StealAlarm` behavior.

### QLIE-AUD-003 — poisoned state is inverted

Weapon item-data processing sets `isPoisoned` only when the selected extra-data
list does _not_ contain `ExtraDataType::kPoison`. This reverses the intended
condition and affects icons, sorting, integrations, and API consumers.

### QLIE-AUD-005 — two-handed weapons also compete as ranged weapons

The best-in-class weapon switch has no `break` after the two-handed cases.
Two-handed melee weapons update both the two-handed and ranged candidates.

### QLIE-AUD-006 — known armor exceptions never execute

The armor processing path calls `SkyUiProcessArmorOther` twice and never calls
`SkyUiProcessArmorKnownForms`. The explicit wedding-wreath and Vampire Lord
armor exceptions are consequently unreachable through the normal processing
path.

### QLIE-AUD-007 — version-specific input context is overwritten

`UniversalMenu::ConstructFlatrim` writes context 19 on runtime 1.6.1130 or newer
and then unconditionally writes context 18. The branch cannot affect the final
value. Immediate impact may be latent while the menu does not request the normal
menu context, but the implementation contradicts its version handling.

## Investigations

### QLIE-AUD-004 — use/equip count semantics

The use action transfers one normal item and then calls `EquipObject` with the
source entry's full `countDelta`. Ammo and books are transferred as complete
stacks. Engine behavior must be tested for stacked consumables, ingredients,
weapons, armor, ammo, spell tomes, and ordinary books before prescribing the
final count policy.

### QLIE-AUD-012 — detached container animation workers

Container animation creates detached threads that poll engine object state and
later queue a main-thread task. The object is retained by a smart reference, but
engine read-thread safety, repeated-thread accumulation, and process teardown
remain unproven.

### QLIE-AUD-021 — open-state re-entry defense

Upstream pull request 110 proposes a re-entry guard. The maintainer reports that
the submitted stack overflow's root cause was fixed separately, while agreeing
that a guard is useful defense in depth. The fork should reproduce the original
failure and decide whether to implement a clean guard independently.

## Compatibility and product limitations

- Direct item transfer and synthesized activation events cannot reproduce every
  scripted activator's behavior. The default blacklist covers known vanilla and
  Alternate Start cases, not every quest or alternate-start mod.
- Whole-page input actions have empty handlers.
- Current upstream reports identify DualShock 4 binding behavior as unresolved.
- QuickLootIE 4.0 is published as beta software; the audited source is newer
  nightly development code.
- Skyrim VR builds but contains a cross-thread data race, an infinite detached
  poller, raw offsets, hard-coded transforms, incomplete HUD lifecycle work, and
  an unimplemented enchanted-weapon refresh path.

## Verification gap

No repository tests exercise ownership, transfer semantics, item classification,
version selection, configuration reloads, menu lifecycle, input mappings, or
integration behavior. The existing workflow validates compilation and assembly
of artifacts, not runtime correctness.

## Build, release, and distribution findings

- Spriggit is downloaded from the latest release while a nominal version input
  affects only the cache key.
- XMake is selected as `latest`, its repository is updated during builds, and
  Papyrus source inputs are fetched from branch heads.
- Release-related third-party actions use mutable tags rather than commit SHAs.
- Manual release strings are directly interpolated into shell programs.
- CMake is documented but absent from CI; `vcpkg.json` still declares 2.0.0.
- Player packages include development symbols.
- The MIT license is packaged, but the binary package lacks a complete credits
  or third-party-notices document matching the upstream permission record.

## Initial release decision

The artifact is suitable for controlled engineering tests, not for designation
as a stable release. QLIE-AUD-001 and the verification program are release
blockers. VR must remain explicitly experimental until its independent P0-VR
findings are resolved.
