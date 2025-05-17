#include <raylib.h>
#include <stdlib.h>

#include "src/key_handlers.h"
#include "src/state.h"
#include "src/util.h"

void draw_background(struct GameState* state, struct GameTextures* textures) {
    struct Rectangle rect;

    rect.width = 800;
    rect.height = 450;
    rect.x = 0;
    rect.y = 0;

    struct Vector2 offset;
    offset.x = 0;
    offset.y = 0;
    DrawTextureRec(*textures->background, rect, offset, WHITE);
}
void draw_bird(struct GameState* state, struct GameTextures* textures) {
    struct Rectangle rect;

    rect.x = 0;
    rect.y = 0;
    rect.width = 64;
    rect.height = 64;

    DrawTextureRec(*textures->bird, rect, state->player.position, WHITE);
}

void draw_pipes(struct GameState* state, struct GameTextures* textures) {

    struct Pipe* pipe;
    struct Rectangle rect;

    rect.width = 30;
    rect.height = 327;
    rect.x = 0;
    rect.y = 0;

    struct Vector2 offset;
    for (int i = 0; i < 1; i++) {
        pipe = &(state->pipes[i]);

        offset.y = pipe->gap_top - 327;
        offset.x = pipe->position;
        DrawTextureRec(*textures->pipe_down, rect, offset, WHITE);

        offset.y = pipe->gap_top + 100;
        offset.x = pipe->position;
        DrawTextureRec(*textures->pipe_up, rect, offset, WHITE);

        // DrawTexture(*(textures->pipe), pipe->position, 0, RED);
        // DrawRectangle(pipe->position, 0, 10, pipe->gap_top, BLUE);
        // DrawRectangle(pipe->position,
        //               pipe->gap_bottom,
        //               10,
        //               450 - pipe->gap_bottom,
        //               BLUE);
    }
}

int main(void) {
    InitWindow(800, 450, "raylib [core] example - basic window");
    SetTargetFPS(60);
    struct GameState state = { 
      .pipes = {
      {
        .position = 700,
        .gap_top = 200,
        .gap_bottom = 300,
      },
      {
        .position = 1200,
        .gap_top = 100,
        .gap_bottom = 200,
      },
      {
        .position = 1800,
        .gap_top = 300,
        .gap_bottom = 400,
      }
    },
    .pipe_count = 3,
      .player = { 
        .position = { .x = 400, .y = 225, },
      },
}
;
    struct GameTextures textures = {};
    load_textures(&textures);

    while (!WindowShouldClose()) {
        handle_inputs(&state);
        tick(&state);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_background(&state, &textures);
        draw_bird(&state, &textures);
        draw_pipes(&state, &textures);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
