//domain.cpp
#include <iostream>
#include <string>

class User {
private:
    int id;
    std::string name;
    std::string email;
    int id_boss;
    std::string workgroup;
    std::string department;
    std::string role;

public:
    User(int userId, const std::string& userName, const std::string& userEmail, int bossId,
         const std::string& userWorkgroup, const std::string& userDepartment, const std::string& userRole)
        : id(userId), name(userName), email(userEmail), id_boss(bossId), workgroup(userWorkgroup),
          department(userDepartment), role(userRole) {}

    int getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    std::string getEmail() const {
        return email;
    }

    int getBossId() const {
        return id_boss;
    }

    std::string getWorkgroup() const {
        return workgroup;
    }

    std::string getDepartment() const {
        return department;
    }

    std::string getRole() const {
        return role;
    }
};

class Ticket {
private:
    int id;
    std::string title;
    std::string description;
    int user_id;
    std::string timestamp;
    std::string priority;
    std::string status;
    int assigned_to;

public:
    Ticket(int ticketId, const std::string& ticketTitle, const std::string& ticketDescription,
           int userId, const std::string& ticketTimestamp, const std::string& ticketPriority,
           const std::string& ticketStatus, int assignedTo)
        : id(ticketId), title(ticketTitle), description(ticketDescription), user_id(userId),
          timestamp(ticketTimestamp), priority(ticketPriority), status(ticketStatus),
          assigned_to(assignedTo) {}

    int getId() const {
        return id;
    }

    std::string getTitle() const {
        return title;
    }

    std::string getDescription() const {
        return description;
    }

    int getUserId() const {
        return user_id;
    }

    std::string getTimestamp() const {
        return timestamp;
    }

    std::string getPriority() const {
        return priority;
    }

    std::string getStatus() const {
        return status;
    }

    int getAssignedTo() const {
        return assigned_to;
    }
};

class CI {
private:
    int id;
    std::string name;
    std::string description;
    std::string location;
    int owner_id;
    std::string date_added;

public:
    CI(int ciId, const std::string& ciName, const std::string& ciDescription,
       const std::string& ciLocation, int ownerId, const std::string& ciDateAdded)
        : id(ciId), name(ciName), description(ciDescription), location(ciLocation),
          owner_id(ownerId), date_added(ciDateAdded) {}

    int getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    std::string getDescription() const {
        return description;
    }

    std::string getLocation() const {
        return location;
    }

    int getOwnerId() const {
        return owner_id;
    }

    std::string getDateAdded() const {
        return date_added;
    }
};