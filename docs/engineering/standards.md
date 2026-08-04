# Engineering standards

## Principles

QuickLootIE runs inside a stateful native game process. Changes are therefore
evaluated for memory safety, engine-thread correctness, save-game behavior,
gameplay fidelity, compatibility, performance, reproducibility, and provenance.

Claims must be proportional to evidence. A source-level contradiction can be a
verified defect; uncertain engine behavior remains an investigation until it is
reproduced or demonstrated against authoritative engine behavior.

## Finding classifications

- **Verified defect:** the implementation contradicts its declared or directly
  inferable behavior, with sufficient source or runtime evidence.
- **Investigation:** credible risk whose runtime behavior or intended semantics
  are not yet proven.
- **Known limitation:** deliberate or currently accepted product boundary.
- **Maintenance:** engineering work that reduces future risk without correcting
  a presently demonstrated user-facing defect.
- **Upstream dependency:** behavior owned wholly or partly by another project;
  this repository still tracks local exposure and verification.

## Priority

- **P0 — release blocker:** credible corruption, uncontrolled crash, security or
  supply-chain compromise, or absence of evidence required to claim a stable
  release.
- **P1 — high:** material gameplay, compatibility, input, packaging, or
  reliability failure with no acceptable default-path mitigation.
- **P2 — normal:** incorrect or incomplete behavior with bounded impact or a
  practical workaround.
- **P3 — low:** polish, optional behavior, documentation debt, or low-impact
  packaging inefficiency.

Priority describes project response, not certainty. Certainty is represented by
the finding classification and `status:` label.

## Issue requirements

Verified-defect issues must include:

- stable audit identifier;
- affected targets;
- source or runtime evidence;
- expected and actual behavior;
- impact analysis;
- acceptance criteria;
- verification plan;
- parent master issue.

Investigation issues must state the hypothesis, evidence for and against it,
specific questions to answer, and the condition that converts or closes the
investigation.

## Change control

- Work occurs on a branch and enters `main` through review.
- High-risk native changes require at least one focused regression procedure.
- Changes to engine offsets, hooks, object layout, threading, ownership, item
  transfer, or crime handling require explicit risk notes.
- Generated artifacts are not accepted as the sole source of a change.
- Upstream synchronization must preserve local commits, document divergence,
  and rerun the complete validation matrix.

## Verification layers

1. Formatting and repository policy checks.
2. Compilation of the DLL, ESP, and Papyrus scripts.
3. Unit or host-side tests for pure logic.
4. Artifact inspection and reproducibility checks.
5. Minimal-load-order in-game regression tests.
6. Representative integration tests for supported configurations.
7. Soak or lifecycle testing when work touches menu creation, destruction,
   background tasks, save/load, or repeated cell transitions.

## Definition of done

A change is done only when:

- acceptance criteria are satisfied;
- tests or documented verification cover the failure mode;
- supported targets are not silently narrowed;
- performance and compatibility impacts are understood;
- documentation, changelog, credits, and audit status are updated as needed;
- CI is green from a clean checkout;
- the resulting package has been inspected;
- remaining uncertainty is explicitly recorded.

## Release gates

A stable release is prohibited while a P0 issue is open. Any waived P1 issue
requires a documented rationale, mitigation, and user-facing release note. Beta
and nightly artifacts must be clearly labeled and must not be promoted as
stability-qualified.
