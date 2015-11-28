/******************************************************************************

    tiny.c

    mamedriv.c substitute file for "tiny" MAME builds.

    Copyright Nicola Salmoria and the MAME Team.
    Visit http://mamedev.org for licensing and usage restrictions.

    The list of used drivers. Drivers have to be included here to be recognized
    by the executable.

    To save some typing, we use a hack here. This file is recursively #included
    twice, with different definitions of the DRIVER() macro. The first one
    declares external references to the drivers; the second one builds an array
    storing all the drivers.

******************************************************************************/

#include "emu.h"

#ifndef DRIVER_RECURSIVE

#define DRIVER_RECURSIVE

/* step 1: declare all external references */
#define DRIVER(NAME) GAME_EXTERN(NAME);
#include "tgm.c"

/* step 2: define the drivers[] array */
#undef DRIVER
#define DRIVER(NAME) &GAME_NAME(NAME),
const game_driver * const drivers[] =
{
#include "tgm.c"
	0	/* end of array */
};

#else	/* DRIVER_RECURSIVE */

	/* Capcom ZN2 */
	DRIVER( cpzn2 )
	DRIVER( tgmj )		/* Tetris The Grand Master (JAPAN 980710) */

	/* Psikyo games */
	DRIVER( tgm2 )		/* (c) 2000 */
	DRIVER( tgm2p )		/* (c) 2000 */

#endif	/* DRIVER_RECURSIVE */
