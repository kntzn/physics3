#include "Vector.h"

// Operators overload

// Binary plus
Vectord operator + (const Vectord &left, const Vectord &right)
    {
    return Vectord (left.x + right.x, left.y + right.y);
    }
Vectord operator += (Vectord &left, Vectord &right)
    {
    return Vectord (left.x = left.x + right.x, left.y = left.y + right.y);
    }
// Unary plus
Vectord operator + (const Vectord &right)
    {
    return right;
    }

// Binary minus
Vectord operator - (const Vectord &left, const Vectord &right)
    {
    return Vectord (left.x - right.x, left.y - right.y);
    }
Vectord operator -= (Vectord &left, Vectord &right)
    {
    return Vectord (left.x = left.x - right.x, left.y = left.y - right.y);
    }
// Unary minus
Vectord operator - (const Vectord &right)
    {
    return Vectord (-right.x, -right.y);
    }

// Scalar multiplication
PHYSENG_DATA_TYPE operator * (const Vectord &left, const Vectord &right)
    {
    return (double)(left.x * right.x + left.y * right.y);
    }
Vectord operator * (const Vectord &left, const PHYSENG_DATA_TYPE factor)
    {
    return Vectord (left.x * factor, left.y * factor);
    }
Vectord operator *= (Vectord &left, const PHYSENG_DATA_TYPE factor)
    {
    return Vectord (left.x = left.x * factor, left.y = left.y * factor);
    }

// Scalar division
Vectord operator / (const Vectord &left, const PHYSENG_DATA_TYPE factor)
    {
    return Vectord (left.x / factor, left.y / factor);
    }
Vectord operator /= (Vectord &left, const PHYSENG_DATA_TYPE factor)
    {
    return Vectord (left.x = left.x / factor, left.y = left.y / factor);
    }

// Vector2 multiplication
PHYSENG_DATA_TYPE operator ^ (const Vectord &left, const Vectord &right)
    {
    return left.x*right.y - left.y*right.x;
    }

// Logical operators
const bool operator == (const Vectord &left, const Vectord &right)
    {
    return ((left.x == right.x) && (left.y == right.y));
    }
const bool operator != (const Vectord &left, const Vectord &right)
    {
    return !(left == right);
    }
const bool operator ! (Vectord &left)
    {
    return !(bool)left;
    }
const bool operator && (Vectord &left, Vectord &right)
    {
    return (bool)left && (bool)right;
    }
const bool operator || (Vectord &left, Vectord &right)
    {
    return (bool)left || (bool)right;
    }

// Comparators
const bool operator < (const Vectord &left, const Vectord &right)
    {
    return (left.length () < right.length ());
    }
const bool operator <= (const Vectord &left, const Vectord &right)
    {
    return (left.length () <= right.length ());
    }
const bool operator > (const Vectord &left, const Vectord &right)
    {
    return (left.length () > right.length ());
    }
const bool operator >= (const Vectord &left, const Vectord &right)
    {
    return (left.length () >= right.length ());
    }

template<typename dataType>
void Vector2<dataType>::operator=(const PHYSENG_DATA_TYPE & right)
    {
    if (this->length ())
        {
        PHYSENG_DATA_TYPE k = right / this->length ();
        this->x *= k;
        this->y *= k;
        }
    }

// Casts
template <typename dataType>
inline Vector2<dataType>::operator bool () const
    {
    return (this->x != 0 && this->y != 0);
    }
template<typename dataType>
inline Vector2<dataType>::operator PHYSENG_DATA_TYPE() const
    {
    return PHYSENG_DATA_TYPE (this->x + this->y);
    }

// Functions
template<typename dataType>
inline dataType Vector2<dataType>::length () const
    {
    return dataType (sqrt (x*x + y*y));
    }
template<typename dataType>
inline Vector2<dataType> Vector2<dataType>::dir () const
    {
    return *this / length ();
    }

// Stream operators
std::ostream& operator << (std::ostream &s, Vectord &v)
    {
    s << '(' << v.x << "; " << v.y << ')';
    return s;
    }

std::istream& operator >> (std::istream &s, Vectord &v)
    {
    std::cout << "Input vector values\nX:";
    std::cin >> v.x;
    std::cout << "Y:";
    std::cin >> v.y;
    std::cout << std::endl;
    return s;
    }