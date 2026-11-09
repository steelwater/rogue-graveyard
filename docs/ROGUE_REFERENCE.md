# Rogue 5.4.4 — Death and score reference notes

Reference: [Davidslv/rogue](https://github.com/Davidslv/rogue). Inspected: 2026-11-09. These notes interpret reference behavior, **not** an assertion that fictional cemetery profiles represent real Rogue games.

## Ground truth from the upstream code

- [rip.c](https://github.com/Davidslv/rogue/blob/master/rip.c): `death(char monst)` renders the original tombstone (when enabled), including the player's name (`whoami`), gold amount (`purse` after a 10% death penalty), killer text (`killname`), and a calendar year. It calls `score(purse, amulet ? 3 : 0, monst)`.
- `score(int amount, int flags, char monst)` saves and prints a score entry consisting of score/gold, name, ending flag, dungeon level (`level` or `max_level` for a winner), and killer code. Its displayed reasons are **killed**, **quit**, **A total winner**, and **killed with Amulet**.
- `killname` resolves uppercase monster codes using the monster table and special lowercase codes: `a` arrow, `b` bolt, `d` dart, `h` hypothermia, and `s` starvation. Do not assume every death is a monster kill.
- [rogue.h](https://github.com/Davidslv/rogue/blob/master/rogue.h) defines `AMULETLEVEL 26` and Rogue item symbols (weapons, armor, scrolls, potions, rings, sticks, food, gold, and the amulet). For future randomized tombstones, plausible depths should respect this context; 26 is the amulet's dungeon depth, not a hard maximum dungeon level.
- [monsters.c](https://github.com/Davidslv/rogue/blob/master/monsters.c) includes `lvl_mons` (a progression array indexed by depth), `randmonster`, and `new_monster`. For procedural epitaphs, choose monsters compatible with the recorded depth instead of selecting the entire roster uniformly.
- Upstream `rip.c` does **not** preserve full inventories, experience, a cause-of-death anecdote, or epitaph prose in the score record. Future Graveyard profiles containing these fields are **fictional generated reconstructions**, not imported history.

## Data-design guidance for Milestones 2–3

Proposed compact RAM record (design note, not yet implemented): a seed plus packed name index, depth, gold, XP bracket, item index, cause type, culprit index and closing-line index. Keep fixed fragments in flash via `F()`/`PROGMEM`.

Validation rules:

1. A death cause of starvation/hypothermia/projectile must not be described as a monster attack unless separately and consistently represented.
2. A monster killer must be found in Rogue's original monster vocabulary; consider the level progression.
3. No NetHack-specific classes, alignments, gods, or invented spells.
4. Every grave is stable during a single program launch; on executable reset, new fictional stories may be generated (Milestone 2).
5. No persistent grave records, EEPROM, FX writes, shared data or Rogue End Run dependency.

## License provenance

Original Rogue copyright: **Michael Toy, Ken Arnold and Glenn Wichman**, with notices for other contributors in the upstream license. Its [LICENSE.TXT](https://github.com/Davidslv/rogue/blob/master/LICENSE.TXT) is preserved verbatim at [third_party/ROGUE-LICENSE.TXT](../third_party/ROGUE-LICENSE.TXT) for attribution and future compatibility. This project creates its own screen layout and code; the upstream tombstone image, source and inventory data are **not copied** into Milestone 0.
