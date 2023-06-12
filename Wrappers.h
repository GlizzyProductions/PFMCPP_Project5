#pragma once
#include "MassageChair.h"
#include "PetCat.h"

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
