#include "key_handlers.h"
#include <raylib.h>

void handle_inputs(struct GameState* state) {
    const float acceleration = 1.0f;

    if (IsKeyDown(KEY_SPACE)) {
        state->player.velocity.y = -10.0f;
    }
    //     if (IsKeyDown(KEY_UP)) {
    //         state->player.velocity.y -= acceleration;
    //     }
    //     if (IsKeyDown(KEY_DOWN)) {
    //         state->player.velocity.y += acceleration;
    //     }
    //     if (IsKeyDown(KEY_LEFT)) {
    //         state->player.velocity.x -= acceleration;
    //     }
    //     if (IsKeyDown(KEY_RIGHT)) {
    //         state->player.velocity.x += acceleration;
    //     }
}
