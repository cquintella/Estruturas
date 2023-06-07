//g++ -o IncidentsRepositoryTest IncidentsRepositoryTest.cpp repos.cpp ./IncidentsRepositoryTest
#include <iostream>
#include <cassert>
#include "domain.h"
#include "repos.h"

void testIncidentsRepository() {
    IncidentsRepository repo;

    // Test adding an incident
    Incident incident1;
    incident1.id = 1;
    incident1.description = "Test incident 1";
    repo.addIncident(incident1);

    // Test getting all incidents
    std::vector<Incident> incidents = repo.getAllIncidents();
    assert(incidents.size() == 1);
    assert(incidents[0].id == incident1.id);
    assert(incidents[0].description == incident1.description);

    // Test adding another incident
    Incident incident2;
    incident2.id = 2;
    incident2.description = "Test incident 2";
    repo.addIncident(incident2);

    // Test getting all incidents again
    incidents = repo.getAllIncidents();
    assert(incidents.size() == 2);

    // Test deleting an incident
    repo.deleteIncident(1);
    incidents = repo.getAllIncidents();
    assert(incidents.size() == 1);
    assert(incidents[0].id == incident2.id);
    assert(incidents[0].description == incident2.description);
}

int main() {
    testIncidentsRepository();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
