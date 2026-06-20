#include "dataGenrator.hpp"

DataGenrator::DataGenrator()
{
}

DataGenrator::~DataGenrator()
{
}

std::vector<DataGenrator::Point> DataGenrator::genrateLenearData(int numPoint, float m, float b, float noiseMagniture)

{
    std::vector<Point> pointData;
        std::random_device rd; 
        std::mt19937 gen(rd()); 
        std::uniform_real_distribution<float> dist(-5.0f, 5.0f);

        float num = dist(gen);

        std::cout << num ;

        for(int i=0 ; i < numPoint ; i++){

            float num = dist(gen);
            std::cout << num << std::endl;
        }

        return pointData;
}






