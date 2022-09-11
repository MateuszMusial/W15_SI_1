#pragma once
#include <functional>
#include "Database_entry.h"
#include "Database_manager.h"

class Ui_db_context
{
public:
	Ui_db_context();

	std::function <bool(const typename std::vector<Database_entry>, const typename std::vector<Database_entry>)> filtering;
	std::function <bool(const typename Database_entry, const typename Database_entry)> sorting;
	
};

