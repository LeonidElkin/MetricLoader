#pragma once

#include <atomic>
#include <chrono>
#include <iostream>
#include <utility>

class IMetric {
public:
	[[nodiscard]] virtual std::string name() const = 0;
	[[nodiscard]] virtual std::string valueAsString() const = 0;
	[[nodiscard]] virtual bool isUpdated() const = 0;
	virtual void reset() = 0;
	virtual ~IMetric() = default;
};

template<typename T>
class Metric : public IMetric {
	std::string name_;
	std::atomic<T> value_;
	std::atomic<bool> updated_;

public:
	explicit Metric(std::string name) : name_(std::move(name)), value_(0), updated_(false) {}
	void set(T val) {
		value_.store(val);
		updated_.store(true);
	}
	void reset() override {
		value_.store(0);
		updated_.store(false);
	}
	[[nodiscard]] std::string name() const override { return name_; }
	[[nodiscard]] std::string valueAsString() const override {
		if constexpr (std::is_floating_point_v<T>) {
			std::ostringstream oss;
			oss << std::fixed << std::setprecision(2) << value_;
			return oss.str();
		} else {
			return std::to_string(value_);
		}
	}
	[[nodiscard]] bool isUpdated() const override { return updated_.load(); }
};