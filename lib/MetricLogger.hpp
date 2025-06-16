#pragma once

#include "MetricRegistry.hpp"
#include <format>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>

class MetricsLogger {
	MetricsRegistry &registry_;
	std::ofstream file_;
	std::thread worker_;
	std::atomic<bool> running_;

	static std::string formatTime(std::chrono::system_clock::time_point timePoint) {
		std::time_t const t = std::chrono::system_clock::to_time_t(timePoint);
		std::tm const tm = *std::localtime(&t);

		std::ostringstream oss;
		oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");

		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(timePoint.time_since_epoch()) % 1000;
		oss << "." << std::setfill('0') << std::setw(3) << ms.count();

		return oss.str();
	}


public:
	MetricsLogger(MetricsRegistry &registry, const std::string &filename)
		: registry_(registry), file_(filename), running_(true) {
		worker_ = std::thread(&MetricsLogger::loop, this);
	}

	void loop() {
		while (running_) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			auto metrics = registry_.getMetrics();
			auto updated = false;

			for (auto &metric: metrics) {
				if (metric->isUpdated()) {
					updated = true;
					break;
				}
			}

			if (!updated) continue;

			file_ << formatTime(std::chrono::system_clock::now());
			for (auto &metric: metrics) {
				file_ << " \"" << metric->name() << "\" " << metric->valueAsString();
				metric->reset();
			}
			file_ << '\n';
			file_.flush();
		}
	}

	~MetricsLogger() {
		running_ = false;
		if (worker_.joinable()) worker_.join();
	}
};
