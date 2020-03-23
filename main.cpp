#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <cstdlib>

bool fileExists(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
};

struct recordInfo
{
    int acc_num;
    std::string first_name;
    std::string last_name;
    float balance;
};

class Record
{

private:
    std::vector<recordInfo> record;
public:
    Record()                          // if the file is not already created, than create it, otherwise, read the data from it.
    {
        if(fileExists("record.txt")){    // if the file exists, read from the file, else create it
            std::ifstream f1;
            f1.open("record.txt");

            // Check for Error
            if(f1.fail()) {
                std::cerr << "Error opening file" << std::endl;
                exit(1);
            }
        }

        else
            std::ofstream myfile("record.txt", std::ios::app);    // this signifies that it is in append mode. You create the file here, and store the values in it after finishing your operation.
    };

    void storeData()                // at the end of each operation you are going to call this function, and update the file, with the new vector.
    {

    };

    void print(int i)
    {
        std::cout << "Account number: " << record[i].acc_num << "\n";
        std::cout << "First name: " << record[i].first_name << "\n";
        std::cout << "Last name: " << record[i].last_name << "\n";
        std::cout << "Balance: " << record[i].balance << "\n";
        std::cout << "\n";

    };

    void add_record()
    {
        int num;
        std::string name;
        std::string lastname;
        float balance;

        std::cout << "Account number:";
        std::cin >> num;
        std::cout << "First name:";
        std::cin >> name;
        std::cout << "Last name:";
        std::cin >> lastname;
        std::cout << "Balance:";
        std::cin >> balance;

        recordInfo temp = {num, name, lastname, balance};
        record.push_back(temp);
    };

    void show_record_from_file()
    {
        for(int i = 0; i < record.size(); i++)
            print(i);
    };


    };

//    void search_record();
//    void update_record();
//    void delete_record();


int main()
{

    int choice;
    Record CL;

    while(true)
    {
    std::cout << "***Account Information System*** \n";
    std::cout << "\t1-->Add record to file \n";
    std::cout << "\t2-->Show record from file \n";
    std::cout << "\t3-->Search record to file \n";
    std::cout << "\t4-->Update record \n";
    std::cout << "\t5-->Delete record \n";
    std::cout << "\t6-->Quit \n";
    std::cout << "Enter your choice:";

    std::cin >> choice;

    switch(choice)
        {
        case 1:
            CL.add_record();
            break;
        case 2:
            CL.show_record_from_file();
            break;
//        case 3:
//            CL.search_record();
//        case 4:
//            CL.update_record();
//        case 5:
//            CL.delete_record();
//        case 6:
//            exit();
        };
    }

    return 0;
}
