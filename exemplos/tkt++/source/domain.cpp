// IC.h
#include <string>
#include <list>

class IC {
public:
    int id;
    std::string name;
    int location_id;
    int vendor_id;
    int model_id;
    std::string serial_num;

    IC() {}
    ~IC() {}

    void update();
    void show();
};

// User.h
class User {
public:
    int id;
    std::string name;
    std::string email;
    int manager_id;
    int team;
    int organization;
    int role;
    int system_role;

    User() {}
    ~User() {}

    void update();
    void show();
    void change_role();
};

// Ticket.h
class Ticket {
public:
    int id;
    std::string description;
    std::string status;
    User assignedTo;
    User owner;
    int dt_creation;
    std::list<std::string> action;
    std::string priority;
    std::string sla;

    Ticket() {}
    ~Ticket() {}

    void updateStatus();
    void notifySLAExpiry();
    void change_priority();
    void add_action();
    void change_assigned();
};

// Incident.h
class Incident {
public:
    int id;
    Ticket relatedTicket;
    std::string severity;
    std::string description;
    std::string status;

    Incident() {}
    ~Incident() {}

    void escalate();
    void setStatus();
};

// Problem.h
class Problem {
public:
    int id;
    std::list<Incident> relatedIncidents;
    std::string impact;
    std::string response;
    std::string status;

    Problem() {}
    ~Problem() {}

    void linkIncident();
    void changeStatus();
    void close();
};
