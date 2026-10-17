#include <neurolens/data/spiral.hpp>

#include <cmath>
#include <numbers>
#include <random>

namespace neurolens::data {

std::vector<Point> make_spiral(int num_points, int classes, float noise, float twist,
                               std::uint32_t seed)
{
    std::vector<Point> points;
    if (num_points <= 0 || classes <= 0) return points;

    std::mt19937 gen(seed);
    std::uniform_real_distribution<float> unit(0.0f, 1.0f);
    // normal_distribution needs stddev > 0, so noise == 0 means "no jitter".
    std::normal_distribution<float> jitter(0.0f, noise > 0.0f ? noise : 1.0f);
    auto add_jitter = [&] { return noise > 0.0f ? jitter(gen) : 0.0f; };

    const int points_per_class = num_points / classes;
    const float max_radius = 5.0f;
    const float twist_amount = twist * std::numbers::pi_v<float>;
    points.reserve(static_cast<std::size_t>(points_per_class) * classes);

    for (int k = 0; k < classes; ++k) {
        // each arm starts at an evenly spaced angle around the circle
        float class_offset = k * (2.0f * std::numbers::pi_v<float> / classes);

        for (int p = 0; p < points_per_class; ++p) {
            // sqrt of a uniform value spreads points evenly over the disc
            float r = std::sqrt(unit(gen)) * max_radius;

            // the further from the centre, the more the arm has turned
            float theta = (r / max_radius) * twist_amount + class_offset;

            // polar -> cartesian, plus noise
            float x = r * std::cos(theta) + add_jitter();
            float y = r * std::sin(theta) + add_jitter();

            points.push_back({x, y, k});
        }
    }

    return points;
}

}  // namespace neurolens::data
