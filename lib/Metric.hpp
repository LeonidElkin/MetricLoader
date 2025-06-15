#pragma once

#include <atomic>
#include <iostream>
#include <utility>

class IMetric {
public:
	[[nodiscard]] virtual std::string name() const = 0;

	[[nodiscard]] virtual std::string valueAsString() const = 0;

	virtual ~IMetric() = default;
};

template<typename T>
class Metric : public IMetric {
	std::string name_;
	std::atomic<T> value_;

public:
	explicit Metric(std::string name) : name_(std::move(name)), value_(0) {}

	void set(T val) { value_.store(val); }

	void reset() { value_.store(0); }

	[[nodiscard]] std::string name() const override { return name_; }

	[[nodiscard]] std::string valueAsString() const override { return std::to_string(value_.load()); }
};