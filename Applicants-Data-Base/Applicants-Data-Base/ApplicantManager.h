#pragma once

#include <algorithm>
#include <vector>
#include <string>

#include "Applicant.h"

class ApplicantManager {
public:
    void loadFromFile();
    void saveToFile();

    void addApplicantProcess();
    void removeApplicantProcess();
    void sortApplicantProcces();

    void printAll() const;

private:
    std::vector<Applicant> applicants;

    void addApplicant(const Applicant& applicant);

    void removeApplicantByName(const std::string& name);
    void removeApplicantByPassport(const std::string& passport);

    void sortByName();
    void sortByTotalScore();
};