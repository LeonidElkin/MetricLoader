#include "Metric.hpp"
#include "MetricLogger.hpp"
#include "MetricRegistry.hpp"
#include <memory>

constexpr int logs_count_example = 10;

int main() {
	MetricsRegistry registry;
	auto cpu = std::make_shared<Metric<float>>("CPU");
	auto http = std::make_shared<Metric<int>>("HTTP requests RPS");

	registry.registerMetric(cpu);
	registry.registerMetric(http);

	MetricsLogger const logger(registry, "metrics.log");

	for (int i = 1; i <= logs_count_example; ++i) {
		cpu->set(i * 0.52);
		http->set(i * 11);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}
