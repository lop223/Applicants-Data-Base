#include "ApplicantManager.h"

void ApplicantManager::addApplicant(const Applicant& applicant) {
    applicants.push_back(applicant);
}

void ApplicantManager::addApplicantProcess() {
    std::string name, passport;
    int age;
    int nScores;
    bool contract;

    std::cout << "Введіть ім'я: ";
    std::getline(std::cin >> std::ws, name);
    std::cout << "Введіть паспорт: ";
    std::getline(std::cin >> std::ws, passport);
    std::cout << "Введіть вік: ";
    std::cin >> age;
    std::cout << "Кількість оцінок: ";
    std::cin >> nScores;

    std::vector<int> scores(nScores);
    std::cout << "Введіть оцінки через пробіл: ";
    for (int& s : scores) std::cin >> s;

    std::cout << "Контрактна основа (1 — так, 0 — ні): ";
    std::cin >> contract;

    addApplicant(Applicant(name, passport, age, scores, contract));
    std::cout << "Абітурієнт доданий (поки без збереження в об’єкт)\n";
}

void ApplicantManager::removeApplicantByName(const std::string& name) {
    auto it = std::remove_if(applicants.begin(), applicants.end(),
        [&](const Applicant& a) { return a.getName() == name; });
    if (it != applicants.end()) {
        applicants.erase(it, applicants.end());
    }
}

void ApplicantManager::removeApplicantByPassport(const std::string& passport) {
    auto it = std::remove_if(applicants.begin(), applicants.end(),
        [&](const Applicant& a) { return a.getPassport() == passport; });
    if (it != applicants.end()) {
        applicants.erase(it, applicants.end());
    }
}

void ApplicantManager::removeApplicantProcess() {
    int choice;
    std::cout << "Видалити за:\n1. Ім'ям\n2. Паспортом\nВаш вибір: ";
    std::cin >> choice;

    if (choice == 1) {
        std::string name;
        std::cout << "Введіть ім'я: ";
        std::getline(std::cin >> std::ws, name);
        removeApplicantByName(name);
    }
    else if (choice == 2) {
        std::string passport;
        std::cout << "Введіть паспорт: ";
        std::getline(std::cin >> std::ws, passport);
        removeApplicantByPassport(passport);
    }
    else {
        std::cout << "Невірний вибір.\n";
    }
}
