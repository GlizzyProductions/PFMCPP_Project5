#include "Human.h"

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

void Human::HealthStatus::contractSTD(const std::string whichSTD, const std::string dateContracted) const
{
    std::cout << "Your tested positive for the folling STD " << whichSTD << " which was contracted on" << dateContracted <<" \n";
}

void Human::HealthStatus::developeHealthCondition(const bool& isHereditary, const std::string knownSymptoms, const std::string conditionName) const
{
    std::cout << "You have noticed having" << knownSymptoms << " \n";
    std::cout << "which are symptoms of " << conditionName << " \n";
    
    if(isHereditary == true) std::cout << "this condition is hereditary\n";
}

void Human::HealthStatus::scheduleCheckUp(std::string returnDate, bool sameDoctor) const
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

int Human::HealthStatus::countdownNextVisit(const int daysSinceLastVisit)
{
    int daysLeft = 365 - daysSinceLastVisit;
            
    for(int i = daysLeft; i > 0; --i)
    {
        std::cout << i << " days left until next visit\n";
    }
    goToAppointment = true;
    return daysLeft;
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

void Human::goToSleep(const int howLong) const
{
    std::cout << nameOfHuman << " is going to get " << howLong << " hours of sleep!\n";
}

void Human::donateBlood(Human& girlfriend, const bool giveLeftArm) const
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
