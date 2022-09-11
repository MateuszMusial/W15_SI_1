#pragma once
#include <algorithm>
#include <string>
#include <unordered_map>
#include "Database_entry.h"
#include <fstream>
#include <iostream>
#include "Windows.h"

class Database_manager
{
	
public:
	Database_manager() = default;
	~Database_manager() = default;
	void add_entry(std::string name, uint8_t grade);
	void remove_entry(std::string name);
	void modify_entry(std::string name, uint8_t newGrade);
	void save_DB_to_file();
	void read_DB_from_file();
	std::vector<Database_entry> get_entries();
	std::unordered_map<std::string, uint8_t> studentsDB;

};

