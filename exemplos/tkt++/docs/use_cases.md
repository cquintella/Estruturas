
# Use Case #

Sure, here are the descriptions for each use case:

**User_Standard (role)**

- **User Authenticates**: This use case involves the user providing their credentials (such as username and password) to access the system. The system verifies the credentials and, if valid, grants access to the user.

- **Open a Ticket**: In this use case, the user creates a new ticket in the system. This could involve specifying details about an issue they are experiencing, or a request they have.

- **Change Ticket Status**: This use case involves the user updating the status of a ticket they have opened. This could involve marking the ticket as resolved, or updating progress on the issue or request.

**User_Admin (role)**

- **Creates a User**: This use case involves the admin creating a new user account in the system. This could involve specifying the user's details and assigning them a role.

- **Modify a User**: In this use case, the admin makes changes to an existing user's account. This could involve updating the user's details or changing their role.

- **Disable a User**: This use case involves the admin disabling a user's account, which would prevent the user from accessing the system.

- **Promotes a User to Admin**: In this use case, the admin changes a user's role to admin, granting them admin privileges.

- **Demotes a User to Standard User**: This use case involves the admin changing an admin's role to a standard user, removing their admin privileges.

**User_Analyst (role)**

- **Add Ticket**: This use case involves the analyst creating a new ticket in the system. This could involve specifying details about an issue they are investigating, or a request they are handling.

- **Add Action to Ticket**: In this use case, the analyst adds an action to a ticket. This could involve specifying a step taken to resolve the issue or fulfill the request.

- **Change Ticket Status**: This use case involves the analyst updating the status of a ticket. This could involve marking the ticket as resolved, or updating progress on the issue or request.

- **Add a Problem**: In this use case, the analyst identifies a new problem and adds it to the system. This could involve specifying details about the problem and its impact.

- **Modify Problem**: This use case involves the analyst making changes to an existing problem in the system. This could involve updating the problem's details or impact.

- **Close Problem**: This use case involves the analyst marking a problem as resolved.

- **Add an Incident**: In this use case, the analyst identifies a new incident and adds it to the system. This could involve specifying details about the incident and its impact.

- **Modify Incident**: This use case involves the analyst making changes to an existing incident in the system. This could involve updating the incident's details or impact.

- **Close Incident**: This use case involves the analyst marking an incident as resolved.

**User_Manager (role)**

- **Gets Notification of SLA Violation**: In this use case, the manager receives a notification when a Service Level Agreement (SLA) is violated. This could involve a ticket not being resolved within the agreed time frame.

- **Demands Action (*out of the system)**: This use case involves the manager taking action in response to an issue. This could involve communicating with team members or stakeholders, or making decisions about resources or priorities.


```mermaid

   graph TB
    subgraph User_Standard
    UA["User Authenticates"]
    OT["Open a Ticket"]
    CTS["Change Ticket Status"]
    end
    subgraph User_Admin
    CU["Creates a User"]
    MU["Modify a User"]
    DU["Disable a User"]
    PUA["Promotes a User to Admin"]
    DUS["Demotes a User to Standard User"]
    end
    subgraph User_Analyst
    AT["Add Ticket"]
    AAT["Add Action to Ticket"]
    CTS2["Change Ticket Status"]
    AP["Add a Problem"]
    MP["Modify Problem"]
    CP["Close Problem"]
    AI["Add an Incident"]
    MI["Modify Incident"]
    CI["Close Incident"]
    end
    subgraph User_Manager
    GNSV["Gets Notification of SLA Violation"]
    DA["Demands Action"]
    end
    User_Standard -- UA
    User_Standard -- OT
    User_Standard -- CTS
    User_Admin -- CU
    User_Admin -- MU
    User_Admin -- DU
    User_Admin -- PUA
    User_Admin -- DUS
    User_Analyst -- AT
    User_Analyst -- AAT
    User_Analyst -- CTS2
    User_Analyst -- AP
    User_Analyst -- MP
    User_Analyst -- CP
    User_Analyst -- AI
    User_Analyst -- MI
    User_Analyst -- CI
    User_Manager -- GNSV
    User_Manager -- DA
```

