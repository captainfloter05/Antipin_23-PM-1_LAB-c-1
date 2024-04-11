#pragma once

#include "Furniture.h"

namespace funcs {
	void save(Furniture* arr, const int& n);
	Furniture* load(int& n);
}