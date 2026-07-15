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
| <sos/algorithm/embed_optimized.hpp> | `void sos_embed_optimizes(carrier, payload, optional[key])` |
| <sos/algorithm/extract_optimized.hpp> | `payload sos_extract_optimized(carrier, optional[key])` |
| <sos/tools/convert.hpp> | `std::vector<ByteT> to_bytes<ByteT>(const Range& range)`, `Range bytes_to<Range>(const std::vector<ByteT>& bytes)` |


## Description

This algorithm is used to hide any list of bytes into any other list of bytes 

> [!WARNING]
> The algorithm is securised and shouldn't be able to be reversed from the carrier only (min `2^19937` possiblity **with a key**), but dosen't ensure it in **ANY WAYS**

> [!NOTE]
> Multiple thing can be enable/disable or modified at compilation using template or runtime (noise, key, byte size, ...), see into the `sos/sos.hpp` for more details

> [!IMPORTANT]
> Every constant such as limit computing, rms, percentage, default type... can be edited in `sos/sosDefine.hpp` & `sos/sosType.hpp`

### Core Principles

- **'valid' storage byte**
```
A byte is considered valid if it's value is between the min & max treshold.
The min & max threshold are computed using ByteT as the type of the bytes (uint8, uint16, uint32, uint64)
min: ((1ull << (sizeof(ByteT) * 8 / 2)) - 1ull)
max: (std::numeric_limits<ByteT>::max() - min)
```

- **noise**
```
The algorithm contain a noise generation function that can be used with 2 mode, local & global.
local: only generate noise on valid storage byte
global: generate noise on every carrier's bytes
The noise generation use the rms of the carrier + a coef to generate noise that dosen't disturb much or become the information.
```

- **seed**
```
The seed (uint_fast32) is generated using a custom hash (see in sos/tools/hash.hpp) on the last 256 valid storage byte found.
```

- **key**
```
The key can be of any given size is used along side the seed to shuffle the list of valid storage byte.
```

### Requirements

- **noise generation**
```
The noise generation has only one check, the rms of the carrier.
If it's too small and the noise will litteraly become the information, a throw will occur.
The rms minimal limit is computed using the sound wave as principle,
we take the minimal rms of a signal that should be normal~, 100 ~ 5000 (scaled on a base of uint16)
rms limit: 250.0 * (static_cast<double>(std::numeric_limits<ByteT>::max()) / static_cast<double>(UINT16_MAX))
```

- **threshold removing**
```
The byte on the threshold are removed to ensure after byte modification that during the extraction there will be no loss or more data.
Before doing that the percentage of the range used should be between a min & max, so the partially missing 2 range won't be detected so easly.
min: std::min(2048.0, std::numeric_limits<ByteT>::max() * 0.05)
max: (std::numeric_limits<ByteT>::max() * (1.0 - 0.05))
There should be 5% < range_used < 95% (0.05 represent the percentage) for the removing to be accepted and not throw an error.
```

- **carrier**
```
The check on the carrier ensure that the payload won't destroy the carrier or create too much information.
1 - Percentage of the payload into the storage
  Limit the payload to be 7.5% of the total valid storage byte.
2 - Number of valid byte
  Check if the number of valid storage byte - seed is sufficient to store the header + payload.
```

## Complexity

### Parameters

- **n** = `len(carrier)`
- **m** = `len(payload)`
- **k** = `len(key)`

### Time Complexity

| Case  | Complexity |
| ----- | ---------- |
| Best  | `O(n + m + k)` |
| Avg   | `O(n + m + k)` |
| Worst | `O(n + m + k)` |

### Memory Complexity

| Case  | Complexity |
| ----- | ---------- |
| Best  | `O(n)` |
| Avg   | `O(n)` |
| Worst | `O(n)` |


## Licence
![CC-BY-NC-4.0](https://img.shields.io/badge/build-CC--BY--NC--4.0-brightgreen?style=for-the-badge&logo=github&label=Licence&link=https%3A%2F%2Fgithub.com%2FTsukiNi22%2Fc2dmp-hsm%2Fblob%2Fmain%2FLICENSE.md)
