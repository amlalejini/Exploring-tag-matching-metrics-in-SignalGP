#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

#include <limits>

#include "tools/BitSet.h"
#include "tools/math.h"
#include "tools/Random.h"
#include "tools/MatchBin.h"
#include "tools/matchbin_utils.h"
#include "tools/Range.h"

#include "AltSignalWorld.h"
#include "AltSignalConfig.h"
#include "mutation_utils.h"

TEST_CASE( "Hello World", "[general]" ) {
  std::cout << "Hello tests!" << std::endl;
}

/*
TEST_CASE( "Figuring Out Ranked Selector Thresholds", "[general]" ) {
  constexpr size_t TAG_WIDTH = 16;
  using tag_t = emp::BitSet<TAG_WIDTH>;
  emp::HammingMetric<TAG_WIDTH> hamming_metric;
  emp::Random random(2);

  emp::vector<tag_t> tags;
  for (size_t i = 0; i < emp::Pow(2, TAG_WIDTH); ++i) {
    tags.emplace_back();
    tags.back().SetUInt(0, i);
  }

  // Create a couple of match bins!
  emp::MatchBin<size_t,
                emp::HammingMetric<TAG_WIDTH>,
                emp::RankedSelector<>> matchbin_0(random); // 0% min threshold

  emp::MatchBin<size_t,
                emp::HammingMetric<TAG_WIDTH>,
                emp::RankedSelector<std::ratio<TAG_WIDTH+(TAG_WIDTH/2), TAG_WIDTH>>
               > matchbin_1(random); // 50% min threshold

  for (size_t i = 0; i < tags.size(); ++i) {
    std::cout << "=== i = " << i << " ===" << std::endl;
    // Clear the matchbins.
    matchbin_0.Clear();
    matchbin_1.Clear();
    emp::vector<size_t> matches;
    // Add focal tag to matchbin.
    matchbin_0.Set(i, tags[i], i);
    matchbin_1.Set(i, tags[i], i);
    std::cout << "Focal tag = "; tags[i].Print(); std::cout << std::endl;
    // Does 0000 match with focal tag?
    std::cout << "Matchbin 0" << std::endl;
    matches = matchbin_0.Match(tags[0], 1);
    if (matches.size()) {
      std::cout << "  "; tags[0].Print();
      std::cout << " matched with "; tags[i].Print();
      std::cout << std::endl;
    } else {
      std::cout << "  "; tags[0].Print();
      std::cout << " DID NOT MATCH WITH "; tags[i].Print();
      std::cout << std::endl;
    }
    std::cout << "Matchbin 1" << std::endl;
    matches = matchbin_1.Match(tags[0], 1);
    if (matches.size()) {
      std::cout << "  "; tags[0].Print();
      std::cout << " matched with "; tags[i].Print();
      std::cout << std::endl;
    } else {
      std::cout << "  "; tags[0].Print();
      std::cout << " DID NOT MATCH WITH "; tags[i].Print();
      std::cout << std::endl;
    }
  }

}
*/

TEST_CASE( "LinearFunctionsProgram Mutator" ) {
  constexpr size_t TAG_WIDTH = 16;
  constexpr int RANDOM_SEED = 1;
  using mem_model_t = emp::signalgp::SimpleMemoryModel;
  using tag_t = emp::BitSet<TAG_WIDTH>;
  using arg_t = int;
  using matchbin_t = emp::MatchBin< size_t, emp::HammingMetric<TAG_WIDTH>, emp::RankedSelector<> >;
  using hardware_t = emp::signalgp::LinearFunctionsProgramSignalGP<mem_model_t,
                                                                   tag_t,
                                                                   arg_t,
                                                                   matchbin_t>;

  using inst_t = typename hardware_t::inst_t;
  using inst_lib_t = typename hardware_t::inst_lib_t;
  using program_t = typename hardware_t::program_t;
  using mutator_t = MutatorLinearFunctionsProgram<hardware_t, tag_t, arg_t>;

  inst_lib_t inst_lib;
  inst_lib.AddInst("Nop-A", [](hardware_t & hw, const inst_t & inst) { ; }, "No operation!");
  inst_lib.AddInst("Nop-B", [](hardware_t & hw, const inst_t & inst) { ; }, "No operation!");
  inst_lib.AddInst("Nop-C", [](hardware_t & hw, const inst_t & inst) { ; }, "No operation!");
  emp::Random random(RANDOM_SEED);
  mutator_t mutator(inst_lib);

  emp::Range<int> ARG_VAL_RANGE = {0, 15};
  emp::Range<size_t> FUNC_LEN_RANGE = {0, 128};
  emp::Range<size_t> FUNC_CNT_RANGE = {1, 32};
  size_t MAX_TOTAL_LEN = 1024;
  size_t NUM_FUNC_TAGS = 1;
  size_t NUM_INST_TAGS = 1;
  size_t NUM_INST_ARGS = 3;

  mutator.SetProgFunctionCntRange(FUNC_CNT_RANGE);
  mutator.SetProgFunctionInstCntRange(FUNC_LEN_RANGE);
  mutator.SetProgInstArgValueRange(ARG_VAL_RANGE);
  mutator.SetTotalInstLimit(MAX_TOTAL_LEN);
  mutator.SetFuncNumTags(NUM_FUNC_TAGS);
  mutator.SetInstNumTags(NUM_INST_TAGS);
  mutator.SetInstNumArgs(NUM_INST_ARGS);

  // Test 0 mutation rate on all functions.
  mutator.SetRateInstArgSub(0.0);
  mutator.SetRateInstArgTagBF(0.0);
  mutator.SetRateInstSub(0.0);
  mutator.SetRateInstIns(0.0);
  mutator.SetRateInstDel(0.0);
  mutator.SetRateSeqSlip(0.0);
  mutator.SetRateFuncDup(0.0);
  mutator.SetRateFuncDel(0.0);
  mutator.SetRateFuncTagBF(0.0);
  program_t nop_prog;
  size_t num_muts = 0;
  for (size_t f = 0; f < 3; ++f) {
    nop_prog.PushFunction(tag_t());
    for (size_t i = 0; i < 8; ++i) nop_prog.PushInst(inst_lib, "Nop-A", {0, 0, 0}, {tag_t()});
  }
  program_t copy_prog(nop_prog);
  num_muts = mutator.ApplyInstSubs(random, nop_prog);
  REQUIRE(num_muts == 0);
  REQUIRE(copy_prog == nop_prog);
  REQUIRE(mutator.VerifyProgram(nop_prog));
  num_muts = mutator.ApplyInstInDels(random, nop_prog);
  REQUIRE(num_muts == 0);
  REQUIRE(copy_prog == nop_prog);
  REQUIRE(mutator.VerifyProgram(nop_prog));
  num_muts = mutator.ApplySeqSlips(random, nop_prog);
  REQUIRE(num_muts == 0);
  REQUIRE(copy_prog == nop_prog);
  REQUIRE(mutator.VerifyProgram(nop_prog));
  num_muts = mutator.ApplyFuncDup(random, nop_prog);
  REQUIRE(num_muts == 0);
  REQUIRE(copy_prog == nop_prog);
  REQUIRE(mutator.VerifyProgram(nop_prog));
  num_muts = mutator.ApplyFuncDel(random, nop_prog);
  REQUIRE(num_muts == 0);
  REQUIRE(copy_prog == nop_prog);
  REQUIRE(mutator.VerifyProgram(nop_prog));
  num_muts = mutator.ApplyFuncTagBF(random, nop_prog);
  REQUIRE(num_muts == 0);
  REQUIRE(copy_prog == nop_prog);
  REQUIRE(mutator.VerifyProgram(nop_prog));

}

/*
TEST_CASE( "AltSignalWorld ") {
  AltSignalConfig config;
  config.SEED(2);
  config.POP_SIZE(100);
  config.GENERATIONS(10);
  config.NUM_SIGNAL_RESPONSES(2);
  config.NUM_ENV_CYCLES(4);
  config.CPU_TIME_PER_ENV_CYCLE(64);

  emp::Random random(config.SEED());
  AltSignalWorld world(random);

  world.Setup(config);
  world.Run();

}
*/