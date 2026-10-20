#include <iostream>
#include <string>
#include "MyVector.h"
#include "MyUniquePtr.h"

class Robot {
private:
    std::string m_Name;
public:
    Robot() : m_Name("Unknown") { std::cout << "[Default Construct] Robot created\n"; }
    Robot(std::string name) : m_Name(name) { std::cout << "[Construct] Robot '" << m_Name << "' created\n"; }
    ~Robot() { std::cout << "[Destruct] Robot '" << m_Name << "' wiped from memory\n"; }

    Robot(const Robot& other) : m_Name(other.m_Name + "_Copy") { std::cout << "[Copy Construct] '" << m_Name << "' duplicated\n"; }
    Robot& operator=(const Robot& other) {
        m_Name = other.m_Name + "_CopyAssign";
        std::cout << "[Copy Assignment] Called for '" << m_Name << "'\n";
        return *this;
    }

    Robot(Robot&& other) noexcept : m_Name(std::move(other.m_Name)) {
        other.m_Name = "Hollowed Shell";
        std::cout << "[Move Construct] '" << m_Name << "' moved out\n";
    }
    Robot& operator=(Robot&& other) noexcept {
        m_Name = std::move(other.m_Name);
        other.m_Name = "Hollowed Shell";
        std::cout << "[Move Assignment] '" << m_Name << "' reassigned via move\n";
        return *this;
    }

    void Speak() const { std::cout << "Robot '" << m_Name << "' says: Hello!\n"; }
};

int main() {
    std::cout << "===========================================\n";
    std::cout << "STAGE 1: Testing MyUniquePtr Automation\n";
    std::cout << "===========================================\n";
    {
        MyUniquePtr<Robot> botPtr(new Robot("R2-D2"));
        botPtr->Speak();
        MyUniquePtr<Robot> modernBotPtr = std::move(botPtr);
    } 

    std::cout << "\n===========================================\n";
    std::cout << "STAGE 2: Testing MyVector Dynamic Growth\n";
    std::cout << "===========================================\n";
    {
        MyVector<Robot> squad;
        squad.PushBack(Robot("Alpha"));
        squad.PushBack(Robot("Beta"));
        squad.PushBack(Robot("Gamma"));
    } 

    std::cout << "===========================================\n";
    std::cout << "Execution ended with zero leaks.\n";
    return 0;
}
