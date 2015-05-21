drop table if exists person;
drop table if exists project;
drop table if exists field;
drop table if exists batch;
drop table if exists record;
drop table if exists cell;

create table person
(
  id integer not null primary key autoincrament,
  user_name varchar(255) not null,
  password varchar(255) not null,
  first_name varchar(255) not null,
  last_name varchar(255) not null,
  email varchar(255) not null,
  number_indexed integer not null,
  current_batch_id integer not null
);

create table project
(
  id integer not null primary key autoincrament,
  title varchar(255) not null,
  records_per_image integer not null,
  first_y_coord integer not null,
  record_height integer not null
);

create table field
(
  id integer not null primary key autoincrament,
  parent_id integer not null,
  title varchar(255) not null,
  width integer not null,
  column_number integer not null,
  first_x_coord integer not null
);

create table batch
(
  id integer not null primary key autoincrament,
  parent_id integer not null,
  path varchar(255)
  available boolean not null
);

create table record
(
  id integer not null primary key autoincrament,
  parent_id integer not null,
  row_number integer not null
);

create table cell
(
  parent_id integer not null,
  field_id integer not null,
  value varchar(255) not null
);
