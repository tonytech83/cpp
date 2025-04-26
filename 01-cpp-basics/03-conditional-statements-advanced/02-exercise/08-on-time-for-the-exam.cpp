#include <iostream>

int main() {
    int exam_hour, exam_minute, arrival_hour, arrival_minute;
    std::cin >> exam_hour >> exam_minute >> arrival_hour >> arrival_minute;

    const int exam_in_minutes = exam_hour * 60 + exam_minute;
    const int arrival_in_minutes = arrival_hour * 60 + arrival_minute;

    if (exam_in_minutes == arrival_in_minutes) {
        std::cout << "On time" << '\n';
    } else {
        if (exam_in_minutes > arrival_in_minutes) {
            if (exam_in_minutes - arrival_in_minutes <= 30) {
                std::cout << "On time" << std::endl;
            } else {
                std::cout << "Early" << std::endl;
            }
        } else {
            std::cout << "Late" << std::endl;
        }

        int diff = exam_in_minutes - arrival_in_minutes;

        if (diff > 0) {
            if (diff > 59) {
                const int hours = diff / 60;
                const int minutes = diff % 60;
                if (minutes < 10) {
                    std::cout << hours << ":0" << minutes << " hours before the start" << '\n';
                } else {
                    std::cout << hours << ':' << minutes << " hours before the start" << '\n';
                }

            } else {
                std::cout << diff << " minutes before the start" << std::endl;
            }
        } else {
            diff *= -1;
            if (diff > 59) {
                const int hours = diff / 60;
                const int minutes = diff % 60;
                if (minutes < 10) {
                    std::cout << hours << ":0" << minutes << " hours after the start" << '\n';
                }
                std::cout << hours << ':' << minutes << " hours after the start" << '\n';
            } else {
                std::cout << diff << " minutes after the start" << std::endl;
            }
        }
    }


    return 0;
}
