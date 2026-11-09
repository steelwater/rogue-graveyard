# Milestone 0 — Verification checklist

**Status:** Code and build configuration prepared. Compilation, simulator checks and hardware tests are **not yet verified**. Do not mark Milestone 0 complete until this checklist is checked with recorded results.

## Toolchain

- [ ] Install PlatformIO Core / IDE extension and run `pio run` from repository root.
- [ ] Confirm `.pio/build/arduboy/firmware.hex` exists and is nonempty.
- [ ] Run `pio run -t size`; record actual flash/RAM use below.
- [ ] Load generated HEX into an Arduboy simulator; ensure all strings fit the 128x64 display.
- [ ] Flash and test on physical standard Arduboy (if available).

## Manual interaction

- [ ] Initial boot displays ROGUE GRAVEYARD and A: ENTER.
- [ ] One press of **A** reaches THE GRAVEYARD placeholder.
- [ ] One press of **B** returns to the title; repeated visits do not change state unexpectedly.
- [ ] Held A/B do not repeatedly transition because `justPressed` is edge-triggered.
- [ ] D-pad does not move anything in Milestone 0 (intentional; movement is Milestone 1).
- [ ] Reset/boot returns to title. No EEPROM writes or FX save writes.

## Memory budget (standard Arduboy / ATmega32U4)

| Resource | Hardware capacity | Milestone 0 budget / target | Actual |
| --- | --- | --- | --- |
| SRAM | 2,560 B | **<= 2,048 B used**, reserve >= 512 B for stack/headroom | Pending compilation |
| Flash | 32,768 B physical (bootloader reserves a portion) | **<= 26,000 B image target** for early development | Pending compilation |
| EEPROM | 1,024 B | 0 B written | No write calls |
| Display | 128x64 pixels, 1 bit/pixel | Arduboy2 framebuffer approximately 1,024 B SRAM | Expected; verify build |

> The flash budget is a conservative development target, not a measured usable-capacity claim. Toolchain and library versions affect memory usage; verify actual sizes with `pio run -t size`. The Arduboy2 framebuffer itself accounts for ~1KB SRAM, so keep future grave structs small.

## Tester report

- Date/device:
- PlatformIO / toolchain:
- Firmware size:
- SRAM used:
- Simulator result:
- Hardware result:
- Defects / screenshots:
- Outcome: Pending
