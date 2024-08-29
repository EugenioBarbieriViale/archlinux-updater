#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <cstdlib>

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
    file.open("database.log");

    while (getline(file, line))
        arr.push_back(line);

    file.close();
    return arr;
}

void update_ascii() {
    std::cout << "                     ,--.          ,--.            " << '\n';
    std::cout << "   ,--.,--. ,---.  ,-|  | ,--,--.,-'  '-. ,---.    " << '\n';
    std::cout << "   |  ||  || .-. |' .-. |' ,-.  |'-.  .-'| .-. :   " << '\n';
    std::cout << "   '  ''  '| '-' '\\ `-' |\\ '-'  |  |  |  \\   --.   " << '\n';
    std::cout << "    `----' |  |-'  `---'  `--`--'  `--'   `----'   " << '\n';
    std::cout << "           `--'                                    " << '\n';
}

int main() {
    const int interval = 6;

    std::ofstream file;
    file.open("database.log", std::ios::app);

    std::string date = get_date();

    std::string sday = {date[0], date[1]};
    int day = std::stoi(sday);

    std::vector<std::string> arr = get_array_of_lines();
    std::string last_date = arr[arr.size()-1];

    std::string slast_day = {last_date[0], last_date[1]};
    int last_day = std::stoi(slast_day);

    if (day != last_day) {
        file << date << '\n';
        update_ascii();
        std::system("sudo pacman -Syu && yay");
        std::cout << "--- System upgraded successfully ---" << '\n';
    }

    file.close();
    return 0;
}
