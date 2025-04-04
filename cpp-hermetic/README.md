# C++ Hermetic Toolchain Example

This example demonstrates using Bazel with a hermetic C++ toolchain to achieve cross-platform builds from a single environment.

## Overview

The project shows how to configure Bazel with the `hermetic_cc_toolchain` to compile C++ code for multiple platforms:
- Linux (amd64, arm64)
- macOS (arm64)
- Windows (amd64)

A hermetic toolchain is completely self-contained, allowing reliable builds across different environments without depending on the host system's toolchain.

## Key Features

- Uses Zig as the underlying cross-compiler
- Configures platform-specific toolchains in `MODULE.bazel`
- Demonstrates platform detection in a simple C++ program

## Prerequisites

- Bazel (bazelisk will automatically download the correct version)

## Building

Build for the host platform:
```bash
bazel build //src:main
```

Build for a specific platform (e.g., Linux ARM64):
```bash
bazel build --platforms @zig_sdk//platform:linux_arm64 //src:main
```

## Running

Run the binary directly:
```bash
bazel run //src:main
```

### Testing Linux Binary on Other Platforms

If you have Docker installed, you can validate the Linux ARM64 binary using:
```bash
docker run --rm -v $(pwd)/bazel-bin/src/main:/app/main --platform linux/arm64 -it alpine:latest /app/main
```

## Project Structure

- `src/main.cpp` - Simple C++ program that demonstrates platform detection
- `MODULE.bazel` - Configures the Bazel dependencies and toolchains
- `.cpp.bazelrc` - C++ specific Bazel configurations
- `.bazelrc` - General Bazel configuration including platform-specific settings
