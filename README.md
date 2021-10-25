This repository contains a collection of applications adjusted to be executed on [AxPIKE](https://github.com/VArchC/axpike-isa-sim).

All applications were modified to read their inputs from stdin and write their outputs in stdout for simulation purposes.

The folder "input", inside each app folder, contains an example input to each application, named "train".

The folder "output", inside each app folder, contains the respective accurate output this input.

# Build applications

To build all applications:
```shell
$ cd apps
$ make all
```

To build a single application:
```shell
$ cd apps/<application>
$ make 
```

# Run 

To run a single application
```shell
$ cd apps/<application>
$ make 
$ spike pk bin/<application>.rv < input/<input_type>
```

# Sources

The applications and their respective source are:

|application | benchmark | quality metric | input | exec. time (s) | total instructions |
|--- | --- | --- | --- | --- | --- |
|2mm | Polybench [5] | MAPE | 32x32 double matrices | 46 | 8,62E+07 |
|atax | Polybench [5] | FEE | 500x500 double matrices | 43 | 6,72E+07 |
|blackscholes | AxBench [1] | MAPE | 1,000 entries | 45 | 8,20E+07 |
|bunzip2 | CBench [3] | SSI | compressed 256x256 image | 43 | 5,52E+07 |
|bzip2 | CBench [3] | SSI | 256x256 image | 109 | 1,11E+08 |
|correlation | Polybench [5] | FEE | 64x64 long int matrices | 26 | 4,77E+07 |
|covariance | Polybench [5] | FEE | 32x32 double matrices | 61 | 9,09E+07 |
|dijkstra | MiBench [4] | FEE | complete graph of 60 vertices | 18 | 3,37E+07 |
|fannkuch-redux | Benchmarks Game [2] | MAPE | N=9 | 64 | 1,29E+08 |
|fasta | Benchmarks Game [2] | FEE | N=50,000 | 10 | 2,15E+07 |
|fft | MiBench [4] | MAPE | Max waves 8, size 1024 | 82 | 1,56E+08 |
|floyd-warshall | Polybench [5] | FEE | complete graph of 64 vertices | 68 | 1,30E+08 |
|inversek2j | AxBench [1] | MAPE | 1,000 coordinates | 59 | 9,82E+07 |
|jacobi-2d-imper | Polybench [5] | FEE | Arrays of 32 double values | 36 | 6,39E+07 |
|jmeint | AxBench [1] | FEE | 1,0000 coordinates | 62 | 9,77E+07 |
|jpeg | AxBench [1] | SSI | 512x512 image | 127 | 2,30E+08 |
|k-nucleotide | Benchmarks Game [2] | MAPE | 2 sequences of 50,000 nucleotides | 121 | 9,79E+07 |
|mandelbrot | Benchmarks Game [2] | SSI | N=500 | 28 | 7,49E+07 |
|mm |  | MAPE | 100x100 int matrices | 42 | 8,01E+07 |
|nbody | Benchmarks Game [2] | MAPE | N=100,000 | 35 | 6,48E+07 |
|pi |  | MAPE | N=1,000,000 | 17 | 3,53E+07 |
|qsort | MiBench [4] | FEE | 10,000 strings | 36 | 6,68E+07 |
|reg_detect | Polybench [5] | MAPE | Iter=10,000, Length=32, MaxGrid=6 | 41 | 7,78E+07 |
|reverse-complement | Benchmarks Game [2] | FEE | 2 sequences of 50,000 nucleotides | 30 | 5,67E+07 |
|sobel |  | SSI | 256x256 image | 124 | 1,54E+08 |
|spectralnorm | Benchmarks Game [2] | MAPE | N=500 | 48 | 1,26E+08 |



# References

Benchmarks repositories:

[1] AxBench: http://axbench.org/

[2] Benchmarks Game: https://benchmarksgame-team.pages.debian.net/benchmarksgame/

[3] CBench: http://ctuning.org/cbench

[4] MiBench: http://vhosts.eecs.umich.edu/mibench/

[5] Polybench: https://web.cse.ohio-state.edu/~pouchet.2/software/polybench/ 


# See more

These applications were used on the evaluation of <tt>SmartApprox</tt>. See more at https://varchc.github.io/smartapprox


