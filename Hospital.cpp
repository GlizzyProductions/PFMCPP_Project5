#include "Hospital.h"

Hospital::Hospital() :
numOfPatients(1000)
{
     std::cout << "Hospital is being constructed\n";  
}

Hospital::~Hospital()
{
    std::cout << "Hospital is being constructed\n";
    pateint.printHumanVars();
}

bool Hospital::giveXray(const Human& currentPatient, const Human::HealthStatus currentStatus) const
{
    std::cout << currentPatient.nameOfHuman << " Are you experiencing any pain?\n";
        
    if (currentStatus.experiencingPain == true)
    {
        return true;
    }
    return false;
}

bool Hospital::recomendMedication(const Human& injuredPatient, const Human::HealthStatus injuredStatus) const
{
    if (injuredStatus.brokenBone == true)
    {
        std::cout << injuredPatient.nameOfHuman << "I'm going to prescribe an anabolic medication for your broken bone.\n";
        return true;
    }
    return false;
}

void Hospital::printHospitalVars() const
{
    std::cout << "numOfPatients " << this->numOfPatients << "\n\n";
}
