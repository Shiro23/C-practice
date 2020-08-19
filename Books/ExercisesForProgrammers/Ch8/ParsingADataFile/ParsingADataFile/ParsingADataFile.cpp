#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <tuple>
#include <algorithm>

using namespace std;

void getDataFromFile(vector<tuple<string, string, string>> &employee);
void outputDataAsTable(const vector<tuple<string, string, string>> &employee);
void sortBySalary(vector<tuple<string, string, string>> &employee);
bool salaryField(const tuple<string, string, string>& a, const tuple<string, string, string>& b);

int main()
{
	vector<tuple<string, string, string>> employee;

	getDataFromFile(employee);
	sortBySalary(employee);
	outputDataAsTable(employee);
}

void outputDataAsTable(const vector<tuple<string, string, string>>& employee)
{
	cout << setw(16) << right << "Last " << setw(15) << "First " << setw(15) << "Salary " << endl;

	for (int i = 0; i < employee.size(); i++) {
		auto t = employee[i];
		cout << setw(15) << right << get<0>(t) << setw(15) << get<1>(t) << setw(10) << "$" << get<2>(t) << endl;
	}
}

bool salaryField(const tuple<string, string, string>& a,const tuple<string, string, string>& b)
{
	return (get<2>(a) < get<2>(b));
}

void sortBySalary(vector<tuple<string, string, string>>& employee) {
	sort(employee.begin(), employee.end(), salaryField);
}

void getDataFromFile(vector<tuple<string, string, string>>& employee){
	string input;
	ifstream file;

	file.open("data.txt");

	if (!file.is_open()) {
		cout << "Could not open file!";
		exit(1);
	}

	while (getline(file, input)) {
		std::stringstream ss(input);
		std::string token;
		vector<string> tokenizedData;
		tuple<string, string, string> tuple;

		while (getline(ss, token, ',')) {
			tokenizedData.push_back(token);
		}

		std::get<0>(tuple) = tokenizedData[0];
		std::get<1>(tuple) = tokenizedData[1];
		std::get<2>(tuple) = tokenizedData[2];

		employee.push_back(tuple);
	}	
}
