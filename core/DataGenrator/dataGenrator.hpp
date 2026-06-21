#pragma once 
#include "iostream"
#include "vector"
#include "random"
#include "dataTypes/dataTypes.hpp"
class DataGenrator 
{
private:
    
public:
    DataGenrator();
    ~DataGenrator();

 
    

    std::vector<Point> genrateLenearData(int numPoint  , float m , float b , float noiseMagnitude );
};


