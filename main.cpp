#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <cstring>

bool fileExists(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
};

struct recordInfo
{
    char first_name[10];
    char last_name[10];
    float balance;
};

void writevecfield(std::ostream& os, const std::vector<recordInfo> &vec)
{
    typename std::vector<recordInfo>::size_type sz = vec.size();          //size_type as an integer datatype large enough to represent any possible string size
    os.write((char*)&sz, sizeof(sz));                                     // this writes the size of the data
    os.write((char*)&vec[0], vec.size() * sizeof(recordInfo));            // this writes the data itself
};

void readvecfield(std::istream& is, std::vector<recordInfo> &vec)
{
    typename std::vector<recordInfo>::size_type sz = 0;
    is.read((char*)&sz, sizeof(sz));
    vec.resize(sz);
    is.read((char*)&vec[0], vec.size() * sizeof(recordInfo));
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

            if(f1.fail()) {
                std::cerr << "Error opening file" << std::endl;
                exit(1);
            }

            readvecfield(f1, record);

            f1.close();
            }
        else
            std::ofstream myfile("record.txt", std::ios::app);    // this signifies that it is in append mode. You create the file here, and store the values in it after finishing your operation.
    };

    void storeData()                // at the end of each operation you are going to call this function, and update the file, with the new vector.
    {
        std::ofstream str1("record.txt");
        writevecfield(str1, record);
        str1.close();
    };

    void print_data(int i, int mode=0)
    {
        if(mode == 0)
            std::cout << "\nAccount number: " << record.size()-1 << "\n";
        else
            std::cout << "\nAccount number: " << mode << "\n";

        std::cout << "First name: " << record[i].first_name << "\n";
        std::cout << "Last name: " << record[i].last_name << "\n";
        std::cout << "Balance: " << record[i].balance << "\n";
        std::cout << "\n";

    };

    void add_record()
    {
        char name[10];
        char lastname[10];
        float balance;

        std::cout << "First name:";
        std::cin >> name;

        std::cout << "Last name:";
        std::cin >> lastname;

        std::cout << "Balance:";
        std::cin >> balance;

        recordInfo temp;
        strncpy(temp.first_name, name, 10);
        strncpy(temp.last_name, lastname, 10);
        record.push_back(temp);
    };

    void show_records_from_file()
    {
        for(int i = 0; i < record.size(); i++)
            print_data(i, i + 1);
    };

    void search_record()
    {
        int acc_num;
        std::cout << "Enter account number: \n";
        std::cin >> acc_num;
        print_data(acc_num - 1, acc_num);
    };

    void update_record()
    {

        char fName[10];
        char lName[10];
        int bal;
        int num2;

        std::cout << "Enter record number: ";
        std::cin >> num2;

        std::cout << "\n Current data: \n";
        print_data(num2-1, num2);

        std::cout << "Enter new data: \n";
        std::cout << "First name:";
        std::cin >> fName;

        std::cout << "Last name:";
        std::cin >> lName;

        std::cout << "Balance:";
        std::cin >> bal;

        strncpy(record[num2-1].first_name, fName, 10);
        strncpy(record[num2-1].last_name, lName, 10);
        record[num2-1].balance = bal;

        std::cout << "Record successfully updated! \n";
    }

    void delete_record()
    {
        int num;
        std::cout << "Enter record number: ";
        std::cin >> num;
        print_data(num-1, num);
        record.erase(record.begin() + num - 1);

        std::cout << "Record successfully deleted! \n";
    }

};

int main()
{
    int choice;
    Record CL;

    while(true)
    {
    std::cout << "\n ***Account Information System*** \n";
    std::cout << "\t1-->Add record to file \n";
    std::cout << "\t2-->Show record from file \n";
    std::cout << "\t3-->Search record to file \n";
    std::cout << "\t4-->Update record \n";
    std::cout << "\t5-->Delete record \n";
    std::cout << "\t6-->Quit \n";
    std::cout << "Enter your choice: \n";

    std::cin >> choice;

    switch(choice)
        {
        case 1:
            CL.add_record();
            break;
        case 2:
            CL.show_records_from_file();
            break;
        case 3:
            CL.search_record();
            break;
        case 4:
            CL.update_record();
            break;
        case 5:
            CL.delete_record();
            break;
        case 6:
            CL.storeData();
            return 0;              // here you are going to store everything to the file finally.
        };
    };

    return 0;
};
