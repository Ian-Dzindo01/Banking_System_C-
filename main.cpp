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

    };

    void print_data(int i)
    {
        std::cout << "\nAccount number: " << record[i].acc_num << "\n";
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

    void show_records_from_file()
    {
        for(int i = 0; i < record.size(); i++)
            print_data(i);
    };

    void search_record()
    {
        int acc_num;
        std::cout << "Enter account number: \n";
        std::cin >> acc_num;
        print_data(acc_num - 1);
    }

    void update_record()
    {
        int num;
        std::cout << "Enter record number: ";
        std::cin >> num;

        std::string fName, lName;
        int bal;

        std::cout << "Current data:";
        print_data(num);

        std::cout << "Enter new data: \n";
        std::cout << "First name:";
        std::cin >> fName;
        std::cout << "Last name:";
        std::cin >> lName;
        std::cout << "Balance:";
        std::cin >> bal;

        record[num].first_name = fName;
        record[num].last_name = lName;
        record[num].balance = bal;

        std::cout << "Record successfully updated!";
    }

    void delete_record()
    {
        int num;
        std::cout << "Enter record number: ";
        std::cin >> num;
        record.erase(record.begin() + num - 1);
    }

};

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
            CL.show_records_from_file();
            break;
        case 3:
            CL.search_record();
        case 4:
            CL.update_record();
        case 5:
            CL.delete_record();
        case 6:
            exit(1);              // here you are going to store everything to the file finally.
        };
    };

    return 0;
};
