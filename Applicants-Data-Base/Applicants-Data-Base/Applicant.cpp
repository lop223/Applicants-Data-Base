#include "Applicant.h"

Applicant::Applicant()
    : name("Unknown"), passport("N/A"), age(0), contractBasics(false) {}

Applicant::Applicant(const std::string& name,
                     const std::string& passport,
                     int age,
                     const std::vector<int>& score,
                     bool contractBasics)
    : name(name), passport(passport), age(age), score(score), contractBasics(contractBasics) {}

Applicant::~Applicant() {}