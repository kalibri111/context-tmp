//
// Created by Иван Лескин on 18/03/2024.
//
#pragma once

/**
 * Make current execution as an MachineContext object
 * @return current stack pointer
 */

void* SetupMachineContext(void* stack, void* trampoline, void* arg);

void SwitchMachineContext(void** from_rsp, void** to_rsp);
