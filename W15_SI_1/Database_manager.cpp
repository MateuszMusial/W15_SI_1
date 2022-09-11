#include "Database_manager.h"

void Database_manager::add_entry(std::string name, uint8_t grade)
{
	studentsDB.insert(std::make_pair(name, grade));
}

void Database_manager::remove_entry(std::string name)
{
	studentsDB.erase(name);
}

void Database_manager::modify_entry(std::string name, uint8_t newGrade)
{
	studentsDB.at(name) = newGrade;
}

void Database_manager::save_DB_to_file()
{
	std::ofstream myFile{ "studentsAndGrades.txt",std::ios::trunc };
	if (myFile) {
		
			for (auto& it : studentsDB) {
				myFile << it.first << "\n"
					<< it.second << std::endl;
			}
		
		std::cout << "\nDatabase has been saved to the file succesfully!" << std::endl;
		Sleep(2000);
		myFile.close();
	}
	else {
		std::cerr << "Cannot open the file!" << std::endl;
		Sleep(2000);
	}
	studentsDB.clear();
}

void Database_manager::read_DB_from_file()
{
	std::ifstream myFile{ "studentsAndGrades.txt" };
	if (myFile) {
		std::string name;
		uint8_t grade;

		while (!myFile.eof()) {
			myFile >> name;
			myFile >> grade;
			studentsDB.insert({ name, grade });
		}

		std::cout << "\nDatabase has been loaded from the file succesfully!" << std::endl;
		Sleep(2000);
		myFile.close();
	}
	else {
		std::cerr << "Cannot open the file!" << std::endl;
		Sleep(2000);
	}
}

std::vector<Database_entry> Database_manager::get_entries()
{
	std::vector<Database_entry> dbVec(studentsDB.size());
	int i{ 1 };

	for (auto& it : studentsDB) {
		Database_entry i;
		i.students_name = it.first;
		i.grade = it.second;
		dbVec.push_back(i);
	}

	for (auto i : dbVec) {
		std::cout << "\n---------------------------" << std::endl;
		std::cout << "| Student: " << i.students_name << "| Grade: " << i.grade << " |" << std::endl;
		std::cout << "---------------------------" << std::endl;
	}
	return dbVec;
}
