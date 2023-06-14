#pragma once
#include "PetCat.h"

struct Human;
struct CatShelter
{
    PetCat msDoris;
    PetCat::CatCollar catCollar;
    int roomForCat {1000};

    CatShelter();
    ~CatShelter();

    int AdmitNewCat(PetCat& newCat, PetCat::CatCollar newCollar);

    int getCatAdopted(const PetCat& newCat, const Human& catAdopter);

    void printCatShelterVars() const;
    JUCE_LEAK_DETECTOR(CatShelter)
};

