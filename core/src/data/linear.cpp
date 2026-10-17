#include <neurolens/data/linear.hpp>

#include <random>

namespace neurolens::data {

std::vector<Point> make_linear(int num_points, float m, float b, float noise,
                               std::uint32_t seed)
{
    std::vector<Point> points;
    if (num_points <= 0) return points;
    points.reserve(static_cast<std::size_t>(num_points));

    std::mt19937 gen(seed);
    std::uniform_real_distribution<float> coord(-5.0f, 5.0f);
    // normal_distribution needs stddev > 0, so noise == 0 means "no jitter".
    std::normal_distribution<float> jitter(0.0f, noise > 0.0f ? noise : 1.0f);

    for (int i = 0; i < num_points; ++i) {
        float x = coord(gen);
        float y = coord(gen);

        float line_y = m * x + b;
        float offset = noise > 0.0f ? jitter(gen) : 0.0f;

        int label = (y > line_y + offset) ? 1 : 0;
        points.push_back({x, y, label});
    }

    return points;
}

}  // namespace neurolens::data
