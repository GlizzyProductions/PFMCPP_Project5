/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword 

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */




/*
 copied UDT 1:
 ===============================================================
 */
#include <iostream>
#include "LeakedObjectDetector.h"

struct MassageChair
{
    int numOfVibrationControls {9};
    int appliedPressure {10}; //measured in PSI
    float backrestReclineAngle = 34.6f;
    double massageDuration;
    float footrestInclineAngle;

    MassageChair();
    ~MassageChair();

    void giveMassage(bool startMassage);
    void playBackgroundSound(); 
    int displayTimer(int msgDuration); // displays how much time is left on massage.
    void printMassageChairVars();
    bool startVibration(bool startMassage)
    {
        startMassage == false ? std::cout << "would you like to start a massage?\n" : std::cout <<  "starting\n";
        while(startMassage == true)
        {
            --massageDuration;
            startMassage = (massageDuration < 0.1);
        }
        return startMassage;
    }  
    JUCE_LEAK_DETECTOR(MassageChair)
};

MassageChair::MassageChair() :
massageDuration(30.00),
footrestInclineAngle(90.f)
{
    std::cout << "MassageChair is being constructed!" << std::endl;
}

MassageChair::~MassageChair()
{
    std::cout << "MassageChair destructed!" << std::endl; 
}

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

void MassageChair::giveMassage(bool startMassage)
{
    if(startMassage == true)
    {
        std::cout << "Please remove shoes, and relax!!\n";
    }
    else
    {
        std::cout << "No Massage For You!\n";
    }
}

void MassageChair::playBackgroundSound()
{
    std::cout << "Now playing! \n";
}

int MassageChair::displayTimer(int msgDuration)
{
    std::cout << "now counting down from " << msgDuration << "minuntes\n";
    int secs = 60, mins = msgDuration;
    
    while(mins >= 0)
    {
        --secs;
        
        if(mins > 0 && secs == 0)
        {
            --mins;
            secs += 60;
            
            while(mins == 0 && secs > 0)
            {
                --secs;
            }
        }
        else if(mins == 0 && secs < 0)
        {
            std::cout << "Massage Complete\n";
            break;
        }
        std::cout << mins << " : " << secs << "\n";
    }
    return msgDuration;
}

void MassageChair::printMassageChairVars()
{
    std::cout << "MassageChair numOfVibrationControls: " << this->numOfVibrationControls << " \n";
    std::cout << "MassageChair appliedPressure: " << this->appliedPressure << " \n";
    std::cout << "MassageChair backrestReclineAngle: " << this->backrestReclineAngle << "\n";
    std::cout << "MassageChair footrestInclineAngle: " << this->footrestInclineAngle << "\n";
    std::cout << "MassageChair massageDuration:  " << this->massageDuration << "\n\n";
}

/*
 copied UDT 2:
 ===============================================================
 */

struct PetCat
{
    int numOfEyes {2};
    int ageOfCat;
    double weightOfCat = 13;
    double legnthOfTail {10.35};
    std::string furColor = "Grey & White";
    std::string nameOfPetCat;
    bool maleGender;
    bool catHungry = true;
    bool hasVaccines = false;

    struct CatCollar
    {
        std::string materialOfCollar {"Nylon"};
        float collarMeasurement {10.2f};
        bool isWaterProof = true;
        bool hasCollarBuckle;
        int numOfHolesForBuckle;
        int leashLength;
        int idNumber = 1000;

        CatCollar();
        ~CatCollar();

        void repelFleas(int repellantStrength, std::string repellantExpiration);
        void attachLeash();
        int tightenCollar(int bucklePosition);
        void printCatCollarVars();
        int leashExtend(int desiredLength)
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
        JUCE_LEAK_DETECTOR(CatCollar)
    };

    PetCat();
    ~PetCat();

    void takeOffCollar(CatCollar newCollar);
    void knockOverObjects();
    void scratchVisitors();
    CatCollar replacementCollar;
    void printPetCatVars();
    void catEatFood()
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
    JUCE_LEAK_DETECTOR(PetCat)
};

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

struct CatCollarWrapper
{
    CatCollarWrapper(PetCat::CatCollar* ptr) : 
    pointToCatCollar(ptr)
    {
    
    }

    ~CatCollarWrapper()
    {
        delete pointToCatCollar;
    }

     PetCat::CatCollar* pointToCatCollar = nullptr;
};

void PetCat::CatCollar::repelFleas(int repellantStrength, std::string repellantExpiration)
{
    std::cout << repellantStrength << "is the repellant strength of this collar\n"; 
    std::cout << repellantExpiration << "is the expiration date\n";
}

void PetCat::CatCollar::attachLeash()
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

void PetCat::CatCollar::printCatCollarVars()
{
    std::cout << "materialOfCollar: " << this->materialOfCollar << " \n";
    std::cout << "collarMeasurement: " << this->collarMeasurement << " \n";
    std::cout << "isWaterProof: " << this->isWaterProof << "\n";
    std::cout << "hasCollarBuckle:  " << this->hasCollarBuckle << "\n";
    std::cout << "numOfHolesForBuckle: " << this->numOfHolesForBuckle << "\n";
    std::cout << "leashLegnth: " << this->leashLength << "\n";
    std::cout << "idNumber: " << this->idNumber << "\n\n";
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

void PetCat::takeOffCollar(CatCollar newCollar)
{
    std::cout << nameOfPetCat << " has removed her collar please replace it\n"; 
    replacementCollar = newCollar;
}

void PetCat::knockOverObjects()
{
    std::cout << nameOfPetCat << " has knock over an Object\n";
}

void PetCat::scratchVisitors()
{
    std::cout << nameOfPetCat << " has scratched a visitor\n";
}

void PetCat::printPetCatVars()
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

        void contractSTD(std::string whichSTD, std::string dateContracted);
        void developeHealthCondition(bool isHereditary, std::string knownSymptoms, std::string conditionName);
        void scheduleCheckUp(std::string returnDate, bool sameDoctor);
        void printHealthStatusVars();
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
    void goToSleep(int howLong);
    void donateBlood(Human girlfriend, bool giveLeftArm);
    HealthStatus healthStatus;
    void printHumanVars();
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

void Human::HealthStatus::contractSTD(std::string whichSTD, std::string dateContracted)
{
    std::cout << "Your tested positive for the folling STD " << whichSTD << " which was contracted on" << dateContracted <<" \n";
}

void Human::HealthStatus::developeHealthCondition(bool isHereditary, std::string knownSymptoms, std::string conditionName)
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

void Human::HealthStatus::printHealthStatusVars()
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

void Human::goToSleep(int howLong)
{
    std::cout << nameOfHuman << " is going to get " << howLong << " hours of sleep!\n";
}

void Human::donateBlood(Human girlfriend, bool giveLeftArm)
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

void Human::printHumanVars()
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

    int AdmitNewCat(PetCat newCat, PetCat::CatCollar newCollar);

    int getCatAdopted(PetCat newCat, Human catAdopter);

    void printCatShelterVars();
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

int CatShelter::AdmitNewCat(PetCat newCat, PetCat::CatCollar newCollar)
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

int CatShelter::getCatAdopted(PetCat newCat, Human catAdopter)
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

void CatShelter::printCatShelterVars()
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

    bool giveXray(Human currentUser, Human::HealthStatus currentStatus);

    bool recomendMedication(Human injuredPatient, Human::HealthStatus injuredStatus);

    void printHospitalVars();
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

bool Hospital::giveXray(Human currentPatient, Human::HealthStatus currentStatus)
{
    std::cout << currentPatient.nameOfHuman << " Are you experiencing any pain?\n";
        
    if (currentStatus.experiencingPain == true)
    {
        return true;
    }
    return false;
}

bool Hospital::recomendMedication(Human injuredPatient, Human::HealthStatus injuredStatus)
{
    if (injuredStatus.brokenBone == true)
    {
        std::cout << injuredPatient.nameOfHuman << "I'm going to prescribe an anabolic medication for your broken bone.\n";
        return true;
    }
    return false;
}

void Hospital::printHospitalVars()
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
    MassageChairWrapper osakiOS4000T(new MassageChair() ); //done
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
    
    PetCat doris; //done
    doris.knockOverObjects();
    doris.scratchVisitors();
    doris.takeOffCollar(friscoBreakaway);
    doris.catEatFood();
    std::cout << "numOfEyes: " << doris.numOfEyes << " \n";
    std::cout << "legnthOfTail: " << doris.legnthOfTail << " \n";
    std::cout << "furColor: " << doris.furColor << "\n";
    std::cout << "ageOfCat:  " << doris.ageOfCat << "\n";
    std::cout << "maleGender:  " << doris.maleGender << "\n";    
    std::cout << "nameOfPetCat: " << doris.nameOfPetCat << "\n";
    std::cout << "maleGender: " << doris.maleGender<< "\n";
    std::cout << "catHungry: " << doris.catHungry << "\n";
    std::cout << "hasVaccines: " << doris.hasVaccines << "\n\n";

    doris.printPetCatVars();
    
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

    Human julianneCabour; //done
    julianneCabour.nameOfHuman = "Julianne Cabour";
    julianneCabour.ageInYears = 13;
    julianneCabour.goToSleep(10);
    julianneCabour.donateBlood(julianneCabour, false);
    julianneCabour.visitDoctor(may5thUpdate);
    std::cout << "ageInYears: " << julianneCabour.ageInYears << " \n";
    std::cout << "nameOfHuman: " << julianneCabour.nameOfHuman << " \n";
    std::cout << "ethnicity: " << julianneCabour.ethnicity << "\n";
    std::cout << "bloodType: " << julianneCabour.bloodType << "\n\n";
    std::cout << "heightOfHuman: " << julianneCabour.heightOfHuman << "\n";
    std::cout << "amountOfBlood: " << julianneCabour.amountOfBlood << "\n";
    std::cout << "dateOfBirth: " << julianneCabour.dateOfBirth << "\n";
    std::cout << "weightOfHuman: " << julianneCabour.weightOfHuman << "\n";
    std::cout << "isAngry: " << julianneCabour.isAngry << "\n";
    std::cout << "genderMale: " << julianneCabour.genderMale << "\n";

    julianneCabour.printHumanVars();

    CatShelter stIves;
    stIves.AdmitNewCat(doris, friscoBreakaway);
    stIves.getCatAdopted(doris, julianneCabour);
    std::cout << "roomForCat " << stIves.roomForCat << "\n\n";

    stIves.printCatShelterVars();

    Hospital stJames;
    stJames.giveXray(julianneCabour, may5thUpdate);
    stJames.recomendMedication(julianneCabour, may5thUpdate);
    std::cout << "numOfPatients " << stJames.numOfPatients << "\n\n";

    stJames.printHospitalVars();

    std::cout << "good to go!" << std::endl;
}
