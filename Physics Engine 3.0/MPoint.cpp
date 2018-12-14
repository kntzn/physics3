#include "MPoint.h"

MPoint::MPoint (Vectord position,
                PHYSENG_DATA_TYPE mass,
                Vectord velocity = 0)
    {
    state_temp.r = position;
    m = mass;
    state_temp.v = velocity;
    }

MPoint::~MPoint ()
    {
    }