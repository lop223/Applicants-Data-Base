#pragma once

#include<iostream>
#include<string>
#include<vector>


class Applicant {
public:
	Applicant();
    Applicant(const std::string& name, const std::string& passport,
              int age, const std::vector<int>& score, bool contractBasics);
	Applicant(const Applicant& other);
	Applicant(Applicant&& other) noexcept;
    ~Applicant();

	const std::string& getName() const { return name; }
	const std::string& getPassport() const { return passport; }
	int getAge() const { return age; }
	const std::vector<int>& getScore() const { return score; }
	bool isContractBasics() const { return contractBasics; }

	std::string toString() const;
private:
	std::string name;
	std::string passport;
	int age;
	std::vector<int> score;
	bool contractBasics;
};