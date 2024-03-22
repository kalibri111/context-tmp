//
// Created by Иван Лескин on 18/03/2024.
//
#pragma once
namespace context {
    struct IPortal {
        virtual ~IPortal() = default;

        virtual void Run() = 0;  // never returns
    };

    /**
     * Class represents execution runtime for x86-64:
     * - stack pointer
     * - callee saved registers
     */
    class MachineContext : private IPortal {
    public:
        MachineContext(){};
        // non copyable
        MachineContext(const MachineContext &) = delete;

        MachineContext &operator=(const MachineContext &) = delete;

        // non movable
        MachineContext(MachineContext &&) = delete;

        MachineContext &operator=(MachineContext &&) = delete;

        void Setup(void *stack, IPortal *runnable);

        void SwitchTo(MachineContext &target);
    private:
        void Run() noexcept override;
        void* rsp_;
    };


}