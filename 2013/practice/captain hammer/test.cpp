/**
 * Captain Hammer
 * 
 * https://code.google.com/codejam/contest/2933486/dashboard#s=p1
 * 
 * The Hamjet is a true marvel of aircraft engineering. 
 * It is a jet airplane with a single engine so powerful 
 * that it burns all of its fuel instantly during takeoff. 
 * The Hamjet doesn't have any wings because who needs them 
 * when the fuselage is made of a special Wonderflonium isotope 
 * that makes it impervious to harm.
 * 
 * Piloting the Hamjet is a not a job for your typical, meek-bodied 
 * superhero. That's why the Hamjet belongs to Captain Hammer, who 
 * is himself impervious to harm. The G-forces that the pilot 
 * endures when taking a trip in the Hamjet are legen-dary.
 * 
 * The Hamjet takes off at an angle of θ degrees up and a speed 
 * of V meters per second. V is a fixed value that is determined 
 * by the awesome power of the Hamjet engine and the capacity of 
 * its fuel tank. The destination is D meters away. Your job is to 
 * program the Hamjet's computer to calculate θ given V and D.
 * 
 * Fortunately, the Hamjet's Wondeflonium hull is impervious to 
 * air friction. Even more fortunately, the Hamjet doesn't fly too 
 * far or too high, so you can assume that the Earth is flat, and 
 * that the acceleration due to gravity is a constant 9.8 m/s^2 down.
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int T; 
double V, D;
#define ASIN_MAX  1.0000000
#define ASIN_MIN -1.0000000
#define M_PI 3.14159265358979323846

double solve()
{
    cin >> V >> D;
    double ret = 9.8 * D / V / V;
    if (ret>ASIN_MAX)
    {
        ret = ASIN_MAX;
    }
    else if(ret<ASIN_MIN)
    {
        ret = ASIN_MIN;
    }
    // cout << 9.8 * D << "\n";
    // cout << 9.8 * D/V << "\n";
    // cout << ret << "\n";
    // cout << asin(ret) << "\n";
    return asin(ret)/2.0 / M_PI * 180.0;
}

int main()
{
    cin >> T;
    for (int i=1;i<=T;++i)
    {
        printf("Case #%d: %.8f\n", i, solve());
    }
}