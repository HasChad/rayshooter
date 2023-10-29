#include <raylib.h>
#include <raymath.h>

typedef enum GameScreen {GAMEPLAY, INVENTORY, PAUSE} GameScreen;

void playerMovementX();
void playerMovementY();
float squareroot(float number);

void main()
{
    //Window, resolotuion and camera settings
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "test"); //window heigh, width and name
    InitAudioDevice();
    SetTargetFPS(60); //Set game to run at 60 fps    
    SetWindowIcon(LoadImage(SPRITE_PATH"icon.png"));
    HideCursor();

    GameScreen currentScreen = GAMEPLAY;
    //Sprites
    Texture2D player = LoadTexture(SPRITE_PATH"player.png");
    Texture2D bullet = LoadTexture(SPRITE_PATH"bullet.png");
    Texture2D cursor = LoadTexture(SPRITE_PATH"cursor.png");
    Texture texpatter = LoadTexture(SPRITE_PATH"beton.png");

    //Sounds
    SetMasterVolume(1.0); 
    Music wood_ambiance = LoadMusicStream(SOUND_PATH"wood_ambiance.mp3");
    Music walk_forest = LoadMusicStream(SOUND_PATH"walk_forest.mp3");
    Sound gunshot = LoadSound(SOUND_PATH"gunshot.mp3");
    SetSoundVolume(gunshot, 0.3);
    SetMusicVolume(walk_forest, 0.3);
    PlayMusicStream(wood_ambiance);
    PlayMusicStream(walk_forest);

    //creating game elements
    Vector2 playerPosition = {(float)screenWidth/2, (float)screenHeight/2}; //center position for player
    Vector2 cursorPosition;
    Vector2 bulletPosition;
    Rectangle screen = {0,0,800,450};
    Rectangle playerRecSource = {playerPosition.x,playerPosition.y,19, 19};
    Rectangle playerRec = {playerPosition.x,playerPosition.y,19, 19};
    bool bulletactive = false;
    float bulletMoveX, bulletMoveY, subX, subY, square;

    //Main game loop
    while (!WindowShouldClose())    //Detect window close button or ESC key
    {
        //-Update-Start---------------------------------------------------------------------
        
        UpdateMusicStream(wood_ambiance); //update music everyframe
        cursorPosition = GetMousePosition();

        //player movement
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_D) || IsKeyDown(KEY_W) || IsKeyDown(KEY_S))
        {
            UpdateMusicStream(walk_forest);
            if (IsKeyDown(KEY_A) || IsKeyDown(KEY_D))
                playerMovementX(&playerPosition.x);

            if (IsKeyDown(KEY_W) || IsKeyDown(KEY_S))
                playerMovementY(&playerPosition.y);
        }

        //shooting confirm
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            //bullet start position
            PlaySoundMulti(gunshot);
            if (GetMouseX() < playerPosition.x)
                bulletPosition.x = playerPosition.x;
            else
                bulletPosition.x = playerPosition.x + 19;
            bulletPosition.y = playerPosition.y + 7;
            //position subtraction
            subX = GetMouseX() - playerPosition.x;
            subY = GetMouseY() - playerPosition.y;
            bulletactive = true;
            //movement calc
            square = squareroot((subX*subX)+(subY*subY));
            bulletMoveX = 10*(subX/square)*(subX/square);
            bulletMoveY = 10*(subY/square)*(subY/square);

            if (subX < 0 && subY >= 0)
                bulletMoveX = -bulletMoveX, bulletMoveY = -bulletMoveY;
            if (subX < 0 && subY < 0)
                bulletMoveX = -bulletMoveX;
            if (subX >= 0 && subY >= 0)
                bulletMoveY = -bulletMoveY;
        }
        //-Update-End-----------------------------------------------------------------------

        //-Draw-Start-----------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);
        DrawTexturePro(texpatter, screen, screen, (Vector2){0.0f,0.0f}, 0, WHITE);
        DrawTexture(cursor, cursorPosition.x, cursorPosition.y, WHITE);
        if (GetMouseX() >= playerPosition.x)
            DrawTexture(player, playerPosition.x, playerPosition.y, WHITE);
        if (GetMouseX() < playerPosition.x)
            DrawTextureRec(player, (Rectangle){0,0, -player.width, player.height}, (Vector2){playerPosition.x, playerPosition.y}, WHITE);

        if (bulletactive == true)
        {
            DrawTexture(bullet, bulletPosition.x, bulletPosition.y, WHITE);
            bulletPosition.x += bulletMoveX;
            bulletPosition.y -= bulletMoveY;
        }

        EndDrawing();
        //-Draw-End------------------------------------------------------------------------
    }
    StopMusicStream(wood_ambiance);
    CloseAudioDevice();
    CloseWindow();  //Close window and OpenGL context
}

void playerMovementX(float *positionx) //player movement X
{
    if (IsKeyDown(KEY_D))
    {
        *positionx += 2.0f;
        if (IsKeyDown(KEY_LEFT_SHIFT))
            *positionx += 1.0f;
    }       
    if (IsKeyDown(KEY_A))
    {
        *positionx -= 2.0f;
        if (IsKeyDown(KEY_LEFT_SHIFT))
            *positionx -= 1.0f;
    }
}

void playerMovementY(float *positiony) //player movement Y
{
    if (IsKeyDown(KEY_W)) 
    {
        *positiony -= 2.0f;
        if (IsKeyDown(KEY_LEFT_SHIFT))
            *positiony -= 1.0f;
    }
    if (IsKeyDown(KEY_S))
    {
        *positiony += 2.0f;
        if (IsKeyDown(KEY_LEFT_SHIFT))
            *positiony += 1.0f;
    }
}

float squareroot(float number)
{
    float temp, square;

    square = number / 2;
    temp = 0;

    while(square != temp)
    {
        temp = square;
        square = ( number/temp + temp) / 2;
    }
    return square;
}