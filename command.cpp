#include <iostream>
#include <vector>
#include <stack>

class ICommand{
public:
    virtual void positive() = 0;
    virtual void negative() = 0;
};

class Monkey{
public:
    void sleep(){
        std::cout << "monkey are sleeping" << std::endl;
    }
    void wakeup(){
        std::cout << "the sun has risen monkeys are plowing!" << std::endl;
    }
    void hitTheMonkey(){
        std::cout << "monkey is trying harder" << std::endl;
    }
    void petTheMonkey(){
        std::cout << "monkey relaxed (work worse)" << std::endl;
    }
};

class MonkeyOwner : public ICommand {
private:
    Monkey* monkey;
public:
    MonkeyOwner(Monkey* _monkey) : monkey(_monkey) {}
    void positive() override{
        monkey->wakeup();
    }
    void negative() override{
        monkey->sleep();
    }
};

class MonkeyWarden : public ICommand{
private:
    Monkey* monkey;
public:
    MonkeyWarden(Monkey* _monkey) : monkey(_monkey) {}
    void positive() override{
        monkey->hitTheMonkey();
    }
    void negative() override{
        monkey->petTheMonkey();
    }
};

class MonkeyLeader{
private:
    std::vector<ICommand*> commands;
    std::stack<ICommand*> history;
public:
    MonkeyLeader(){
        commands.resize(2);
    }
    void setCommand(int button, ICommand* command){
        commands[button] = command;
    };

    void pressedOn(int button){
        commands[button]->positive();
        history.push(commands[button]);
    };
    void pressCancel(){
        if (history.empty()) return;
        history.top()->negative();
        history.pop();
    }
};
int main(){
    Monkey* monkey = new Monkey();
    MonkeyLeader* leader = new MonkeyLeader();

    leader->setCommand(0, new MonkeyOwner(monkey));
    leader->setCommand(1, new MonkeyWarden(monkey));

    leader->pressedOn(0);
    leader->pressedOn(1);
    leader->pressedOn(1);
    leader->pressCancel();
    leader->pressCancel();
    leader->pressCancel();
    return 0;
}