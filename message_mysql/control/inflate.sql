CREATE DATABASE message_control;

GRANT SELECT, INSERT, UPDATE, DELETE, CREATE, INDEX, DROP, ALTER, CREATE TEMPORARY TABLES, LOCK TABLES ON message_control.* TO 'root'@'localhost';


CREATE DATABASE message_client;

GRANT SELECT, INSERT, UPDATE, DELETE, CREATE, INDEX, DROP, ALTER, CREATE TEMPORARY TABLES, LOCK TABLES ON message_client.* TO 'root'@'localhost';


create table message_control.client (
    Id int,
    Code nvarchar(10),
    Value nvarchar(256)
);

create table message_control.db_enviroment (
    Id int,
    Client_Id int,
    Schema_Name NVARCHAR(50)
);

drop table message_client.topics;
drop table message_client.user;
drop table message_client.client_node_topic;
drop table message_client.client_node;
drop table message_client.user_client_node;
drop table message_client.user_password;
drop table message_client.payload_history;

create table message_client.topics (
    Id int NOT NULL AUTO_INCREMENT,
    Value nvarchar(80),
    PRIMARY KEY (Id)
);

create table message_client.user (
    Id int NOT NULL AUTO_INCREMENT,
    FirstName nvarchar(120),
    LastName nvarchar(120),
    Email nvarchar(120),
    UserName nvarchar(100),
    ImageURL nvarchar(120),
    PRIMARY KEY (Id)
);

create table message_client.client_node_topic (
    ClientNodeId int,
    TopicId int
);

create table message_client.client_node (
    Id int NOT NULL AUTO_INCREMENT,
    Code nvarchar(120),
    MessageService bit,
    PRIMARY KEY (Id)
);

create table message_client.user_client_node (
    UserId int,
    ClientNodeId int
);

create table message_client.user_password (
    UserId int,
    password varchar(40)
);

create table message_client.payload_history (
    Id int NOT NULL AUTO_INCREMENT,
    PayloadMessage text,
    Discriminator nvarchar(20),
    TopicId int,
    UserId int,
    DateSent datetime,
    PRIMARY KEY (Id)
);


DELETE FROM message_control.client;
DELETE FROM message_control.db_enviroment;

INSERT INTO message_control.client
VALUES(1, 'client1', 'message client');

INSERT INTO message_control.db_enviroment
VALUES(1, 1, 'message_client');

DELETE FROM message_client.topics;
DELETE FROM message_client.user;
DELETE FROM message_client.user_password;
DELETE FROM message_client.client_node_topic;
DELETE FROM message_client.client_node;
DELETE FROM message_client.user_client_node;
DELETE FROM message_client.user;
DELETE FROM message_client.payload_history;

INSERT INTO message_client.topics
VALUES(1, 'message_service')
    , (2, 'client_1')
    , (3, 'client_2')
    , (4, 'client_3');

INSERT INTO message_client.user
VALUES(1, 'test', 'user', 'testUser@gmail.com', 'test_user', 'https://www.spicefactors.com/wp-content/uploads/default-user-image.png'),
      (2, 'test', 'user2', 'testUser2@gmail.com', 'test_user_2', 'https://www.spicefactors.com/wp-content/uploads/default-user-image.png'),
      (3, 'test', 'user3', 'testUser3@gmail.com', 'test_user_3', 'https://www.spicefactors.com/wp-content/uploads/default-user-image.png');

INSERT INTO message_client.user_password
VALUES(1, SHA1('test123'))
    , (2, SHA1('test123'))
    , (3, SHA1('test123'));

INSERT INTO message_client.client_node_topic
VALUES(1, 1)
    , (2, 2)
    , (3, 3)
    , (4, 4);

INSERT INTO message_client.client_node
VALUES(1, 'message_service_bus', 1)
    , (2, 'client_user_1', 0)
    , (3, 'client_user_2', 0)
    , (4, 'client_user_3', 0);

INSERT INTO message_client.user_client_node
VALUES(1, 2)
    , (2, 3)
    , (3, 4);