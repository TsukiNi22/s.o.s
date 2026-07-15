# S.O.S

> **S**teganography **O**ptimized and **S**ecurized

## Installation

#### Cloning the repository
```bash
git clone https://github.com/TsukiNi22/s.o.s
cd s.o.s
```

#### Build & Installation
```bash
export BUILD_DIR=build
cmake -S . -B $BUILD_DIR -DCMAKE_BUILD_TYPE=Optimized
sudo cmake --build $BUILD_DIR --target install --parallel $(nproc)
```

#### Include
> [!WARNING]
> Everything is defined within the namespace `sos::`

See in the `.hpp` for more details
| Include | Content |
| ------- | ------- |
| -lsos         | `Nothing for now` |
| <sos/sos.hpp> | `void sos_embed(carrier, payload, key = none)`, `payload sos_extract(carrier, key = none)` |

## Licence
![CC-BY-NC-4.0](https://img.shields.io/badge/build-CC--BY--NC--4.0-brightgreen?style=for-the-badge&logo=github&label=Licence&link=https%3A%2F%2Fgithub.com%2FTsukiNi22%2Fc2dmp-hsm%2Fblob%2Fmain%2FLICENSE.md)
