#include "MPoint.h"

MPoint::MPoint (Vectord position,
                PHYSENG_DATA_TYPE mass,
                Vectord velocity = 0) :
    r (position),
    m (mass),
    v (velocity)
    {
    }

MPoint::~MPoint ()
    {
    }