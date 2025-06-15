#include <Metric.hpp>
#include <iostream>
#include <memory>

int main() {

	auto cpu = std::make_shared<Metric<float>>("CPU");
	cpu->set(0.92);
	std::cout <<"Hello, world\n";
	return 0;
}