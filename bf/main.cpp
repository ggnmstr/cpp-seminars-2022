#include <iostream>

void interpret(const std::string &cmds, uint8_t *ptr){
    for (const char cmd : cmds){
        switch (cmd)
        {
        case '>':
            ptr++;
            break;
        case '<':
            ptr--;
            break;
        case '+':
            (*ptr)++;
            break;
        case '-':
            (*ptr)--;
        case '.':
            std::cout << unsigned(*ptr) << std::endl;
        case ',':
            int number;
            std::cin >> number;
            *ptr = number;
            break;
        default:
            std::cerr << "unknown command: '" << cmd << "'" << std::endl;
            break;
        }
    }
}

int main (int argc, char ** argv){
    std::string cmds;
    uint8_t data[30000] = {};
    uint8_t *ptr = data;
    while (true) {
        std::cin >> cmds;
        interpret(cmds, data);
    } 
    return 0;
}