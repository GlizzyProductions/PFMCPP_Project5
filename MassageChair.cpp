#include "MassageChair.h"

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

void MassageChair::giveMassage(bool startMassage) const
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

void MassageChair::playBackgroundSound() const
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

void MassageChair::printMassageChairVars() const
{
    std::cout << "MassageChair numOfVibrationControls: " << this->numOfVibrationControls << " \n";
    std::cout << "MassageChair appliedPressure: " << this->appliedPressure << " \n";
    std::cout << "MassageChair backrestReclineAngle: " << this->backrestReclineAngle << "\n";
    std::cout << "MassageChair footrestInclineAngle: " << this->footrestInclineAngle << "\n";
    std::cout << "MassageChair massageDuration:  " << this->massageDuration << "\n\n";
}

bool MassageChair::startVibration(bool startMassage)
{
        startMassage == false ? std::cout << "would you like to start a massage?\n" : std::cout <<  "starting\n";
        while(startMassage == true)
        {
            --massageDuration;
            startMassage = (massageDuration < 0.1);
        }
        return startMassage;
}
