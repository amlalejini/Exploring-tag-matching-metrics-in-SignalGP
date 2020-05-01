# Diagnostic Tasks

Here we give a brief overview of the changing-signal and directional-signal tasks as well as the parameterizations we used for each.

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

## Directional-signal Task

### Directional-signal task parameterization