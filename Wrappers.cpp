#include "Wrappers.h"
#include "MassageChair.h"
#include "CatShelter.h"
#include "Hospital.h"

MassageChairWrapper::MassageChairWrapper(MassageChair* ptr) :
pointToMassageChair(ptr) { }

MassageChairWrapper::~MassageChairWrapper() {delete pointToMassageChair;}

PetCatWrapper::PetCatWrapper(PetCat* ptr) : 
pointToPetCat(ptr) { }

PetCatWrapper::~PetCatWrapper() {delete pointToPetCat;}

HealthStatusWrapper::HealthStatusWrapper(Human::HealthStatus* ptr) : 
pointToHealthStatus(ptr) { }

HealthStatusWrapper::~HealthStatusWrapper() {delete pointToHealthStatus;}

HumanWrapper::HumanWrapper(Human* ptr) : 
pointToHuman(ptr) { }

HumanWrapper::~HumanWrapper() {delete pointToHuman;}

CatShelterWrapper::CatShelterWrapper(CatShelter* ptr) : 
pointToCatShelter(ptr) { }

CatShelterWrapper::~CatShelterWrapper() {delete pointToCatShelter;}

HospitalWrapper::HospitalWrapper(Hospital* ptr) : 
pointToHospital(ptr) { }

HospitalWrapper::~HospitalWrapper() {delete pointToHospital;}
