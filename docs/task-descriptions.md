# Diagnostic Tasks

Here we give a brief overview of the changing-signal and directional-signal tasks as well as the parameterizations we used for each.

Note that for both of these experiments that only variation operators that introduce new tags into a
population are the per-bit tag mutation operators. For these runs, we disabled single-instruction insertions
and deletions and multi-instruction duplications. Whole-function duplications and deletions are still
possible, however, these operators do not vary instruction or function tags (as new tags are identical
to copied tags). We also initialized populations with a common ancestor comprising only Nop instructions,
each with identical instruction tags (again, trying to control sources of tag variation).

## Changing-signal Task

The changing-signal task requires programs to express a unique response for each of K distinct environmental signals (_i.e._, each signal has a distinct tag).
Because signals are distinct, programs do not need to alter their responses to particular signals over time.
Instead, programs may 'hardware' each of the K possible responses to the appropriate environmental signal.
However, environmental signals are presented in a random order; thus, the correct order of responses will vary and cannot be hardcoded.
Programs respond by executing one of K response instructions.

During evaluation, we afford programs a fixed number of time steps to express the appropriate response after receiving a signal.
Once a program expresses a response or the allotted time expires, we reset the program's virtual hardware (resetting all executing threads and thread-local memory), and the environment produces the next signal.
Evaluation continues until the program correctly responds to each of the K environmental signals or until the program expresses an incorrect response.
During each evaluation, programs experience environmental signals in a random order; thus, the correct _order_ of responses will vary and cannot be hardcoded.

### Changing-signal task parameterization

Available run-time parameters for the changing-signal task can be found in [../source/ChgEnvConfig.h](https://github.com/amlalejini/Exploring-tag-matching-metrics-in-SignalGP/blob/master/source/ChgEnvConfig.h).
Generate a configuration file by executing the changing-signal task executable with the `--gen`
command line option.

Here, we give the final set of parameters used in our experiments.

| parameter | value | description |
| --- | --- | --- |
| matchbin_metric | varied by condition |  Compile-time parameter. Which tag-matching metric should be used for tag-based referencing?  |
| matchbin_thresh | 0 | Compile-time parameter. What is the minimum similarity threshold (as a percentage; e.g., 25 = 25% match) for tag-matches to succeed? |
| matchbin_regulator | mult | Compile-time parameter. Which tag-matching regulator should be used for genetic regulation? |
| TAG_LEN | 32 | Compile-time parameter. Number of bits in each tag bit string. |
| INST_TAG_CNT | 1 | Compile-time parameter. How many argument-tags does each instruction have? |
| INST_ARG_CNT | 3 | Compile-time parameter. How many numeric arguments does each instruction have? |
| FUNC_NUM_TAGS | 1 | Compile-time parameter. How many function-tags does each function have? |
| env_state_tags | Not a set-able parameter. Varied by replicate (randomly generated at beginning of run) | Defines the set of environment signals. |
| SEED | varied by replicate | Random number generator seed |
| GENERATIONS | 100 | How many generations should the population evolve? |
| POP_SIZE | 500 | How many individuals are in our population? |
| RANDOM_INIT_POP | 0 | Should we initialize the population with random programs? |
| NUM_ENV_UPDATES | 8 | How many times does the environment change (i.e., produce an environmental signal)? |
| NUM_ENV_STATES | 8 | How many possible responses are there? |
| CPU_CYCLES_PER_ENV_UPDATE | 64 | How many time steps do programs have to respond after receiving an environmental signal? |
| MAX_ACTIVE_THREAD_CNT | 8 | How many threads are allowed to be running concurrently? |
| MAX_THREAD_CAPACITY | 16 | How many threads are allowed to be running concurrently + the number allowed to be in a pending state? |
| USE_GLOBAL_MEMORY | 1 | Do SignalGP digital organisms have access to global memory? |
| USE_FUNC_REGULATION | 0 | Do SignalGP digital organisms have access to genetic regulation? |
| SELECTION_MODE | tournament | What selection scheme should we use to select parents to reproduce? |
| TOURNAMENT_SIZE | 8 | How many individuals participate in each tournament for parent selection? |
| EVAL_TRIAL_CNT | 3 | How many times should we independently evaluate each individual in the population (taking their minimum score)? |
| MIN_FUNC_CNT | 0 | What is the minimum number of functions allowed in a program (constrains the mutation operators)? |
| MAX_FUNC_CNT | 32 | What is the maximum number of functions allowed in a program (constrains the mutation operators)? |
| MIN_FUNC_INST_CNT | 32 | What is the minimum number of instructions allowed in each program function? |
| MAX_FUNC_INST_CNT | 32 | What is the maximum number of instructions allowed in each program function? |
| INST_MIN_ARG_VAL | -8 | What is the minimum value for numeric instruction arguments? |
| INST_MAX_ARG_VAL | 8 | What is the maximum value for numeric instruction arguments? |
| MUT_RATE__FUNC_TAG_BF | varied by metric | The per-bit mutation rate for function tags |
| MUT_RATE__INST_TAG_BF | varied by metric | The per-bit mutation rate for instruction-argument tags |
| MUT_RATE__FUNC_DUP | 0.05 | The per-function mutation rate for whole-function duplications |
| MUT_RATE__FUNC_DEL | 0.05 | The per-function mutation rate for whole-function deletions |
| MUT_RATE__SEQ_SLIP | 0 | The per-function mutation rate for slip mutations (which can result in instruction-sequence duplications and deletions) |
| MUT_RATE__INST_INS | 0 | The per-instruction mutation rate for single-instruction insertions |
| MUT_RATE__INST_DEL | 0 | The per-instruction mutation rate for single-instruction deletions |
| MUT_RATE__INST_SUB | 0.005 | The per-instruction mutation rate for substitutions |
| MUT_RATE__INST_ARG_SUB | 0.005 | The per-instruction-argument rate for numeric argument substitutions |
| OUTPUT_DIR | output | What directory will the experiment write output? |
| STOP_ON_SOLUTION | 1 | Should we stop running (and output) as soon as a solution is found? |
| SNAPSHOT_RESOLUTION | 100 | At what resolution (in generations) should we output 'snapshot' data? |
| SUMMARY_RESOLUTION | 5 | At what resolution (in generations) should we output summary data? |

Tag mutation rates by metric:

- Hamming
  - MUT_RATE__FUNC_TAG_BF=0.01
  - MUT_RATE__INST_TAG_BF=0.01
- Hash:
  - MUT_RATE__FUNC_TAG_BF=0.002
  - MUT_RATE__INST_TAG_BF=0.002
- Integer
  - MUT_RATE__FUNC_TAG_BF=0.02
  - MUT_RATE__INST_TAG_BF=0.02
- Bidirectional integer
  - MUT_RATE__FUNC_TAG_BF=0.02
  - MUT_RATE__INST_TAG_BF=0.02
- Streak
  - MUT_RATE__FUNC_TAG_BF=0.01
  - MUT_RATE__INST_TAG_BF=0.01

## Directional-signal Task

As in the changing-signal task, the directional-signal task requires that programs respond to a sequence of environmental cues; in the directional-signal task, however, the correct response depends on previously experienced signals.
In the directional signal task (for this work), there are two possible environmental signals --- a 'forward-signal' and a 'backward-signal' (each with a distinct tag) ---  and four possible responses.
If a program receives a forward-signal, it should express the next response, and if the program receives, a backward-signal, it should express the previous response.
For example, if response-three is currently required, then a subsequent forward-signal indicates that response-four is required next, while a backward-signal would instead indicate that response-two is required next.
Because the appropriate response to both the backward- and forward-signals change over time, successful programs must regulate which functions these signals trigger (rather than hardcode each response to a particular signal).

We evaluate programs on all possible four-signal sequences of forward- and backward-signals (sixteen total).
For each program, we evaluate each sequence of signals independently, and a program's fitness is equal to its aggregate performance.
Otherwise, evaluation on a single sequence of signals mirrors that of the changing signal task.

### Directional-signal task parameterization

Available run-time parameters for the directional-signal task can be found in [../source/DirSignalConfig.h](https://github.com/amlalejini/Exploring-tag-matching-metrics-in-SignalGP/blob/master/source/DirSignalConfig.h).
Generate a configuration file by executing the the directional-signal task executable with the `--gen`
command line option.

Here, we give the final set of parameters used in our experiments.

| parameter | value | description |
| --- | --- | --- |
| matchbin_metric | varied by condition |  Compile-time parameter. Which tag-matching metric should be used for tag-based referencing?  |
| matchbin_thresh | 0 | Compile-time parameter. What is the minimum similarity threshold (as a percentage; e.g., 25 = 25% match) for tag-matches to succeed? |
| matchbin_regulator | mult | Compile-time parameter. Which tag-matching regulator should be used for genetic regulation? |
| TAG_LEN | 32 | Compile-time parameter. Number of bits in each tag bit string. |
| INST_TAG_CNT | 1 | Compile-time parameter. How many argument-tags does each instruction have? |
| INST_ARG_CNT | 3 | Compile-time parameter. How many numeric arguments does each instruction have? |
| FUNC_NUM_TAGS | 1 | Compile-time parameter. How many function-tags does each function have? |
| env_state_tags | Not a set-able parameter. Varied by replicate (randomly generated at beginning of run) | Defines the forward and backward environment signals. |
| SEED | varied by replicate | Random number generator seed |
| GENERATIONS | 5000 | How many generations should the population evolve? |
| POP_SIZE | 500 | How many individuals are in our population? |
| RANDOM_INIT_POP | 0 | Should we initialize the population with random programs? |
| NUM_ENV_UPDATES | 4 | How many times does the environment change (i.e., produce an environmental signal)? |
| NUM_ENV_STATES | 4 | How many possible responses are there? |
| CPU_CYCLES_PER_ENV_UPDATE | 64 | How many time steps do programs have to respond after receiving an environmental signal? |
| MAX_ACTIVE_THREAD_CNT | 8 | How many threads are allowed to be running concurrently? |
| MAX_THREAD_CAPACITY | 16 | How many threads are allowed to be running concurrently + the number allowed to be in a pending state? |
| USE_GLOBAL_MEMORY | 1 | Do SignalGP digital organisms have access to global memory? |
| USE_FUNC_REGULATION | 1 | Do SignalGP digital organisms have access to genetic regulation? |
| SELECTION_MODE | tournament | What selection scheme should we use to select parents to reproduce? |
| TOURNAMENT_SIZE | 8 | How many individuals participate in each tournament for parent selection? |
| EVAL_TRIAL_CNT | 1 | How many times should we independently evaluate each individual in the population (taking their minimum score)? |
| TEST_SAMPLE_SIZE | 16 | How many environment sequences (each unique) should we use to evaluate each organism? |
| MIN_FUNC_CNT | 0 | What is the minimum number of functions allowed in a program (constrains the mutation operators)? |
| MAX_FUNC_CNT | 32 | What is the maximum number of functions allowed in a program (constrains the mutation operators)? |
| MIN_FUNC_INST_CNT | 32 | What is the minimum number of instructions allowed in each program function? |
| MAX_FUNC_INST_CNT | 32 | What is the maximum number of instructions allowed in each program function? |
| INST_MIN_ARG_VAL | -8 | What is the minimum value for numeric instruction arguments? |
| INST_MAX_ARG_VAL | 8 | What is the maximum value for numeric instruction arguments? |
| MUT_RATE__FUNC_TAG_BF | varied by metric | The per-bit mutation rate for function tags |
| MUT_RATE__INST_TAG_BF | varied by metric | The per-bit mutation rate for instruction-argument tags |
| MUT_RATE__FUNC_DUP | 0.05 | The per-function mutation rate for whole-function duplications |
| MUT_RATE__FUNC_DEL | 0.05 | The per-function mutation rate for whole-function deletions |
| MUT_RATE__SEQ_SLIP | 0 | The per-function mutation rate for slip mutations (which can result in instruction-sequence duplications and deletions) |
| MUT_RATE__INST_INS | 0 | The per-instruction mutation rate for single-instruction insertions |
| MUT_RATE__INST_DEL | 0 | The per-instruction mutation rate for single-instruction deletions |
| MUT_RATE__INST_SUB | 0.005 | The per-instruction mutation rate for substitutions |
| MUT_RATE__INST_ARG_SUB | 0.005 | The per-instruction-argument rate for numeric argument substitutions |
| OUTPUT_DIR | output | What directory will the experiment write output? |
| STOP_ON_SOLUTION | 1 | Should we stop running (and output) as soon as a solution is found? |
| MINIMAL_TRACES | 1 | Should we output a minimal number of execution traces or traces for all possible environment sequences (watch out, this could be big!)? |
| SNAPSHOT_RESOLUTION | 1000 | At what resolution (in generations) should we output 'snapshot' data? |
| SUMMARY_RESOLUTION | 10 | At what resolution (in generations) should we output summary data? |
| SCREEN_RESOLUTION | 10 | At what resolution should we screen max-fitness organisms to check if they are a general solution? |

Tag mutation rates by metric:

- Hamming: 0.001
  - MUT_RATE__FUNC_TAG_BF=0.001
  - MUT_RATE__INST_TAG_BF=0.001
- Hash: 0.001
  - MUT_RATE__FUNC_TAG_BF=0.001
  - MUT_RATE__INST_TAG_BF=0.001
- Integer: 0.002
  - MUT_RATE__FUNC_TAG_BF=0.002
  - MUT_RATE__INST_TAG_BF=0.002
- Bidirectional integer: 0.0001
  - MUT_RATE__FUNC_TAG_BF=0.0001
  - MUT_RATE__INST_TAG_BF=0.0001
- Streak: 0.002
  - MUT_RATE__FUNC_TAG_BF=0.002
  - MUT_RATE__INST_TAG_BF=0.002