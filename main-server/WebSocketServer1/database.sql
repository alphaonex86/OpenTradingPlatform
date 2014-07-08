----------------------
---  TABLE Client  ---
----------------------

CREATE TABLE IF NOT EXISTS Client(
    id int PRIMARY KEY,
    login varchar(32) UNIQUE,
    password varchar(64),
    validated boolean DEFAULT(FALSE),
    emailConfirmId varchar(64) NULL
);
