#include "memory.h"
#include <thread>
#include <iostream>

int main() {
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		const uintptr_t localPlayer = VARS::memRead<uintptr_t>(VARS::baseAddress + 0x16C2D98);

		if (!localPlayer) { 
			continue;
		}

		int32_t health = VARS::memRead<int>(localPlayer + 0x32C);

		std::cout << "Local Player Health: \033[1;32m" <<  "" << health << "\033[0m" << std::endl;
	}

	return 0;
}