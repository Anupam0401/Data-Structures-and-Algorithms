class Point
{
private:
    double m_dX, m_dY, m_dZ;

public:
    Point(double dX=0.0, double dY=0.0, double dZ=0.0)
    {
    m_dX = dX;
    m_dY = dY;
    m_dZ = dZ;
    }

    // Convert a Point into it's negative equivalent
    friend Point operator- (const Point &cPoint);

    // Return true if the point is set at the origin
    friend bool operator! (const Point &cPoint);

    double GetX() { return m_dX; }
    double GetY() { return m_dY; }
    double GetZ() { return m_dZ; }
};

// Convert a Point into it's negative equivalent
Point operator- (const Point &cPoint)
{
    return Point(-cPoint.m_dX, -cPoint.m_dY, -cPoint.m_dZ);
}

// Return true if the point is set at the origin
bool operator! (const Point &cPoint)
{
    return (cPoint.m_dX == 0.0 &&
        cPoint.m_dY == 0.0 &&
        cPoint.m_dZ == 0.0);
}