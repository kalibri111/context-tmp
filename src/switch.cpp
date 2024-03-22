//
// Created by Иван Лескин on 18/03/2024.
//
#include "switch.hpp"

extern "C" {
#include "x86_64/context.h"
}

/**
 * Skip first 6 arguments to registers, 7th argument will be on stack.
 * 7th argument is Runnable object, this function just call its method
 * @param arg7 IPortal runnable object
 */
static void callRunnableRun(void *, void *, void *, void *, void *, void *, void *arg7) {
    auto *portal = (context::IPortal *) arg7;
    portal->Run();
}

void context::MachineContext::Setup(void *stack, context::IPortal *runnable) {
    rsp_ = SetupMachineContext(stack, (void*)callRunnableRun, (void*)runnable);
}

void context::MachineContext::SwitchTo(context::MachineContext &target) {
    SwitchMachineContext(&rsp_, &target.rsp_);
}

void context::MachineContext::Run() noexcept {

}
