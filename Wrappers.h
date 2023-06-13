#pragma once
#include "Human.h"

struct MassageChair;
struct PetCat;
struct Hospital;
struct CatShelter;
struct Hospital;



struct MassageChairWrapper
{
    MassageChairWrapper(MassageChair* ptr);
    ~MassageChairWrapper();
    MassageChair* pointToMassageChair = nullptr;
};

struct PetCatWrapper
{
    PetCatWrapper(PetCat* ptr);
    ~PetCatWrapper();
    PetCat* pointToPetCat = nullptr;
};

struct HealthStatusWrapper
{
    HealthStatusWrapper(Human::HealthStatus* ptr);
    ~HealthStatusWrapper();
    Human::HealthStatus* pointToHealthStatus = nullptr;
};

struct HumanWrapper
{
    HumanWrapper(Human* ptr);
    ~HumanWrapper();
    Human* pointToHuman = nullptr;
};

struct CatShelterWrapper
{
    CatShelterWrapper(CatShelter* ptr);
    ~CatShelterWrapper();
    CatShelter* pointToCatShelter = nullptr;
};

struct HospitalWrapper
{
    HospitalWrapper(Hospital* ptr);
    ~HospitalWrapper();
    Hospital* pointToHospital = nullptr;
};

