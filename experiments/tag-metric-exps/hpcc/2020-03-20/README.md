# Exploratory experiments - 03-20-2020

Purpose: compare performance of different tag-matching metrics. Use uniform population initialization,
and parameterize mutation rates using Matthew's performance results.

## Mutation rates by metric:

From Matthew:

```
              Update Target Structure  Target Degree  Mutation Rate  seed  Maximum Fitness Target Configuration  Sum Fitness
Metric
Hamming            1          Regular              2           2.00  2400          0.34375            Regular 2    335.37500
Hash               1          Regular              1           0.75  1000          0.31250            Regular 1    382.31250
Integer            1          Regular              1           6.00  3400          0.31250            Regular 1    358.93750
Integer (bi)       1          Regular              1           4.00  3000          0.37500            Regular 1    365.43750
Streak             1          Regular              2           1.50  2000          0.34375            Regular 2    346.34375

the mutation rate is per genome, so to get the per-bit mutation rate, divide by 1024
```

Translated:

- Hamming: (2.00 / 1024) = 0.001953125
- Hash: (0.75 / 1024) = 0.000732421875
- Integer: (6.00 / 1024) = 0.005859375
- Integer (bi): (4.00 / 1024) = 0.00390625
- Streak: (1.50 / 1024) = 0.00146484375

## Results

- Graphs: [analysis/imgs](https://github.com/amlalejini/Exploring-tag-matching-metrics-in-SignalGP/tree/master/experiments/tag-metric-exps/analysis/imgs/2020-03-20)
- [web page](http://lalejini.com/Exploring-tag-matching-metrics-in-SignalGP/experiments/tag-metric-exps/analysis/2020-03-20.html)

We see a performance difference between metrics using these mutation rates.

Next steps:

- Mutation sweep for each metric, compare all at best rates.
  - Expectations:
    - Difference in performance:
      - Effect goes away, in which case picking the best mutation rate for your metric is very
        important
      - Or, smaller effect
    - Robustness to mutations: Some metrics will be better across a wider range of rates.