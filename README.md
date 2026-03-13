# Python Bindings Proof-of-Concept for ectool

## Overview

This repository contains a small proof-of-concept demonstrating how functionality from a low-level hardware control tool can be exposed to Python using a native C extension module.

The goal of this project is to demonstrate how commands normally executed through a command-line tool can instead be accessed directly from Python through a reusable library interface. This approach avoids the overhead of spawning subprocesses and provides a cleaner integration for applications that need frequent access to hardware control functions.

The current implementation simulates fan control behaviour in order to demonstrate the architecture and binding mechanism.

---

## Motivation

Many Linux hardware utilities are implemented as command-line tools. Python applications that interact with them often rely on repeatedly invoking the tool using `subprocess`.

This approach has several drawbacks:

- Each command launches a new process
- Output must be parsed from standard output
- Performance can degrade in continuous monitoring loops
- Error handling becomes more complex

A better approach is to expose the underlying functionality through a reusable library and allow Python to call it directly.

This repository demonstrates the basic structure required to build such bindings.

---

## Project Structure

```
ectool-python-extension-poc/

coolctl/
    __init__.py
    coolctlmodule.c

examples/
    demo.py

setup.py
README.md
run_demo.sh
```

### coolctl/

Contains the C extension module and the Python package interface.

### examples/

Example script demonstrating how the Python bindings can be used.

### setup.py

Build configuration used to compile the C extension module.

### run_demo.sh

Optional helper script to build and run the example.

---

## How It Works

The extension module exposes a simple interface to Python:

- `read_fan_level()` – returns the current fan level
- `update_fan_level(level)` – updates the fan level

These functions are implemented in C and compiled into a Python extension module. Python programs can import the module and call these functions directly.

---

## Building the Extension

Create a virtual environment:

```bash
python3 -m venv venv
source venv/bin/activate
```

Install the project locally:

```bash
pip install -e .
```

This compiles the C extension module and installs the package.

---

## Running the Example

Run the demo script:

```bash
python examples/demo.py
```

Example output:

```
Initial fan level: 35
Updated fan level: 75
Fan level: 75
Fan level: 75
Fan level: 75
```

The script demonstrates how Python code can call functions implemented in C.

---

## Future Improvements

This proof-of-concept focuses on demonstrating the binding mechanism. Future improvements could include:

- Connecting the library to real embedded controller functionality
- Expanding the C API for additional hardware operations
- Improving error handling and documentation
- Integrating the bindings with fan control tools such as `fw-fanctrl`

---

## Author

Saurav Jaiswal

---

## License

This project is intended for demonstration and educational purposes.
