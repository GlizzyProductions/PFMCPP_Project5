#include "PetCat.h"

PetCat::CatCollar::CatCollar() :
hasCollarBuckle(true),
numOfHolesForBuckle(4),
leashLength(10)
{
    std::cout << "CatCollar is being constructed!" << std::endl; 
}

PetCat::CatCollar::~CatCollar()
{
    std::cout << "CatCollar destructed!" << std::endl; 
}

void PetCat::CatCollar::repelFleas(const int& repellantStrength, const std::string& repellantExpiration) const
{
    std::cout << repellantStrength << "is the repellant strength of this collar\n"; 
    std::cout << repellantExpiration << "is the expiration date\n";
}

void PetCat::CatCollar::attachLeash() const
{
    std::cout << "Now attaching leash...\n";
    
    if(isWaterProof == true)
    {
        std::cout << "don't be afraid to get a little wet\n";  
    }
}

int PetCat::CatCollar::tightenCollar(int bucklePosition)
{ 
    if(hasCollarBuckle == true && bucklePosition <= numOfHolesForBuckle)
    {
        --bucklePosition;
        std::cout << "collar has been tightened\n";
    }
    else
    {
        std::cout << "This collar only has " << numOfHolesForBuckle << " please inut a whole number smaller or equal to that\n";
    }
    return bucklePosition;
}

void PetCat::CatCollar::printCatCollarVars() const
{
    std::cout << "materialOfCollar: " << this->materialOfCollar << " \n";
    std::cout << "collarMeasurement: " << this->collarMeasurement << " \n";
    std::cout << "isWaterProof: " << this->isWaterProof << "\n";
    std::cout << "hasCollarBuckle:  " << this->hasCollarBuckle << "\n";
    std::cout << "numOfHolesForBuckle: " << this->numOfHolesForBuckle << "\n";
    std::cout << "leashLegnth: " << this->leashLength << "\n";
    std::cout << "idNumber: " << this->idNumber << "\n\n";
}

int PetCat::CatCollar::leashExtend(int desiredLength)
{
    if(desiredLength > leashLength)
    {
        std::cout << "leash isn't that long!\n";
    }
    else
    {
        for(int i = 0; i < desiredLength; ++i)
        {
            std::cout << "extending to " << i << " \n";
        }
    }
    return desiredLength;
}

PetCat::PetCat() :
ageOfCat(3),
nameOfPetCat("Doris"),
maleGender(false)
{
    std::cout << "PetCat is being constructed!" << std::endl;
}

PetCat::~PetCat()
{
    std::cout << "PetCat destructed!" << std::endl;
}

void PetCat::takeOffCollar(CatCollar newCollar)
{
    std::cout << nameOfPetCat << " has removed her collar please replace it\n"; 
    replacementCollar = newCollar;
}

void PetCat::knockOverObjects() const
{
    std::cout << nameOfPetCat << " has knock over an Object\n";
}

void PetCat::scratchVisitors() const
{
    std::cout << nameOfPetCat << " has scratched a visitor\n";
}

void PetCat::printPetCatVars() const
{
    std::cout << "numOfEyes: " << this->numOfEyes << " \n";
    std::cout << "legnthOfTail: " << this->legnthOfTail << " \n";
    std::cout << "furColor: " << this->furColor << "\n";
    std::cout << "ageOfCat:  " << this->ageOfCat << "\n";
    std::cout << "maleGender:  " << this->maleGender << "\n";    
    std::cout << "nameOfPetCat: " << this->nameOfPetCat << "\n";
    std::cout << "maleGender: " << this->maleGender << "\n";
    std::cout << "catHungry: " << this->catHungry<< "\n";
    std::cout << "hasVaccines: " << this->hasVaccines << "\n\n";
}

void PetCat::catEatFood()
{
    int nomNomNom = 0;
        
    if(catHungry == true)
    {
        while(catHungry == true && nomNomNom <= 3)
        {
            ++nomNomNom;
            std::cout << "nom nom nom... im still hungry!\n";
                
             if(nomNomNom > 3)
            {
                std::cout << "Meow... I'm Full now.\n";
                catHungry = false;
            }   
        }
    }
}
