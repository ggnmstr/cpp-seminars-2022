#include <iostream>

class Command{
    public:
        virtual void apply(uint8_t *ptr) = 0;
};

class Right: public Command{
    public:
        void apply(uint8_t *ptr) override{
            ptr++;
        }
};

class Left: public Command{
    public:
        void apply(uint8_t *ptr) override{
            ptr--;
        }
};

class Plus: public Command{
    public:
        void apply(uint8_t *ptr) override{
            (*ptr)++;
        }
};

class Minus: public Command{
    public:
        void apply(uint8_t *ptr) override{
            (*ptr)--;
        }
};

class Dot: public Command{
    public:
        void apply(uint8_t *ptr) override{
            std::cout << unsigned(*ptr) << std::endl;
        }
};

class Comma: public Command{
    public:
        void apply(uint8_t *ptr) override{
            int number;
            std::cin >> number;
            *ptr = number;
        }
};

class OpenBracket: public Command{
    public:
        void apply(uint8_t *ptr) override{
            
        }
};

class CloseBracket: public Command{
    public:
        void apply(uint8_t *ptr) override{

        }
};

Command *get_cmd(const char c){
    switch (c)
        {
        case '>':
            return new Right();
        case '<':
            return new Left();
        case '+':
            return new Plus();
        case '-':
            return new Minus();
        case '.':
            return new Dot();
        case ',':
            return new Comma();
        case '[':
            return new OpenBracket();
        case ']':
            return new CloseBracket();
        }
    return nullptr;
}

void interpret(const std::string &cmds, uint8_t *ptr){
    for (const char c : cmds){
        Command *cmd = get_cmd(c);
        if (cmd == nullptr) {
            std::cerr << "unknown command: '" << c << "'" << std::endl;
            continue;
        }
        cmd->apply(ptr);
        delete cmd;
        
    }
}

int main (int argc, char ** argv){
    std::string cmds;
    uint8_t data[30000] = {};
    uint8_t *ptr = data;
    while (true) {
        std::cin >> cmds;
        interpret(cmds, ptr);
        std::cout << (unsigned)data[0] << " " << (unsigned)data[1] << " " << (unsigned)data[2] << std::endl ;
    }
    return 0;
}