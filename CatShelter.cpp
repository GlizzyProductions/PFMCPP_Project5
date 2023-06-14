#include "CatShelter.h"
#include "Human.h"

CatShelter::CatShelter()
{
    std::cout << "CatShelter is being constructed\n";
}

CatShelter::~CatShelter()
{
    std::cout << "CatShelter deconstructed\n";
    msDoris.printPetCatVars();
}

int CatShelter::AdmitNewCat(PetCat& newCat, PetCat::CatCollar newCollar)
{   
    if(newCat.hasVaccines == false)
    {
        std::cout << "administering all vacines\n";
        newCat.hasVaccines = true;
    }

    if(newCollar.idNumber == roomForCat)
    {
        roomForCat -= 1;
    }
    return roomForCat; 
}

int CatShelter::getCatAdopted(const PetCat& newCat, const Human& catAdopter)
{
    int ageRequirement = 18;
    int newOwnersAge = catAdopter.ageInYears;
    std::string catsNewOwner = catAdopter.nameOfHuman;
        
    if(newOwnersAge < ageRequirement)
    {
        std::cout << "you are too young to legally adopt this cat\n";
    }
    else
    {
        std::cout << catsNewOwner << "thank you for adopting " << newCat.nameOfPetCat << "\n";
        roomForCat += 1; 
    }
    return roomForCat;
}

void CatShelter::printCatShelterVars() const
{
    std::cout << "roomForCat " << this->roomForCat << "\n\n";
}
