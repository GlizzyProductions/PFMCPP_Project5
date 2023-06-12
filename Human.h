# include "LeakedObjectDetector.h"

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

        void contractSTD(const std::string whichSTD, const std::string dateContracted) const;
        void developeHealthCondition(const bool& isHereditary, const std::string knownSymptoms, const std::string conditionName) const;
        void scheduleCheckUp(std::string returnDate, bool sameDoctor) const;
        void printHealthStatusVars() const;
        int countdownNextVisit(const int daysSinceLastVisit);
        JUCE_LEAK_DETECTOR(HealthStatus)
    };

    Human();
    ~Human();

    void visitDoctor(HealthStatus updateHealthStatus);
    void goToSleep(const int howLong) const;
    void donateBlood(Human& girlfriend, const bool giveLeftArm) const;
    HealthStatus healthStatus;
    void printHumanVars() const;
    JUCE_LEAK_DETECTOR(Human)
};
