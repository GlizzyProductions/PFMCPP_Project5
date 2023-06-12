/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
        the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */





/*
 copied UDT 1:
 ===============================================================
 */
#include <iostream>
#include "LeakedObjectDetector.h"
#include "Wrappers.h"

struct MassageChair;


/*
 copied UDT 2:
 ===============================================================
 */

/*
 copied UDT 3:
 ===============================================================
 */

struct Human
{
    int ageInYears {33};
    std::string nameOfHuman {"First Last"};
    std::string ethnicity = "Black/African American";
    std::string bloodType;
    std::string heightOfHuman;
    int amountOfBlood;
    int dateOfBirth;
    int weightOfHuman;
    bool isAngry = false;
    bool genderMale = false;

    struct HealthStatus
    {
        int numOfHealthComplications {0};
        bool chronicDiseasesPresent {false};
        bool brokenBone {false};
        bool experiencingPain {false};
        bool goToAppointment = false;
        std::string dateOfLastCheckup = "23 Feburary 2022";
        std::string bloodPressureLevel;
        float bodyMassIndex;

        HealthStatus();
        ~HealthStatus();

        void contractSTD(std::string whichSTD, std::string dateContracted) const;
        void developeHealthCondition(const bool& isHereditary, std::string knownSymptoms, std::string conditionName) const;
        void scheduleCheckUp(std::string returnDate, bool sameDoctor);
        void printHealthStatusVars() const;
        int countdownNextVisit(int daysSinceLastVisit)
        {
            int daysLeft = 365 - daysSinceLastVisit;
            
            for(int i = daysLeft; i > 0; --i)
            {
                std::cout << i << " days left until next visit\n";
            }
            goToAppointment = true;
            return daysLeft;
        }
        JUCE_LEAK_DETECTOR(HealthStatus)
    };

    Human();
    ~Human();

    void visitDoctor(HealthStatus updateHealthStatus);
    void goToSleep(int howLong) const;
    void donateBlood(Human& girlfriend, bool giveLeftArm);
    HealthStatus healthStatus;
    void printHumanVars() const;
    JUCE_LEAK_DETECTOR(Human)
};

Human::HealthStatus::HealthStatus() :
bloodPressureLevel("120/83 mmHg"),
bodyMassIndex(23.8f)
{
    std::cout << "HealthStatus is being constructed!" << std::endl;
}

Human::HealthStatus::~HealthStatus()
{
    std::cout << "HealthStatus destructed!" << std::endl;
}

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

Human::Human() :
bloodType("O Negative"),
heightOfHuman("5'5"),
amountOfBlood(5000), //mL;
dateOfBirth(12181989),
weightOfHuman(150)
{
    std::cout << "Human is being constructed!" << std::endl;
}

Human::~Human()
{
    std::cout << "Human destructed!" << std::endl;
}

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

void Human::HealthStatus::contractSTD(std::string whichSTD, std::string dateContracted) const
{
    std::cout << "Your tested positive for the folling STD " << whichSTD << " which was contracted on" << dateContracted <<" \n";
}

void Human::HealthStatus::developeHealthCondition(const bool& isHereditary, std::string knownSymptoms, std::string conditionName) const
{
    std::cout << "You have noticed having" << knownSymptoms << " \n";
    std::cout << "which are symptoms of " << conditionName << " \n";
    
    if(isHereditary == true) std::cout << "this condition is hereditary";
}

void Human::HealthStatus::scheduleCheckUp(std::string returnDate, bool sameDoctor)
{
    returnDate = "Day/Month/Year";
    sameDoctor = true;
}

void Human::HealthStatus::printHealthStatusVars() const
{
    std::cout << "numOfHealthComplications: " << this->numOfHealthComplications << " \n";
    std::cout << "chronicDiseasesPresent: " << this->chronicDiseasesPresent << " \n";
    std::cout << "brokenBone: " << this->brokenBone << "\n";
    std::cout << "experiencingPain: " << this->experiencingPain << "\n";
    std::cout << "goToAppointment: " << this->goToAppointment << "\n";
    std::cout << "dateOfLastCheckup: " << this->dateOfLastCheckup << "\n";
    std::cout << "bloodPressureLevel: " << this->bloodPressureLevel << "\n";
    std::cout << "bodyMassIndex:  " << this->bodyMassIndex << "\n\n";
}

void Human::visitDoctor(HealthStatus updateHealthStatus)
{
    //I would ideally update all the member variables of HealthStatus here with std::cin's.
    std::cout << "Blood Pressure: " << updateHealthStatus.bloodPressureLevel << " \n";
    std::cout << "Body Mass Index: " << updateHealthStatus.bodyMassIndex << " \n";
    std::cout << "Chronic Diseases Present: " << updateHealthStatus.chronicDiseasesPresent << " \n";
    std::cout << "Date Of Last Check-Up: " << updateHealthStatus.dateOfLastCheckup << " \n";
    std::cout << "Number of Complications: " << updateHealthStatus.numOfHealthComplications << " \n";
    //here I would replace dateOfLastCheckup with todays date.
    updateHealthStatus.goToAppointment = false;
}

void Human::goToSleep(int howLong) const
{
    std::cout << nameOfHuman << " is going to get " << howLong << " hours of sleep!\n";
}

void Human::donateBlood(Human& girlfriend, bool giveLeftArm)
{
    if(giveLeftArm == true)
    {
         std::cout << "you have decided to donate from your left arm\n";
    }
    else
    {
        std::cout << "you have decided to donate from your right arm\n";
    }
    int bloodDonated = 0;
    
    while(bloodDonated < 500 || girlfriend.amountOfBlood < 4000)
    {
        bloodDonated += 100;
        girlfriend.amountOfBlood -= 100;
        std::cout << "still donating: " << bloodDonated << "/500... hang in there.\n";
    }
    std::cout << "all done, go home\n";
}

void Human::printHumanVars() const
{
    std::cout << "ageInYears: " << this->ageInYears << " \n";
    std::cout << "nameOfHuman: " << this->nameOfHuman << " \n";
    std::cout << "ethnicity: " << this->ethnicity << "\n";
    std::cout << "bloodType: " << this->bloodType << "\n";
    std::cout << "heightOfHuman: " << this->heightOfHuman << "\n";
    std::cout << "amountOfBlood: " << this->amountOfBlood << "\n";
    std::cout << "dateOfBirth: " << this->dateOfBirth << "\n";
    std::cout << "weightOfHuman: " << this->weightOfHuman << "\n";
    std::cout << "isAngry: " << this->isAngry << "\n";
    std::cout << "genderMale: " << this->genderMale << "\n\n";
}

/*
 new UDT 4:
 ===============================================================
 with 2 member functions
 */
struct CatShelter
{
    PetCat msDoris;
    PetCat::CatCollar catCollar;
    int roomForCat {1000};

    CatShelter();
    ~CatShelter();

    int AdmitNewCat(PetCat& newCat, PetCat::CatCollar newCollar);

    int getCatAdopted(const PetCat& newCat, const Human catAdopter);

    void printCatShelterVars() const;
    JUCE_LEAK_DETECTOR(CatShelter)
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

int CatShelter::getCatAdopted(const PetCat& newCat, const Human catAdopter)
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

/*
 new UDT 5:
 ===============================================================
 with 2 member functions
 */
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

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    MassageChairWrapper osakiOS4000T( new MassageChair() ); //done
    osakiOS4000T.pointToMassageChair->giveMassage(true);
    osakiOS4000T.pointToMassageChair->displayTimer(1);
    osakiOS4000T.pointToMassageChair->playBackgroundSound();
    std::cout << "osaki0S4000T numOfVibrationControls: " << osakiOS4000T.pointToMassageChair->numOfVibrationControls << " \n";
    std::cout << "osaki0S4000T appliedPressure: " << osakiOS4000T.pointToMassageChair->appliedPressure << " \n";
    std::cout << "osaki0S4000T backrestReclineAngle: " << osakiOS4000T.pointToMassageChair->backrestReclineAngle << " \n";
    std::cout << "osaki0S4000T footrestInclineAngle: " << osakiOS4000T.pointToMassageChair->footrestInclineAngle << " \n";
    std::cout << "osaki0S4000T massageDuration: " << osakiOS4000T.pointToMassageChair->massageDuration << " \n\n";

    osakiOS4000T.pointToMassageChair->printMassageChairVars();

    PetCat::CatCollar friscoBreakaway; //done
    friscoBreakaway.repelFleas(10, "12/12/2012");
    friscoBreakaway.attachLeash();
    friscoBreakaway.tightenCollar(3);
    friscoBreakaway.leashExtend(8);
    std::cout << "materialOfCollar: " << friscoBreakaway.materialOfCollar << " \n";
    std::cout << "collarMeasurement: " << friscoBreakaway.collarMeasurement << " \n";
    std::cout << "isWaterProof: " << friscoBreakaway.isWaterProof << "\n";
    std::cout << "hasCollarBuckle:  " << friscoBreakaway.hasCollarBuckle << "\n";
    std::cout << "numOfHolesForBuckle: " << friscoBreakaway.numOfHolesForBuckle << "\n";
    std::cout << "leashLegnth: " << friscoBreakaway.leashLength << "\n";
    std::cout << "idNumber: " << friscoBreakaway.idNumber << "\n\n";

    friscoBreakaway.printCatCollarVars();
    
    PetCatWrapper doris( new PetCat() );
    doris.pointToPetCat->knockOverObjects();
    doris.pointToPetCat->scratchVisitors();
    doris.pointToPetCat->takeOffCollar(friscoBreakaway);
    doris.pointToPetCat->catEatFood();
    std::cout << "numOfEyes: " << doris.pointToPetCat->numOfEyes << " \n";
    std::cout << "legnthOfTail: " << doris.pointToPetCat->legnthOfTail << " \n";
    std::cout << "furColor: " << doris.pointToPetCat->furColor << "\n";
    std::cout << "ageOfCat:  " << doris.pointToPetCat->ageOfCat << "\n";
    std::cout << "maleGender:  " << doris.pointToPetCat->maleGender << "\n";    
    std::cout << "nameOfPetCat: " << doris.pointToPetCat->nameOfPetCat << "\n";
    std::cout << "maleGender: " << doris.pointToPetCat->maleGender<< "\n";
    std::cout << "catHungry: " << doris.pointToPetCat->catHungry << "\n";
    std::cout << "hasVaccines: " << doris.pointToPetCat->hasVaccines << "\n\n";

    doris.pointToPetCat->printPetCatVars();
    
    Human::HealthStatus may5thUpdate; //done
    may5thUpdate.contractSTD("Cold Sore", "10/28/2021");
    may5thUpdate.developeHealthCondition(false, "small blisters around body", "chickenpox");
    may5thUpdate.scheduleCheckUp("11/22/2024", true);
    may5thUpdate.countdownNextVisit(355);
    std::cout << "numOfHealthComplications: " << may5thUpdate.numOfHealthComplications << " \n";
    std::cout << "chronicDiseasesPresent: " << may5thUpdate.chronicDiseasesPresent << " \n";
    std::cout << "brokenBone: " << may5thUpdate.brokenBone << "\n";
    std::cout << "experiencingPain: " << may5thUpdate.experiencingPain << "\n";
    std::cout << "goToAppointment: " << may5thUpdate.goToAppointment << "\n";
    std::cout << "dateOfLastCheckup: " << may5thUpdate.dateOfLastCheckup << "\n";
    std::cout << "bloodPressureLevel: " << may5thUpdate.bloodPressureLevel << "\n";
    std::cout << "bodyMassIndex: " << may5thUpdate.bodyMassIndex << "\n\n";

    may5thUpdate.printHealthStatusVars();

    HumanWrapper julianneCabour( new Human() ); //done
    julianneCabour.pointToHuman->nameOfHuman = "Julianne Cabour";
    julianneCabour.pointToHuman->ageInYears = 13;
    julianneCabour.pointToHuman->goToSleep(10);
    julianneCabour.pointToHuman->donateBlood(*julianneCabour.pointToHuman, false);
    julianneCabour.pointToHuman->visitDoctor(may5thUpdate);
    std::cout << "ageInYears: " << julianneCabour.pointToHuman->ageInYears << " \n";
    std::cout << "nameOfHuman: " << julianneCabour.pointToHuman->nameOfHuman << " \n";
    std::cout << "ethnicity: " << julianneCabour.pointToHuman->ethnicity << "\n";
    std::cout << "bloodType: " << julianneCabour.pointToHuman->bloodType << "\n\n";
    std::cout << "heightOfHuman: " << julianneCabour.pointToHuman->heightOfHuman << "\n";
    std::cout << "amountOfBlood: " << julianneCabour.pointToHuman->amountOfBlood << "\n";
    std::cout << "dateOfBirth: " << julianneCabour.pointToHuman->dateOfBirth << "\n";
    std::cout << "weightOfHuman: " << julianneCabour.pointToHuman->weightOfHuman << "\n";
    std::cout << "isAngry: " << julianneCabour.pointToHuman->isAngry << "\n";
    std::cout << "genderMale: " << julianneCabour.pointToHuman->genderMale << "\n";

    julianneCabour.pointToHuman->printHumanVars();

    CatShelterWrapper stIves( new CatShelter() );
    stIves.pointToCatShelter->AdmitNewCat(*doris.pointToPetCat, friscoBreakaway);
    stIves.pointToCatShelter->getCatAdopted(*doris.pointToPetCat, *julianneCabour.pointToHuman);
    std::cout << "roomForCat " << stIves.pointToCatShelter->roomForCat << "\n\n";

    stIves.pointToCatShelter->printCatShelterVars();

    HospitalWrapper stJames( new Hospital() );
    stJames.pointToHospital->giveXray(*julianneCabour.pointToHuman, may5thUpdate);
    stJames.pointToHospital->recomendMedication(*julianneCabour.pointToHuman, may5thUpdate);
    std::cout << "numOfPatients " << stJames.pointToHospital->numOfPatients << "\n\n";

    stJames.pointToHospital->printHospitalVars();

    std::cout << "good to go!" << std::endl;
}
