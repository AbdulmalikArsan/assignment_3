#ifndef __POINT2D_HPP__
#define __POINT2D_HPP__

class Point2D {
    private:
        float _x, _y;

    public:
        Point2D();
        Point2D(float x, float y);

        float GetX() const { return _x; };
        float GetY() const { return _y; };

        inline void SetX(float x) { _x = x; }
        inline void SetY(float y) { _y = y; }

        float Distance(const Point2D& other) const;
};

#endif 
