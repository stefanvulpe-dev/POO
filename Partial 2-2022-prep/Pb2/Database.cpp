#include "Database.h"

Database::Database() {
	this->entries = vector<Entry*>(0);
}

Database& Database::operator+=(Entry* entry) {
	this->entries.push_back(entry);
	return *this;
}

Database& Database::operator-=(const string& name) {
	vector<Entry*>::iterator tmp;
	for (auto it = this->entries.begin(); it != this->entries.end(); ++it) {
		if ((*it)->GetName() == name) {
			tmp = it;
		}
	}
	this->entries.erase(tmp);
	return *this;
}

MyIterator Database::begin() {
	return MyIterator(&this->entries.at(0));
}

MyIterator Database::end() {
	return MyIterator(&this->entries[0] + this->entries.size());
}

void Database::Print() {
	for (auto it = this->entries.begin(); it != this->entries.end(); ++it) {
		(*it)->Print();
	}
	cout << "\n";
}
