#pragma once

#include <cstdint>
#include <vector>

#include <neurolens/data/point.hpp>

namespace neurolens::data {

 
std::vector<Point> make_linear(int num_points, float m, float b, float noise,
                               std::uint32_t seed = 42);

}  // namespace neurolens::data
