#ifndef __TRIANGLES_HPP__
#define __TRIANGLES_HPP__

#include "point2d.hpp"
#include <string>

class Triangle {
    private:
        Point2D _t1, _t2, _t3;
    
    public:
        Triangle();
        Triangle(Point2D t1, Point2D t2, Point2D t3);
        
        void SetT1(Point2D t1);
        void SetT2(Point2D t2);
        void SetT3(Point2D t3);
        
        std::string GetType() const;
};

#endif
