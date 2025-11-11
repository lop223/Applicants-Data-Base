#include "Applicant.h"

Applicant::Applicant()
    : name("Unknown"), passport("N/A"), age(0), contractBasics(false) {}

Applicant::Applicant(const std::string& name,
                     const std::string& passport,
                     int age,
                     const std::vector<int>& score,
                     bool contractBasics)
    : name(name), passport(passport), age(age), score(score), contractBasics(contractBasics) {}

Applicant::Applicant(const Applicant& other)
    : name(other.name),
    passport(other.passport),
    age(other.age),
    score(other.score),
    contractBasics(other.contractBasics) {
    std::cout << "[Copy] Applicant: " << name << "\n";
}

Applicant::Applicant(Applicant&& other) noexcept
    : name(std::move(other.name)),
    passport(std::move(other.passport)),
    age(other.age),
    score(std::move(other.score)),
    contractBasics(other.contractBasics) {
    std::cout << "[Move] Applicant: " << name << "\n";
    other.age = 0;
    other.contractBasics = false;
}

Applicant::~Applicant() {}