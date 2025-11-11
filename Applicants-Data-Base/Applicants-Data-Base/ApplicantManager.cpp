#include "ApplicantManager.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <numeric>

const std::string FILE_NAME = "applicants.txt";

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

void ApplicantManager::saveToFile() {
    std::ofstream file(FILE_NAME);
    if (!file.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису!\n";
        return;
    }

    for (const auto& a : applicants) {
        file << a.getName() << ';'
            << a.getPassport() << ';'
            << a.getAge() << ';';
        for (int s : a.getScore()) file << s << ',';
        file << ';' << a.isContractBasics() << '\n';
    }
    std::cout << "Дані збережено у файл " << FILE_NAME << "\n";
}

void ApplicantManager::loadFromFile() {
    std::ifstream file(FILE_NAME);
    if (!file.is_open()) {
        std::cerr << "Не вдалося відкрити файл для читання!\n";
        return;
    }

    applicants.clear();
    std::string line;
    while (std::getline(file, line)) {
    if (line.empty()) continue;

    std::stringstream ss(line);
    std::string name, passport, ageStr, scoreStr, contractStr;

    std::getline(ss, name, ';');
    std::getline(ss, passport, ';');
    std::getline(ss, ageStr, ';');
    std::getline(ss, scoreStr, ';');
    std::getline(ss, contractStr, ';');

    int age = std::stoi(ageStr);
    bool contract = (contractStr == "1" || contractStr == "true");

    std::vector<int> scores;
    std::stringstream scoreStream(scoreStr);
    std::string scoreVal;
    while (std::getline(scoreStream, scoreVal, ',')) {
        if (!scoreVal.empty())
            scores.push_back(std::stoi(scoreVal));
    }

    applicants.push_back({ name, passport, age, scores, contract });
}

    std::cout << "Дані завантажено з файлу " << FILE_NAME << "\n";
}

void ApplicantManager::sortByName() {
    std::sort(applicants.begin(), applicants.end(),
        [](const Applicant& a, const Applicant& b) {
            return a.getName() < b.getName();
        });
}

void ApplicantManager::sortByTotalScore() {
    std::sort(applicants.begin(), applicants.end(),
        [](const Applicant& a, const Applicant& b) {
            int sumA = std::accumulate(a.getScore().begin(), a.getScore().end(), 0);
            int sumB = std::accumulate(b.getScore().begin(), b.getScore().end(), 0);
            return sumA > sumB; 
        });
}

void ApplicantManager::printAll() const {
    for (const auto& a : applicants) {
        std::cout << a.toString() << "\n";
    }
}
