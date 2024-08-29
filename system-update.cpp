#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

std::string get_date() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", timeinfo);
    std::string str(buffer);
    return buffer;
}

std::vector<std::string> get_array_of_lines() {
    std::string line;
    static std::vector<std::string> arr;

    std::ifstream file;
    file.open("database.txt");

    while (getline(file, line))
        arr.push_back(line);

    file.close();
    return arr;
}

int main() {
    const int interval = 6;

    std::ofstream file;
    file.open("database.txt", std::ios::app);

    std::string date = get_date();

    std::string sday = {date[0], date[1]};
    std::string smonth = {date[3], date[4]};
    std::string shour = {date[11], date[12]};
    std::string smin = {date[14], date[15]};

    int day = std::stoi(sday);
    int month = std::stoi(smonth);
    int hour = std::stoi(shour);
    int min = std::stoi(smin);

    if (day == 29) {
        file << date << '\n';

        std::vector<std::string> arr = get_array_of_lines();
        for (auto x:arr)
            std::cout << x << '\n';
    }

    file.close();
    return 0;
}
