#pragma once

#include "Metric.hpp"
#include <vector>
#include <memory>

class MetricsRegistry {
	std::mutex mutex_;
	std::vector<std::shared_ptr<IMetric>> metrics_;
public:
	void registerMetric(std::shared_ptr<IMetric> metric) {
		std::lock_guard<std::mutex> lock(mutex_);
		metrics_.push_back(std::move(metric));
	}

	std::vector<std::shared_ptr<IMetric>> getMetrics() {
		std::lock_guard<std::mutex> lock(mutex_);
		return metrics_;
	}
};

