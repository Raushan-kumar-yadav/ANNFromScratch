#include "dataGenrator.hpp"

DataGenrator::DataGenrator()
{
}

DataGenrator::~DataGenrator()
{
}

std::vector<Point> DataGenrator::genrateLenearData(int numPoint, float m, float b, float noiseMagnitude)

{
    std::vector<Point> pointData;
        std::random_device rd; 
        std::mt19937 gen(rd()); 
        std::uniform_real_distribution<float> dist(-5.0f, 5.0f);
        std::normal_distribution<float> noise(0.0f, noiseMagnitude);

        float num = dist(gen);

        std::cout << num ;

       for (int i = 0; i < numPoint; ++i) {
        float x1 = dist(gen);
        float x2 = dist(gen);
        
         float lineX2 = m * x1 + b;
        
         int label = (x2 > lineX2 + noise(gen)) ? 1 : 0;
        
        pointData.push_back({x1, x2, label});
    }

        return pointData;
}






