/*! \file TofCalculator.hpp
 * \brief 
 * \author S. V. Paulauskas
 * \date February 6, 2015
 *
 * Copyright S. V. Paulauskas 2015
 * stanpaulauskasATgmailDOTcom
 * Distributed under GNU General Public Licence v3
 */
#ifndef __TOFCALCULATOR_HPP__
#define __TOFCALCULATOR_HPP__

#include <string>

class TofCalculator {
public:
    /** Default Constructor */
    TofCalculator(){};
    /** Constructor taking the bar type that we want
     * \param[in] type : the bar type to use */
    TofCalculator(const std::string &type, const double &distance);
    /** Default Destructor */
    ~TofCalculator(){};

    /** \return the distance */
    double GetDistance(void) const {return(distance_);};
    /** \return the energy */
    double GetEnergy(void) const {return(energy_);};
    /** \return the error on the energy */
    double GetEnergyError(void) const {return(energyErr_);};
    /** \return the time of flight */
    double GetTimeOfFlight(void) const {return(time_);};
    /** \return the bar type */
    std::string GetType(void) const {return(type_);};

    /** Sets distance_ to the desired distance
     * \param[in] a : Sets the distance*/
    void SetDistance(const double &a) {distance_ = a;};
    /** Sets energy_ of the neutron
     * \param[in] a : Sets the energy of the neutron */
    void SetEnergy(const double &a) {energy_ = a; CalcTimeOfFlight();};
    /** Sets time_ for the neutron
     * \param[in] a : Sets the time_ */
    void SetTimeOfFlight(const double &a) {
        time_ = a; CalcEnergy(); CalcEnergyError(); };
    /** Sets type_ to the desired bar type 
     * \param[in] a : Sets the type_ */
    void SetType(const std::string &a) {type_ = a;};
private:
    /** \brief Calculate the energy of the neutron given the time of flight */
    void CalcEnergy(void);
    /** \brief Calculate the time of flight of the particle */
    void CalcTimeOfFlight(void);
    /** \brief Calculate the error on the energy */
    void CalcEnergyError(void);
    /** \brief Check the type of bar and set appropriate values */
    void CheckType(void);
    
    double energy_; //!< The Energy of the neutron
    double energyErr_; //!< The error in the energy
    double distance_;//!< The distance the neutron traveled
    double time_;//!< The time of flight of the neutron
    double resolution_; //!< The time resolution of the bars
    double thickness_; //!< The thickness of the bars
    static constexpr double c_ = 29.9792458; //!< The speed of light in cm/ns
    static constexpr double mass_ = 939.565378; //!< The mass of a neutron in MeV/c/c

    std::string type_;
};
#endif //__TOFCALCULATOR_HPP__
