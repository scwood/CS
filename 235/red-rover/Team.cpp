#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Team.h"

Team::Team() {
	srand (time(NULL));
	head = NULL;
	size = 0;
}

Team::~Team() {
	clear();
}

void Team::printTeam() {
	Person* go = head;
	while (go->rightPerson != NULL) {
		cout << go->name << ", ";
		go = go->rightPerson;
	}
	cout << go->name << endl;
	go = NULL;
}

void Team::printInfo() {
	Person* go = head;
	while (go != NULL) {
		cout << go->name << ": " << go->strength << ", " << go->speed << endl;
		go = go->rightPerson;
	}
	go = NULL;
}

void Team::shuffleTeam() {
	for (int index = 0; index < size; index++) {
		int random_number = rand() % size;
		if (random_number != index) {
			Person* first = head;
			Person* second = head;
			for (int i = 0; i < index; i++) {
				first = first->rightPerson;
			}
			for (int i = 0; i < random_number; i++) {
				second = second->rightPerson;
			}
			string temp_name = first->name;
			int temp_strength = first->strength;
			int temp_speed = first->speed;
			first->name = second->name;
			first->strength = second->strength;
			first->speed = second->speed;
			second->name = temp_name;
			second->strength = temp_strength;
			second->speed = temp_speed;
			first = NULL;
			second = NULL;
		}
	}
}

void Team::addHeadPerson(string name, int strength, int speed) {
	if (head == NULL) {
		Person* newPerson = new Person(name, strength, speed);
		head = newPerson;
		newPerson = NULL;
		size++;
		return;
	}
	else {
		Person* go = head;
		Person* previous;
		while (go != NULL) {
			previous = go;
			go = go->rightPerson;
		}
		Person* newPerson = new Person(name, strength, speed);
		previous->rightPerson = newPerson;
		newPerson->leftPerson = previous;
		size++;
		newPerson = NULL;
		previous = NULL;
		go = NULL;
		return;
	}
}

void Team::removeHeadPerson() {
	Person* temp = head;
	head = temp->rightPerson;
	delete temp;
	size--;
	return;
}

void Team::remove(string name) {
	Person* go = head;
	while (go != NULL) {
		if (name == go->name) {
			if (go == head) {
				removeHeadPerson();
				go = NULL;
				return;
			}
			else if (go->rightPerson == NULL) {
				Person* temp = go;
				go = go->leftPerson;
				go->rightPerson = NULL;
				delete temp;
				go = NULL;
				size--;
				return;
			}
			else {
				Person* temp = go;
				go = go->leftPerson;
				go->rightPerson = go->rightPerson->rightPerson;
				go = go->rightPerson;
				go->leftPerson = go->leftPerson->leftPerson;
				delete temp;
				go = NULL;
				size--;
				return;
			}
		}
		go = go->rightPerson;
	}
}

void Team::insertAfter(string name, string newName, int strength, int speed) {
	Person* go = head;
	while (go->name != name) {
		go = go->rightPerson;
	}
	if (go->rightPerson == NULL) {
		Person* newPerson = new Person(newName, strength, speed);
		newPerson->leftPerson = go;
		go->rightPerson = newPerson;
		go = NULL;
		newPerson = NULL;
		size++;
		return;
	}
	else {
		Person* newPerson = new Person(newName, strength, speed);
		newPerson->leftPerson = go;
		newPerson->rightPerson = go->rightPerson;
		go->rightPerson = newPerson;
		go = go->rightPerson->rightPerson;
		go->leftPerson = newPerson;
		go = NULL;
		newPerson = NULL;
		size++;
		return;
	}
}

void Team::insertBetween(string name, string newName, int strength, int speed) {
	Person* go = head;
	Person* previous;
	while (go->name != name) {
		previous = go;
		go = go->rightPerson;
	}
	if (go->rightPerson != NULL) {
		insertAfter(name, newName, strength, speed);
		go = NULL;
		previous = NULL;
		return;
	}
	else {
		Person* newPerson = new Person(newName, strength, speed);
		newPerson->leftPerson = previous;
		newPerson->rightPerson = go;
		previous->rightPerson = newPerson;
		go->leftPerson = newPerson;
		go = NULL;
		newPerson = NULL;
		size++;
		return;
	}
}

string Team::headName() {
	return head->name;
}

string Team::nextName(string name) {
	Person* go = head;
	string temp_name;
	while (go != NULL) {
		if (go->name == name) {
			if (go->rightPerson == NULL) {
				go = go->leftPerson;
				temp_name = go->name;
				go = NULL;
				return temp_name;
			}
			else {
				go = go->rightPerson;
				temp_name = go->name;
				go = NULL;
				return temp_name;
			}
		}
		go = go->rightPerson;
	}
	return "";
}

string Team::getRandomPerson() {
	int random_number = rand() % size;
	Person* go = head;
	for (int i = 0; i < random_number; i++) {
		go = go->rightPerson;			
	}
	string temp_name = go->name;
	go = NULL;
	return temp_name;
}

void Team::clear() {
	while (head != NULL) {
		removeHeadPerson();
	}
}

int Team::headStrength() {
	return head->strength;
}

int Team::headSpeed() {
	return head->speed;
}

int Team::strengthAt(string name) {
	Person* go = head;
	while (go != NULL) {
		if (go->name == name) {
			int temp_strength = go->strength;
			go = NULL;
			return temp_strength;
		}
		go = go->rightPerson;
	}
	go = NULL;
	return 0;
}

int Team::speedAt(string name) {
	Person* go = head;
	while (go != NULL) {
		if (go->name == name) {
			int temp_speed = go->speed;
			go = NULL;
			return temp_speed;
		}
		go = go->rightPerson;
	}
	go = NULL;
	return 0;
}

int Team::getSize() {
	return size;
}

bool Team::search(string name) {
	Person* go = head;
	while (go != NULL) {
		if (go->name == name) {
			go = NULL;
			return true;
		}
		go = go->rightPerson;
	}
	go = NULL;
	return false;
}

bool Team::empty() {
	if (size == 0) {
		return true;
	}
	return false;
}