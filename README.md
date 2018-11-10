# sshared

A C++ implementation of Secret Sharing.

Supported Implementations:
- Shamir

# Development Requirements

To development you must use a Linux (Debian/Ubuntu if possible). The internal requirements to develop can be installed with the `ntl-install.sh` script inside the `scripts/` directory.

# Test

The following commands should create and run the test program:

```bash
$ make test
$ ./stest
```

# Compile

If you want to compile and use, the lib can be compile and used in 3 forms:

* Standalone
```bash
make
```
* Dynamic
```bash
make dynamic
```
* Static
```bash
make static
```

This will generate the files inside the `bin/` directory and you can use them as you wish.

# Usage

If you don't know how to use the lib you can try to compile the `Standalone` targed and execute
```bash
./bin/sshared -h
```

Or see the test files for how you can use and create your application using this lib!