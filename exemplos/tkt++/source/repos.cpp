//repos.cpp
#ifndef TKTPP_REPOS_H
#define TKTPP_REPOS_H

#include <iostream>
#include <fstream>
#include "domain.h"
#include "repos.h"

// IncidentsRepository implementation

std::vector<Incident> IncidentsRepository::getAllIncidents() {
    std::ifstream file(".tkt++/incidents-repo.csv");
    std::vector<Incident> incidents;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // Parse the line and create Incident objects
            // Add the Incident objects to the vector
        }

        file.close();
    } else {
        std::cerr << "Failed to open incidents-repo.csv" << std::endl;
    }

    return incidents;
}

void IncidentsRepository::addIncident(const Incident& incident) {
    std::ofstream file(".tkt++/incidents-repo.csv", std::ios_base::app);

    if (file.is_open()) {
        // Write the incident details to the file
        // Format the incident details according to the CSV format

        file.close();
    } else {
        std::cerr << "Failed to open incidents-repo.csv" << std::endl;
    }
}

void IncidentsRepository::deleteIncident(int id) {
    // Remove the incident with the given id from the incidents-repo.csv file
    // Update the file accordingly
}

// UsersRepository implementation

std::vector<User> UsersRepository::getAllUsers() {
    std::ifstream file(".tkt++/users-repo.csv");
    std::vector<User> users;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // Parse the line and create User objects
            // Add the User objects to the vector
        }

        file.close();
    } else {
        std::cerr << "Failed to open users-repo.csv" << std::endl;
    }

    return users;
}

void UsersRepository::addUser(const User& user) {
    std::ofstream file(".tkt++/users-repo.csv", std::ios_base::app);

    if (file.is_open()) {
        // Write the user details to the file
        // Format the user details according to the CSV format

        file.close();
    } else {
        std::cerr << "Failed to open users-repo.csv" << std::endl;
    }
}

void UsersRepository::deleteUser(int id) {
    // Remove the user with the given id from the users-repo.csv file
    // Update the file accordingly
}

// CIRepository implementation

std::vector<CI> CIRepository::getAllCIs() {
    std::ifstream file(".tkt++/ci-repo.csv");
    std::vector<CI> cis;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // Parse the line and create CI objects
            // Add the CI objects to the vector
        }

        file.close();
    } else {
        std::cerr << "Failed to open ci-repo.csv" << std::endl;
    }

    return cis;
}

void CIRepository::addCI(const CI& ci) {
    std::ofstream file(".tkt++/ci-repo.csv", std::ios_base::app);

    if (file.is_open()) {
        // Write the CI details to the file
        // Format the CI details according to the CSV format

        file.close();
    } else {
        std::cerr << "Failed to open ci-repo.csv" << std::endl;
    }
}

void CIRepository::deleteCI(int id) {
    // Remove the CI with the given id from the ci-repo.csv file
    // Update the file accordingly
}
