#include <iostream>
#include "managment.h"
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    managment::employeer staticEmployeers[5]; // 5 об'єктів у статичній пам'яті
    managment::employeer* employeerPtr = &staticEmployeers[0];
    strcpy_s(employeerPtr->name, "Petruk Kateryna");
    strcpy_s(employeerPtr->position, "Accountant");
    employeerPtr->experience = 2;
    employeerPtr->setEmployeerID("Petryk");
    employeerPtr->setTeam("Rows");
    employeerPtr->setTasks("Manage project budget and track expenses. Prepare financial reports and ensure accuracy. Process invoices, payments, and ensure compliance with accounting standards.");
    employeerPtr->setResources("Accounting Software, Spreadsheets, Financial Reporting Tools, Legal/Compliance Guidelines");
    employeerPtr->setBudget(5000);//використання сетерів
    employeerPtr->printInfo();//використання покажчика
    staticEmployeers[0].addExperience(5);
    cout << "\nAfter adding experience (5 years)" << endl;
    staticEmployeers[0].printInfo();// Виклик методу додавання досвіду
    staticEmployeers[0].writeToFile("employeer.txt");// Запис співробітника у файл
    staticEmployeers[0].readFromFile("employeer.txt");
    cout << "\nInformation after reading from a file" << endl;
    staticEmployeers[0].printInfo();// Читання співробітника з файлу
    cout << "\nOutput via an overloaded operator" << endl;
    cout << staticEmployeers[0] << endl;// Використання перевантаженого оператора <<
    strcpy_s(staticEmployeers[1].name, "Solodyuk Andrii");
    strcpy_s(staticEmployeers[1].position, "Designer");
    staticEmployeers[1].experience = 4;
    staticEmployeers[1].setEmployeerID("Suslik");
    staticEmployeers[1].setTeam("Rows");
    staticEmployeers[1].setTasks("Create visual concepts for project materials (graphics, layouts, etc.). Design logos, websites, or promotional assets based on project needs. Collaborate with the team to ensure designs align with the project vision.");
    staticEmployeers[1].setResources("Design Software, Inspiration Platforms, Collaboration Tools");
    staticEmployeers[1].setBudget(10000);
    staticEmployeers[1].printInfo();
    managment::employeer combinedEmployeer = staticEmployeers[0] + staticEmployeers[1];
    cout << "\nUnited employee (via the + operator)" << endl;
    combinedEmployeer.printInfo(); // Використання перевантаженого оператора +
    strcpy_s(staticEmployeers[2].name, "Borishchuk Sophia");
    strcpy_s(staticEmployeers[2].position, "Coder");
    staticEmployeers[2].experience = 3;
    staticEmployeers[2].setEmployeerID("Borshch");
    staticEmployeers[2].setTeam("Rows");
    staticEmployeers[2].setTasks("Write and maintain clean, efficient code for project applications. Debug, test, and optimize code to ensure performance and functionality. Collaborate with the team to meet project requirements and deadlines.");
    staticEmployeers[2].setResources("Development Tools, Programming Languages, Collaboration Tools, Code Libraries");
    staticEmployeers[2].setBudget(15000);
    staticEmployeers[2].printInfo();
    strcpy_s(staticEmployeers[3].name, "Lisovska Viktoria");
    strcpy_s(staticEmployeers[3].position, "Marketer");
    staticEmployeers[3].experience = 6;
    staticEmployeers[3].setEmployeerID("Fairy");
    staticEmployeers[3].setTeam("Tales");
    staticEmployeers[3].setTasks("Develop and implement marketing strategies to promote the project. Manage social media campaigns, email marketing, and ads. Analyze market trends and customer feedback to optimize campaigns.");
    staticEmployeers[3].setResources("Marketing Tools, Design Tools, SEO & SEM Tools, Collaboration Tools");
    staticEmployeers[3].setBudget(30000);
    staticEmployeers[3].printInfo();
    strcpy_s(staticEmployeers[4].name, "Suska Nadia");
    strcpy_s(staticEmployeers[4].position, "Tester");
    staticEmployeers[4].experience = 5;
    staticEmployeers[4].setEmployeerID("Angel");
    staticEmployeers[4].setTeam("Tales");
    staticEmployeers[4].setTasks("Test software and applications to identify bugs and issues. Develop test cases and scenarios based on project requirements. Collaborate with developers to ensure product quality and functionality.");
    staticEmployeers[4].setResources("Testing Tools, Bug Tracking Tools, Automation Tools, Collaboration Tools.");
    staticEmployeers[4].setBudget(35000);
    staticEmployeers[4].printInfo();

    managment::project* dynamicProjects[5];     // 5 об'єктів у динамічній пам'яті
    for (int i = 0; i < 5; i++) {
        dynamicProjects[i] = new managment::project();
    }
    strcpy_s(dynamicProjects[0]->name, "Website development");
    strcpy_s(dynamicProjects[0]->customer, "Sushi-Kushi");
    dynamicProjects[0]->budget = 50000;
    dynamicProjects[0]->setManager("Uzliuk Iryna");//використання сетерів
    dynamicProjects[0]->setTeams("Tales");
    dynamicProjects[0]->setEmployeers("Lisovska Viktoriya, Suska Nadia");
    dynamicProjects[0]->setTasks("Create a visually appealing website for a sushi restaurant that allows customers to browse the menu and place orders online.");
    dynamicProjects[0]->setResources("Domain Name and Hosting; Content Management System (CMS); Database; Frontend Libraries/Frameworks; Payment Gateway; Image Resources; Development Tools; Analytics; SEO Tools; Customer Support.");
    dynamicProjects[0]->printInfo();
    dynamicProjects[0]->changeBudget(60000);
    cout << "\nAfter changing the project budget" << endl;
    dynamicProjects[0]->printInfo();// Зміна бюджету проекту
    dynamicProjects[0]->writeToFile("project.txt");// Запис проекту у файл
    dynamicProjects[0]->readFromFile("project.txt");
    cout << "\nThe project after reading from the file" << endl;
    dynamicProjects[0]->printInfo();// Читання проекту з файлу
    cout << "\nExiting the project through an overloaded operator" << endl;
    cout << *dynamicProjects[0] << endl;// Використання перевантаженого оператора << для проекту
    strcpy_s(dynamicProjects[1]->name, "Fixing bugs");
    strcpy_s(dynamicProjects[1]->customer, "KvaCommision");
    dynamicProjects[1]->budget = 30000;
    dynamicProjects[1]->setManager("Yaroshuk Karina");
    dynamicProjects[1]->setTeams("Rows");
    dynamicProjects[1]->setEmployeers("Petruk Kateryna, Borishchuk Sophia");
    dynamicProjects[1]->setTasks("Identify and resolve bugs in the frog-themed website to enhance user experience and functionality.");
    dynamicProjects[1]->setResources("Testing Tools; Bug Tracking Tools; Development Tools; User Feedback Tools; Documentation; Analytics.");
    dynamicProjects[1]->printInfo();
    managment::project combinedProject = *dynamicProjects[0] + *dynamicProjects[1];
    cout << "\nCombined project (via the + operator)" << endl;
    combinedProject.printInfo();// Об'єднання двох проектів через оператор +
    strcpy_s(dynamicProjects[2]->name, "Advertisting campaign");
    strcpy_s(dynamicProjects[2]->customer, "LadyBugAuto");
    dynamicProjects[2]->budget = 45000;
    dynamicProjects[2]->setManager("Potapskiy Vladyslav");
    dynamicProjects[2]->setTeams("Tales, Rows");
    dynamicProjects[2]->setEmployeers("Lisovska Viktoriya, Suska Nadia, Petruk Kateryna, Borishchuk Sophia, Solodyuk Andrii");
    dynamicProjects[2]->setTasks("Develop and execute an effective advertising campaign to promote a new automobile model, increasing brand awareness and driving sales.");
    dynamicProjects[2]->setResources("Market Research Tools; Creative Tools; Advertising Platforms; Budget Management; Analytics Tools; Collaboration Tools.");
    dynamicProjects[2]->printInfo();
    for (int i = 0; i < 5; i++) {
        delete dynamicProjects[i];
    }

    managment::employeer employeer1;
    strcpy_s(employeer1.name, "Petruk Kateryna");
    strcpy_s(employeer1.position, "Accountant");
    employeer1.experience = 2;
    employeer1.setEmployeerID("Petryk");
    employeer1.setTeam("Rows");
    employeer1.setTasks("Manage project budget and track expenses. Prepare financial reports and ensure accuracy. Process invoices, payments, and ensure compliance with accounting standards.");
    employeer1.setResources("Accounting Software, Spreadsheets, Financial Reporting Tools, Legal/Compliance Guidelines");
    employeer1.setBudget(5000);
    managment::employeer employeer2;
    strcpy_s(employeer2.name, "Borishchuk Sophia");
    strcpy_s(employeer2.position, "Coder");
    employeer2.experience = 3;
    employeer2.setEmployeerID("Borshch");
    employeer2.setTeam("Rows");
    employeer2.setTasks("Write and maintain clean, efficient code for project applications. Debug, test, and optimize code to ensure performance and functionality. Collaborate with the team to meet project requirements and deadlines.");
    employeer2.setResources("Development Tools, Programming Languages, Collaboration Tools, Code Libraries");
    employeer2.setBudget(15000);
    managment::project project1;
    strcpy_s(project1.name, "Fixing bugs");
    strcpy_s(project1.customer, "KvaCommision");
    project1.budget = 30000;
    project1.addEmployeer(employeer1);
    project1.addEmployeer(employeer2);
    cout << "\nInformation about the project" << endl;
    project1.printProjectInfo();//взаємодія

    employeer1.printInfo();
    employeer1.generateAndSortExperience(10);//генерація

    return 0;
}
