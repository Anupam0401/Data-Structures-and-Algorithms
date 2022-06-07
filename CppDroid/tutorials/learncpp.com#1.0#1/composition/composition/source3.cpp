#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

class Point2D
{
private:
    int m_nX;
    int m_nY;

public:
    // A default constructor
    Point2D()
        : m_nX(0), m_nY(0)
    {
    }

    // A specific constructor
    Point2D(int nX, int nY)
        : m_nX(nX), m_nY(nY)
    {
    }

    // An overloaded output operator
    friend std::ostream& operator<<(std::ostream& out, const Point2D &cPoint)
    {
        out << "(" << cPoint.GetX() << ", " << cPoint.GetY() << ")";
        return out;
    }

    // Access functions
    void SetPoint(int nX, int nY)
    {
        m_nX = nX;
        m_nY = nY;
    }

    int GetX() const { return m_nX; }
    int GetY() const { return m_nY; }
};

#endif