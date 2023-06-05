# ER Diagram #

```mermaid

erDiagram
    USER ||--|{ TICKET : creates
    USER ||--|| USER : manages
    TICKET ||--|| INCIDENT : relates_to
    INCIDENT ||--|| PROBLEM : relates_to
    PROBLEM ||--|{ INCIDENT : has
    USER {
        string name
        string email
        string role
    }
    TICKET {
        string description
        string status
        string priority
        datetime sla_expiry
    }
    INCIDENT {
        string severity
        string description
    }
    PROBLEM {
        string impact
    }
    ```
