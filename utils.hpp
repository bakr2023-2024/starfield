#include <vector>
#include <random>
inline std::mt19937 rng(std::random_device{}());
struct Star
{
    float x, y, z;
};
class Generator
{
public:
    std::uniform_real_distribution<float> rx, ry, rz;
    Generator(float maxX, float maxY, float maxZ) : rx(-maxX, maxX - 1), ry(-maxY, maxY - 1), rz(1.0f, maxZ - 1) {}
    std::vector<Star> initStars(int n)
    {
        std::vector<Star> stars;
        stars.reserve(n);
        for (int i = 0; i < n; i++)
            stars.emplace_back(rx(rng), ry(rng), rz(rng));
        return stars;
    }
};
float map(float val, float iMin, float iMax, float oMin, float oMax) { return (val - iMin) * (oMax - oMin) / (iMax - iMin) + oMin; }