#include <raylib.h>
#include "utils.hpp"
Color hexToRGBA(unsigned int hex)
{
    return Color{
        (unsigned char)((hex >> 24) & 0xFF),
        (unsigned char)((hex >> 16) & 0xFF),
        (unsigned char)((hex >> 8) & 0xFF),
        (unsigned char)(hex & 0xFF)};
}
int main(int argc, char **argv)
{
    int starsCount = 18000;
    int fps = 90;
    Color spaceColor = BLACK;
    Color starsColor = WHITE;
    if (argc > 5)
        return 1;
    if (argc == 5)
        starsColor = hexToRGBA(std::stoul(argv[4], nullptr, 0));
    if (argc >= 4)
        spaceColor = hexToRGBA(std::stoul(argv[3], nullptr, 0));
    if (argc >= 3)
        fps = std::stoi(argv[2]);
    if (argc >= 2)
        starsCount = std::stoi(argv[1]);
    SetConfigFlags(FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_MAXIMIZED);
    InitWindow(0, 0, "Starfield");
    SetTargetFPS(fps);
    int sw = GetScreenWidth(), sh = GetScreenHeight();
    Generator gen(sw, sh, sw);
    float speed = 100.0f;
    float dt = 1.0f / fps;
    std::vector<Star> stars = gen.initStars(starsCount);
    float tx = sw / 2.0f, ty = sh / 2.0f;
    while (!WindowShouldClose())
    {
        speed += GetMouseWheelMove() * fps;
        BeginDrawing();
        ClearBackground(spaceColor);
        for (auto &star : stars)
        {
            float pz = star.z;
            star.z -= speed * dt;
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
            float brightness = map(star.z, 1.0f, sw, 255.0f, 20.0f) / 255.0f;
            Color color{(unsigned char)(starsColor.r * brightness),
                        (unsigned char)(starsColor.g * brightness),
                        (unsigned char)(starsColor.b * brightness),
                        starsColor.a};
            DrawLine(px, py, sx, sy, color);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}