# Exploring tag-matching metrics in SignalGP

This repository is a companion to our 2020 ALife conference submission that characterizes the properties
of five tag-matching metrics: Hamming, Hash, Integer, Bidirectional Integer, and Streak.
Specifically, this repository houses the source code, documentation, and analyses (for final and preliminary experiments) for the genetic programming experiments presented in the paper.

We characterized the performance SignalGP on two diagnostic tasks (the changing-signal task and the directional-signal task) using each of the five tag-matching metrics.

- **[Diagnostic task descriptions](./docs/tasks-descriptions.md)** - See this document for descriptions of the changing- and directional-signal tasks as well as the parameterizations used by our experiments for each.
- **Experiment source code** can be found in the [./source/](./source/) directory. Our diagnostic experiments are implemented in C++ using the [Empirical Library](https://github.com/devosoft/Empirical) and a new implementation of [SignalGP](https://github.com/amlalejini/SignalGP).
  - SignalGP version: <https://github.com/amlalejini/SignalGP/releases/tag/1.0>
  - Empirical Library version: <https://github.com/amlalejini/Empirical/releases/tag/v1.0-ALife2020>
- **Data analyses** can be found in the [./experiments/analysis/](./experiments/analysis/) directory. See directory readme for more details.
- **HPCC submission scripts** can be found in the [./experiments/hpcc/](./experiments/hpcc/) directory. See directory readme for more details.
- **Data** - Data for preliminary and final experiments are in [./experiments/data/](./experiments/data/)
- **[Replication Guide](./docs/run-locally.md)** - Step-by-step guide to compiling and running our experiments
  locally.

## Repository contact

amlalejini@gmail.com