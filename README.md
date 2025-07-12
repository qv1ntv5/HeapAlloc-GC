### Introduction.

In this repository we are going to implement a custom heap allocator based on a heap array and a garbage collector.

The files includes:

- **heap.h**: A file in which a public interface of the code can be found (declaration but not implementation).
- **heap.c**: A file with the main implementation of the allocator, the operations and the garbage collector.
- **main.c**: A PoC showing the logic of the heap allocator and how the garbage collection works. 

This repository works with a complementary paper explaining this stuff in: https://qv1ntv5.github.io/2025-07-11-GarbageCollector/