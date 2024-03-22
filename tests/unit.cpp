//
// Created by Иван Лескин on 20/03/2024.
//
#include <gtest/gtest.h>
#include "switch.hpp"
#include <iostream>


struct Printer : public context::IPortal {
    explicit Printer(context::MachineContext& caller): caller(caller) {
        own.Setup(stack, this);
    }

    void Print() {
        caller.SwitchTo(own);
    }

    /**
     * Print in other context
     */
    [[noreturn]] void Run() override {
        std::cout << "Print in other context!" << std::endl;
        own.SwitchTo(caller);
        std::abort();  // unreachable
    }

    context::MachineContext& caller;
    context::MachineContext own;
    char stack[1024];
};

/**
 * Checks correct switch sequence
 */
TEST(SuteTest, Example) {
    context::MachineContext caller_ctx;
    Printer printer(caller_ctx);

    std::cout << "In caller" << std::endl;

    printer.Print();

    std::cout << "Back to caller" << std::endl;
}

/**
* Checks stacks acts independently
*/
void testContextIndependent() {

}

/**
* Checks switching back restores condition
*/
void testContextRestored() {

}

/**
* Checks stackless context fails
*/
void testContextStackless() {

}