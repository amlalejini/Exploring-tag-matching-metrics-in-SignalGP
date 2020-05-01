# Exploratory experiments - 03-12-2020

Look at performance of different SignalGP variants (each using different tag matching metric) on the
directional signal task. For each tag metric, use most performant mutation rate found in previous work.

Result: no clear signal. We need more control over initial genetic variation (to avoid instruction
substitutions providing fresh tags for regulation instructions).

Things to try:

- Initialize initial population to uniform ancestor (1 function, all tags are same)
- Parameterize mutation rates based on Matthew's diagnostic experiments