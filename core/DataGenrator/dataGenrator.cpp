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
        std::random_device rd; // genrate a single seed 
        std::mt19937 gen(rd()); // genrate random number based on seed by rd 

        int64_t num = gen();
        std::cout << num ;

        return pointData;
}






