# Rogue Graveyard

A small, standalone **Arduboy** cemetery inspired by **Rogue 5.4.4**. Eventually you'll explore a monochrome graveyard, walk up to up to five fictional adventurers' tombstones, and read their imagined end-of-run stories. This is **not** Rogue End Run, and it does not import actual play records.

**Development status:** Milestone 0 technical foundation. The title and a placeholder screen are implemented; movement, tombstones, randomized records, and epitaphs belong to later milestones.

## Build

Requires [PlatformIO Core](https://docs.platformio.org/en/latest/core/installation/index.html) or the PlatformIO IDE extension.

```sh
pio run
pio run -t size
```

The target is the **standard Arduboy**, using `atmelavr`, the Arduino framework and the `Arduboy2` library. Compiled output is at `.pio/build/arduboy/firmware.hex`. Flash it with your Arduboy flashing tool of choice, or load the HEX into an Arduboy-compatible simulator.

The build environment is defined in `platformio.ini`. It has not yet been compiled or tested on physical hardware in this PR; see [Milestone 0 verification](docs/MILESTONE_0_TESTING.md).

## Current controls

| Screen | A | B | D-pad |
| --- | --- | --- | --- |
| Title | Enter placeholder graveyard | No action | Reserved for later |
| Placeholder | No action | Return to title | Reserved for Milestone 1 |

Use **A** to enter and **B** to return. There are no EEPROM writes, saved graves, RNG-based profiles, or End Run links in Milestone 0.

## Roadmap

[Project roadmap](https://docs.google.com/document/d/11gZ2YML-7b2eJQJBDReymHJcC9IeYGlUvY_9rsEXves/edit)

- **Milestone 0:** Rogue reference notes, licensing and attribution, title-screen skeleton, build setup, testing plan, memory budget.
- **Milestone 1:** Walkable cemetery and three test tombstones.
- **Milestone 2:** Session-only grave generation (up to five).
- **Milestone 3:** Coherent, paginated epitaph reader.
- **Milestone 4:** Atmosphere and writing polish.
- **Milestone 5:** QA and first release.

## Source attribution and license

Rogue 5.4.4 is authored by Michael Toy, Ken Arnold and Glenn Wichman. Reference source: [Davidslv/rogue](https://github.com/Davidslv/rogue), especially [rip.c](https://github.com/Davidslv/rogue/blob/master/rip.c). See [reference notes](docs/ROGUE_REFERENCE.md) and the full [upstream license](third_party/ROGUE-LICENSE.TXT).

This project's **original** code is distributed under the [BSD 3-Clause License](LICENSE). No upstream Rogue source files or graphical assets are copied into the executable for this foundation milestone. Arduboy2 has its own applicable license; see its upstream repository.
