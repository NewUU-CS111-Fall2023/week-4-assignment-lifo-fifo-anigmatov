/*
 * Author: Abdusamad
 * Date: 08.11.2023
 * Name: Main.cpp
 */

#include <iostream>
#include <vector>
#include <stack>
#include <utility>

#include "task_1.h"
#include "task_2.h"
#include "task_3.h"
#include "task_4.h"
#include "task_5.h"

int main() {
    std::cout << "Task 1" << std::endl;
    
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    Stack anotherStack;
    anotherStack.push(50);
    
    std::cout << "Task 2" << std::endl;
    
    bool isValidExpression(const std::string& brackets);
    void processTrainOrder();
    
    std::cout << "Task 3" << std::endl;
    
    std::string expression = "5 2 +"; // Example postfix expression
    int result = evaluatePostfixExpression(expression);
    std::cout << "Result: " << result << std::endl;
    
    std::cout << "Task 4" << std::endl;

    void solveContainerStacks(int N, std::vector<std::stack<int>>& stacks, std::vector<int>& targetStack, std::vector<std::pair<int, int>>& actions);
    
    std::cout << "Task 5" << std::endl;
    
    int n;
    std::cout << "Enter the number of disks: ";
    std::cin >> n;

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
