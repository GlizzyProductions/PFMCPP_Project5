#pragma once
#include "MassageChair.h"
#include "CatShelter.h"
#include "Hospital.h"

struct MassageChairWrapper
{
    MassageChairWrapper(MassageChair* ptr) : 
    pointToMassageChair(ptr)
    {
    
    }

    ~MassageChairWrapper()
    {
        delete pointToMassageChair;
    }

     MassageChair* pointToMassageChair = nullptr;
};

struct PetCatWrapper
{
    PetCatWrapper(PetCat* ptr) : 
    pointToPetCat(ptr)
    {
    
    }

    ~PetCatWrapper()
    {
        delete pointToPetCat;
    }

     PetCat* pointToPetCat = nullptr;
};

struct HealthStatusWrapper
{
    HealthStatusWrapper(Human::HealthStatus* ptr) : 
    pointToHealthStatus(ptr)
    {
    
    }

    ~HealthStatusWrapper()
    {
        delete pointToHealthStatus;
    }

     Human::HealthStatus* pointToHealthStatus = nullptr;
};

struct HumanWrapper
{
    HumanWrapper(Human* ptr) : 
    pointToHuman(ptr)
    {
    
    }

    ~HumanWrapper()
    {
        delete pointToHuman;
    }

     Human* pointToHuman = nullptr;
};

struct CatShelterWrapper
{
    CatShelterWrapper(CatShelter* ptr) : 
    pointToCatShelter(ptr)
    {
    
    }

    ~CatShelterWrapper()
    {
        delete pointToCatShelter;
    }

     CatShelter* pointToCatShelter = nullptr;
};

struct HospitalWrapper
{
    HospitalWrapper(Hospital* ptr) : 
    pointToHospital(ptr)
    {
    
    }

    ~HospitalWrapper()
    {
        delete pointToHospital;
    }

     Hospital* pointToHospital = nullptr;
};



