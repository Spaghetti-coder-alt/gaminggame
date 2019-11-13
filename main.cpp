#include "raylib.h"
#define NUM_FRAMES 3

int main(void) {
    
    
    const int Width = 1280, Height = 720;
    //SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(Width, Height, "bruh gaming 2092");
    SetTargetFPS(60);
    
    unsigned char c1 = 1, c2 = 43, c3 = 55;
    bool c1inc = true;
    bool renderTitleMain = true;
    bool renderSettingsMain = false;
    bool fullscreenm = false;
    bool playgame = false;
    // const char msg[256] = "text";
    
    // button stuff
    Texture2D button0 = LoadTexture("rsrc/settings.png");
    Texture2D button1 = LoadTexture("rsrc/defbutton.png");
    Texture2D button2 = LoadTexture("rsrc/defbutton.png");
    Texture2D button3 = LoadTexture("rsrc/backbutton.png");
    Texture2D button4 = LoadTexture("rsrc/defbutton.png");
    bool button0action = false;
    bool button1action = false;
    bool button2action = false;
    bool button3action = false;
    bool button4action = false;
    int btnState0 = 0;
    int btnState1 = 0;
    int btnState2 = 0;
    int btnState3 = 0;
    int btnState4 = 0;
    
    
    //settings
    int frameHeight0 = button0.height/NUM_FRAMES;
    Rectangle sourceRec0 = { 0, 0, button0.width, frameHeight0 };
    Rectangle btnBounds0 = { 10, Height - 110, button0.width, frameHeight0 };
    
    
    //fullscreen
    int frameHeight1 = button1.height/NUM_FRAMES;
    Rectangle sourceRec1 = { 0, 0, button1.width, frameHeight1 };
    Rectangle btnBounds1 = { Width/2 - button1.width/2, Height/2 - button1.height/NUM_FRAMES/2, button1.width, frameHeight1 };
    
    
    //exit
    int frameHeight2 = button2.height/NUM_FRAMES;
    Rectangle sourceRec2 = { 0, 0, button2.width, frameHeight2 };
    Rectangle btnBounds2 = { Width/2 - button2.width/2, Height - 110, button2.width, frameHeight2 };
    
    //button3 = go back from settings
    
    //play
    int frameHeight4 = button4.height/NUM_FRAMES;
    Rectangle sourceRec4 = { 0, 0, button4.width, frameHeight4 };
    Rectangle btnBounds4 = { Width/2 - button4.width/2, Height/2, button4.width, frameHeight4 };
    
    Vector2 mousePoint = { 0.0f, 0.0f };
    
    while (!WindowShouldClose()) {
        mousePoint = GetMousePosition();
        button0action = false;
        button1action = false;
        button2action = false;
        button3action = false;
        button4action = false;
        
        
        if (!playgame) {
        
        if (CheckCollisionPointRec(mousePoint, btnBounds0))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) btnState0 = 2;
            else btnState0 = 1;

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                if (renderTitleMain) { button0action = true; }
                if (renderSettingsMain) { button3action = true; }
            }
        }
        else btnState0 = 0;
        
        if (CheckCollisionPointRec(mousePoint, btnBounds1))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) btnState1 = 2;
            else btnState1 = 1;

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) button1action = true;
        }
        else btnState1 = 0;
        if (CheckCollisionPointRec(mousePoint, btnBounds2))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) btnState2 = 2;
            else btnState2 = 1;

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) button2action = true;
        }
        else btnState2 = 0;
        
        if (CheckCollisionPointRec(mousePoint, btnBounds4))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) btnState4 = 2;
            else btnState4 = 1;

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) button4action = true;
        }
        else btnState4 = 0;
        
        if (button0action)
        {
            renderTitleMain = false;
            renderSettingsMain = true;
        }
        if (button1action)
        {
            ToggleFullscreen();
            if (fullscreenm) { fullscreenm = false; }
            else fullscreenm = true;
        }
        if (button2action)
        {
            CloseWindow();
        }
        if (button3action)
        {
            renderTitleMain = true;
            renderSettingsMain = false;
        }
        
        if (button4action)
        {
            playgame = true;
        }
        
        sourceRec0.y = btnState0*frameHeight0;
        sourceRec1.y = btnState1*frameHeight1;
        sourceRec2.y = btnState2*frameHeight2;
        sourceRec4.y = btnState4*frameHeight4;
        
        
        if (c1inc) {
            if (c1 > 100) {
                c1inc = false;
            }
            else c1++;
        }
        else {
            if (c1 < 1) {
                c1inc = true;
            }
            else c1--;
        }
        
        if (renderTitleMain) {
            BeginDrawing();
        
            DrawTextureRec(button0, sourceRec0, (Vector2){ btnBounds0.x, btnBounds0.y }, WHITE);
            DrawTextureRec(button2, sourceRec2, (Vector2){ btnBounds2.x, btnBounds2.y }, WHITE);
            DrawTextureRec(button4, sourceRec4, (Vector2){ btnBounds4.x, btnBounds4.y }, WHITE);
            
            DrawRectangle(0, 100, 2000, 200, RED);
            DrawText("Exit", btnBounds2.x + 270, btnBounds2.y + 17, 75, LIGHTGRAY);
            DrawText("Play", btnBounds4.x + 270, btnBounds4.y + 17, 75, LIGHTGRAY);
            DrawText("Gaming", Width/2.4, 175, 75, WHITE);
            
            ClearBackground(Color{c1, c2, c3});
            
            EndDrawing();
        
        }
        if (renderSettingsMain) {
            
            BeginDrawing();
            
            DrawTextureRec(button1, sourceRec1, (Vector2){ btnBounds1.x, btnBounds1.y }, WHITE);
            DrawTextureRec(button3, sourceRec0, (Vector2){ btnBounds0.x, btnBounds0.y }, WHITE);
            
            DrawText("Toggle Fullscreen", btnBounds1.x + 40, btnBounds1.y + 17, 65, LIGHTGRAY);
            
            ClearBackground(Color{c1, c2, c3});
            DrawRectangle(0, 25, 2000, 200, RED);
            DrawText("Settings", Width/2.6, 100, 75, WHITE);
            
            EndDrawing();
        }
        
        }
    }
    UnloadTexture(button0);
    UnloadTexture(button1);
    UnloadTexture(button2);
    UnloadTexture(button3);
    UnloadTexture(button4);
    return 0;
}