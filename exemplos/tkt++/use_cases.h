//use_cases.h
#ifndef USE_CASES_H
#define USE_CASES_H

#include "domain.h"
#include <vector>

class UserUseCase {
public:
    std::vector<User> getAllUsers();
    User findUserByName(const std::string& name);
    void printUser(const User& user);
    void addUser(const User& user);
    void deleteUser(const User& user, const User& loggedInUser);
};

class IncidentUseCase {
public:
    std::vector<Incident> getAllIncidents();
    void printIncident(const Incident& incident);
    Incident findIncidentByTitle(const std::string& title);
    void deleteIncident(const Incident& incident);
    void addIncident(const Incident& incident);
};

class CIUseCase {
public:
    std::vector<CI> getAllCIs();
    void printCI(const CI& ci);
    void addCI(const CI& ci);
    void deleteCI(const CI& ci);
};

#endif  // USE_CASES_H
