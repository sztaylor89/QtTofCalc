#ifndef MASS_HPP
#define MASS_HPP

#include <map>

class Mass {
public:
    Mass();
    ~Mass(){};

    double GetMass(const int &z, const int &a);

private:
    std::map<std::pair<int,int>, double> masses_;
};

#endif // MASS_HPP
