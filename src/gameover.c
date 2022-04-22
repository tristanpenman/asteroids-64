#include "canvas.h"
#include "defines.h"
#include "input.h"
#include "level.h"
#include "loop.h"
#include "timing.h"
#include "titlescreen.h"

static unsigned int level = 1;
static unsigned int lives = 3;
static unsigned int score = 0;

static float elapsed = 0.f;

static char titlecard[100];

/******************************************************************************
 *
 * Public interface
 *
 *****************************************************************************/

void gameover_init()
{
    canvas_reset();
    input_reset();
}

void gameover_loop(bool draw)
{
    uint32_t residual;

    input_update();

    produce_simulation_time();
    residual = residual_simulation_time();
    while (maybe_consume_simulation_time(residual)) {
        elapsed += (float) residual;
    }

    if (elapsed >= GAME_OVER_DELAY_MS) {
        titlescreen_init();
        set_main_loop(titlescreen_loop);
        return;
    }

    if (!draw) {
        return;
    }

    canvas_start_drawing(true);
    canvas_draw_text_centered("GAME OVER", 0.65f, -0.05f, FONT_SPACE);
    canvas_finish_drawing(true);
}
