# green_efficiency_analysis.md

## Measurement Methodology

Three C programs were executed to analyze runtime behavior and evaluate computational efficiency using CPU time measurements. All timings were performed using `clock_t` and `clock()` from `<time.h>`, with conversion to seconds via `CLOCKS_PER_SEC`. The algorithmic logic of each program remained strictly unchanged.

In the multi-phase program, timing boundaries were defined consistently. The total measurement started immediately before the call to `build_dataset()` and ended immediately after `reduce_checksum()`. Each phase was individually measured by placing `clock()` calls directly before and after its execution. This ensures that only the computational cost of each phase is measured, while the total time reflects the entire execution flow.

The recorded results were:

- TOTAL seconds: 0.001859  
- BUILD_DATA seconds: 0.000667  
- PROCESS seconds: 0.000994  
- REDUCE seconds: 0.000171  

The total time is greater than each individual phase measurement, confirming consistent boundary definition.

The algorithm comparison program measured execution time independently for both implementations using separate timing intervals. The baseline loop program measured a deterministic computation to evaluate timing variability under repeated execution.

---

## Observed Performance Differences

In the instrumentation lab program, the processing phase dominated execution time. With a measured value of 0.000994 seconds, it represents more than half of the total runtime (0.001859 seconds). The build phase required 0.000667 seconds, while the checksum reduction phase required only 0.000171 seconds. This clearly shows that the arithmetic transformation inside `process_dataset()` is the most computationally intensive part of the workflow.

In the comparison experiment, the naive algorithm averaged approximately 2.940606 seconds, while the single-pass algorithm averaged 0.000117 seconds. This means the naive implementation was approximately 25,133 times slower than the optimized single-pass approach. Both algorithms produced identical results, confirming correctness while highlighting the dramatic performance impact of algorithmic complexity.

The baseline loop execution showed stable timing across runs, demonstrating that measurement variability was minimal and that observed differences between algorithms were not caused by random fluctuations.

---

## Relation Between Runtime and Energy Consumption

Execution time directly affects energy consumption, as CPU energy usage is proportional to processing duration. The naive algorithm’s execution time of nearly three seconds results in significantly higher energy use compared to the microsecond-scale execution of the single-pass algorithm. Reducing runtime from seconds to microseconds drastically lowers computational energy cost.

Similarly, within the multi-phase program, optimizing the processing phase would likely provide the greatest reduction in overall energy consumption because it accounts for the largest share of total runtime.

---

## Limitations of the Experiment

Several limitations must be acknowledged. First, `clock()` measures CPU time rather than wall-clock time, which excludes potential scheduling overhead. Second, all experiments were conducted on a single machine, meaning results may differ on other hardware configurations. Third, dataset sizes were fixed at 50,000 elements, limiting conclusions about scalability for significantly larger inputs.

---

## Practical Engineering Takeaway

These experiments demonstrate that algorithmic complexity has a decisive impact on performance and energy efficiency. The processing phase was identified as the dominant cost in the multi-phase program, showing the importance of profiling individual components. Most importantly, the comparison between the naive and single-pass implementations revealed a performance gap of over 25,000 times. Engineers should prioritize efficient algorithm design and systematic timing instrumentation to reduce execution time and energy consumption, particularly in large-scale or high-frequency systems.
