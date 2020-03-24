# 2020-03-23 Experiments

Do we still see difference in performance if we tune mutation rates for each task?

## Runs

### First-step runs:

- Goal: find good mutation rate for each metric for directional and changing signal tasks
  - secondary goal: look at how 'robust' each task is across mutation rates
    - Approaches:
      - aggregate across rates, use rank-based statistics for comparisons
- Tasks (2): directional signal task, changing signal task
- Metrics (5): hamming, hash, streak, integer, integer-symmetric
- Mutation rates (7):
  - 0.02
  - 0.01
  - 0.005
  - 0.002
  - 0.001
  - 0.0005
  - 0.0002
- Replicates: 50?

#### Directional signal - mutation rate results

- Hamming
  - By solution count: **0.001**
  - By median: 5e-04, 0.001, 0.002
  - By mean: 0.002
- Hash
  - By solution count: **0.001**
  - By median: 0.001
  - By mean: 0.001
- Integer
  - By solution count: **0.002**
  - By median: 5e-04, 0.002, 0.005
  - By mean: 0.005
- Integer-symmetric
  - By solution count: **0.0001**
  - By median: 5e-04, 0.002, 0.005, 0.01
  - By mean: 0.01
- Streak
  - By solution count: 0.001, **0.002**
  - By median: 2e-04, 5e-04, 0.001, 0.002
  - By mean: 0.002

```
[1] "------------ hamming ------------"
[1] "Metric: hamming Mutation rate: 2e-04"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
   40.0    56.0    61.0    59.1    64.0    64.0
[1] "======="
[1] "Metric: hamming Mutation rate: 5e-04"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  43.00   56.00   64.00   59.58   64.00   64.00
[1] "======="
[1] "Metric: hamming Mutation rate: 0.001"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  42.00   57.00   64.00   60.36   64.00   64.00
[1] "======="
[1] "Metric: hamming Mutation rate: 0.002"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
   49.0    60.0    64.0    60.5    64.0    64.0
[1] "======="
[1] "Metric: hamming Mutation rate: 0.005"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  36.00   49.00   56.00   54.54   60.00   64.00
[1] "======="
[1] "Metric: hamming Mutation rate: 0.01"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  32.00   43.00   46.00   47.66   56.00   64.00
[1] "======="
[1] "Metric: hamming Mutation rate: 0.02"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  32.00   36.00   42.00   40.92   46.00   52.00
[1] "======="

[1] "------------ integer ------------"
[1] "Metric: integer Mutation rate: 2e-04"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  15.00   40.00   49.00   46.16   60.00   64.00
[1] "======="
[1] "Metric: integer Mutation rate: 5e-04"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  15.00   45.25   56.00   49.82   63.50   64.00
[1] "======="
[1] "Metric: integer Mutation rate: 0.001"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
     15      45      51      50      60      64
[1] "======="
[1] "Metric: integer Mutation rate: 0.002"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  24.00   45.25   56.00   51.22   64.00   64.00
[1] "======="
[1] "Metric: integer Mutation rate: 0.005"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  18.00   46.00   56.00   51.74   59.00   64.00
[1] "======="
[1] "Metric: integer Mutation rate: 0.01"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
   24.0    45.0    49.0    49.1    56.0    64.0
[1] "======="
[1] "Metric: integer Mutation rate: 0.02"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  34.00   45.00   46.00   48.34   54.25   64.00
[1] "======="

[1] "------------ integer-symmetric ------------"
[1] "Metric: integer-symmetric Mutation rate: 2e-04"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  18.00   46.00   46.00   48.92   63.00   64.00
[1] "======="
[1] "Metric: integer-symmetric Mutation rate: 5e-04"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  24.00   46.00   56.00   53.06   60.00   64.00
[1] "======="
[1] "Metric: integer-symmetric Mutation rate: 0.001"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
   15.0    46.0    55.5    51.4    56.0    64.0
[1] "======="
[1] "Metric: integer-symmetric Mutation rate: 0.002"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  28.00   46.00   56.00   52.34   56.00   64.00
[1] "======="
[1] "Metric: integer-symmetric Mutation rate: 0.005"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  30.00   46.00   56.00   52.30   62.75   64.00
[1] "======="
[1] "Metric: integer-symmetric Mutation rate: 0.01"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  30.00   49.25   56.00   54.32   60.75   64.00
[1] "======="
[1] "Metric: integer-symmetric Mutation rate: 0.02"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  30.00   45.00   46.00   46.98   54.00   57.00
[1] "======="

[1] "------------ hash ------------"
[1] "Metric: hash Mutation rate: 2e-04"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  36.00   50.00   56.00   56.06   64.00   64.00
[1] "======="
[1] "Metric: hash Mutation rate: 5e-04"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
   38.0    52.0    60.0    57.4    64.0    64.0
[1] "======="
[1] "Metric: hash Mutation rate: 0.001"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
   36.0    56.0    61.5    58.8    64.0    64.0
[1] "======="
[1] "Metric: hash Mutation rate: 0.002"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  36.00   49.00   56.00   55.26   64.00   64.00
[1] "======="
[1] "Metric: hash Mutation rate: 0.005"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  36.00   38.25   46.00   45.16   48.00   56.00
[1] "======="
[1] "Metric: hash Mutation rate: 0.01"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  30.00   30.00   31.00   32.88   36.00   36.00
[1] "======="
[1] "Metric: hash Mutation rate: 0.02"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  16.00   24.00   26.00   25.52   27.00   30.00
[1] "======="

[1] "------------ streak ------------"
[1] "Metric: streak Mutation rate: 2e-04"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  43.00   63.25   64.00   61.06   64.00   64.00
[1] "======="
[1] "Metric: streak Mutation rate: 5e-04"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  46.00   61.00   64.00   61.62   64.00   64.00
[1] "======="
[1] "Metric: streak Mutation rate: 0.001"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
   36.0    64.0    64.0    61.1    64.0    64.0
[1] "======="
[1] "Metric: streak Mutation rate: 0.002"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  30.00   64.00   64.00   61.76   64.00   64.00
[1] "======="
[1] "Metric: streak Mutation rate: 0.005"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  36.00   56.00   56.00   56.98   64.00   64.00
[1] "======="
[1] "Metric: streak Mutation rate: 0.01"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  36.00   43.00   46.00   46.98   52.00   59.00
[1] "======="
[1] "Metric: streak Mutation rate: 0.02"
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max.
  30.00   36.00   42.00   40.64   45.00   49.00
[1] "======="
```

#### Changing signal - mutation rate results

After 100 updates

- Hamming
  - By solution count: 0.01
  - By median:
  - By mean:
- Hash
  - By solution count: 0.002
  - By median:
  - By mean:
- Integer
  - By solution count: 0.02
  - By median:
  - By mean:
- Integer-symmetric
  - By solution count: 0.02
  - By median:
  - By mean:
- Streak
  - By solution count: 0.01
  - By median:
  - By mean:

```
```

### Next-step runs:

- Goal: compare performance of each at best found rates
- Tasks (2): directional signal task, changing signal task
- Metrics (5): hamming, hash, streak, integer, integer-symmetric
- Mutation rates (1 each):
  - Hamming: ___
  - Hash: ___
  - Streak: ___
  - Integer: ___
  - Integer-symmetric: ___

## 2020-03-20 mutation rates

For reference:

- Hamming: (2.00 / 1024) = 0.001953125; ~0.002
- Hash: (0.75 / 1024) = 0.000732421875; ~0.0007
- Integer: (6.00 / 1024) = 0.005859375; ~0.006
- Integer (bi): (4.00 / 1024) = 0.00390625; ~0.004
- Streak: (1.50 / 1024) = 0.00146484375; ~0.0015

## Base config file snapshots

To get an accurate picture of configuration settings, you'll need to look at these snapshots & the
submission scripts. Settings in the submission scripts override these configuration files.

directional signal task

```
### DEFAULT_GROUP ###
# General settings

set SEED 0              # Random number seed (-1 for seed based on time)
set GENERATIONS 1000    # How many generations do we evolve things?
set POP_SIZE 500        # How big is our population?
set STOP_ON_SOLUTION 1  # Should we stop run on solution?
set RANDOM_INIT_POP 0   # Should the population be initialized with random organisms?

### EVALUATION_GROUP ###
# Organism evaluation settings

set EVAL_TRIAL_CNT 1  # How many times should we evaluate individuals (where fitness = min trial performance)?

### ENVIRONMENT_GROUP ###
# Environment settings

set NUM_ENV_STATES 4               # How many responses are there to the environment signal?
set NUM_ENV_UPDATES 4              # How many responses are there to the environment signal?
set CPU_CYCLES_PER_ENV_UPDATE 128  # How many CPU cycles do organisms get per environment time step?

### PROGRAM_GROUP ###
# Program settings

set USE_FUNC_REGULATION 1  # Do programs have access to function regulation instructions?
set USE_GLOBAL_MEMORY 1    # Do programs have access to global memory?
set MIN_FUNC_CNT 0         # Minimum number of functions per program.
set MAX_FUNC_CNT 32       # Maximum number of functions per program.
set MIN_FUNC_INST_CNT 64    # Minimum number of instructions per function.
set MAX_FUNC_INST_CNT 64   # Maximum number of instructions per function.
set INST_MIN_ARG_VAL -8    # Minimum instruction-argment value
set INST_MAX_ARG_VAL 8     # Maximum instruction-argument value

### HARDWARE_GROUP ###
# Virtual hardware settings

set MAX_ACTIVE_THREAD_CNT 8  # How many threads can be simultaneously running (active)?
set MAX_THREAD_CAPACITY 16    # Maximum capacity for thread memory (pending + active).

### SELECTION_GROUP ###
# Selection settings

set SELECTION_MODE tournament  # Selection scheme? [lexicase, tournament]
set TOURNAMENT_SIZE 8          # How big are tournaments when doing tournament selection?
set TEST_SAMPLE_SIZE 16        # How many directional sequences should we sample to evaluate organisms?

### MUTATION_GROUP ###
# Mutation settings

set MUT_RATE__INST_ARG_SUB 0.005  # InstArgSub rate
set MUT_RATE__INST_SUB 0.005      # InstSub rate
set MUT_RATE__INST_INS 0.0        # InstIns rate
set MUT_RATE__INST_DEL 0.0        # InstDel rate
set MUT_RATE__SEQ_SLIP 0.0        # SeqSlip rate
set MUT_RATE__FUNC_DUP 0.05      # FuncDup rate
set MUT_RATE__FUNC_DEL 0.05      # FuncDel rate
set MUT_RATE__INST_TAG_BF 0.001   # InstArgTagBF rate
set MUT_RATE__FUNC_TAG_BF 0.001   # FuncTagBF rate

### DATA_COLLECTION_GROUP ###
# Data collection settings

set OUTPUT_DIR output         # where should we dump output?
set SUMMARY_RESOLUTION 100    # How often should we output summary statistics?
set SCREEN_RESOLUTION 10      # How often should we attempt to screen for a solution?
set SNAPSHOT_RESOLUTION 1000  # How often should we snapshot the population?
```

changing signal task

```
### DEFAULT_GROUP ###
# General settings

set SEED 0              # Random number seed (-1 for seed based on time)
set GENERATIONS 1000     # How many generations do we evolve things?
set POP_SIZE 500        # How big is our population?
set STOP_ON_SOLUTION 1  # Should we stop run on solution?
set RANDOM_INIT_POP 0   # Should the population be initialized with random organisms?

### EVALUATION_GROUP ###
# Organism evaluation settings

set EVAL_TRIAL_CNT 3  # How many times should we evaluate individuals (where fitness = min trial performance)?

### ENVIRONMENT_GROUP ###
# Environment settings

set NUM_ENV_STATES 8             # How many responses are there to the environment signal?
set NUM_ENV_UPDATES 8            # How many responses are there to the environment signal?
set CPU_CYCLES_PER_ENV_UPDATE 128  # How many CPU cycles do organisms get per environment time step?

### PROGRAM_GROUP ###
# Program settings

set USE_FUNC_REGULATION 0  # Do programs have access to function regulation instructions?
set USE_GLOBAL_MEMORY 1    # Do programs have access to global memory?
set MIN_FUNC_CNT 0         # Minimum number of functions per program.
set MAX_FUNC_CNT 32        # Maximum number of functions per program.
set MIN_FUNC_INST_CNT 64   # Minimum number of instructions per function.
set MAX_FUNC_INST_CNT 64   # Maximum number of instructions per function.
set INST_MIN_ARG_VAL -8    # Minimum instruction-argment value
set INST_MAX_ARG_VAL 8     # Maximum instruction-argument value

### HARDWARE_GROUP ###
# Virtual hardware settings

set MAX_ACTIVE_THREAD_CNT 8  # How many threads can be simultaneously running (active)?
set MAX_THREAD_CAPACITY 16    # Maximum capacity for thread memory (pending + active).

### SELECTION_GROUP ###
# Selection settings

set TOURNAMENT_SIZE 8  # How big are tournaments when doing tournament selection?

### MUTATION_GROUP ###
# Mutation settings

set MUT_RATE__INST_ARG_SUB 0.005  # InstArgSub rate
set MUT_RATE__INST_SUB 0.005      # InstSub rate
set MUT_RATE__INST_INS 0.0        # InstIns rate
set MUT_RATE__INST_DEL 0.0        # InstDel rate
set MUT_RATE__SEQ_SLIP 0.0        # SeqSlip rate
set MUT_RATE__FUNC_DUP 0.05      # FuncDup rate
set MUT_RATE__FUNC_DEL 0.05      # FuncDel rate
set MUT_RATE__INST_TAG_BF 0.001   # InstArgTagBF rate
set MUT_RATE__FUNC_TAG_BF 0.001   # FuncTagBF rate

### DATA_COLLECTION_GROUP ###
# Data collection settings

set OUTPUT_DIR output        # where should we dump output?
set SUMMARY_RESOLUTION 10    # How often should we output summary statistics?
set SNAPSHOT_RESOLUTION 100  # How often should we snapshot the population?
```