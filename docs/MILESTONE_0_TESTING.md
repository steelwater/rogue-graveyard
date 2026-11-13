# Milestone 0 — Verification checklist

**Status:** Desktop build, emulator screenshots, and reported emulator playtest passed on 2026-11-13. Physical Arduboy test is optional and not reported. Memory figures recorded from the tester's `pio run -t size` output.

## Toolchain

- [x] Run `pio run` from repository root (user confirmed successful build).
- [x] Confirm `.pio/build/arduboy/firmware.hex` exists (user located it).
- [x] Run `pio run -t size`; record actual flash/RAM below.
- [x] Load generated HEX into Arduboy emulator (two screenshots attached to PR).
- [ ] Flash and test on physical standard Arduboy (optional; not yet reported).

## Manual interaction

- [x] Initial title and placeholder screens visibly render in emulator screenshots.
- [x] Tester reports emulator playthrough with no issues.
- [ ] Individually confirm A, B, button hold edge handling, and reset behavior on hardware or in a detailed follow-up report (no separate per-control results supplied).
- [ ] D-pad inactivity verified separately (intended until Milestone 1).
- [x] No EEPROM or FX writes in Milestone 0 source (code inspection).

## Memory budget (standard Arduboy / ATmega32U4)

| Resource | Hardware capacity | Milestone 0 target | Measured |
| --- | --- | --- | --- |
| SRAM | 2,560 B | <= 2,048 B used; >= 512 B remaining | **1,202 B (47.0%); 1,358 B free** |
| Flash | 28 KB usable according to PlatformIO | <= 26,000 B image | **7,004 B (21.4% of 32,768 B; ~24.4% of 28 KB usable); 21,668 B usable space left** |
| EEPROM | 1,024 B | 0 B written | No write calls in source; no runtime persistence test |
| Display | 128x64 pixels | Arduboy2 framebuffer ~1,024 B SRAM | Included in total static RAM use |

Note: PlatformIO's AVR Memory Usage output reports Program: 7,004 bytes (21.4% Full) and Data: 1,202 bytes (47.0% Full). The Program percent shown uses 32 KB physical flash while the configured board advertises 28 KB usable application flash. The static SRAM number does not measure maximum stack depth.

## Tester report

- Date: November 13, 2026.
- Environment: macOS desktop; Arduboy emulator (physical device untested).
- Platform: Atmel AVR 5.3.0, Arduino AVR framework 5.4.0, toolchain 7.3.0, Arduboy2 6.0.0.
- Target: ATmega32U4 16 MHz, 2.50 KB RAM, 28 KB flash.
- Firmware program size: **7,004 bytes**.
- Static data/SRAM: **1,202 bytes**.
- Simulator: title and placeholder visible, no issues reported.
- Hardware: Not tested.
- Evidence: [PR #1 test comment and screenshots](https://github.com/steelwater/rogue-graveyard/pull/1#issuecomment-6852191979).
- Outcome: **Milestone 0 build, emulator smoke test and memory-budget checks passed.** Physical testing and granular control checklist remain optional follow-up.

No further features from Milestone 1 or later are included here.
