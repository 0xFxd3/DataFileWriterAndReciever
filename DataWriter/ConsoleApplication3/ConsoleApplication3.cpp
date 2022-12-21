
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string> 

using namespace std;
string input;

void dataremover()
{

	std::ofstream ofs;
	ofs.open("C:\\Zero\\DATARECIEVER\\DATA1.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();


}

void recieve_script(string script)
{

	if (script.find("print_myplayername"))
	{
		printf("PrintedPlayerName:Systex1337\n");
	}
    if (script.find("notifymap(pname)"))
	{
		printf("notifymapfound\n");
	}


}

int main()
{
	G:
	std::cout << "This is the datawriter, what would you like to write?" << std::endl;
	std::cin >> input;

	recieve_script(input);

		//std::fstream myReadFile;
		//myReadFile.open("C:\\Zero\\DATARECIEVER\\DATA1.txt");
		//char output[100];
		//if (myReadFile.is_open()) //checking whether the file is open {	
		//	myReadFile << input;//inserting text
		//myReadFile.close(); //close the file objec		
		//dataremover();
	goto G;
}
