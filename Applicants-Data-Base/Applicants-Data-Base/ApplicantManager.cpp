#include "ApplicantManager.h"

void ApplicantManager::removeApplicantByName(const std::string& name) {
    auto it = std::remove_if(applicants.begin(), applicants.end(),
        [&](const Applicant& a) { return a.getName() == name; });
    if (it != applicants.end()) {
        applicants.erase(it, applicants.end());
        return true;
    }
    return false;
}

void ApplicantManager::removeApplicantByPassport(const std::string& passport) {
    auto it = std::remove_if(applicants.begin(), applicants.end(),
        [&](const Applicant& a) { return a.getPassport() == passport; });
    if (it != applicants.end()) {
        applicants.erase(it, applicants.end());
        return true;
    }
    return false;
}

void ApplicantManager::removeApplicantProcess() {
    int choice;
    std::cout << "Видалити за:\n1. Ім'ям\n2. Паспортом\nВаш вибір: ";
    std::cin >> choice;

    if (choice == 1) {
        std::string name;
        std::cout << "Введіть ім'я: ";
        std::getline(std::cin >> std::ws, name);
        if (removeApplicantByName(name))
            std::cout << "✅ Видалено.\n";
        else
            std::cout << "❌ Не знайдено.\n";
    }
    else if (choice == 2) {
        std::string passport;
        std::cout << "Введіть паспорт: ";
        std::getline(std::cin >> std::ws, passport);
        if (removeApplicantByPassport(passport))
            std::cout << "✅ Видалено.\n";
        else
            std::cout << "❌ Не знайдено.\n";
    }
    else {
        std::cout << "Невірний вибір.\n";
    }
}
