#include "Body.h"

Body::Body (Vectord position, PHYSENG_DATA_TYPE mass, Vectord velocity,
            size_t nPoints, darray <Vectord> pointsArray) :
    MPoint (position, mass, velocity),
    n_points (nPoints)
    {
    // Calculating coordinates of mass center
    Vectord mass_center;
    for (size_t i = 0; i < n_points; i++)
        mass_center += pointsArray [i] / (PHYSENG_DATA_TYPE) n_points;

    // Moves all points by (zero_point - mass_center)
    for (size_t i = 0; i < n_points; i++)
        pointsArray [i] -= mass_center;

    // Filling points array with angles and distances
    for (size_t i = 0; i < n_points; i++)
        {
        // x coord - distance to center
        points [i].x = pointsArray [i].length ();
        // y coord - additional angle
        points [i].y = atan2 (-pointsArray [i].y, -pointsArray [i].x);

        // Calculating radius
        if (radius < points [i].x)
            radius = points [i].x;
        }

    // Calculating total inertia moment of a body
    J = 0;
    for (size_t i = 0; i < n_points; i++)
        J += points [i].x * points [i].x * (mass / n_points) / 3;
    }

Body::~Body ()
    {
    }

/*


*/