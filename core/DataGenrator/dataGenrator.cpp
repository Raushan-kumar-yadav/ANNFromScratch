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

std::vector<Point> DataGenrator::generateSpiralData(int numPoints, int classes, float noiseMagnitude , float twistFactor)
{
    std::vector<Point> pointData;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(-5.0f , 5.0f );
    std::normal_distribution<float> noise(0.0f , noiseMagnitude);


    int pointPerClass = numPoints / classes;
    float maxRadius = 5.0f;  
    float twistAmount = twistFactor * 3.14159265f;

    // for each classes 
    for(int k = 0 ; k < classes ; ++k){

        // offeset btw classes 
        float classOffset = k * (2.0f * 3.14159265f / classes);;

        // for each points 
        for(int p = 0 ; p < pointPerClass ; ++p){

            // random value 
            float randVal = dist(gen);  
            
            // find randiom radious
            float r = std::sqrt(randVal) * maxRadius;;

            // theta from randiom radio and max radious 
            float theta = (r / maxRadius) * twistAmount + classOffset;

            // ploar to cartasion  + some noise 
            float x = r * std::cos(theta) + noise(gen);
            float y = r * std::sin(theta) + noise(gen);
            
             pointData.push_back({x, y, k});




        }
    }

    return pointData;
}
