#ifndef GUARD_TRAINER_REMATCH_H
#define GUARD_TRAINER_REMATCH_H

enum {
    REMATCH_WALLY_3,
    REMATCH_ROXANNE,
    REMATCH_BRAWLY,
    REMATCH_WATTSON,
    REMATCH_FLANNERY,
    REMATCH_NORMAN,
    REMATCH_WINONA,
    REMATCH_TATE_AND_LIZA,
    REMATCH_JUAN,
    REMATCH_SIDNEY, // Entries below SIDNEY are considered part of REMATCH_ELITE_FOUR_ENTRIES.
    REMATCH_PHOEBE,
    REMATCH_GLACIA,
    REMATCH_DRAKE,
    REMATCH_WALLACE,
    REMATCH_TABLE_ENTRIES // The total number of rematch entries. Must be last in enum
};

#define REMATCH_SPECIAL_TRAINER_START   REMATCH_WALLY_3
#define REMATCH_ELITE_FOUR_ENTRIES      REMATCH_SIDNEY

void UpdateGymLeaderRematch(void);

#endif //GUARD_TRAINER_REMATCH_H
