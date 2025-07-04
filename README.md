# MetricLoader

## Для запуска проекта необходимо

- `cmake` >= 3.20
- `g++` | `clang` | `MSVC` версий с поддержкой C++20

## Сборка и запуск

Сборка проекта происходит с помощью CMake. Библиотека является header-only. Чтобы включить в сборку пример добавьте
опцию `DBUILD_EXAMPLE=ON`(По умолчанию включено). Примерная сборка проекта:

```bash
cmake -S . -B build DBUILD_EXAMPLE=ON
cmake --build build
./build/example
```

## Пример

Ниже будет приведен результат работы [примера](example/example_output.log). Если метрика не изменялась между `timestamp`, её значение будет обнулено согласно пункту в задаче.


```textmate
2025-06-16 03:40:31.883 "CPU load" 0.52 "HTTP requests, RPS" 11 "GPU load, %" 10 "RAM usage, GB" 0
2025-06-16 03:40:32.891 "CPU load" 1.04 "HTTP requests, RPS" 22 "GPU load, %" 0 "RAM usage, GB" 0
2025-06-16 03:40:34.916 "CPU load" 1.56 "HTTP requests, RPS" 33 "GPU load, %" 30 "RAM usage, GB" 3000
2025-06-16 03:40:36.938 "CPU load" 2.08 "HTTP requests, RPS" 44 "GPU load, %" 0 "RAM usage, GB" 0
2025-06-16 03:40:38.955 "CPU load" 2.60 "HTTP requests, RPS" 55 "GPU load, %" 50 "RAM usage, GB" 0
2025-06-16 03:40:40.973 "CPU load" 3.12 "HTTP requests, RPS" 66 "GPU load, %" 0 "RAM usage, GB" 6000
2025-06-16 03:40:42.994 "CPU load" 3.64 "HTTP requests, RPS" 77 "GPU load, %" 70 "RAM usage, GB" 0
2025-06-16 03:40:45.019 "CPU load" 4.16 "HTTP requests, RPS" 88 "GPU load, %" 0 "RAM usage, GB" 0
2025-06-16 03:40:47.040 "CPU load" 4.68 "HTTP requests, RPS" 99 "GPU load, %" 90 "RAM usage, GB" 9000
2025-06-16 03:40:49.060 "CPU load" 5.20 "HTTP requests, RPS" 110 "GPU load, %" 0 "RAM usage, GB" 0

```
