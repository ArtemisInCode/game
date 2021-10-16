#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "system.h"
#include "pio.h"
#include "levels.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


/* Checks whether player move is legal */
bool is_legal_move (uint16_t map[], uint16_t player_X, uint16_t player_Y);

/* Updates and displays the new map using coords */
void update_map(uint16_t collectables[], uint16_t map[], uint16_t player_X, uint16_t player_Y);

/* Allows the player to navigate around the map */
void movement_update(uint16_t map[], Stats_t* levelStats);

#endif //MOVEMENT_H
