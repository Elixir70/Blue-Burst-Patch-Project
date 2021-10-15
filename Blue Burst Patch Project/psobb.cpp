#include "pch.h"
#include "globals.h"
#include "palette.h"
#include "shop.h"
#include "earlywalk.h"
#include "slow_gibbles.h"
#include "customize_menu.h"
#include "ime.h"
#include "fastwarp.h"
#include "enemy_spawns.h"
#include "map.h"

void PSOBB()
{
    // By default, keep the game guard patch enabled
#ifndef DO_NOT_PATCH_DISABLE_GAMEGUARD
    memset((void*)addrMainGameGuardCall, 0x90, 0x05);
#endif

#ifdef PATCH_EARLY_WALK_FIX
    ApplyEarlyWalkFix();
#endif

#ifdef PATCH_KEYBOARD_ALTERNATE_PALETTE
    PatchPalette();
#endif

#ifdef PATCH_SLOW_GIBBLES_FIX
    ApplySlowGibblesFix();
#endif

#ifdef PATCH_CUSTOMIZE_MENU
    CustomizeMenu::ApplyActionListPatch();
#endif

    PatchShop();

    PatchIme();

#ifdef PATCH_FASTWARP
    ApplyFastWarpPatch();
#endif

#ifdef PATCH_ENEMY_SPAWNS
    EnemySpawns::ApplyEnemySpawnPatch();
#endif

#ifdef PATCH_MAP_INIT_LISTS
    Map::ApplyMapInitListPatch();
#endif
}
