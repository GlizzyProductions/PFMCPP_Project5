#include "LeakedObjectDetector.h"

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

        void repelFleas(const int& repellantStrength, const std::string& repellantExpiration) const;
        void attachLeash() const;
        int tightenCollar(int bucklePosition);
        void printCatCollarVars() const;
        int leashExtend(int desiredLength);

        JUCE_LEAK_DETECTOR(CatCollar)
    };

    PetCat();
    ~PetCat();

    void takeOffCollar(CatCollar newCollar);
    void knockOverObjects()const;
    void scratchVisitors() const;
    CatCollar replacementCollar;
    void printPetCatVars() const;
    void catEatFood();

    JUCE_LEAK_DETECTOR(PetCat)
};
