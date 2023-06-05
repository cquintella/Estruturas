#ifndef DOMAIN_H
#define DOMAIN_H

#include <string>

class User {
private:
    int id;
    std::string name;
    std::string email;
    int bossId;
    std::string workgroup;
    std::string department;
    std::string role;

public:
    User(int id, const std::string& name, const std::string& email, int bossId,
         const std::string& workgroup, const std::string& department, const std::string& role);

    // Getters and setters for User class

    int getId() const;
    std::string getName() const;
    std::string getEmail() const;
    int getBossId() const;
    std::string getWorkgroup() const;
    std::string getDepartment() const;
    std::string getRole() const;
};

class Ticket {
private:
    int id;
    std::string title;
    std::string description;
    int userId;
    std::string timestamp;
    std::string priority;
    std::string status;
    int assignedTo;

public:
    Ticket(int id, const std::string& title, const std::string& description, int userId,
           const std::string& timestamp, const std::string& priority, const std::string& status,
           int assignedTo);

    // Getters and setters for Ticket class

    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    int getUserId() const;
    std::string getTimestamp() const;
    std::string getPriority() const;
    std::string getStatus() const;
    int getAssignedTo() const;
};

// Other domain classes (CI, etc.) and their headers

#endif  // DOMAIN_H
