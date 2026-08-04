# Contributing to QuickLootIE

Thank you for helping improve QuickLootIE. This fork prioritizes runtime safety,
gameplay fidelity, compatibility, reproducibility, and respectful upstream
collaboration.

## Before starting

1. Search existing issues and master trackers.
2. For a defect, provide a minimal reproduction, affected Skyrim runtime, SKSE
   version, QuickLootIE commit or release, and relevant log or crash record.
3. For a proposed change, describe the observable behavior and acceptance
   criteria before implementation.
4. Keep one pull request focused on one coherent concern.

Security-sensitive reports must follow [SECURITY.md](SECURITY.md) and must not be
opened publicly until coordinated disclosure is appropriate.

## Engineering requirements

- Do not commit directly to `main`.
- Preserve compatibility with the declared runtime matrix unless the change is
  explicitly approved and documented.
- Add or update automated tests for behavior that can be exercised outside the
  game. Provide a repeatable in-game verification procedure for engine-bound
  behavior.
- Treat compiler success as a build check, not proof of runtime correctness.
- Pin build inputs where practical and document unavoidable floating inputs.
- Do not add redistributed assets without recording their source, license,
  author, required attribution, and redistribution permission.
- Update the audit register when resolving or invalidating a recorded finding.
- Use `Fixes #<issue>` only when the pull request fully satisfies that issue's
  acceptance criteria.

The complete policy, priority definitions, and definition of done are in
[docs/engineering/standards.md](docs/engineering/standards.md).

## Native policy tests

Host-side policy tests do not require Skyrim, SKSE, or CommonLibSSE. From the
repository root, run:

```powershell
xmake f -F xmake.lua -P tests -y -m release -p windows -a x64
xmake -F xmake.lua -P tests -y
xmake run -F xmake.lua -P tests QuickLootIEPolicyTests `
  --reporter console --colour-mode none
```

The test project and its package lock are independent of the game-plugin build.
Update `tests/xmake-requires.lock` intentionally whenever a test dependency is
changed.

## Pull requests

Pull requests must state:

- the problem and linked issue;
- user-visible and technical effects;
- affected runtimes and integrations;
- verification performed and remaining gaps;
- compatibility, save-game, performance, and licensing risk;
- rollback or recovery considerations when the change is high risk.

Draft pull requests are encouraged for early design review. A pull request is
not release-ready merely because CI passes.
