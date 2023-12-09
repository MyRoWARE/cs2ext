#include "memory.h"
#include <thread>
#include <iostream>

int main() {
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		const uintptr_t localPlayer = VARS::memRead<uintptr_t>(VARS::baseAddress + 0x16C2D98);

		int health = VARS::memRead<int>(localPlayer + 0x32C);

		std::cout << health << std::endl;
	}

	return 0;
}