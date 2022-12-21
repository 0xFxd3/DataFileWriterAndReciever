// DataReciever.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <istream>
#include <iostream>


using namespace std;

#include <iostream>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <cerrno>
#include <cstring>


void dataremover()
{

    std::ofstream ofs;
    ofs.open("C:\\Zero\\DATARECIEVER\\DATA1.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();


}


void datareader()
{
    ifstream myReadFile;
    myReadFile.open("C:\\Zero\\DATARECIEVER\\DATA1.txt");
    char output[100];

            myReadFile >> output;
            cout << "Recieved Data : " << output << std::endl;
            


    myReadFile.close();

}

int checkdatachange()
{
    struct stat fileInfo;


    if (stat("C:\\Zero\\DATARECIEVER\\DATA1.txt", &fileInfo) != 0) {  // Use stat() to get the info
        std::cerr << "Error: " << strerror(errno) << '\n';
        return(EXIT_FAILURE);
    }

    //    std::cout << "Type:         : ";
    if ((fileInfo.st_mode & S_IFMT) == S_IFDIR) { // From sys/types.h
    //    std::cout << "Directory\n";
    }
    else {
        //      std::cout << "File\n";
    }

    //    std::cout << "Size          : " <<
    fileInfo.st_size << '\n';               // Size in bytes
    if (fileInfo.st_size > 0)
    {
        datareader();
        dataremover();
    }
    
    //std::cout << "Device        : " <<
    //    (char)(fileInfo.st_dev + 'A') << '\n';  // Device number
    //std::cout << "Created       : " <<
    //    std::ctime(&fileInfo.st_ctime);         // Creation time
    //std::cout << "Modified      : " <<
    //    std::ctime(&fileInfo.st_mtime);         // Last mod time
}



void main()
{
    while (true)
    {
        checkdatachange();
    }
}
