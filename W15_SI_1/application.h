#pragma once
#include "Database_manager.h"
#include "ui_db_context.h"
#include <iostream>
#include <iomanip>

class Application
{
public:
	int run();
	void menu();
	void welcomeScreen();
	void print(std::vector<Database_entry> db);

	Database_manager manager;
	Ui_db_context db;
};

