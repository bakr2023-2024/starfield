#include <raylib.h>
#include "utils.hpp"
int n = 18000;
int fps = 90;
int main()
{
    SetConfigFlags(FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_MAXIMIZED);
    InitWindow(0, 0, "Starfield");
    SetTargetFPS(fps);
    int sw = GetScreenWidth(), sh = GetScreenHeight();
    Generator gen(sw, sh, sw);
    float speed = 100.0f;
    std::vector<Star> stars = gen.initStars(n);
    float tx = sw / 2.0f, ty = sh / 2.0f;
    while (!WindowShouldClose())
    {
        speed += GetMouseWheelMove() * fps;
        BeginDrawing();
        ClearBackground(BLACK);
        for (auto &star : stars)
        {
            float pz = star.z;
            star.z -= speed * GetFrameTime();
            if (star.z < 1.0f)
            {
                star.x = gen.rx(rng);
                star.y = gen.ry(rng);
                star.z = gen.rz(rng);
                pz = star.z;
            }
            float px = (star.x / pz) * sw + tx;
            float py = (star.y / pz) * sh + ty;
            float sx = (star.x / star.z) * sw + tx;
            float sy = (star.y / star.z) * sh + ty;
            DrawLine(px, py, sx, sy, WHITE);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}