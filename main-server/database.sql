----------------------
---  TABLE Client  ---
----------------------

CREATE TABLE IF NOT EXISTS Client(
    id int PRIMARY KEY,
    login varchar(32) UNIQUE,
    password varchar(64)
);
