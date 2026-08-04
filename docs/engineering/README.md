# QuickLootIE engineering handbook

This directory is the authoritative maintenance record for this fork. It keeps
facts, hypotheses, product limitations, and release decisions distinct.

## Documents

- [Engineering standards](standards.md) defines priorities, evidence rules,
  review expectations, and the definition of done.
- [Audit register](audit-register.md) assigns immutable identifiers to findings
  and links them to their tracking issues.
- [Compatibility policy](compatibility.md) records supported targets,
  dependencies, known boundaries, and integration policy.
- [Initial source audit](audits/2026-08-04-source-audit.md) preserves the
  evidence and scope of the baseline review.

## Sources of truth

The following precedence applies:

1. Source code and reproducible test evidence.
2. Accepted architecture and engineering documentation in this repository.
3. Repository issues and pull requests.
4. Current upstream documentation and issue reports.
5. Anecdotal reports that have not yet been reproduced.

Disagreement between these sources is itself a finding and must be resolved or
documented before release.

## Tracking model

Every audit entry has a stable `QLIE-AUD-NNN` identifier. Actionable entries are
linked to a narrowly scoped child issue. Related child issues are collected by
master issues labeled `kind: tracking`.

Master issues coordinate a principle or risk domain; they do not replace child
issues. Each child remains independently testable, reviewable, and closable.
