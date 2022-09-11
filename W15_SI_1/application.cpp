#include "application.h"
#include "Windows.h"

int Application::run()
{
    welcomeScreen();
    menu();
    return 0;
}

void Application::menu()
{
    int choose{ 0 };
    std::cout << "\n\nStudents: " << manager.studentsDB.size();

   std::cout << "\n\n\n\nPlease choose what You want to do:" << std::endl;
   std::cout << "\n1. Modify database\n"
       << "2. Load/Store database\n"
       << "3. Filter database\n"
       << "4. Set sorting order\n"
       << "5. Visualize database\n"
       << "6. EXIT\n" << std::endl << "-> ";
    std::cin >> choose;

   switch (choose) {
   case 1:
   {
       system("cls");
       int choose1{ 0 };

       std::cout << "\n1.Add entry"
           << "\n2.Remove entry"
           << "\n3.Modify entry"
           << "\n4.<- BACK" << std::endl << "-> ";
       std::cin >> choose1;

       switch (choose1) {
       case 1:
       {
           std::string stName;
           uint8_t stGrade;

           std::cout << "\nPlease enter a name of student:" << std::endl << "-> ";
           std::cin >> stName;
           std::cout << "\nPlease enter grade of this student:" << std::endl << "-> ";
           std::cin >> stGrade;

           manager.add_entry(stName, stGrade);
           system("cls");
           std::cout << "\nNew student was succesfully added!" << std::endl;
           Sleep(2000);
           system("cls");
           menu();
           break;
       }
       case 2:
       {
           std::string stName;
           std::cout << "\nPlease enter a name of student You want to delete:" << std::endl << "-> ";
           std::cin >> stName;

           manager.remove_entry(stName);
           system("cls");
           std::cout << "\nStudent was succesfully deleted!" << std::endl;
           Sleep(2000);
           system("cls");
           menu();
           break;
       }

       case 3:
       {
           std::string stName;
           uint8_t stGrade;
           std::cout << "\nPlease enter a name of student You want to modify:" << std::endl << "-> ";
           std::cin >> stName;
           system("cls");
           std::cout << "\nPlease enter new grade: " << std::endl << "->";
           std::cin >> stGrade;
           manager.modify_entry(stName, stGrade);
           Sleep(2000);
           system("cls");
           menu();
           break;
       }
       case 4:
       {
           system("cls");
           welcomeScreen();
           menu();
           break;
       }
     }
       break;
   }
   case 2:
   {
       system("cls");
       int choose2{ 0 };

       std::cout << "\n1.Load database from the file"
           << "\n2.Store database in a file"
           << "\n3.<- BACK" << std::endl << "-> ";
       do {
           std::cin >> choose2;
       } while (choose2 != 1 && choose2 != 2 && choose2 != 3);

       switch (choose2) {
       case 1:
       {
           manager.read_DB_from_file();
           system("cls");
           welcomeScreen();
           menu();
           break;
       }
       case 2:
       {
           manager.save_DB_to_file();
           system("cls");
           welcomeScreen();
           menu();
           break;
       }
       case 3:
       {
           system("cls");
           welcomeScreen();
           menu();
       }
     }
       break;
   }
   case 3:
   {
       system("cls");
       int choose3{ 0 };

       std::cout << "\n1. Apply filter \"-Only passing grades\""
           << "\n2. Apply filter \"-Only non-passing grades\""
           << "\n3. Apply filter \"-All grades\""
           << "\n4. <- BACK" << std::endl << "-> ";
        std::cin >> choose3;
        switch (choose3) {
        case 1:
        {
           // db.filtering = []() {};          in progress
        }
        case 2:
        {

        }
        case 3:
        {

        }
        case 4:
        {
            system("cls");
            welcomeScreen();
            menu();
        }
     }
       break;
   }
   case 4:
   {
       system("cls");
       int choose4{ 0 };

       std::cout << "\n1. Set sorting \"-Increasing by name\""
           << "\n2. Set sorting \"-Decreasing by name\""
           << "\n3. Set sorting \"-Increasing by grade\""
           << "\n3. Set sorting \"-Decreasing by grade\""
           << "\n4. <- BACK" << std::endl << "-> ";

       std::cin >> choose4;
       switch (choose4) {
       case 1:
       {

       }
       case 2:
       {

       }
       case 3:
       {

       }
       case 4:
       {
           system("cls");
           welcomeScreen();
           menu();
       }
       }
       break;

   }
   case 5:
   {
       system("cls");
       welcomeScreen();
       manager.get_entries();
      
       //print();
       Sleep(3000);
       system("cls");
       welcomeScreen();
       menu();
   }
 
   case 6:
   {
       system("cls");
       welcomeScreen();
       std::cout << "GOOD BYE!" << std::endl;
       Sleep(2000);
       exit(1);
   }
   default:
       system("cls");
       welcomeScreen();
       menu();
   }
  
}

void Application::welcomeScreen()
{
    std::cout << "\n\t*** GRADE MANAGEMENT SYSTEM ***\n" << std::endl;
}

void Application::print(std::vector<Database_entry> vec)
{
    for (auto i : vec) {
        std::cout << "\n---------------------------" << std::endl;
        std::cout << "| Student: " << i.students_name << "| Grade: " << i.grade << " |" << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
}
