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
    Generator(float maxX, float maxY, float maxZ) : rx(-maxX, maxX), ry(-maxY, maxY), rz(1.0f, maxZ) {}
    std::vector<Star> initStars(int n)
    {
        std::vector<Star> stars;
        stars.reserve(n);
        for (int i = 0; i < n; i++)
            stars.emplace_back(rx(rng), ry(rng), rz(rng));
        return stars;
    }
};