#include <iostream>
#include <vector>
#include "domain.h"

// Inclua os cabeçalhos dos objetos de domínio aqui (User, Ticket, CI)

class IncidentManager {
private:
    std::vector<Ticket> tickets;
    std::vector<User> users;
    // Outros objetos de domínio e repositórios necessários

public:
    void addIncidentTicket(const Ticket& ticket) {
        // Lógica para adicionar um ticket de incidente
        tickets.push_back(ticket);
        std::cout << "Incident ticket added successfully!" << std::endl;
    }

    void listTickets() {
        // Lógica para listar todos os tickets
        std::cout << "Listing all tickets:" << std::endl;
        for (const auto& ticket : tickets) {
            std::cout << "Ticket ID: " << ticket.getId() << std::endl;
            std::cout << "Ticket Title: " << ticket.getTitle() << std::endl;
            std::cout << "Ticket Description: " << ticket.getDescription() << std::endl;
            std::cout << "-----------------------" << std::endl;
        }
    }

    void addUser(const User& user) {
        // Lógica para adicionar um usuário
        users.push_back(user);
        std::cout << "User added successfully!" << std::endl;
    }
};

