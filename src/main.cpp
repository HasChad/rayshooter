#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <vector>

typedef enum GameScreen { GAMEPLAY, INVENTORY, PAUSE } GameScreen;

const float PLAYER_SPEED = 2.0f;
const float SHIFT_SPEED = 1.0f;
const float BULLET_SPEED = 10.0f;

struct Bullet {
    Vector2 pos;
    Vector2 vel;
};

struct Player {
    Vector2 pos;
    Vector2 rec;
};

struct Textures {
    Texture2D player;
    Texture2D bullet;
    Texture2D cursor;
    Texture bg;
};

struct Sounds {
    Music wood_ambiance;
    Music walk_forest;
    Sound gunshot;
};

void playerMove(Vector2* position) {
    float speed = IsKeyDown(KEY_LEFT_SHIFT) ? SHIFT_SPEED : PLAYER_SPEED;

    if (IsKeyDown(KEY_W))
        position->y -= speed;
    if (IsKeyDown(KEY_S))
        position->y += speed;
    if (IsKeyDown(KEY_D))
        position->x += speed;
    if (IsKeyDown(KEY_A))
        position->x -= speed;
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "RayShooter");
    InitAudioDevice();
    SetTargetFPS(60);
    SetWindowIcon(LoadImage("sprites/icon.png"));
    HideCursor();

    GameScreen currentScreen = GAMEPLAY;

    Textures textures{
        .player = LoadTexture("sprites/player.png"),
        .bullet = LoadTexture("sprites/bullet.png"),
        .cursor = LoadTexture("sprites/cursor.png"),
        .bg = LoadTexture("sprites/beton.png"),
    };

    // Sounds
    SetMasterVolume(0.3);
    Sounds sounds{
        .wood_ambiance = LoadMusicStream("sounds/wood_ambiance.mp3"),
        .walk_forest = LoadMusicStream("sounds/walk_forest.mp3"),
        .gunshot = LoadSound("sounds/gunshot.mp3"),
    };
    PlayMusicStream(sounds.wood_ambiance);
    PlayMusicStream(sounds.walk_forest);

    Rectangle screen = {0, 0, 800, 450};
    Vector2 cursorPos;
    Player player = {.pos = {screenWidth / 2.0, screenHeight / 2.0},
                     .rec = {20, 20}};
    std::vector<Bullet> bullets;

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        UpdateMusicStream(sounds.wood_ambiance);
        cursorPos = GetMousePosition();

        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_D) || IsKeyDown(KEY_W) ||
            IsKeyDown(KEY_S)) {
            UpdateMusicStream(sounds.walk_forest);
            playerMove(&player.pos);
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            PlaySound(sounds.gunshot);

            Vector2 vel = cursorPos - player.pos;
            vel = Vector2Normalize(vel);

            bullets.push_back({player.pos, vel});
        }

        for (auto& bullet : bullets)
            bullet.pos += bullet.vel * BULLET_SPEED;

        for (int i = bullets.size() - 1; i >= 0; i--) {
            if (bullets[i].pos.x > screenWidth || bullets[i].pos.x < 0 ||
                bullets[i].pos.y > screenHeight || bullets[i].pos.y < 0) {
                bullets.erase(bullets.begin() + i);
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        DrawTexturePro(textures.bg, screen, screen, {0.0f, 0.0f}, 0, WHITE);

        int flip = GetMouseX() < player.pos.x ? -1 : 1;
        DrawTextureRec(textures.player,
                       (Rectangle){0, 0, (float)textures.player.width * flip,
                                   (float)textures.player.height},
                       player.pos, WHITE);

        for (const auto& bullet : bullets) {
            float angleDeg = atan2f(bullet.vel.y, bullet.vel.x) * RAD2DEG;

            DrawTextureEx(
                textures.bullet,
                {static_cast<float>(bullet.pos.x - textures.bullet.width / 2.0),
                 static_cast<float>(bullet.pos.y -
                                    textures.bullet.height / 2.0)},
                angleDeg, 1, WHITE);
        }

        DrawTexture(textures.cursor, cursorPos.x - textures.cursor.width / 2.0,
                    cursorPos.y - textures.cursor.width / 2.0, WHITE);

        EndDrawing();
    }

    StopMusicStream(sounds.wood_ambiance);
    StopMusicStream(sounds.walk_forest);
    CloseAudioDevice();
    CloseWindow();
}
