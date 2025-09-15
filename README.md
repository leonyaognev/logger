# 📝 Logger Library

Минималистичная C++ библиотека для логирования с поддержкой уровней **TRACE**, **INFO**, **WARN**, **ERROR**.

## ⚡ Возможности
- Цветные уровни логов (TRACE — серый, INFO — зелёный, WARN — жёлтый, ERROR — красный)
- Вывод в консоль и в файл (по умолчанию `app.log`)
- Макросы `LOG_TRACE`, `LOG_INFO`, `LOG_WARN`, `LOG_ERROR`, которые можно отключить флагом `-DNDEBUG`
- Потокобезопасность через `std::mutex` (многопоточность не ломает вывод)

## 🔧 Сборка
```bash
make
```

Соберёт статическую библиотеку **liblogger.a** в корне проекта, а все промежуточные файлы будут в `build/`.

Очистка:

```bash
make clean
```

Полная пересборка:

```bash
make rebuild
```

## 🖋 Пример использования

```cpp
#include "logger.h"

int main() {
    log_trace("Hello from trace");
    log_info("This is an info message");
    log_warn("Something might be wrong");
    log_error("Oops, something broke");
    return 0;
}
```

## 📦 Структура проекта

```
.
├── logger.cpp      # Реализация логгера
├── logger.h        # Заголовок с макросами
├── levelTo.h       # Таблица цветов/имен уровней
├── Makefile        # Сборка
└── build/          # Временные файлы сборки (.o)
```
