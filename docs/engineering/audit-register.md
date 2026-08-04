# Engineering audit register

Audit identifiers are immutable. Rows remain in this register after resolution;
their status and issue links are updated instead of deleting or renumbering
them.

<!-- markdownlint-disable MD013 -->

| ID           | Classification      | Priority | Area              | Summary                                                                                                   | Status        | Issue                                                                   |
| ------------ | ------------------- | -------: | ----------------- | --------------------------------------------------------------------------------------------------------- | ------------- | ----------------------------------------------------------------------- |
| QLIE-AUD-001 | Verified defect     |       P0 | Runtime safety    | `UniversalMenu` manually destroys `menuName`, which is then destroyed automatically                       | In review     | [#6](https://github.com/Ensrick/QuickLootIE/issues/6)                   |
| QLIE-AUD-002 | Verified defect     |       P1 | Item actions      | Theft calculation checks the container owner instead of the resolved item owner                           | Open          | [#10](https://github.com/Ensrick/QuickLootIE/issues/10)                 |
| QLIE-AUD-003 | Verified defect     |       P1 | Item data         | Poisoned-weapon detection is inverted                                                                     | Open          | [#11](https://github.com/Ensrick/QuickLootIE/issues/11)                 |
| QLIE-AUD-004 | Investigation       |       P1 | Item actions      | Use/equip passes the source stack count after transferring one item; book use transfers the whole stack   | Open          | [#12](https://github.com/Ensrick/QuickLootIE/issues/12)                 |
| QLIE-AUD-005 | Verified defect     |       P2 | Item data         | Two-handed weapons fall through into ranged best-in-class evaluation                                      | Open          | [#13](https://github.com/Ensrick/QuickLootIE/issues/13)                 |
| QLIE-AUD-006 | Verified defect     |       P2 | Item data         | Armor fallback processing is called twice and known-form processing is skipped                            | Open          | [#14](https://github.com/Ensrick/QuickLootIE/issues/14)                 |
| QLIE-AUD-007 | Verified defect     |       P2 | Input             | The post-1.6.1130 input context is immediately overwritten by the legacy value                            | Open          | [#15](https://github.com/Ensrick/QuickLootIE/issues/15)                 |
| QLIE-AUD-008 | Maintenance         |       P2 | Configuration     | Wrong JSON value types are not handled consistently and blacklist reloads only add entries                | Open          | [#7](https://github.com/Ensrick/QuickLootIE/issues/7)                   |
| QLIE-AUD-009 | Known limitation    |       P3 | Input/UI          | Whole-page scrolling actions are present but unimplemented                                                | Upstream open | [upstream #94](https://github.com/MissCorruption/QuickLootIE/issues/94) |
| QLIE-AUD-010 | Known limitation    |       P1 | Compatibility     | Scripted activators require explicit exclusion or integration                                             | Open          | [#16](https://github.com/Ensrick/QuickLootIE/issues/16)                 |
| QLIE-AUD-011 | Verified defect     |    P0-VR | VR/runtime safety | VR polling shares non-atomic state across threads and has no shutdown path                                | Open          | [#18](https://github.com/Ensrick/QuickLootIE/issues/18)                 |
| QLIE-AUD-012 | Investigation       |       P1 | Runtime safety    | Container animation reads engine state from detached worker threads                                       | Open          | [#8](https://github.com/Ensrick/QuickLootIE/issues/8)                   |
| QLIE-AUD-013 | Known limitation    |    P0-VR | VR                | VR contains hard-coded transforms, raw offsets, TODO lifecycle work, and missing enchanted-weapon refresh | Open          | [#18](https://github.com/Ensrick/QuickLootIE/issues/18)                 |
| QLIE-AUD-014 | Maintenance         |       P0 | Verification      | No automated behavior or runtime regression tests exist                                                   | Open          | [#19](https://github.com/Ensrick/QuickLootIE/issues/19)                 |
| QLIE-AUD-015 | Maintenance         |       P1 | Build             | Several build inputs float despite the presence of lock metadata                                          | Open          | [#21](https://github.com/Ensrick/QuickLootIE/issues/21)                 |
| QLIE-AUD-016 | Verified defect     |       P1 | Release           | Manual release inputs are interpolated into shell code; release actions are not immutable                 | Open          | [#22](https://github.com/Ensrick/QuickLootIE/issues/22)                 |
| QLIE-AUD-017 | Maintenance         |       P2 | Build/docs        | CMake is not exercised by CI and build/version documentation is stale                                     | Open          | [#21](https://github.com/Ensrick/QuickLootIE/issues/21)                 |
| QLIE-AUD-018 | Maintenance         |       P1 | Distribution      | Packaged notices do not preserve the complete upstream attribution record                                 | Open          | [#23](https://github.com/Ensrick/QuickLootIE/issues/23)                 |
| QLIE-AUD-019 | Maintenance         |       P3 | Packaging         | Player artifact includes a 25.6 MB PDB instead of separating debug symbols                                | Open          | [#23](https://github.com/Ensrick/QuickLootIE/issues/23)                 |
| QLIE-AUD-020 | Upstream dependency |       P1 | Input             | DualShock 4 behavior has a current upstream incompatibility report on 1.6.1170                            | Upstream open | [#17](https://github.com/Ensrick/QuickLootIE/issues/17)                 |
| QLIE-AUD-021 | Investigation       |       P1 | Runtime safety    | A defensive `RefreshOpenState` re-entry guard remains under upstream review                               | Upstream open | [#9](https://github.com/Ensrick/QuickLootIE/issues/9)                   |

<!-- markdownlint-enable MD013 -->

The detailed evidence baseline is preserved in
[the 2026-08-04 source audit](audits/2026-08-04-source-audit.md).
