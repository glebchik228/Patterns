#include <iostream>

class Monkey{
    Monkey(){
        std::cout << "monkey was born" << std::endl;
    }
    static Monkey* monkey;

    std::string data = "why did u say monkey!?\n";

public:
    Monkey(const Monkey&) = delete;
    void operator=(const Monkey&) = delete;

    static Monkey* getMonkey(){
        if (monkey == nullptr)
            monkey = new Monkey();
        return monkey;
    };

    std::string getData(){
        return data;
    }

    void setData(std::string newData){
        data = newData;
    }
};
Monkey* Monkey::monkey = nullptr;

int main(){
    std::cout << Monkey::getMonkey()->getData();
    Monkey::getMonkey()->setData("lol\n");
    std::cout << Monkey::getMonkey()->getData();
    return 0;
}