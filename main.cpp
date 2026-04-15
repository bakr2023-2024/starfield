#include <raylib.h>
#include "utils.hpp"
int n = 18000;
int fps = 90;
Color spaceColor = BLACK;
Color starColor = WHITE;
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
        ClearBackground(spaceColor);
        for (auto &star : stars)
        {
            float pz = star.z;
            star.z -= speed * GetFrameTime();
            if (star.z < 1.0f || star.z > sw)
            {
                star.x = gen.rx(rng);
                star.y = gen.ry(rng);
                star.z = gen.rz(rng);
                continue;
            }
            float px = (star.x / pz) * sw + tx;
            float py = (star.y / pz) * sh + ty;
            float sx = (star.x / star.z) * sw + tx;
            float sy = (star.y / star.z) * sh + ty;
            float brightness = map(star.z, 1.0f, sw, 255.0f, 10.0f) / 255.0f;
            Color color{(unsigned char)(starColor.r * brightness),
                        (unsigned char)(starColor.r * brightness),
                        (unsigned char)(starColor.r * brightness),
                        starColor.a};
            DrawLine(px, py, sx, sy, color);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}