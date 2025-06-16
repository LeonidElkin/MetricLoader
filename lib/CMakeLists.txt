add_library(MetricLoaderLib INTERFACE)
target_include_directories(MetricLoaderLib INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)