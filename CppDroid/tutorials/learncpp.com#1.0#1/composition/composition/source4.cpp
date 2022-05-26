#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include "Point2D.h"

class Creature
{
private:
    std::string m_strName;
    Point2D m_cLocation;

    // We don't want people to create Creatures with no name or location
    // so our default constructor is private
    Creature() { }

public:
    Creature(std::string strName, const Point2D &cLocation)
        : m_strName(strName), m_cLocation(cLocation)
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Creature &cCreature)
    {
        out << cCreature.m_strName.c_str() << " is at " << cCreature.m_cLocation;
        return out;
    }

    void MoveTo(int nX, int nY)
    {
        m_cLocation.SetPoint(nX, nY);
    }
};
#endif