#include "student.h"
#include <iomanip>

int main() {
    
    Student std[5];
    std[0] = Student("George", 82);
    std[1] = Student("John", 73);
    std[2] = Student("Luci", 91);
    std[3] = Student("Mary", 72);
    std[4] = Student("Sue", 65);
    for (int i = 0; i < 5; i++) {
        std[i].print();
    }
    return 0;
}