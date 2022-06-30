#include "mathutil.h"

double RadDistance(double a, double b)
{
    auto d = fmod(b - a, M_PI * 2.0);
    return fmod(d * 2.0, M_PI * 2.0) - d;
}

double RadLerp(double a, double b, double t)
{
    return a + RadDistance(a, b) * t;
}

double IntAngleToRad(int16_t a)
{
    return a / 65535.0 * M_PI * 2.0 - M_PI;
}

int16_t RadToIntAngle(double a)
{
    return (a + M_PI) / (M_PI * 2.0) * 0xffff;
}
