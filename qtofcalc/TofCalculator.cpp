/*! \file TofCalculator.hpp
 * \brief 
 * \author S. V. Paulauskas
 * \date February 6, 2015
 *
 * Copyright S. V. Paulauskas 2015
 * stanpaulauskasATgmailDOTcom
 * Distributed under GNU General Public Licence v3
 */
#include <cmath>

#include "TofCalculator.hpp"

using namespace std;

TofCalculator::TofCalculator(const std::string &type,
                             const double &distance) {
    type_ = type;
    distance_ = distance;
    CheckType();
}

void TofCalculator::CalcEnergyError(void) {
    CheckType();
    energyErr_ = sqrt(pow(2*resolution_/time_,2) +
                      pow(2*thickness_/distance_,2))* energy_;
}

void TofCalculator::CalcEnergy(void) {
    CheckType();
    energy_ = 0.5*mass_*pow(distance_/(time_*c_),2);
    CalcEnergyError();
}

void TofCalculator::CalcTimeOfFlight(void) {
    CheckType();
    time_ = (distance_/c_)*sqrt(mass_/(2*energy_));
}

void TofCalculator::CheckType(void) {
    if(type_ == "big") {
        thickness_ = 5.0;
        resolution_ = 2.0;
    } else {
        thickness_ = 3.0;
        resolution_ = 1.0;
    }
}
