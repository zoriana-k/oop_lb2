#pragma once
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;
class managment
{
public:
class employeer {
    public:
        // Публічні поля
        char name[256];
        char position[128];
        int experience;

        // Метод для виведення всієї інформації
        void printInfo() const {
            cout << "Name: " << name << endl;
            cout << "Position: " << position << endl;
            cout << "Experience: " << experience << " years" << endl;
            cout << "Employeer ID: " << employeerID << endl;
            cout << "Team: " << team << endl;
            cout << "Tasks: " << tasks << endl;
            cout << "Resources: " << resources << endl;
            cout << "Budget: $" << budget << endl;
        }

        // Перевантажений оператор +
        employeer operator+(const employeer& other) {
            employeer result;
            result.experience = this->experience + other.experience;
            strcpy_s(result.name, sizeof(result.name), this->name);
            strcat_s(result.name, sizeof(result.name), other.name);
            strcpy_s(result.position, sizeof(result.position), this->position);
            strcat_s(result.position, sizeof(result.position), other.position);
            strcpy_s(result.employeerID, sizeof(result.employeerID), this->employeerID);
            strcat_s(result.employeerID, sizeof(result.employeerID), other.employeerID);
            strcpy_s(result.team, sizeof(result.team), this->team);
            strcat_s(result.team, sizeof(result.team), other.team);
            strcpy_s(result.tasks, sizeof(result.tasks), this->tasks);
            strcat_s(result.tasks, sizeof(result.tasks), other.tasks);
            strcpy_s(result.resources, sizeof(result.resources), this->resources);
            strcat_s(result.resources, sizeof(result.resources), other.resources);
            result.budget = this->budget + other.budget;
            return result;
        }

        // Перевантажений оператор <<
        friend ostream& operator<<(ostream& os, const employeer& e) {
            os << "Name: " << e.name << endl;
            os << "Position: " << e.position << endl;
            os << "Experience: " << e.experience << " years" << endl;
            return os;
        }

        void setEmployeerID(const char* newID) {
            strcpy_s(employeerID, sizeof(employeerID), newID);
        }
        void setTeam(const char* newTeam) {
            strcpy_s(team, sizeof(team), newTeam);
        }
        void setTasks(const char* newTasks) {
            strcpy_s(tasks, sizeof(tasks), newTasks);
        }
        void setResources(const char* newResources) {
            strcpy_s(resources, sizeof(resources), newResources);
        }
        void setBudget(int newBudget) {
            budget = newBudget;
        }//сетери
        // Метод для запису в файл
        void writeToFile(const std::string& filename) const {
            std::ofstream file(filename);
            if (file.is_open()) {
                file << name << endl;
                file << position << endl;
                file << experience << endl;
                file << employeerID << endl;
                file << team << endl;
                file << tasks << endl;
                file << resources << endl;
                file << budget << endl;
                file.close();
            }
            else {
                cerr << "Unable to open file for writing: " << filename << endl;
            }
        }

        // Метод для читання з файлу
        void readFromFile(const std::string& filename) {
            std::ifstream file(filename);
            if (file.is_open()) {
                file.getline(name, 256);
                file.getline(position, 128);
                file >> experience;
                file.ignore();
                file.getline(employeerID, 64);
                file.getline(team, 128);
                file.getline(tasks, 2048);
                file.getline(resources, 2048);
                file >> budget;
                file.close();
            }
            else {
                cerr << "Unable to open file for reading: " << filename << endl;
            }
        }

        // Метод для додавання досвіду
        void addExperience(int years) {
            experience += years;
        }

        // Метод для генерації і сортування досвіду
        void generateAndSortExperience(int numValues) {
            int* experienceArray = new int[numValues];
            for (int i = 0; i < numValues; i++) {
                experienceArray[i] = rand() % 50;
            }
            cout << "\nGenerated experience values: ";
            for (int i = 0; i < numValues; i++) {
                cout << experienceArray[i] << " ";
            }
            cout << endl;
            sort(experienceArray, experienceArray + numValues);
            cout << "\nSorted experience values: ";
            for (int i = 0; i < numValues; i++) {
                cout << experienceArray[i] << " ";
            }
            cout << endl;
            delete[] experienceArray;
        }

    private:
        // Приватні поля
        char employeerID[64];
        char team[128];
        char tasks[2048];
        char resources[2048];
        int budget;
    };

	class project {
	public:
		char name[256];
		char customer[256];
		int budget;//3 загальні елементи
		vector<employeer> team;
		void printInfo() {
			cout << name << endl;
			cout << customer << endl;
			cout << budget << endl;
			cout << manager << endl;
			cout << teams << endl;
			cout << employeers << endl;
			cout << tasks << endl;
			cout << resourses << endl;
		};//метод з використанням усіх полів
        void setManager(const char* newManager) {
            strcpy_s(manager, sizeof(manager), newManager);
        }
        void setTeams(const char* newTeams) {
            strcpy_s(teams, sizeof(teams), newTeams);
        }
        void setEmployeers(const char* newEmployeers) {
            strcpy_s(employeers, sizeof(employeers), newEmployeers);
        }
        void setTasks(const char* newTasks) {
            strcpy_s(tasks, sizeof(tasks), newTasks);
        }
        void setResources(const char* newResourses) {
            strcpy_s(resourses, sizeof(resourses), newResourses);
        }//сетери
		project operator+(const project& other) {
			project result;
			result.budget = this->budget + other.budget;
            strcpy_s(result.name, sizeof(result.name), this->name);
            strcat_s(result.name, sizeof(result.name), other.name);
            strcpy_s(result.customer, sizeof(result.customer), this->customer);
            strcat_s(result.customer, sizeof(result.customer), other.customer);
            strcpy_s(result.manager, sizeof(result.manager), this->manager);
            strcat_s(result.manager, sizeof(result.manager), other.manager);
            strcpy_s(result.teams, sizeof(result.teams), this->teams);
            strcat_s(result.teams, sizeof(result.teams), other.teams);
            strcpy_s(result.employeers, sizeof(result.employeers), this->employeers);
            strcat_s(result.employeers, sizeof(result.employeers), other.employeers);
            strcpy_s(result.tasks, sizeof(result.tasks), this->tasks);
            strcat_s(result.tasks, sizeof(result.tasks), other.tasks);
            strcpy_s(result.resourses, sizeof(result.resourses), this->resourses);
            strcat_s(result.resourses, sizeof(result.resourses), other.resourses);
            result.budget = this->budget + other.budget;
			return result;
		}//перевантажений метод, який приймає в якості параметрів об'єкт класу
		friend ostream& operator<<(ostream& os, const project& p) {
			os << "Project Name: " << p.name << endl;
			os << "Customer: " << p.customer << endl;
			os << "Budget: " << p.budget << endl;
			os << "Manager: " << p.manager << endl;
			os << "Teams: " << p.teams << endl;
			os << "Employeers: " << p.employeers << endl;
			os << "Tasks: " << p.tasks << endl;
			os << "Resources: " << p.resourses << endl;
			return os;
		}//перевантажений метод, який повертає тип класу
		void writeToFile(const std::string& filename) const {
			std::ofstream file(filename);
			if (file.is_open()) {
				file << name << endl;
				file << customer << endl;
				file << budget << endl;
				file << manager << endl;
				file << teams << endl;
				file << employeers << endl;
				file << tasks << endl;
				file << resourses << endl;
				file.close();
			}
		}//метод для запису у файл
		void readFromFile(const std::string& filename) {
			std::ifstream file(filename);
			if (file.is_open()) {
				file.getline(name, 256);
				file.getline(customer, 256);
				file >> budget;
				file.ignore();
				file>>manager;
				file>>teams;
				file>>employeers;
				file>>tasks;
				file>>resourses;
				file.close();
			}
			else {
				std::cerr << "Unable to open file: " << filename << std::endl;
			}
		}//метод для читання з файлу
		void changeBudget(int newBudget) {
			budget = newBudget;
		}//метод для зміни бюджету
		void addEmployeer(const employeer& e) {
			team.push_back(e);
		}//метод для приєднання робітника до команди
        void printProjectInfo() const {
            cout << "Project Name: " << name << endl;
            cout << "Customer: " << customer << endl;
            cout << "Budget: " << budget << endl;
            cout << "Team Members:" << endl;
            for (size_t i = 0; i < team.size(); i++) {
                cout << i + 1 << ". " << team[i] << endl;
            }
        }
	private:
		char manager[256];
		char teams[128];
		char employeers[1028];
		employeer employeer;//зв'язок двох об'єктів
		char tasks[5086];
		char resourses[5086];//5 приватних елементів
	};
};