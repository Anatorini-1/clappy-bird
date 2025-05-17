#include "state.h"
#include "util.h"
#include <raylib.h>
#include <stdlib.h>

void move_pipes(struct GameState*);

void tick(struct GameState* state) {
    const float EPSILON = 0.001f;
    const float decelleration = 0.5f;

    clip_float(&(state->player.velocity.x), -5.0f, 5.0f);
    clip_float(&(state->player.velocity.y), -5.0f, 5.0f);

    state->player.position.x += state->player.velocity.x;
    state->player.position.y += state->player.velocity.y;

    decellerate(&(state->player.velocity.x), decelleration);
    state->player.velocity.y += 0.3f;
    move_pipes(state);
}

void move_pipes(struct GameState* state) {
    const float EPSILON = 0.001f;
    struct Pipe* pipe;
    for (int i = 0; i < state->pipe_count; i++) {
        pipe = &state->pipes[i];
        pipe->position -= 3.0f;
        if (pipe->position < 0) {
            pipe->position = 850.0f;
            pipe->gap_top = rand() % 150 + 150;
            pipe->gap_bottom = pipe->gap_top + 150;
        }
        if (pipe->position - state->player.position.x < EPSILON &&
            state->player.position.x - pipe->position < EPSILON) {
            state->score += 1;
        }
    }
}
