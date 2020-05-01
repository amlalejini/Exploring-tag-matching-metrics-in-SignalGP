# Experiment directory

As part of this work, we performed several exploratory/preliminary experiments before the final set of
experiments presented in the paper --- all are included in this repository. Below, I give brief descriptions
of each experiment (labeled by date run/designed).

All statistical analyses and visualizations can be found in the [./analysis/](./analysis/) directory. All HPCC submission scripts can be found in the [./hpcc/](./hpcc/) directory (organized by experiment). The base configuration files for experiments (separated by diagnostic) are in [./configs-alt-sig/](./configs-alt-sig/), [./configs-chg-env/](./configs-chg-env/), and [./configs-dir-sig/](./configs-dir-sig/). Note that the settings in configuration files are overriden by
any command line settings set in the relevant HPCC submission scripts.

- Tag metric experiments (labeled by date run/designed)
  - **2020-03-12**
    - Initial exploratory experiment. Found no clear differences between metrics because we did not control for additional sources of tag variation (e.g., random insertions, random initial population).
  - **2020-03-20**
    - Exploratory experiment. We parameterized tag mutation rates using results from Matthew's graph matching
      experiment results. Here, we controlled for sources of tag variation by initializing the population with
      a common ancestor (with no tag variation) and we disallowed all sources of tag variation outside of
      tag mutations (single bit flips).
    - Controlling for tag variation, we found performance differences among the different tag matching metrics.
  - **2020-03-23**
    - Final experiment in two steps.
    - Step 1 - for each metric, we compared the problem-solving performance at the following tag mutation rates: 0.1, 0.02, 0.05, 0.01, 0.005, 0.002, 0.001, 0.0005, 0.0002. For the both changing-signal and directional-signal
      task (independenly), we selected the most performant mutation rate for each tag matching scheme.
    - Step 2 - for each metric, we compared the problem-solving performance at their most performant
      mutation rate for both the changing-signal and directional-signal tasks.
    - Results resported in paper.
  - **2020-03-27**
    - Follow-up final experiment.
    - Here, we investigated whether the streak or hamming metric solves either diagnostic problem (independently)
      in fewer generations the the other.
    - We ran until 50% of each condition found a solution and only compared those first 50% of runs.
    - Results reported in paper.