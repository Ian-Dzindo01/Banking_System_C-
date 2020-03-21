#include <iostream>
#include <fstream>
#include <vector>

struct recordInfo
{
    int acc_num;
    std::string first_name;
    std::string last_name;
    float balance;
};

class Record
{
public:
    Record()
    {
        std::ofstream myfile("record.txt", std::ios::app);    // this signifies that it is in append mode
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
        std::cout << "Last name";
        std::cin >> lastname;
        std::cout << "Balance";
        std::cin >> balance;

        recordInfo temp = {num, name, lastname, balance};
    };
//    void delete_record();
//    void search_record();
//    void update_record();
//    void delete_record();

};

int main()
{
    int choice;
    Record CL;

    std::vector<recordInfo> arr;

    std::cout << "***Account Information System*** \n";
    std::cout << "\t1-->Add record to file \n";
    std::cout << "\t2-->Show record from file \n";
    std::cout << "\t3-->Search record to file \n";
    std::cout << "\t4-->Update record \n";
    std::cout << "\t5-->Delete record \n";
    std::cout << "\t6-->Quit \n";
    std::cout << "Enter your choice:";

    std::cin >> choice;

//    switch(choice):
//        {
//        case 1:
//            CL.add_record();
//            break;
//        case 2:
//            CL.show_record();
//            break;
//        case 3:
//            CL.search_record();
//        case 4:
//            CL.update_record();
//        case 5:
//            CL.delete_record();
//        case 6:
//            exit();
//        };

    return 0;
}
