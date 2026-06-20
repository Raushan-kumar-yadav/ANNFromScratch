#include "iostream"
#include "vector"
#include "random"

class DataGenrator 
{
private:
    
public:
    DataGenrator();
    ~DataGenrator();

    struct Point
    {
        float x,y;
        int label;
    };
    

    std::vector<Point> genrateLenearData(int numPoint  , float m , float b , float noiseMagniture );
};


