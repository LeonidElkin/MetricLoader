#include "Metric.hpp"
#include "MetricLogger.hpp"
#include "MetricRegistry.hpp"
#include <memory>

constexpr int logs_count_example = 10;

int main() {
	MetricsRegistry registry;
	auto cpu = std::make_shared<Metric<float>>("CPU load");
	auto http = std::make_shared<Metric<int>>("HTTP requests, RPS");
	auto gpu = std::make_shared<Metric<int>>("GPU load, %");
	auto ram = std::make_shared<Metric<int>>("RAM usage, GB");

	registry.registerMetric(cpu);
	registry.registerMetric(http);
	registry.registerMetric(gpu);
	registry.registerMetric(ram);

	MetricsLogger const logger(registry, "metrics.log");

	for (int i = 1; i <= logs_count_example; ++i) {
		cpu->set(i * 0.52);
		http->set(i * 11);
		if (i % 2) gpu->set(i * 10);
		if (!(i % 3)) ram->set(i * 1000);
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}

	return 0;
}
