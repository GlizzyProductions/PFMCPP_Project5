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

    void giveMassage(const bool startMassage) const;
    void playBackgroundSound() const; 
    int displayTimer(int msgDuration) const; // displays how much time is left on massage.
    void printMassageChairVars() const;
    bool startVibration(bool startMassage);
    JUCE_LEAK_DETECTOR(MassageChair)
};
