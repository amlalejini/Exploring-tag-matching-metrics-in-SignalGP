#ifndef MC_REG_WORLD_CONFIG_H
#define MC_REG_WORLD_CONFIG_H

#include "config/config.h"

EMP_BUILD_CONFIG(MCRegConfig,
  GROUP(DEFAULT_GROUP, "General settings"),
    VALUE(SEED, int, 0, "Random number seed (-1 for seed based on time)"),
    VALUE(GENERATIONS, size_t, 100, "How many generations do we evolve things?"),
    VALUE(POP_SIZE, size_t, 100, "How big is our population?"),

  GROUP(ENVIRONMENT_GROUP, "Environment settings"),
    VALUE(NUM_RESPONSE_TYPES, size_t, 4, "How many possible response types are there?"),
    VALUE(DEVELOPMENT_PHASE_CPU_TIME, size_t, 32, "How many CPU cycles do we evaluate demes in this environment phase?"),
    VALUE(RESPONSE_PHASE_CPU_TIME, size_t, 32, "How many CPU cycles do we evaluate demes in this environment phase?"),

  GROUP(PROGRAM_GROUP, "Program settings"),
    VALUE(USE_FUNC_REGULATION, bool, true, "Do programs have access to function regulation instructions?"),
    VALUE(USE_GLOBAL_MEMORY, bool, false, "Do programs have access to global memory?"),
    VALUE(MIN_FUNC_CNT, size_t, 0, "Minimum number of functions per program."),
    VALUE(MAX_FUNC_CNT, size_t, 32, "Maximum number of functions per program."),
    VALUE(MIN_FUNC_INST_CNT, size_t, 0, "Minimum number of instructions per function."),
    VALUE(MAX_FUNC_INST_CNT, size_t, 128, "Maximum number of instructions per function."),
    VALUE(INST_MIN_ARG_VAL, int, -8, "Minimum instruction-argment value"),
    VALUE(INST_MAX_ARG_VAL, int, 8, "Maximum instruction-argument value"),

  GROUP(HARDWARE_GROUP, "Virtual hardware settings"),
    VALUE(DEME_WIDTH, size_t, 4, "How many columns of cells are in a deme?"),
    VALUE(DEME_HEIGHT, size_t, 4, "How many rows of cells are in a deme?"),
    VALUE(PROPAGULE_SIZE, size_t, 1, "How many cells get activated as propagule?"),
    VALUE(PROPAGULE_LAYOUT, std::string, "random", "How are propagules configured on activation?\n  'random': activated cells are randomly selected\n  'clumpy': activated cells are in a clump"),
    VALUE(MAX_ACTIVE_THREAD_CNT, size_t, 32, "How many threads can be simultaneously running (active)?"),
    VALUE(MAX_THREAD_CAPACITY, size_t, 64, "Maximum capacity for thread memory (pending + active)."),
    VALUE(EPIGENETIC_INHERITANCE, bool, false, "Do cells pass on matchbin regulation to (within-multi-cell) offspring?"),
    VALUE(USE_RANDOM_CELL_SCHEDULING, bool, true, "Are cells in a deme executed in random order?"),
    VALUE(FIXED_REPRO_TAG, bool, false, "Should repro tag be pulled from instruction or be fixed?"),
    VALUE(ALLOW_MESSAGING, bool, true, "Should organisms be allowed to send/receive messages?"),

  GROUP(SELECTION_GROUP, "Selection settings"),
    VALUE(TOURNAMENT_SIZE, size_t, 7, "How big are tournaments when doing tournament selection?"),
    VALUE(SCORE_RESPONSE_MODE, std::string, "simple", "Options: [simple, neighbors, distances]"),
    VALUE(CUSTOM_MAX_RESPONSE_CNT, bool, false, "Should we evenly divide max response score or use the parameter 'MAX_RESPONSE_CNT' as max response count that gets scored?"),
    VALUE(MAX_RESPONSE_CNT, size_t, 4, "What is the maximum score that can be awarded for "),

  GROUP(MUTATION_GROUP, "Mutation settings"),
    VALUE(MUT_RATE__INST_ARG_SUB, double, 0.005, "InstArgSub rate"),
    VALUE(MUT_RATE__INST_TAG_BF, double, 0.001, "InstArgTagBF rate"),
    VALUE(MUT_RATE__INST_SUB, double, 0.005, "InstSub rate"),
    VALUE(MUT_RATE__INST_INS, double, 0.005, "InstIns rate"),
    VALUE(MUT_RATE__INST_DEL, double, 0.005, "InstDel rate"),
    VALUE(MUT_RATE__SEQ_SLIP, double, 0.005, "SeqSlip rate"),
    VALUE(MUT_RATE__FUNC_DUP, double, 0.005, "FuncDup rate"),
    VALUE(MUT_RATE__FUNC_DEL, double, 0.005, "FuncDel rate"),
    VALUE(MUT_RATE__FUNC_TAG_BF, double, 0.001, "FuncTagBF rate"),

  GROUP(DATA_COLLECTION_GROUP, "Data collection settings"),
    VALUE(OUTPUT_DIR, std::string, "output", "where should we dump output?"),
    VALUE(SUMMARY_RESOLUTION, size_t, 10, "How often should we output summary statistics?"),
    VALUE(SNAPSHOT_RESOLUTION, size_t, 100, "How often should we snapshot the population?"),
)

#endif