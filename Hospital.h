#pragma once
#include "Human.h"

struct Hospital
{
    Human pateint;
    Human::HealthStatus goodHealth;
    int numOfPatients;

    Hospital();
    ~Hospital();

    bool giveXray(const Human& currentUser, const Human::HealthStatus currentStatus) const;

    bool recomendMedication(const Human& injuredPatient, const Human::HealthStatus injuredStatus) const;

    void printHospitalVars() const;
    JUCE_LEAK_DETECTOR(Hospital)
};
